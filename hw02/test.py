import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

# a, b, c 값 설정
a = -0.0417926603993364
b = -0.025142191526161595
c = 2.480302620277441

# 실험 데이터를 읽어서 저장
data = [
    (35, 27, 1),
    (81, 8, -1),
    (16, 38, 1),
    (28, 42, 1),
    (72, 20, -1),
    (64, 43, -1),
    (29, 13, 1),
    (41, 22, -1),
    (32, 51, -1),
    (15, 36, 1)
]

# 데이터를 개별 리스트로 추출
x_data, y_data, z_data = zip(*data)

# x와 y 값의 범위를 정의
x = np.linspace(-50, 150, 100)
y = np.linspace(-50, 200, 100)

# x와 y 값을 조합하여 2D 그리드 생성
X, Y = np.meshgrid(x, y)

# 주어진 방정식을 사용하여 z 값을 계산
Z = a * X + b * Y + c
# 3D 그래프 생성 및 표시
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# 3D 그래프 생성
ax.plot_surface(X, Y, Z, cmap='viridis')

# 실험 데이터를 점으로 추가
ax.scatter(x_data, y_data, z_data, c='red', marker='o', label='Experimental Data')

# x, y, z 레이블 추가
ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')
ax.set_zlabel('Z-axis')

# 범례 추가
ax.legend()

plt.show()

