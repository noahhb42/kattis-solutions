it=iter(open(0).read().split())
n=int(next(it));m=int(next(it))
g=[list(next(it).strip()) for _ in range(n)]
bad=[]
for i in range(n):
  for j in range(m):
    if g[i][j]=='b':
      ok=0
      for di in (-1,0,1):
        for dj in (-1,0,1):
          if di|dj and 0<=i+di<n and 0<=j+dj<m and g[i+di][j+dj]=='T': ok=1
      if not ok: bad.append((i,j))
if not bad: print('True')
else:
  print('False')
  for i,j in bad: print(i,j)