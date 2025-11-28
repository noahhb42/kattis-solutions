n,m,k=map(int,input().split())
s=[*map(int,input().split())]
l=[0]*(m+1)

for i in s:
    l[i]+=1

pos = []

sm = 0

for i in range(1,m+1):
    a,b=map(int,input().split())
    if l[i] == 0:
        sm+=2*a
        pos.append(2*a)
    elif l[i] == 1:
        sm+=a
        pos.append(a+b)
    else:
        pos.append(2*b)
    
pos.sort()

sm-=sum(pos[k:])

print(-sm)