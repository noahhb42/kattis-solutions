a=list(map(float,open(0).read().split()))
n=int(a[0]);t=a[1];g=a[2:]
print(sum((t*t-(x/2)**2)**0.5 for x in g))