class Dog:
    species = "Canine"  # 【类属性】所有狗都是犬科，共享这个值

    def __init__(self, name):
        self.name = name  # 【实例属性】每只狗名字不一样，独有

d1 = Dog("旺财")
d2 = Dog("来福")

print(d1.name, d2.name)      # 输出: 旺财 来福 (各自独立)
print(d1.species, d2.species)# 输出: Canine Canine (共享)

# 修改类属性，所有狗都会受影响（通常情况）
Dog.species = "Super-Canine"
print(d1.species, d2.species)# 输出: Super-Canine Super-Canine