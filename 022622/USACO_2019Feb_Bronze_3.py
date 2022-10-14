fin = open("traffic.in", "r")
fout = open("traffic.out", "w")

n = int(fin.readline())

state = []
min_num = []
max_num = []

for i in range(n):
    s, mn, mx = fin.readline().split()
    state.append(s)
    min_num.append(int(mn))
    max_num.append(int(mx))

res_in_min, res_out_min, res_in_max, res_out_max = 0, 0, 1e9, 1e9

for i in range(n):
    if state[i] == "on":
        res_out_min += min_num[i]
        res_out_max += max_num[i]
    elif state[i] == "off":
        res_out_min -= max_num[i]
        res_out_min = max(0, res_out_min)
        res_out_max -= min_num[i]
    else:
        res_out_min = max(res_out_min, min_num[i])
        res_out_max = min(res_out_max, max_num[i])

for i in reversed(range(n)):
    if state[i] == "off":
        res_in_min += min_num[i]
        res_in_max += max_num[i]
    elif state[i] == "on":
        res_in_min -= max_num[i]
        res_in_min = max(0, res_in_min)
        res_in_max -= min_num[i]
    else:
        res_in_min = max(res_in_min, min_num[i])
        res_in_max = min(res_in_max, max_num[i])

fout.write("{} {}\n".format(res_in_min, res_in_max))
fout.write("{} {}".format(res_out_min, res_out_max))

'''
4
on 1 1
none 10 14
none 11 15
off 2 3
'''