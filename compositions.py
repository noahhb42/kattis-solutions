it=iter(map(int,open(0).read().split()))
o=[]
for _ in range(next(it)):
    K=next(it);n=next(it);m=next(it);k=next(it)
    f=[1]+[0]*n
    for t in range(1,n+1):
        f[t]=sum(f[t-i] for i in range(1,t+1) if (i-m)%k)
    o.append(f"{K} {f[n]}")
print("\n".join(o))
