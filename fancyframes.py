s,f,t,g=input().split()
t=int(t);g=int(g)

for _ in range(t):
    print(f*(2*t+2*g+len(s)))
for _ in range(g):
    print(f*t+' '*(2*g+len(s))+f*t)
print(f*t+' '*g+s+' '*g+f*t)
for _ in range(g):
    print(f*t+' '*(2*g+len(s))+f*t)
for _ in range(t):
    print(f*(2*t+2*g+len(s)))