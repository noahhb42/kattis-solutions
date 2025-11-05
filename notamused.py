i=1
for L in open(0):
    s=L.split()
    if s[0]=="OPEN":tin={};tot={}
    elif s[0]=="ENTER":tin[s[1]]=int(s[2])
    elif s[0]=="EXIT":
        n=s[1];t=int(s[2])
        tot[n]=tot.get(n,0)+t-tin.pop(n)
    else:
        print(f"Day {i}")
        for n in sorted(tot):
            c=tot[n]*10
            print(n,f"${c//100}.{c%100:02d}")
        print()
        i+=1
