import queue

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

q = queue.Queue()
q.put(0)

vis = [0]
dis_dict = {}
for i in range(n):
    dis_dict[i] = 0

while not q.empty():
    u = q.get()
    # print("arrive at {}".format(u))
    for i in dict[u]:
        if i not in vis:
            # print("put {}".format(i))
            vis.append(i)
            dis_dict[i] = dis_dict[u] + 1
            q.put(i)
print(dis_dict)
# A -> BC -> FED
'''
[]
[A]
[]
[BC]
[C]
[CEF]
[EFD]
[FD]
[D]
[]
'''