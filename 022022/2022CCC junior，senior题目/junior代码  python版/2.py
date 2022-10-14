n = int(input())
cnt = 0
for _ in range(n):
    point_score = int(input())
    foul = int(input())
    if point_score*5-foul*3 > 40:
        cnt += 1

if cnt == n:
    print(cnt,end='+\n')
else:
    print(cnt)