from sys import*
n,k,*g=map(int,stdin.read().split())
a=[[]for _ in range(k+1)]
for i,v in enumerate(g):a[v].append((i//n,i%n))
if 0 in map(len,a[1:]):print(-1);exit()
d=[0]*len(a[1])
for t in range(2,k+1):
 b=[9**9]*len(a[t])
 for i,(x,y) in enumerate(a[t-1]):
  for j,(X,Y) in enumerate(a[t]):
   u=d[i]+abs(x-X)+abs(y-Y)
   if u<b[j]:b[j]=u
 d=b
print(min(d))