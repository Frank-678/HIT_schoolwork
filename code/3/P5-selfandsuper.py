class Grandparent(object):
    def __init__(himself, a):  # himself 这种怪名字完全合法
        himself.a = a

    def greet(ooo):            # ooo 这种怪名字也完全合法
        return f'{ooo.a} says hello!'

class Parent(Grandparent):
    def __init__(s, b):        # s 这种怪名字也合法
        super(Parent, s).__init__(b)

# --- 执行部分 ---

# 1. 正常调用
A = Grandparent('this').greet()
print(f"A: {A}")  # 输出: this says hello!

obj = Parent('that') 
s_result = obj.greet() 
print(f"s_result: {s_result}") # 输出: that says hello!

# 2. 测试 super 逻辑
# 告诉它：从 Parent 类开始往后找，绑定到 obj 实例上
# MRO: [Parent, Grandparent, object]
# 跳过 Parent -> 也就是找 Grandparent 的 greet
super_Parent = super(Parent, obj) 

print(super_Parent.greet()) 
# 输出: that says hello!