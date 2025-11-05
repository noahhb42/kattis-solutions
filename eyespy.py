import collections as C
r,c=map(int,input().split())
g=[list(input().strip()) for _ in range(r)]
for i in range(r):
  for j in range(c):
    if g[i][j]=='A':s=i*c+j
    if g[i][j]=='P':t=i*c+j
p=[-1]*(r*c);p[s]=s;q=C.deque([s])
while q:
  u=q.popleft()
  if u==t:break
  x,y=divmod(u,c)
  for a,b in((1,0),(-1,0),(0,1),(0,-1)):
    nx,ny=x+a,y+b
    if 0<=nx<r and 0<=ny<c and g[nx][ny]!='#':
      v=nx*c+ny
      if p[v]<0:p[v]=u;q.append(v)
if p[t]<0:print('call for help')
else:
  u=t
  while u!=s:
    x,y=divmod(u,c)
    if u!=t and g[x][y]=='.':g[x][y]='X'
    u=p[u]
  for R in g:print(''.join(R))
