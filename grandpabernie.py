t=iter(open(0).read().split())
n=int(next(t));d={}
for _ in range(n):
    c=next(t);d.setdefault(c,[]).append(int(next(t)))
for v in d.values():v.sort()
q=int(next(t))
print('\n'.join(str(d[next(t)][int(next(t))-1])for _ in range(q)))
