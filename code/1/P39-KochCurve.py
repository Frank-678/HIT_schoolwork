# 每一个n阶图形都是4个1/3size的n-1阶图形组合
from turtle import *


def main():
    n = int(input('Rank: '))
    l = int(input('Linear Length(底线): （经尝试，输入300,1000等可行）'))  
    pensize(2)
    pencolor('Green')
    speed(0)
    penup()
    goto(-l/2,-l/9)
    pendown()
    draw(n, l)


def draw(n, size):
    if n == 0:
        forward(size)
    elif n > 0:
        for theta in [60, -120, 60, 0]:    
            draw(n - 1, size / 3)
            left(theta)


main()

done()