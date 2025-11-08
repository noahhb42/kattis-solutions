I=iter(map(int,open(0).read().split()))
D={}
for _ in range(next(I)):
    k=next(I);L=[]
    for _ in range(k):L+=((next(I),next(I)),)
    p=0
    for n,d in sorted(L,key=lambda x:x[1]):
        D[d]=D.get(d,0)+n-p;p=n
s=0;R=[]
for d in sorted(D):s+=D[d];R+=s,
print(*R)