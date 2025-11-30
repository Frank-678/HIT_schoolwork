#方法一：圆括号 (迭代规则)：是生成器。Python 什么都不算，它只保存了一个“生成规则”。
gen = (x for x in range(2, 10, 2)) ####注意注意，这是圆括号（），不是方括号（[]），所以这是一个生成器表达式，而不是列表表达式
print(gen)  # 输出：<generator object <genexpr> at 0x...
for value in gen:
    print(value)

#是规则！这类似于
def func(a, b):
    return a + 3 * b
print(func) # 输出：<function func at 0x...
    
# 方法二：yield 是一个与 return 类似使用的关键词，但该函数会返回一个生成器。
def create_generator():
    numbers = range(3)  # it returns a range object, which is a type of iterator.
    print(numbers)  # 输出：range(0, 3)
    for number in numbers:
        print("About to yield:", number * 2)
        yield number * 2 # 能够多次迭代多次返回 number * 2
        print("Yielded:", number * 2)
generator = create_generator()

try:
    while True:
        value = next(generator)
        print(value)
except StopIteration:
    print("Generator has been exhausted.")
