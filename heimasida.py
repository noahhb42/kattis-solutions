s=open(0).read().lower()
for a,b in [("\u00fe","th"),("\u00e6","ae")]:s=s.replace(a,b)
print(''.join(c for c in s.translate(str.maketrans("\u00e1\u00e9\u00ed\u00f3\u00fa\u00fd\u00f6\u00f0","aeiouyod")) if c.isalnum())+'.is')