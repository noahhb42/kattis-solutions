f=lambda:(lambda a:[(a[i]-144)**2+(a[i+1]-84)**2 for i in range(1,2*a[0]+1,2)])(list(map(int,input().split())))
R=Y=0
for _ in range(10):
 a=f();b=f()
 if a and b:A=min(a);B=min(b);R+=A<B and sum(x<B for x in a);Y+=B<A and sum(x<A for x in b)
 elif a:R+=len(a)
 elif b:Y+=len(b)
print(R,Y)
