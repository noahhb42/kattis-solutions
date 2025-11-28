import sys
d="22233344455566677778889999"
s=sys.stdin.read().split()
n=int(s[0]);f={}
for w in s[2:2+n]:
    k=''.join(d[ord(c)-97]for c in w)
    f.setdefault(k,[]).append(w)
for p in s[2+n:]:
    a=f.get(p,[])
    print(len(a),*a)
