def main():
    total = 0
    a, b = 1, 0
    generator = fibonacci(a, b)
    for i in generator:
        print(i)
        total += i
    print('Total: {}'.format(total))
    

def fibonacci(a, b):
    for i in range(100):
        a, b = b, a + b
        yield b


main()