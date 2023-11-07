f = open('linear_classification.txt', mode = 'r')
for i in f.readlines():
    index, S, T, label = i.split()
    S = int(S)
    T = int(T)
