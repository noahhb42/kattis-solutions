d=open(0).read().split();a=d[2];b=d[3];L=[a,b]+d[4:];I={}
for i,s in enumerate(L):I[s]=i
S=I[a];T=I[b];N=len(L);p=[-1]*N;p[S]=S;q=[S]
for v in q:
 if v==T:break
 s=L[v]
 for i,c in enumerate(s):
  x=int(c)
  for k in(-1,1):
   t=s[:i]+str((x+k)%10)+s[i+1:]
   u=I.get(t)
   if u is not None and p[u]<0:p[u]=v;q.append(u)
if p[T]<0:print("Neibb")
else:
 R=[];v=T
 while 1:
  R.append(L[v])
  if v==p[v]:break
  v=p[v]
 print(len(R)-1)
 print('\n'.join(R[::-1]))