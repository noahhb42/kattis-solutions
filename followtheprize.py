a=list(map(int,open(0).read().split()));p=a[1];i=3
while i<len(a):x,y=a[i],a[i+1];p=y if p==x else x if p==y else p;i+=2
print(p)