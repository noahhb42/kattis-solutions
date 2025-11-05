from math import pi,sqrt
t=iter(open(0).read().split())
n=int(next(t));m=int(next(t));q=int(next(t))
C={};P=[]
for _ in range(q):
    x=int(next(t));y=int(next(t));s=next(t)
    C[(x,y)]=s;P.append((x,y,1 if s=='+' else -1))
T1=1/pi;T2=1/pi**2;T3=1/pi**3
for y in range(1,n+1):
    row=[]
    for x in range(1,m+1):
        s=C.get((x,y))
        if s: row.append(s); continue
        v=0.0
        for px,py,sg in P:
            dx=x-px;dy=y-py
            v+=sg/sqrt(dx*dx+dy*dy)
        a=abs(v)
        row.append('0' if v>0 and a>=T1 else
                   '%' if v<0 and a>=T1 else
                   ('O' if v>0 else 'X') if a>=T2 else
                   ('o' if v>0 else 'x') if a>=T3 else '.')
    print(''.join(row))
