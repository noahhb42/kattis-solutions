import sys
from math import gcd

def egcd(a, b):
    if b == 0:
        return (a, 1, 0)
    g, x1, y1 = egcd(b, a % b)
    return (g, y1, x1 - (a // b) * y1)

def inv_mod(a, m):
    a %= m
    if m == 1:
        return 0
    g, x, _ = egcd(a, m)
    if g != 1:
        return None
    return x % m

def factorize(n):
    f = []
    d = 2
    while d * d <= n:
        if n % d == 0:
            k = 0
            while n % d == 0:
                n //= d
                k += 1
            f.append((d, k))
        d += 1 if d == 2 else 2
    if n > 1:
        f.append((n, 1))
    return f

def divisors_from_factorization(fac):
    divs = [1]
    for p, k in fac:
        cur = []
        mul = 1
        for _ in range(k):
            mul *= p
            for v in divs:
                cur.append(v * mul)
        divs += cur
    return divs

def build_min_d_table(N):
    M = 2 * N
    fac = factorize(M)
    divs = divisors_from_factorization(fac)

    cache = [-1] * M

    def minimal_d_from_B(Bmod):
        best = None
        for m in divs:
            n = M // m
            g = gcd(m, n)
            if Bmod % g != 0:
                continue
            l = M // g 
            m1 = m // g
            n1 = n // g
            if n1 == 1:
                k = 0
            else:
                inv = inv_mod(m1, n1)
                if inv is None:
                    continue
                k = (inv * ((Bmod // g) % n1)) % n1
            d = (m * k) % l
            if d == 0:
                d = l
            if best is None or d < best:
                best = d
        return -1 if best is None else best

    dtab = [0] * M
    for r in range(M):
        Bmod = (2 * r + 1) % M
        if cache[Bmod] == -1:
            cache[Bmod] = minimal_d_from_B(Bmod)
        dtab[r] = cache[Bmod]
    return M, dtab

N, E = map(int, input().split())

M, dtab = build_min_d_table(N)

t = 0
pos = {}
order = [] 
dseq  = []  

while True:
    if E == 0:
        print(t)
        exit()

    r = E % M
    d = dtab[r]
    if d == -1 or d > E:
        t += E * (E + 1) // 2
        print(t)
        exit()
    
    if r not in pos:
        pos[r] = len(order)
        order.append(r)
        dseq.append(d)
    else:
        idx = pos[r]
        cyc_d = dseq[idx:] 
        L = len(cyc_d)

        pref = 0
        Emin = 0
        for di in cyc_d:
            Emin = max(Emin, di + pref)
            pref += di - 2
        deltaE = 2 * L - sum(cyc_d)

        if E >= Emin and deltaE >= 0:
            print("infinity")
            exit()

        if E >= Emin and deltaE < 0:
            C = sum(cyc_d)
            pref = 0
            D = 0
            for di in cyc_d:
                D -= di * pref + di * (di - 1) // 2
                pref += di - 2

            k = (E - Emin) // (-deltaE) + 1
            if k > 0:
                t += k * (C * E + D) + C * deltaE * (k * (k - 1) // 2)
                E += k * deltaE
                continue 

    t += d * E - d * (d - 1) // 2
    E = E - d + 2