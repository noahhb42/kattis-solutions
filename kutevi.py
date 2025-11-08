from math import gcd
I=iter(map(int,open(0).read().split()))
n=next(I);m=next(I);g=0
for _ in range(n): g=gcd(g,next(I))
g=gcd(g,360)
print('\n'.join('YNEOS'[next(I)%g>0::2] for _ in range(m)))