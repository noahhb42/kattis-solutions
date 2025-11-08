it=iter(open(0).read().split())
for _ in range(int(next(it))):
    m=int(next(it))
    X=[0.0]*m;Y=[0.0]*m
    for i in range(m):
        X[i]=float(next(it));Y[i]=float(next(it))
    d=[0.0]+[1e100]*(m-1); used=[0]*m; ans=0.0
    for _ in range(m):
        u=-1; md=1e100
        for i in range(m):
            if not used[i] and d[i]<md: md=d[i]; u=i
        used[u]=1; ans += md**0.5
        for j in range(m):
            if not used[j]:
                dx=X[u]-X[j]; dy=Y[u]-Y[j]; w=dx*dx+dy*dy
                if w<d[j]: d[j]=w
    print(f"{ans:.10f}")
