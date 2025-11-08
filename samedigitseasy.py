a,b=map(int,open(0).read().split());b+=1;p=9
def h(n):
 s=0
 while n:s+=p**(n%10);n//=10
 return s
d={i:h(i)for i in range(a,b)};r=[]
for x in range(a,b):
 for y in range(x,b):
  if d[x]+d[y]==h(x*y):r+=((x,y,x*y),)
print(f"{len(r)} digit-preserving pair(s)");r and print('\n'.join(f"x = {x}, y = {y}, xy = {z}"for x,y,z in r))