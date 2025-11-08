a=list(map(int,open(0).read().split()))
i=1;n=a[0];T=a[i:i+n];i+=n;m=a[i];P=a[i+1:i+1+m];i+=1+m;b=10**9
for t in T:
    k=a[i];i+=1
    while k:k-=1;b=min(b,t+P[a[i]-1]);i+=1
print(max(0,a[-1]//b-1))