it=iter(open(0).read().split())

n=int(next(it));a=[next(it)for _ in range(n)]
d={a[i]:i for i in range(n)}
m=int(next(it));g=[[]for _ in range(n)]
for _ in range(m):
    x,y=next(it),next(it);u,v=d[x],d[y];g[u]+=[v];g[v]+=[u]
c=[-1]*n
for s in range(n):
    if c[s]<0:
        c[s]=0;st=[s]
        while st:
            u=st.pop()
            for v in g[u]:
                if c[v]<0:c[v]=c[u]^1;st.append(v)
                elif c[v]==c[u]:print("impossible");exit()
print(*[a[i]for i in range(n) if c[i]==0])
print(*[a[i]for i in range(n) if c[i]==1])