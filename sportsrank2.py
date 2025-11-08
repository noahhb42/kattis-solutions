from collections import Counter as C
I=iter(open(0).read().split())
for _ in range(int(next(I))):
    n=int(next(I)); c=C(int(next(I)) for __ in range(n))
    p=r=0
    for x in sorted(c,reverse=True):
        p+=c[x]
        if c[x]>1: r=n-p; break
    print(r)
