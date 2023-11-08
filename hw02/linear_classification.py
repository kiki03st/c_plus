import sympy as sp
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
f = open('linear_classification.txt', mode = 'r')
a, b, c = sp.symbols('a b c')
sum_f_x = 0
x_up = []
y_up = []
z_up = []
x_down = []
y_down = []
z_down = []
for i in f.readlines():
    index, S, T, label = i.split()
    S = int(S)
    T = int(T)
    label = int(label)
    if 
    # x : S, y : T, label : z -> sum(ax + by + c - z)
    # 편미분(a), 편미분(b), 편미분(c) 후, 병렬 연산을 활용하여 a, b, c 구하기
    #공식 : z = ax + by + c
    x = a * S + b * T + c - label
    f_x = x * x
    sum_f_x = sum_f_x + f_x
f.close()
dfda = sp.Eq(sp.diff(sum_f_x, a), 0)
dfdb = sp.Eq(sp.diff(sum_f_x, b), 0)
dfdc = sp.Eq(sp.diff(sum_f_x, c), 0)
result = sp.solve((dfda, dfdb, dfdc))
A, B, C = map(float, result.values())
z = A * 47 + B * 29 + C
print(z)
fig = plt.figure()
ax = fig.add_subplot(111, projection = '3d')
