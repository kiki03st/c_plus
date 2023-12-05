import numpy as np
import math

def sigmoid_list(x_list):
    y = np.zeros((len(x_list), 1))
    for i in range(len(x_list)): y[i] = 1 / (1 + math.exp(-x_list[i]))
    return y

n = list(map(float, input().split()))
print(sigmoid_list(n))
