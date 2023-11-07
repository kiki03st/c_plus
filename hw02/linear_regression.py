import matplotlib.pyplot as plt
import numpy as np
# 2 - 1
f = open('linear_regression.txt', mode = 'r')
arr = []
for i in f.readlines():
    print(i.split())
    index, worked_hours, number_of_dolls = i.split()
    worked_hours += ' hours'
    number_of_dolls += ' dolls'
    arr.append([index, worked_hours, number_of_dolls])
f.close()
print(arr)

# 2 - 2
def linear_regression(arr):
    e_x, e_x_2, e_xy, e_y = 0, 0, 0, 0
    n = len(arr)
    for i in arr:
        _, worked_hours_raw, number_of_dolls_raw = i
        worked_hour = float(worked_hours_raw[:-6])
        number_of_dolls = float(number_of_dolls_raw[:-6])
        plt.axis([worked_hour, number_of_dolls])
        e_x+=worked_hour
        e_x_2+=worked_hour ** 2 
        e_xy+=worked_hour * number_of_dolls
        e_y+=number_of_dolls
    a = (n * e_xy - e_x * e_y) / (n * e_x_2 - e_x ** 2)
    b = (e_y - e_x * a) / n
        
    return a, b
a, b = linear_regression(arr)
print('y =', a, 'x +', b)
def function(a, b, x):
    return a * x + b
time = 7.3
print('학습 모델에 의해 예측한', time, '시간 작업하였을 때 완성된 인형은', function(a, b, time), '개입니다. ')
x = []
y = []
for i in range(0, 24):
    x.append(i)
    y.append(function(a, b, i))
plt.plot(x, y)
plt.show()
