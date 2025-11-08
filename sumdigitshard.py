A,B=map(int,open(0).read().split())
def h(n):
 s=0
 while n:s+=9**(n%10);n//=10
 return s
H=[h(i) for i in range(A,B+1)];R=[]
for x in range(A,B+1):
 y=(A+x-1)//x*x
 while y<=B:
  z=y//x
  if z>=x and A<=z<=B and H[x-A]+H[z-A]==H[y-A]:R+=((x,z,y),)
  y+=x
print(f"{len(R)} digit-preserving pair(s)");R.sort();print('\n'.join(f"x = {x}, y = {y}, xy = {z}"for x,y,z in R))