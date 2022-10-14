from functools import cmp_to_key

n = int(input())
t = int(input())
tr = [(0, 0)] * t
xx = [0] * t
for i in range(t):
    x, y = input().split()
    x = int(x)
    y = int(y)
    tr[i] = (x, y)
    xx[i] = x + 1


def cmp(a, b):
    ax, ay = a
    bx, by = b
    if ay < by:
        return -1
    elif ay == by and ax < bx:
        return -1
    return 1


ntr = sorted(tr, key=cmp_to_key(cmp))
xx = list(set(xx))
xx.append(1)
xx.sort()

print(ntr)
print(xx)

left = 1
right = n + 1
while left + 1 < right:
    flag = False
    mid = (left + right) // 2
    # print('mid', mid)
    for i in range(len(xx)):
        # print(xx[i])
        if xx[i] + mid - 1 > n:
            break
        if flag:
            break
        last = 0
        for x, y in ntr:
            if xx[i] <= x <= xx[i] + mid - 1:
                if y - last - 1 >= mid:
                    flag = True
                    left = mid
                    break
                else:
                    last = y
        if n + 1 - last - 1 >= mid:
            flag = True
            left = mid
        # print(left,flag)
    if not flag:
        right = mid
print(left)
