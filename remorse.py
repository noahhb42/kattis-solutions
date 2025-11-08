t=[0]*26
for x in open(0).read().lower():
    i=ord(x)-97
    if 0<=i<26:t[i]+=1
f=sorted([x for x in t if x],reverse=1);n=sum(f);m=len(f);r=[];a=b=1;i=1
while len(r)<m:r+=[2*i-1]*min(b,m-len(r));a,b=b,a+b;i+=1
print(sum(f[j]*r[j] for j in range(m))+3*(n-1))