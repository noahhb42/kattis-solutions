a=list(map(int,open(0).read().split()))
n,yc,ya=a[0],a[2],a[4];i=5;I=[]
for _ in range(n):I+=a[i+1:i+4:2],;i+=4
I.sort();m=[]
for l,r in I:
    if m and l<=m[-1][1]:m[-1][1]=max(m[-1][1],r)
    else:m+=[[l,r]]
if ya>=yc:print(0.0);exit()
c=sum(max(0,min(r,yc)-max(l,ya))for l,r in m)
print(yc-ya-c+0.0)