import matplotlib
from math import ceil	#올림 함수 이용을 위한 math import
matplotlib.use('QtAgg')	#matplotlib 화면을 출력하기 위한 백엔드 설정
import matplotlib.pyplot as plt
f = open('linear_regression.txt', mode = 'r')	#linear_regression.txt 파일 데이터를 입력받을 파일 입출력 객체 f 생성
arr = []	#데이터를 저장할 리스트 arr 생성
for i in f.readlines():	#f.readlines()를 통해 받아온 리스트를 순서대로 i의 값으로 지정
    index, worked_hours, number_of_dolls = i.split()	#파일 내용 한줄의 내용을 각각 index, worked_hours, number_of_dolls로 분할해서 입력
    worked_hours += ' hours'	#worked_hours에 단위인 hours 붙이기
    number_of_dolls += ' dolls'	#number_of_dolls에 단위인 dolls 붙이기
    arr.append([index, worked_hours, number_of_dolls])	#index, worked_hours, number_of_dolls를 리스트로 묶어 arr에 저장하기
f.close()	#파일 입출력 종료
x = []	#데이터의 x 좌표를 저장할 리스트 x 생성
y = []	#데이터의 y 좌표를 저장할 리스트 y 생성
max = 0	#데이터의 x 좌표 중 가장 큰 값을 저장하기 위한 변수 max의 초기값을 0으로 선언
def linear_regression(arr):	#선형 회귀 함수 y = ax + b에서 a와 b를 구하는 함수
	e_x, e_x_2, e_xy, e_y = 0, 0, 0, 0	#x의 합, x의 제곱의 합, x와 y의 곱의 합, y의 합을 저장할 변수들의 초기값을 0으로 선언
	n = len(arr)	#매개변수로 입력받은 배열의 길이를 변수 n에 저장
	global x, y, max	#함수 바깥 변수를 불러오기 위해 global 활용
	for i in arr:
		_, worked_hours_raw, number_of_dolls_raw = i	#arr의 요소 리스트 중 0번째 인덱스 값은 필요없으므로 버리기, 1번째와 2번째 인덱스 값이 각각 x, y를 구하기 위한 값
		worked_hour = float(worked_hours_raw[:-6])	#단위를 제외한 문자열 형태의 실수값을 실수형으로 변환하여 worked_hour에 저장 - x
		number_of_dolls = float(number_of_dolls_raw[:-6])	#단위를 제외한 문자열 형태의 실수값을 실수형으로 변환하여 number_of_dolls에 저장 - y
		x.append(worked_hour)	#x에 x 좌표 저장
		y.append(number_of_dolls)	#y에 y 좌표 저장
		if worked_hour > max: max = worked_hour	#x 좌표가 max보다 크다면 max 값을 현재 x 좌표로 재설정
		e_x+=worked_hour	#x값을 x의 합을 저장하는 변수인 e_x에 더함
		e_x_2+=worked_hour ** 2		#x의 제곱을 x의 제곱의 합을 저장하는 변수인 e_x_2에 더함
		e_xy+=worked_hour * number_of_dolls	#x와 y의 곱을 x와 y의 곱의 합을 저장하는 변수인 e_xy에 더함
		e_y+=number_of_dolls	#y값을 y의 합을 저장하는 변수인 e_y에 더함
	a = (n * e_xy - e_x * e_y) / (n * e_x_2 - e_x ** 2)	#x와 y의 연산을 이용한 a의 값 도출
	b = (e_y - e_x * a) / n	#앞에서 구한 a 값과 x, y 연산을 이용한 b의 값 도출
        
	return a, b	#a, b 값 반환
a, b = linear_regression(arr)	#a, b 변수를 linear_regression 함수의 반환값으로 각각 지정
# 2 - 3
def function(a, b, x):	#y의 값을 반환하기 위해 ax + b 연산을 수행하는 함수 function 선언
	return a * x + b
plt.scatter(x, y)	#x, y 좌표에 해당하는 점 찍기
plt.plot([function(a, b, i) for i in range(ceil(max) + 1)])	#y = ax + b 선형 그래프 그리기
plt.show()	#그래프 출력하기
