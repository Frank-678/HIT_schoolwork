# 有() 代表正在定义（Define）或调用（Execution），没有 () 代表引用（Reference）。
# func_lib 是一个工厂。它的工作不是做加法，而是生产一个能做加法的函数。
# add 才是那个真正干活、做加法的工人。
def func_lib():
    def add(x, y):      # 这是内部定义的函数（产品）
        return x + y
    return add          # 注意！这里返回的是 add 的“引用”（没有括号）

print(func_lib()(1, 7))