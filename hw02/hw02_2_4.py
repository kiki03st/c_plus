f = open('linear_regression.txt', mode = 'r')	#파일 입출력 객체 f 선언
arr = []	#데이터를 저장할 리스트 arr 선언
for i in f.readlines():
    index, worked_hours, number_of_dolls = i.split()	#f.readlines() 속 요소 한줄을 띄어쓰기를 기준으로 세 변수에 나눠서 저장
    worked_hours += ' hours'	#worked_hours에 단위인 hours 붙이기
    number_of_dolls += ' dolls'	#number_of_dolls에 단위인 dolls 붙이기
    arr.append([index, worked_hours, number_of_dolls])	#index, worked_hours, number_of_dolls를 요소로 한 리스트를 arr에 저장
f.close()	#파일 입출력 종료
def linear_regression(arr):	#선형 회귀 함수 y = ax + b에서 a와 b를 구하는 함수
    e_x, e_x_2, e_xy, e_y = 0, 0, 0, 0	#x의 합, x의 제곱의 합, x와 y의 곱의 합, y의 합을 저장할 변수들의 초기값을 0으로 선언
    n = len(arr)	#매개변수로 입력받은 배열의 길이를 변수 n에 저장
    for i in arr:
        _, worked_hours_raw, number_of_dolls_raw = i	#arr의 요소 리스트 중 0번째 인덱스 값은 필요없으므로 버리기, 1번째와 2번째 인덱스 값이 각각 x, y를 구하기 위한 값
        worked_hour = float(worked_hours_raw[:-6])	#단위를 제외한 문자열 형태의 실수값을 실수형으로 변환하여 worked_hour에 저장 - x
        number_of_dolls = float(number_of_dolls_raw[:-6])	#단위를 제외한 문자열 형태의 실수값을 실수형으로 변환하여 number_of_dolls에 저장 - y
        e_x+=worked_hour	#x값을 x의 합을 저장하는 변수인 e_x에 더함
        e_x_2+=worked_hour ** 2		#x의 제곱을 x의 제곱의 합을 저장하는 변수인 e_x_2에 더함
        e_xy+=worked_hour * number_of_dolls	#x와 y의 곱을 x와 y의 곱의 합을 저장하는 변수인 e_xy에 더함
        e_y+=number_of_dolls	#y값을 y의 합을 저장하는 변수인 e_y에 더함
    a = (n * e_xy - e_x * e_y) / (n * e_x_2 - e_x ** 2)	#x와 y의 연산을 이용한 a의 값 도출
    b = (e_y - e_x * a) / n	#앞에서 구한 a 값과 x, y 연산을 이용한 b의 값 도출
        
    return a, b	#a, b 값 반환
a, b = linear_regression(arr)	#a, b 변수를 linear_regression 함수의 반환값으로 각각 지정
def function(a, b, x):	#y의 값을 연산하기 위해 매개변수 a, b, x를 입력받는 함수 function 작성
	return a * x + b
print('학습 모델에 의해 예측한', 7.3, '시간 작업하였을 때 완성된 인형은', function(a, b, 7.3), '개입니다. ')

