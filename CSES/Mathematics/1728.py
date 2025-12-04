from decimal import *
import decimal
import math
n = int(input())
    
decimal.getcontext().prec = 100

ans = Decimal(0)
r = [int(x) for x in input().split()]

batch = [0] * 201
 
for i in range(n - 1):
    curr = Decimal(0)
    a = r[i]
    for j in range(i + 1, n):
        b = r[j]
        tot = Decimal(0)
        if a <= b:
            batch[b] += a - 1
        else: 
            batch[a] += -b - 1
            ans += 2

        ans += tot
    
    # ans += curr

for i in range(1, 201):
    if batch[i]:
        ans += Decimal(batch[i]) / Decimal(i)

ans /= Decimal(2)

# print(ans)
print("{0:0.6f}".format(round(Decimal(ans * Decimal(1e6)))/Decimal(1e6)))