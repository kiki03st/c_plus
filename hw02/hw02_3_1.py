f = open('linear_classification.txt', mode = 'r')	#파일 입출력 객체 f 선언, 읽기 모드로 파일 열기
arr = []	#데이터를 저장할 리스트 arr 선언
for i in f.readlines():	#파일 속 내용을 한줄씩 i에 대입하기
	index, S, T, label = i.split()	#한줄의 내용을 띄어쓰기를 기준으로 index, S, T, label 변수에 각각 할당
	arr.append([index, S + 'ml', T + 'ml', label])	#데이터를 arr에 저장
f.close()	#파일 입출력 종료
print('1열 : 각 실험 인덱스\n2열 : 용액S 용량 (ml)\n3열 : 용액T 용량 (ml)\n4열 : label (+1인 경우 실험 성공 /-1인 경우 실험 실패)\n')
n = int(input('출력할 데이터의 행을 입력해주세요 : '))
n-=1	#인덱스는 0부터 시작하므로 1을 빼서 번호를 맞춰줌
sf = '성공' if int(arr[n][3]) == 1 else '실패'
print('실험', arr[n][0], ', 용액S', arr[n][1], ', 용액T', arr[n][2], ', 실험', sf)
