I=iter(map(int,open(0).read().split()))
n,k=next(I),next(I)
p=[(next(I),next(I),next(I),i) for i in range(n)]
S=set()
for j in range(3):
    S|={x[3] for x in sorted(p,key=lambda t:t[j],reverse=True)[:k]}
print(len(S))