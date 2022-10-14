n = int(input())

xy_list = []
t = int(input())
for i in range(t):
    r, c = [int(x) for x in input().split()]
    xy_list.append((r, c))

res = 0

for i in range(1, n):
    # Judge Square of Side Length i
    i_flag = False
    for x in range(1, n - i + 2):
        for y in range(1, n - i + 2):
            square_flag = False
            for (r, c) in xy_list:
                if x <= r <= x + i - 1 and y <= c <= y + i - 1:
                    square_flag = True
                    break
            if not square_flag:
                i_flag = True
                break
        if i_flag:
            break
    if i_flag:
        res = i
    else:
        break

print(res)

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