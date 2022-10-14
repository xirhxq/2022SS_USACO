left = 0 # False
right = 100000 # True

def judge(x):
    return x >= 1000

while left < right:
    mid = (left + right) // 2
    if judge(mid):
        right = mid
    else:
        left = mid

print(left)