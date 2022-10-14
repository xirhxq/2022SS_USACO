n = int(input())
s = input()

cnt = 0
tmp = 0
a = []

for i in range(len(s)):
    if i > 0 and s[i] != s[i - 1]:
        cnt = cnt + 1
        a.append(tmp)
        tmp = 0
    tmp = tmp + 1
a.append(tmp)
cnt = cnt + 1
res = 0
for i in range(cnt):
    if i > 0:
        res = res + max(0, a[i] - 1)
    if i < cnt - 1:
        res = res + max(0, a[i] - 1)
    if 0 < i < cnt - 1 and a[i] == 1:
        print("a[{}] = {}".format(i, a[i]))
        res = res + a[i - 1] * a[i + 1]



print(res)