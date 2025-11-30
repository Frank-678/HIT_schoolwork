#汉诺塔，移动n个，就是先把n-1个移动到B上。再第n个移动C上，最后把n-1移动到C上
#即f(n) = 2 * f(n-1) + f(1)


def main():
    n = int(input())

    step = f(n)

    print(step)


def f(n):
    if n == 1:
        return 1
    elif n > 1:
        return 2 * f(n - 1) + 1


main()
