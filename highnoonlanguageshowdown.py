import math

N,k = map(int,input().split())

if any(n >= k*math.ceil(math.log2(n+1)) for n in range(1,N+1)):
    print("Good to go!")
    exit()

print("Tweak the bounds!")