import sympy as sp
import matplotlib
matplotlib.use('QtAgg')  # 또는 'QtAgg'
from matplotlib import cm
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

sum_f_x = 0	#방정식의 제곱을 저장하는 변수 sum_f_x 선언
f = open('linear_classification.txt', mode = 'r')	#파일 입출력 객체 f 선언, 읽기 모드로 파일 열기
a, b, c = sp.symbols('a b c')	#변수 a, b, c 선언
x_up = []	#label이 0보다 큰 데이터 저장
y_up = []
z_up = []
x_down = []	#label이 0보다 작은 데이터 저장
y_down = []
z_down = []
for i in f.readlines():	#파일 속 내용을 한줄씩 i에 대입하기
	index, S, T, label = i.split()	#한줄의 내용을 띄어쓰기를 기준으로 index, S, T, label 변수에 각각 할당
	S, T, label = map(int, [S, T, label])	#S, T, label은 문자열로 된 정수 데이터이므로 정수형으로 바꿔줌
    # x : S, y : T, label : z -> sum(ax + by + c - z)
    # 편미분(a), 편미분(b), 편미분(c) 후, 병렬 연산을 활용하여 a, b, c 구하기
    #공식 : z = ax + by + c
	x = a * S + b * T + c - label	#ax + by + c - z 방정식 선언
	f_x = x * x	#방정식의 제곱 연산
	sum_f_x = sum_f_x + f_x	#방정식의 제곱을 sum_f_x에 저장
	if label > 0:
		x_up.append(S)
		y_up.append(T)
		z_up.append(label)
	else:
		x_down.append(S)
		y_down.append(T)
		z_down.append(label)
f.close()	#파일 입출력 종료
dfda = sp.Eq(sp.diff(sum_f_x, a), 0)	#방정식의 제곱합을 a를 기준으로 편미분한 값
dfdb = sp.Eq(sp.diff(sum_f_x, b), 0)	#방정식의 제곱합을 b를 기준으로 편미분한 값
dfdc = sp.Eq(sp.diff(sum_f_x, c), 0)	#방정식의 제곱합을 c를 기준으로 편미분한 값
result = sp.solve((dfda, dfdb, dfdc))	#a, b, c를 기준으로 편미분한 방정식들을 토대로 a, b, c의 값을 구함
A, B, C = map(float, result.values())	#sp.solve를 통해 반환되는 값은 딕셔너리 형태이므로 a, b, c의 값만을 활용해주기 위해 result.values()를 통해 값만을 A, B, C에 저장
X = np.arange(-0.5, 1.5, 0.1) * 100
Y = np.arange(-0.5, 1.5, 0.1) * 100
X, Y = np.meshgrid(X, Y)
Z = A * X + B * Y + C
fig = plt.figure()
ax = fig.add_subplot(111, projection = '3d')
ax.plot(x_up, y_up, z_up, linestyle="none", marker="o", mfc="none", markeredgecolor="g")	#label이 1인 데이터 3차원 좌표 점 찍기
ax.plot(x_down, y_down, z_down, linestyle="none", marker="o", mfc="none", markeredgecolor="b") #label이 -1인 데이터 3차원 좌표 점 찍기
ax.plot_surface(X, Y, Z, rstride=4, cstride=4, alpha=0.4, cmap=cm.Blues) #평면 그래프 그리기
ax.plot([-50, 100], [A * 50 / B - C / B, A * (-100) / B - C / B], [0,0],'r-')	#선형 그래프 그리기 
plt.show()
