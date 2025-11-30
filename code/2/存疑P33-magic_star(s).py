# one star: Unpacking Iterables: It unpacks elements from an iterable (like a list or tuple) into individual arguments or variables.
tuple = (1, 2, 3)
list = [1, 2, 3]
str = "hello"
dict = {'a': 1, 'b': 2, 'c': 3}
print(*tuple)
print(*list)
print(*str)
print(*dict)  # Unpacking keys of the dictionary

#
# two stars: Unpacking Dictionaries: It unpacks key-value pairs from a dictionary into individual keyword arguments.
dict = {'a': 1, 'b': 2, 'c': 3}
print("a={a}, b={b}, c={c}".format(**dict))  # 使用 format 演示解包，因为 print(**dict) 会报错

# *:任意位置参数（ *args ）：在函数定义中， *args 允许函数接受任意数量的位置参数，这些参数随后被收集成元组。
def func(*args):
    print("Arguments received:", args)
    for arg in args:
        print(arg)
    return sum(args)
print(func(1, 2, 3, 4, 5))

# **：任意关键词参数**kwargs:** 同样， **kwargs 函数允许接受任意数量的关键词参数，这些参数被收集到词典中。
def func2(**kwargs):
    print("Keyword arguments received:", kwargs)
    for key, value in kwargs.items():
        print(f"{key}: {value}")
    return sum(kwargs.values())
print(func2(a=1, b=2, c=3))
print(func2(**dict))  # 补充：这里展示了将字典解包后直接传给 **kwargs 函数