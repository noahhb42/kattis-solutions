from fractions import Fraction

it = iter(open(0).read().split())
N = int(next(it)); D = int(next(it)); s = next(it)

p = Fraction(D, 8)
bits = s.split('.')[1]
x = Fraction(int(bits, 2), 1 << len(bits))

a = Fraction(0, 1); b = Fraction(1, 1)
ans = []
for _ in range(N):
    c = a + p * (b - a)
    if x < c:
        ans.append('A'); b = c
    else:
        ans.append('B'); a = c

print(''.join(ans))