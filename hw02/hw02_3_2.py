import sympy as sp
sum_f_x = 0	#방정식의 제곱을 저장하는 변수 sum_f_x 선언
f = open('linear_classification.txt', mode = 'r')	#파일 입출력 객체 f 선언, 읽기 모드로 파일 열기
a, b, c = sp.symbols('a b c')	#변수 a, b, c 선언
for i in f.readlines():	#파일 속 내용을 한줄씩 i에 대입하기
	index, S, T, label = i.split()	#한줄의 내용을 띄어쓰기를 기준으로 index, S, T, label 변수에 각각 할당
	S, T, label = map(int, [S, T, label])	#S, T, label은 문자열로 된 정수 데이터이므로 정수형으로 바꿔줌
    # x : S, y : T, label : z -> sum(ax + by + c - z)
    # 편미분(a), 편미분(b), 편미분(c) 후, 병렬 연산을 활용하여 a, b, c 구하기
    #공식 : z = ax + by + c
	x = a * S + b * T + c - label	#ax + by + c - z 방정식 선언
	f_x = x * x	#방정식의 제곱 연산
	sum_f_x = sum_f_x + f_x	#방정식의 제곱을 sum_f_x에 저장
f.close()	#파일 입출력 종료
dfda = sp.Eq(sp.diff(sum_f_x, a), 0)	#방정식의 제곱합을 a를 기준으로 편미분한 값
dfdb = sp.Eq(sp.diff(sum_f_x, b), 0)	#방정식의 제곱합을 b를 기준으로 편미분한 값
dfdc = sp.Eq(sp.diff(sum_f_x, c), 0)	#방정식의 제곱합을 c를 기준으로 편미분한 값
result = sp.solve((dfda, dfdb, dfdc))	#a, b, c를 기준으로 편미분한 방정식들을 토대로 a, b, c의 값을 구함
A, B, C = map(float, result.values())	#sp.solve를 통해 반환되는 값은 딕셔너리 형태이므로 a, b, c의 값만을 활용해주기 위해 result.values()를 통해 값만을 A, B, C에 저장
print('z = (', A, ')x + (', B, ')y + (', C, ')')	#z를 기준으로 한 함수 출력
