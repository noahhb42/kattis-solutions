a,b,c,d,e,f=[*open(0)]
a,b,c,d,e=map(int,[a,b,c,d,e])
a*=2
print(round(a/(b+c)*c+a/(b+d)*d+a/(b+e)*e))