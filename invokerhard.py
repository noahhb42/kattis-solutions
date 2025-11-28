import sys
a,b,c,d,e,f,g,h=map(int,sys.stdin.read().split())
t=e*e+f*f+g*g+h*h
print((a*e+b*f+c*g+d*h)/t,(-a*f+b*e-c*h+d*g)/t,(-a*g+b*h+c*e-d*f)/t,(-a*h-b*g+c*f+d*e)/t)