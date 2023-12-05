import math

def sigmoid(x):
    y = 1 / (1 + math.exp(-x))
    return y

n = float(input())
print(sigmoid(n))
