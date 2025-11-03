a,b,c=map(float,open(0))
a*=5280/3600

if a*c>=b:
    print('MADE IT')
else:
    print('FAILED TEST')