from decimal import Decimal
from fractions import Fraction

a = Decimal(19700.293094)
b = Fraction(9/17)
c = Fraction(9,17) 

print(a, b, c, sep = '\n')

print(type(a),type(b), type(c))

f = 3 - 2j
g = 2.0e-3
h = 2 ** 3
i = 100 // 7

print(type(f), type(g),'\n', h, i)