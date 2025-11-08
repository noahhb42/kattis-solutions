I=iter(map(int,open(0).read().split()))
n=m=p=0
try:n=next(I);m=next(I);p=next(I)
except:exit()
N=n+m+p+2;S=N-2;T=N-1
G=[[]for _ in[0]*N]
def ae(u,v,c):
    G[u].append([v,c,len(G[v])]);G[v].append([u,0,len(G[u])-1])
for j in range(n):ae(S,j,1)
for j in range(n):
    k=next(I)
    for _ in range(k):ae(j,n+next(I)-1,1)
cat=[-1]*m
for j in range(p):
    l=next(I);L=[next(I)-1 for _ in[0]*l];r=next(I)
    for t in L:cat[t]=j;ae(n+t,n+m+j,1)
    ae(n+m+j,T,r)
for t in range(m):
    if cat[t]<0:ae(n+t,T,1)
from collections import deque
def bfs():
    D=[-1]*N;D[S]=0;q=deque([S])
    while q:
        u=q.popleft()
        for v,c,_ in G[u]:
            if c and D[v]<0:D[v]=D[u]+1;q.append(v)
    return D
def dfs(u,f):
    if u==T:return f
    while it[u]<len(G[u]):
        v,c,r=G[u][it[u]]
        if c and D[v]==D[u]+1:
            x=dfs(v,min(f,c))
            if x:
                G[u][it[u]][1]-=x;G[v][r][1]+=x;return x
        it[u]+=1
    return 0
flow=0
while 1:
    D=bfs()
    if D[T]<0:break
    it=[0]*N
    while 1:
        x=dfs(S,10**9)
        if not x:break
        flow+=x
print(flow)