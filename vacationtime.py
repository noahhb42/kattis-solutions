from heapq import heappop,heappush
a=open(0).read().split();A=int(a[0]);F=int(a[1]);i=2
g=[[]for _ in range(A)];r=[[]for _ in range(A)];e=[]
for _ in range(F):
 u=int(a[i]);v=int(a[i+1]);c=int(a[i+2]);m=a[i+3];i+=4
 g[u]+=(v,c),;r[v]+=(u,c),
 if m=='A380':e+=((u,v,c),)
INF=10**18
def d(s,G):
 D=[INF]*A;D[s]=0;h=[(0,s)]
 while h:
  w,u=heappop(h)
  if w>D[u]:continue
  for v,c in G[u]:
   t=w+c
   if t<D[v]:D[v]=t;heappush(h,(t,v))
 return D
x=d(0,g);y=d(A-1,r)
ans=min([x[u]+c+y[v]for u,v,c in e if x[u]<INF and y[v]<INF]or[INF])
print(ans if ans<INF else -1)