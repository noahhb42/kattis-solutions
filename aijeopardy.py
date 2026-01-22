import math

def find_m(n,k,best_m):
    if k==1:
        return n 
    if k==2:
        d = 1+8*n
        s = int(math.sqrt(d))
        if s*s != d:
            return None
        if (1+s)%2!=0:
            return None 
        m = (1+s)//2
        if m>=4 and math.comb(m,2)==n:
            return m 
        return None 
    lo = 2*k 
    if best_m is not None and lo>=best_m:
        return None
    hi=lo
    while True:
        if best_m is not None and hi>=best_m:
            hi = best_m-1
            if hi < lo:
                return None 
            if math.comb(hi,k) < n:
                return None 
            break 
        c = math.comb(hi,k)
        if c>=n:
            break 
        hi *=2 
    l = lo-1
    r = hi 
    while r-l>1:
        mid = (r+l)//2
        if math.comb(mid,k) >= n:
            r = mid
        else:
            l = mid
    return r if math.comb(r,k)==n else None

n = int(input())
if n==1:
    print(0,0)
    exit()

best_m = None
best_k = None

for k in range(n.bit_length(),0,-1):
    if best_m is not None and 2*k >= best_m:
        continue
    m = find_m(n,k,best_m)
    if m is None:
        continue
    if best_m is None or m < best_m or (m==best_m and k<best_k):
        best_m = m 
        best_k = k

print(best_m, min(best_k, best_m-best_k))