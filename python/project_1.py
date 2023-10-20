n_row, n_col = map(int, input('마을의 행과 열 개수를 공백 기준으로 분리하여 입력: ').split())
village = []    #마을 저장 리스슽
for i in range(n_row):  #마을 입력받기
    col = list(map(int, input(f'{i} 행 입력: ').split()))
    village.append(col)

#코드 작성
cnt_ctr = 0     #창고의 개수를 저장하는 변수
num = -1        #집 또는 창고에 번호를 매기는 변수

def solution(row, col, first):  #row, col에 해당하는 좌표 근처
    global cnt_ctr, n_row, n_col, village
    tf = True   #아래의 for문에서 if문이 작동했는지를 알아보는 변수
    p = [-1, 0, 1]  #현재 row, col을 기준으로 주변 8칸을 살펴보기 위한 리스트
    for i in p:     #이중 for문을 활용하여 row, col에 p 요소 값들을 더하여 주변 8칸 탐색
        for j in p:
            if 0 <= row + i < n_row and 0 <= col + j < n_col:
                if not(i == 0 and j == 0):
                    if village[row + i][col + j] == 1: #만약 row, col을 기준으로 주변에 값 1인 요소가 있다면
                        tf = False  #if문의 실행여부 바꾸기
                        village[row + i][col + j] = village[row][col]   #값이 1인 요소를 village[row][col]과 같은 값으로 변경
                        solution(row + i, col + j, False)   #재귀를 통해 위의 과정 반복, first를 false로 바꾸어 아래의 if문 실행 불가 상태로 변경
    if tf and first:    #위의 과정에서 if문이 실행되지 않고, solution함수가 한번만 작동한 경우
        cnt_ctr+=1  #row, col 위치의 값을 창고로 인식하여 cnt_ctr 값 1 증가

for i_col in range(n_col):      #village 리스트 탐색
    for i_row in range(n_row):
        if village[i_row][i_col] == 1:  #만약 i_row, i_col 위치에 1이 존재한다면
            village[i_row][i_col] = num #village값을 num으로 변경
            solution(i_row, i_col, True)    #solution 함수를 실행하여 주변의 값을 i_row, i_col 좌표와 똑같은 값으로 변경 및 창고라면 cnt_ctr 값 1 증가
            num-=1  #번호를 1 감소(-1, -2, -3...값으로 순서대로 번호 매기기)
cnt_home = -num - 1 - cnt_ctr   #num이 -(창고 및 집의 통합 개수 + 1)이고, cnt_ctr은 창고의 개수이므로 -num - 1 - cnt_ctr 연산을 통한 집의 개수 구하기

print(f'전대마을에는 {cnt_home}개의 집, {cnt_ctr}개의 창고가 있습니다.')
