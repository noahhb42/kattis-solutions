n,m=map(int,input().split())
cr = 0
l = []
s = input().split()
m+=s.count('undo')
i = 0
while i<m:
    if s[i]=='undo':
        a = int(s[i+1])
        i+=2
        for _ in range(a):
            b = l.pop(-1)
            cr-=b
        cr%=n
    else:
        l.append(int(s[i]))
        cr+=int(s[i])
        cr%=n
        i+=1
print(cr)