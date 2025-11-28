import sys,heapq as h
s=list(map(int,sys.stdin.read().split()))
A,H,n,m=s[:4]
g=[[]for _ in range(n+1)]
i=4
for _ in range(m):
    e,b,a,hh=s[i:i+4];i+=4
    g[e].append(((hh-1)//A*a,b))
d=[H]*(n+1);d[1]=0
q=[(0,1)]
while q:
    c,u=h.heappop(q)
    if c>d[u]:continue
    if u==n:break
    for w,v in g[u]:
        nc=c+w
        if nc<d[v]and nc<H:
            d[v]=nc
            h.heappush(q,(nc,v))
print('Oh no' if d[n]>=H else H-d[n])