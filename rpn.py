l = []
while True:
    s = input()

    if s.isnumeric():
        l.append(int(s))
        continue
    
    if s[1:].isnumeric():
        l.append(-int(s[1:]))
        continue

    if s=='+':
        b,a=l.pop(-1),l.pop(-1)
        l.append(a+b)
        continue
    
    if s=='-':
        b,a=l.pop(-1),l.pop(-1)
        l.append(a-b)
        continue

    if s=='*':
        b,a=l.pop(-1),l.pop(-1)
        l.append(a*b)
        continue

    if s=='/':
        b,a=l.pop(-1),l.pop(-1)
        l.append(a//b)
        continue

    if s=='^':
        b,a=l.pop(-1),l.pop(-1)
        l.append(int(a**b))
        continue

    if s=='dup':
        l.append(l[-1])
        continue

    if s=='pop':
        l.pop(-1)
        continue

    if s=='print':
        print(l[-1])
        continue
    
    if s=='swap':
        b,a=l.pop(-1),l.pop(-1)
        l.append(b);l.append(a)
        continue

    if s=='quit':
        break