'''
4
4
0 1
0 2
1 3
2 3
'''

n = int(input())
m = int(input())


graph_list = []
for i in range(n):
    tmp_ls = []
    for j in range(n):
        tmp_ls.append(False)
    graph_list.append(tmp_ls)

for i in range(m):
    ls = list(map(int, input().split()))
    graph_list[ls[0]][ls[1]] = True
    graph_list[ls[1]][ls[0]] = True

print(graph_list)

# dict = {}
# for i in range(n):
#     dict[i] = []
#
# for i in range(m):
#     ls = list(map(int,input().split()))
#     # ls = ['A', 'B']
#     dict[ls[0]].append(ls[1])
#     dict[ls[1]].append(ls[0])
#     print(dict)