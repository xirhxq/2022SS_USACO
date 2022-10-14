n = int(input())
t = int(input())

pos = []
x_list = []

for i in range(t):
    x, y = [int(x) for x in input().split()]
    pos.append((x, y))
    if x not in x_list:
        x_list.append(x)

import time
start = time.time()

x_list.append(0)
x_list.append(n + 1)
x_list = sorted(x_list)

# 离散化

res = 0

for i in range(len(x_list)):
    for j in range(i + 1, len(x_list)):
        x_min = x_list[i] + 1  # 左边界在第i个列号的右面一列
        x_max = x_list[j] - 1  # 右边界在第j个列号的左面一列
        # print("x: {} to {}".format(x_min, x_max))
        if x_max < x_min:
            continue
        # 在固定的左边界和右边界之间 统计树的y值
        y_list = []
        for p in pos:
            x, y = p
            if x_min <= x <= x_max:
                y_list.append(y)
        y_list.append(0)
        y_list.append(n + 1)
        y_list = sorted(y_list)
        # print(y_list)
        for k in range(len(y_list) - 1):
            res = max(res, min(y_list[k + 1] - y_list[k] - 1, x_max - x_min + 1))
        # print(res)
print(res)

elapsed = time.time() - start
print('Time is {}s'.format(elapsed))