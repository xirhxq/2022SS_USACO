sam = []
X = int(input())
for _ in range(X):
    nam1,nam2 = input().split()
    sam.append((nam1,nam2))
dif = []
Y = int(input())
for _ in range(Y):
    nam1,nam2 = input().split()
    dif.append((nam1,nam2))
G = int(input())
d = {}
for i in range(G):
    nam1,nam2,nam3 = input().split()
    d[nam1] = i
    d[nam2] = i
    d[nam3] = i

cnt = 0
for nam1,nam2 in sam:
    if d[nam1] != d[nam2]:
        cnt += 1
for nam1,nam2 in dif:
    if d[nam1] == d[nam2]:
        cnt += 1
print(cnt)