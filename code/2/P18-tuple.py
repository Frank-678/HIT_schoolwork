def a(x):
    b = 2
    c = x + 1
    return b,c

x = 3
s = a(3)  #元组
q, t = a(x)

print(s,type(t),q,type(q), t,type(t), sep="\n")