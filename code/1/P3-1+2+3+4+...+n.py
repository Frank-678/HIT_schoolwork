#1+2+3+4+……n求和

'''
@author Zhu Jun
@date 18/11/2025
'''

n = int(input("n = "))

assert isinstance(n, int)

if n > 0:
    s = 0  #变量名不可以为sum
    for i in range(n):
        s += i + 1
    print(s)
else:
    pass  #注：pass表示什么都不做，所以还会继续读取代码
    print(n <= 0)
    raise ValueError

