s,m,n=map(int,input().split())
for _ in range(n):
    typ,*l = input().split()
    if typ=="DRIP":
        a,b = map(int,l)
        a*=s
        buy = a//b
        s+=buy
        m+=a-buy*b
    else:
        a=int(l[0])
        s+=m//a
        m-=m//a*a
print(*[s,m],sep='\n')