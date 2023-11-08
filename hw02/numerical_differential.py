def numerical_diff(x):
    p1 = x * x + 2 * x + 1  # f(x) = x^2 + 2*x + 1
    h = 1e-8   # h는 0에 근접한 근사치로 설정
    p2 = (x + h) * (x + h) + 2 * (x + h) + 1    # f(x + h) = (x + h)^2 + 2 * (x + h) + 1
    diff_result = (p2 - p1) / h # dy / dx = (f(x + h) - f(x)) / ((x + h) - x)
    return diff_result

print("x ^ 2 + 2 x + 1 함수의 x=2지점에서의 미분값은", numerical_diff(2), "입니다.")
