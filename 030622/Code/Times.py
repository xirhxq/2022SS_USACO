a_input = input()
b_input = input()

a = [ord(i) - ord('0') for i in a_input]
b = [ord(i) - ord('0') for i in b_input]

a.reverse()
b.reverse()

max_len = len(a) + len(b)

for i in range(len(a), max_len):
    a.append(0)

for i in range(len(b), max_len):
    b.append(0)

c = []

for i in range(max_len):
    c.append(0)
    for j in range(i + 1):
        c[i] += a[j] * b[i - j]
    print(c)

for i in range(max_len - 1):
    if c[i] > 9:
        c[i + 1] += c[i] // 10
        c[i] %= 10

if c[max_len - 1] > 9:
    c.append(c[max_len - 1] // 10)
    c[max_len - 1] %= 10

c.reverse()

res = ''

for i in c:
    res = res + str(i)

print(res)
