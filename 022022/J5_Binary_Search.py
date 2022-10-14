ylen = int(input())
yard = []
for i in range(ylen):
    yard.append([False] * ylen)
# yard : ylen * ylen * int = 1e5 * 1e5 * 4B = 4MB * 10^6


n = int(input())
for i in range(n):
    r, c = [int(x) - 1 for x in input().split()]
    yard[r][c] = True

import time
start = time.time()


def judge(r, c, m):
    # print("judge r = {} c = {} m = {}".format(r, c, m))
    kr = r
    statue = True
    while kr < r + m:
        kc = c
        while kc < c + m:
            # print("kr, kc = {}, {}".format(kr, kc))
            if yard[kr][kc]:
                statue = False
                # set kr and kc to end 2 whiles
                kr = r + m
                kc = c + m
            kc += 1
        kr += 1
    # print(statue)
    return statue


maxn = 1
while maxn <= ylen:
    # print(maxn)
    count = 0
    ddl = (ylen - maxn + 1) * (ylen - maxn + 1)
    # print("ddl = {}".format(ddl))
    r = 0
    while r < ylen - (maxn - 1):
        c = 0
        while c < ylen - (maxn - 1):
            # print("r, c = {}, {}".format(r, c))
            if judge(r, c, maxn):
                # set r and c to break 2 whiles
                r = ylen - (maxn - 1)
                c = ylen - (maxn - 1)
                maxn += 1
            else:
                count += 1
            # print("count = {}".format(count))
            if count == ddl:
                r = ylen - (maxn - 1)
                c = ylen - (maxn - 1)
                maxn += ylen
            # print("maxn = {}".format(maxn))
            c += 1
        r += 1
print(maxn - ylen - 1)


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

'''
1. bug in (maxn < ylen) should be (maxn <= ylen)
10
1
1 1
output should be 9 but is (-1)

2. Time Complexity

3. How to write iterations properly
'''