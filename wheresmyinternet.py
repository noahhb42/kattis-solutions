it=iter(map(int,open(0).read().split()))
n=next(it);m=next(it)
g=[[]for _ in range(n+1)]
for _ in range(m):
    a=next(it);b=next(it);g[a]+=b,;g[b]+=a,
v=[0]*(n+1);q=[1];v[1]=1;i=0
while i<len(q):
    x=q[i];i+=1
    for y in g[x]:
        if not v[y]:v[y]=1;q.append(y)
r=[str(i) for i in range(1,n+1)if not v[i]]
print('\n'.join(r)or'Connected')
