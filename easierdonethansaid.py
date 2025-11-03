o=[]
for s in open(0).read().split():
    if s=="end": break
    v="aeiou"
    ok=any(c in v for c in s) and not any(((a in v)==(b in v)==(c in v)) for a,b,c in zip(s,s[1:],s[2:])) and not any(a==b and a not in "eo" for a,b in zip(s,s[1:]))
    o.append((f"<{s}> is acceptable.",f"<{s}> is not acceptable.")[not ok])
print("\n".join(o))
