from collections.abc import Callable
from time import sleep, time

def hello():
    sleep(1)
    print('hello!')
    sleep(1)
    return 200, '{}'.format('hello')

print(type(hello))

def func(func1: Callable[[], tuple[int, str]]) -> None: # ✅ 修正这里：用空列表 [] 代表没有参数
    number, word = func1()
    sleep(2)
    print('func received:', number, word)

time_start = time()
func(hello)
sleep(1)
time_end = time()
print('Elapsed time:', time_end - time_start)