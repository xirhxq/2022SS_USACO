def getReachablePages(node, pages, dict):
    if node not in pages:
        pages.append(node)
        for child in dict[node]:
            getReachablePages(child, pages, dict)

def findShortestPath(nodesToCheck, dist, dict):
    dist += 1
    childNodes = []
    for node in nodesToCheck:
        if len(dict[node]) == 0:
            return dist
        else:
            for child in dict[node]:
                childNodes.append(child)
    return findShortestPath(childNodes, dist, dict)

N = int(input())
dict = {}

for i in range(1, N + 1):
    dict[i] = []

for i in range(1, N + 1):
    d = list(map(int, input().split()))
    for j in range(1, len(d)):
        dict[i].append(d[j])

pages = []
getReachablePages(1, pages, dict)

if len(pages) == N:
    print("Y")
else:
    print("N")

dist = 0
nodeToCheck = [1]
print(findShortestPath(nodeToCheck, dist, dict))