from matplotlib import pyplot as plt
import numpy as np
import math

def sigmoid_list(x_list):
	y = np.zeros((len(x_list), 1))
	for i in range(len(x_list)): y[i] = 1 / (1 + math.exp(-x_list[i]))
	return y

x_list = np.arange(-10, 10.01, 0.01))
plt.plot(x_list, sigmoid_list(x_list))
