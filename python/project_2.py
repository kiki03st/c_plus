N, M, V = map(int, input('마을 주민 수, 친구 관계 수, 피해자의 집 주소: ').split())

relation = {}   #친구 관계를 입력하는 relation 딕셔너리 생성
#친구 관계 입력 받기
print("친구 관계 :")
for i in range(M):
    a, b = map(int, input().split())
    if a not in relation:   #relation에 키 a가 존재하지 않으면
        relation[a] = []    #relation 키 a에 대응하는 값을 빈 배열로 지정
    if b not in relation:   #relation에 키 b가 존재하지 않으면
        relation[b] = []    #relation 키 b에 대응하는 값을 빈 배열로 지정
    relation[a].append(b)   #키 a에 해당하는 리스트에 b값 추가
    relation[b].append(a)   #키 a에 해당하는 리스트에 b값 추가
for i in relation.keys():   #relation 딕셔너리 속 키에 대응하는 리스트값들을 정렬함
    relation[i].sort()

dfs_result = [] #dfs 정렬 값 저장 리스트
bfs_result = [] #bfs 정렬 값 저장 리스트
#코드 작성
def dfs(n): #깊이 우선 탐색 함수
    global dfs_result, relation #전역 변수 dfs_result, relation 불러오기
    if len(dfs_result) == 0:    #dfs_result에 아무런 값이 저장되어있지 않은 경우
        dfs_result.append(n)    #dfs_result에 n 저장
    for i in range(len(relation[n])):   #n의 관계 스캔
        if relation[n][i] not in dfs_result:    #n과 친구 관계인 사람이 dfs_result에 존재하지 않은 경우
            dfs_result.append(relation[n][i])   #친구 관계를 dfs_result에 추가
            dfs(relation[n][i]) #함수의 재귀를 통해 친구 관계인 사람의 관계에 대해 재탐색

def bfs(n): #너비 우선 탑색 함수
    global bfs_result, relation #전역 변수 bfs_result, relation 불러오기
    while True: #무한 반복
        if len(bfs_result) == len(relation.keys()): #친구 관계를 bfs_result에 모두 입력한 경우
            return  #함수 멈추기
        elif len(bfs_result) == 0:  #bfs_result가 빈 배열인 경우
            bfs_result.append(n)    #n을 bfs_result에 추가
        for i in range(len(bfs_result)):    #bfs_result에 추가된 모든 관계 스캔
            for j in range(len(relation[bfs_result[i]])):   #bfs_result에 저장된 모든 사람들의 관계 스캔
                if relation[bfs_result[i]][j] not in bfs_result:    #bfs_result에 저장된 사람의 관계가 bfs_result에 저장되어있지 않은 경우
                    bfs_result.append(relation[bfs_result[i]][j])   #관계를 bfs_result에 저장

dfs(V)  #깊이 우선 탐색 실행
bfs(V)  #너비 우선 탐색 실행

print("동선 계획 1 (DFS) : " + " ".join(map(str, dfs_result)))
print("동선 계획 1 (BFS) : " + " ".join(map(str, bfs_result)))

