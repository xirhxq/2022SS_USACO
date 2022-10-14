n = int(input())
s = input()

res = 0

for i in range(len(s)):
    g_cnt = 0
    h_cnt = 0
    for j in range(len(s) - i):
        if s[i + j] == 'G':
            g_cnt = g_cnt + 1
        else:
            h_cnt = h_cnt + 1
        if j > 1 and (g_cnt == 1 or h_cnt == 1):
            res = res + 1
        if g_cnt > 1 and h_cnt > 1:
            break

print(res)