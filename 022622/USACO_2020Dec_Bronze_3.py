n = int(input())

inf = 0x3f3f3f3f
d = []
x = []
y = []
stop_time = []

for i in range(n):
    _d, _x, _y = input().split()
    d.append(_d)
    x.append(int(_x))
    y.append(int(_y))
    stop_time.append(inf)


def hit_time(i, j, cur):
    if d[i] == d[j]:
        return inf
    if d[i] == 'N':
        ix, iy, jx, jy = x[i], y[i], x[j], y[j]
    else:
        ix, iy, jx, jy = y[i], x[i], y[j], x[j]
    if jy <= iy:
        return inf
    if stop_time[j] == inf:
        if ix < jx - cur or ix >= jx + jy - iy:
            return inf
    else:
        if ix > jx or ix < jx - stop_time[j]:
            return inf
    return cur + jy - iy


def advance(cur):
    time = []
    min_time = inf
    for i in range(n):
        time.append(inf)
        if stop_time[i] == inf:
            for j in range(n):
                t = hit_time(i, j, cur)
                time[i] = min(time[i], t)
            min_time = min(min_time, time[i])
    if min_time == inf:
        return inf
    for i in range(n):
        if stop_time[i] == inf:
            if d[i] == 'N':
                y[i] += min_time - cur
            else:
                x[i] += min_time - cur
        if time[i] == min_time:
            stop_time[i] = min_time
    return min_time

current_time = 0

while current_time != inf:
    current_time = advance(current_time)

for i in range(n):
    if stop_time[i] == inf:
        print("Infinity")
    else:
        print(stop_time[i])

'''
6
E 3 5
N 5 3
E 4 6
E 10 4
N 11 2
N 8 1
'''