# =================ALL COMPLETED BY AI=========================

class SuperVector:
    def __init__(self, data):
        """初始化：传入一个数字列表"""
        self.data = list(data)

    def __repr__(self):
        """便于打印显示的辅助函数"""
        return f"SuperVector({self.data})"

    # ==========================================
    # 1. 基础算术运算符
    # 这些方法通常返回一个新的对象，不改变原对象
    # ==========================================
    def __add__(self, other):
        # 实现 + 运算
        new_data = [x + other for x in self.data]
        return SuperVector(new_data)

    def __sub__(self, other):
        # 实现 - 运算
        new_data = [x - other for x in self.data]
        return SuperVector(new_data)

    def __mul__(self, other):
        # 实现 * 运算
        new_data = [x * other for x in self.data]
        return SuperVector(new_data)

    def __truediv__(self, other):
        # 实现 / 运算 (真除法)
        new_data = [x / other for x in self.data]
        return SuperVector(new_data)

    def __floordiv__(self, other):
        # 实现 // 运算 (整除)
        new_data = [x // other for x in self.data]
        return SuperVector(new_data)

    def __mod__(self, other):
        # 实现 % 运算 (取模)
        new_data = [x % other for x in self.data]
        return SuperVector(new_data)

    def __pow__(self, other):
        # 实现 ** 运算 (幂运算)
        new_data = [x ** other for x in self.data]
        return SuperVector(new_data)

    # ==========================================
    # 2. 比较运算符 
    # 逻辑：比较列表中所有数字的"总和"
    # ==========================================
    def _sum(self):
        return sum(self.data)

    def __lt__(self, other):
        # < 小于 little than
        return self._sum() < other._sum()

    def __gt__(self, other):
        # > 大于 greater than
        return self._sum() > other._sum()

    def __le__(self, other):
        # <= 小于等于 less than or equal to
        return self._sum() <= other._sum()

    def __ge__(self, other):
        # >= 大于等于 greater than or equal to
        return self._sum() >= other._sum()

    # ==========================================
    # 3. 增强赋值运算符 
    # 这些方法必须修改 self (原地修改)，并返回 self
    # ==========================================
    def __iadd__(self, other):
        # +=
        self.data = [x + other for x in self.data]
        return self

    def __isub__(self, other):
        # -=
        self.data = [x - other for x in self.data]
        return self

    def __imul__(self, other):
        # *=
        self.data = [x * other for x in self.data]
        return self

    def __itruediv__(self, other):
        # /=
        self.data = [x / other for x in self.data]
        return self

    def __ifloordiv__(self, other):
        # //=
        self.data = [x // other for x in self.data]
        return self

    def __imod__(self, other):
        # %=
        self.data = [x % other for x in self.data]
        return self

    # ==========================================
    # 4. 容器/列表操作 (对应图1 第三部分)
    # ==========================================
    def __getitem__(self, key):
        # [] 获取元素
        return self.data[key]

    def __setitem__(self, key, value):
        # []= 设置元素
        self.data[key] = value

    def __contains__(self, item):
        # in 判断是否存在
        return item in self.data


# ==========================================
# 测试代码：一次性用上所有函数
# ==========================================

print("--- 初始化 ---")
v1 = SuperVector([10, 20, 30])
v2 = SuperVector([2, 2, 2])
print(f"v1: {v1}")

print("\n--- 图2：基础算术运算 (返回新对象) ---")
print(f"加法 (+ 5): {v1 + 5}")          # 触发 __add__
print(f"减法 (- 5): {v1 - 5}")          # 触发 __sub__
print(f"乘法 (* 2): {v1 * 2}")          # 触发 __mul__
print(f"除法 (/ 4): {v1 / 4}")          # 触发 __truediv__
print(f"整除 (// 3): {v1 // 3}")        # 触发 __floordiv__
print(f"取模 (% 7): {v1 % 7}")          # 触发 __mod__
print(f"幂运算 (** 2): {v1 ** 2}")      # 触发 __pow__

print("\n--- 图1：容器操作 ---")
print(f"索引获取 ([0]): {v1[0]}")       # 触发 __getitem__
v1[0] = 999
print(f"索引修改 ([0]=999): {v1}")      # 触发 __setitem__
print(f"In判断 (999 in v1): {999 in v1}") # 触发 __contains__

# 重置 v1 用于后续测试
v1 = SuperVector([10, 20, 30])

print("\n--- 图1：增强赋值运算 (原地修改) ---")
v1 += 10
print(f"原地加 (+= 10): {v1}")          # 触发 __iadd__
v1 -= 5
print(f"原地减 (-= 5):  {v1}")          # 触发 __isub__
v1 *= 2
print(f"原地乘 (*= 2):  {v1}")          # 触发 __imul__
v1 /= 2
print(f"原地除 (/= 2):  {v1}")          # 触发 __itruediv__
v1 //= 3
print(f"原地整除 (//= 3): {v1}")        # 触发 __ifloordiv__
v1 %= 4
print(f"原地取模 (%= 4):  {v1}")        # 触发 __imod__

print("\n--- 图1：比较运算 (基于总和) ---")
# 目前 v1 是 [1.0, 3.0, 1.0], sum = 5.0
# v2 是 [2, 2, 2], sum = 6
print(f"v1 ({v1._sum()}) < v2 ({v2._sum()}):  {v1 < v2}")   # 触发 __lt__
print(f"v1 ({v1._sum()}) > v2 ({v2._sum()}):  {v1 > v2}")   # 触发 __gt__
print(f"v1 ({v1._sum()}) <= v2 ({v2._sum()}): {v1 <= v2}")  # 触发 __le__
print(f"v1 ({v1._sum()}) >= v2 ({v2._sum()}): {v1 >= v2}")  # 触发 __ge__