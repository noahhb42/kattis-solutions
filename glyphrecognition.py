import sys,math
a=list(map(float,sys.stdin.read().split()))
n=int(a[0]);p=a[1:]
pts=list(zip(p[::2],p[1::2]))
bk=3;bs=-1.0
for k in range(3,9):
    c=math.cos(math.pi/k)
    ang=[(2*i+1)*math.pi/k for i in range(k)]
    lo=1e30;hi=0.0
    for x,y in pts:
        m=0.0
        for t in ang:
            d=math.cos(t)*x+math.sin(t)*y
            if d>m:m=d
        r=m/c
        if r<lo:lo=r
        if r>hi:hi=r
    s=(lo/hi)**2
    if s>bs:bs=s;bk=k
print(bk,f"{bs:.10f}")
