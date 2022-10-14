"""
Algorithm: Use BFS
Feature #1: Run BFS to check if you can visit all nodes
Feature #2: In previous BFS, update distance to node from previous
- This problem can be solved with one run of BFS. There is no edge cost.

"""
import queue
q = queue.Queue()
graph = {}
dist = {}

def create_edge(a, b):
    if a in graph.keys():
        graph[a].append(b)
    else:
        graph[a] = [b]

goneToNodes = []
shortest = []

def bfs(node):
    q.put(node)
    while not q.empty():
        u = q.get()
        print("get {}".format(u))
        goneToNodes.append(u)
        for v in graph[u]:
            if dist[v] == 0:
                dist[v] = dist[u] + 1
                # print("dist {} = {}".format(v, dist[v]))
                q.put(v)

N = int(input())
for i in range(1, N+1):
    graph[str(i)] = []
    line = input().split()
    if line != ['0']:
        for j in range(1, len(line)):
            create_edge(str(i), line[j])
            # print("edge {} -> {}".format(str(i), line[j]))
    else:
        # Find boundary nodes that don't connect to any other pages
        shortest.append(i)

for i in range(1, N+1):
    dist[str(i)] = 0

bfs('1')
if len(goneToNodes) >= len(graph.keys()):
    print("Y")
else:
    print("N")

l = []
# find the distance of all the boundary nodes
for i in shortest:
    l.append(dist[str(i)])

print(graph)
print(goneToNodes)
print(dist)
print(shortest)
print(l)
# ignore all pages that by themselves
if len(l) == 0:
    print(1)
for j in sorted(l):
    if j != 0:
        print(j+1)
        break
if sorted(l)[-1] == 0:
    print(1)
# print(l[0]+1)