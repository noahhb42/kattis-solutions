s=list(map(int,open(0).read().split()))
n,p=s[:2];a=s[2:];x=a[p]
if x>300:print(0,0);exit()
del a[p];a.sort();u=pen=x;k=1
for t in a:
    u+=t
    if u>300:break
    k+=1;pen+=u
print(k,pen)