d=open(0).read().split()
r=int(d[0]);c=int(d[1]);k=2
a=[]
for _ in range(r):
 a.append(list(map(int,d[k:k+c])));k+=c
s=int(d[k]);t=int(d[k+1]);k+=2
p=[list(d[k+i])for i in range(s)]
R=[]
for _ in[0]*4:
 h=len(p);w=len(p[0]);x=[]
 for i in range(h):
  for j in range(w):
   if p[i][j]=='#':x+=i,j,
 R.append((h,w,x))
 p=[*map(list,zip(*p[::-1]))]
m=10**9;tot=sum(map(sum,a))
for h,w,x in R:
 for i in range(r-h+1):
  for j in range(c-w+1):
   s2=0
   for z in range(0,len(x),2):
    s2+=a[i+x[z]][j+x[z+1]]
   if s2<m:m=s2
print(tot-m)