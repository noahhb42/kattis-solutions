from collections import deque as d
s=open(0).read().split();n,m=map(int,s[:2]);r=s[2:]
H=n+2;W=m+2;A=[[0]*W for _ in range(H)]
for i,t in enumerate(r,1):
  for j,c in enumerate(t,1):A[i][j]=c>'0'
v=[[0]*W for _ in range(H)];q=d([(0,0)]);v[0][0]=1;ans=0
while q:
  x,y=q.popleft()
  for dx,dy in((1,0),(-1,0),(0,1),(0,-1)):
    X=x+dx;Y=y+dy
    if 0<=X<H and 0<=Y<W:
      if A[X][Y]:ans+=1
      elif not v[X][Y]:v[X][Y]=1;q.append((X,Y))
print(ans)
