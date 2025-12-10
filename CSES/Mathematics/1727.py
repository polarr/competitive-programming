from decimal import *
import decimal
import math
    
decimal.getcontext().prec = 100

n, k = map(int, input().split())

ans = k ** (n + 1)
for t in range(1, k):
    ans -= t ** n

ans = Decimal(ans) / Decimal(k ** n)
print("{0:0.6f}".format(round(Decimal(ans * Decimal(1e6)))/Decimal(1e6)))