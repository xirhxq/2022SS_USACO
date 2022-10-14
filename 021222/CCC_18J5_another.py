class Node:
    def __init__(self, value):
        self.value = value
        self.children = []


def getReachablePages(node, pages):
    if (node.value not in pages):
        pages.add(node.value)
        for child in node.children:
            getReachablePages(child, pages)


def findShortestPath(nodesTocheck, level):
    level += 1
    childNodes = []
    for node in nodesTocheck:
        if len(node.children) == 0:
            return level
        else:
            for child in node.children:
                childNodes.append(child)
    return findShortestPath(childNodes, level)


totalPages = int(input())
pageMap = {}

for i in range(1, totalPages + 1):
    pageMap[i] = Node(i)

for i in range(1, totalPages + 1):
    d = list(map(int, input().split()))
    for j in range(1, d[0] + 1):
        pageMap[i].children.append(pageMap[d[j]])  #

pages = set()
getReachablePages(pageMap[1], pages)
if len(pages) == totalPages:
    print("Y")
else:
    print("N")

level = 0
nodesToCheck = [pageMap[1]]
print(findShortestPath(nodesToCheck, level))