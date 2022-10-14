import time

y_len = int(input())

xy_list = []
n = int(input())
for i in range(n):
    r, c = [int(x) - 1 for x in input().split()]
    xy_list.append((r, c))

start = time.time()


def judge(r, c, m):
    for kr in range(r, r + m):
        for kc in range(c, c + m):
            if (r, c) in xy_list:
                return False
    return True


res = 0

for max_n in range(1, y_len):
    raise_flag = False
    for r in range(0, y_len - max_n + 1):
        for c in range(0, y_len - max_n + 1):
            if judge(r, c, max_n):
                raise_flag = True
            if raise_flag:
                break
        if raise_flag:
            break
    if raise_flag:
        res = max_n

print(res)

elapsed = time.time() - start
print('Time is {}s'.format(elapsed))

'''
15
8
4 7
4 1
14 11
10 6
13 4
4 10
10 3
9 14
'''