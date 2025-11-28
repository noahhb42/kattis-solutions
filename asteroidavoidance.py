import sys
a=list(map(int,sys.stdin.read().split()))
w,h,n,m=a[:4];i=4
A=[]
for _ in range(n):
 x,y,r=a[i:i+3];i+=3
 A.append((x,y,r*r))
for _ in range(m):
 x,y=a[i:i+2];i+=2
 X=x+w;Y=y+h
 ok=1
 for u,v,R in A:
  qx=u;qy=v
  if qx<x:qx=x
  elif qx>X:qx=X
  if qy<y:qy=y
  elif qy>Y:qy=Y
  if (qx-u)**2+(qy-v)**2<=R:
   ok=0
   break
 print(('DOOMSLUG STOP!','DOOMSLUG GO!')[ok])