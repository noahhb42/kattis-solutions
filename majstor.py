a=open(0).read().split()
n=int(a[0]);s=a[1];r=int(a[2]);F=a[3:3+r]
A=sum((1 if x==y else 2 if x+y in('RS','SP','PR') else 0) for w in F for x,y in zip(s,w))
B=0
for j in range(n):
    R=sum(w[j]=='R'for w in F);P=sum(w[j]=='P'for w in F);S=r-R-P
    B+=max(2*S+R,2*R+P,2*P+S)
print(A,B,sep='\n')
