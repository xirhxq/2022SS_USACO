n = int(input())
m = int(input())
dict = {}
for i in range(n):
    dict[i] = []

for i in range(m):
    ls = list(map(int,input().split()))
    # ls = ['A', 'B']
    dict[ls[0]].append(ls[1])
    dict[ls[1]].append(ls[0])

print(dict)

vis = []

def dfs(x):
    # arrive at x
    vis.append(x)
    print('arrive @ {}'.format(x))
    for i in dict[x]:
        if i not in vis:
            dfs(i)

dfs(0)

print(vis)