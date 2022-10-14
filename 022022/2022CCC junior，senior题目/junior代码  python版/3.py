line = input()

ins = ""
sgn = ""
num = ""
flg = 0
for i in range(len(line)):
    if line[i] == '+' or line[i] == '-':
        if line[i] == '+':
            sgn = 'tighten'
        else:
            sgn = 'loosen'
        num = ""
        flg = 1
        continue
    if flg == 0:
        ins += line[i]
    elif flg == 1:
        if not line[i].isdigit():
            print('%s %s %s'%(ins,sgn,num))
            flg = 0
            ins = line[i]
        else:
            num += line[i]
print('%s %s %s'%(ins,sgn,num))