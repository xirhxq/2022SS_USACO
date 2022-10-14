n = int(input())
s = input()

def count(ls):
    g_cnt = 0
    for i in ls:
        if i == 'G':
            g_cnt += 1
    if g_cnt == 1 or len(ls) - g_cnt == 1:
        return True
    else:
        return False

# length = 3, 4, 5 .. n

res = 0
for l in range(3, n + 1):
    # starts from i
    # n = 8
    # 0 1 2 3 4 5 6 7
    # l = 3
    # i -> [0, 5] == [0, 6)
    for i in range(n - l + 1):
        if count(s[i:i+l]):
            res += 1

print(res)