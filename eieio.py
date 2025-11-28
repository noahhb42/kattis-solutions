n,m=map(int,open(0))
if 4*n<m or m%2==1 or 2*n>m:
    print("Rong talning")
    exit()
while 4*n>m:
    m-=2
    n-=1
print(n)