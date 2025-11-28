import sys
t=sys.stdin.read().split()
i=0
n,m=map(int,t[i:i+2]);i+=2
s=set(t[i:i+n]);i+=n
r=[]
for _ in range(m):
    c=int(t[i]);i+=1
    b=0
    for _ in range(c):
        if t[i]not in s:b=1
        i+=1
    r+=('apply','why bother?')[b],
sys.stdout.write('\n'.join(r))