import math

it = iter(map(int, open(0).read().split()))
k = next(it)
p = [(next(it), next(it)) for _ in range(k)]

s = [0.0]*k
for i in range(k):
    xi, yi = p[i]
    for j in range(i+1, k):
        xj, yj = p[j]
        d = math.hypot(xi - xj, yi - yj)
        s[i] += d; s[j] += d

ans = min(v/(k-1) for v in s)
print(f"{ans:.10f}")