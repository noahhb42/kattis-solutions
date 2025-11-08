a=list(map(int,open(0).read().split()))
h,t=a[1],a[2];x=a[3:]
s=''.join('01'[y<=t]for y in x)
i=s.find('1'*h)
print(i if i!=-1 else'Too hot!')
