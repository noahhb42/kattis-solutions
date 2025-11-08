a=list(map(int,open(0).read().split()))
x,y,z=a[:3];n=a[3];i=4;m=[a[i:i+n],a[i+n:i+2*n],a[i+2*n:i+3*n]]
p=[m[0][0],m[1][0],m[2][0]]
for k in range(1,n):
    p=[m[0][k]+max(p[0],p[1]-x,p[2]-y),
       m[1][k]+max(p[1],p[0]-x,p[2]-z),
       m[2][k]+max(p[2],p[0]-y,p[1]-z)]
print(max(p))