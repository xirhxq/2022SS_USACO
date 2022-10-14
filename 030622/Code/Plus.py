a_input = input()
b_input = input()

a = [ord(i) - ord('0') for i in a_input]
b = [ord(i) - ord('0') for i in b_input]

a.reverse()
b.reverse()

max_len = max(len(a), len(b))

c = []

for i in range(max_len):
    c.append(a[i] + b[i])

for i in range(max_len - 1):
    if c[i] > 9:
        c[i + 1] += c[i] // 10
        c[i] %= 10

if c[max_len - 1] > 9:
    c.append(1)
    c[max_len - 1] %= 10

c.reverse()

res = ''

for i in c:
    res = res + str(i)

print(res)
