from sys import*
s=stdin.read().split()
n=int(s[0]);g=s[1:];o=1;d=(1,0,-1,0,1)
for i in range(n):
 for j in range(n):
  c=g[i][j]
  if c in '.?':
   h=0
   for k in range(4):
    x=i;y=j
    while 1:
     x+=d[k];y+=d[k+1]
     if x<0 or y<0 or x>=n or y>=n:break
     t=g[x][y]
     if t=='?':
      if c=='?':o=0
      else:h=1
      break
     if t!='.':break
   if c=='.'and not h:o=0
  elif c!='X':
   z=0
   if i and g[i-1][j]=='?':z+=1
   if i<n-1 and g[i+1][j]=='?':z+=1
   if j and g[i][j-1]=='?':z+=1
   if j<n-1 and g[i][j+1]=='?':z+=1
   if z!=ord(c)-48:o=0
  if not o:break
 if not o:break
print(o)