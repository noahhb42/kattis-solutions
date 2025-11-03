from collections import defaultdict
n = int(input())
for _ in range(n):
    m = defaultdict(int)
    for i in input().split():
        m[i[0]]+=1
    mx = -1
    out = ''
    for i in m:
        if m[i]>mx or (m[i]==mx and i<out):
            mx = m[i]
            out = i
    print(out)
        