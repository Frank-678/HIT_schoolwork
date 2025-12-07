class Animal(object):
    def __init__(self, name, age):
        self.name = name
        self.years = age

    def __str__(self):
        return f'{self.name}, {self.age}'
    
    def get_age(self):
        return self.years
    
    @property  # Decorator， make it seems like having defined a property(calling do not use ())
    def age(self):
        return self.years
    
    @classmethod
    def fromstring(cls, age_str, name): #self is an instance, cls is this class
        age = int(age_str.split(' ')[2])
        return cls(age, name)
    
    @staticmethod  # @staticmethod 装饰的静态方法不能访问 self（实例）或 cls（类）(实际上与类什么关系也没有)
    def isValidAge(n):
        return 1 <= n <= 25

dog = Animal("Buddy", 5)
print(dog.get_age())        # Calls the method
print(dog.age)       # Accesses the property( no parentheses needed ， like an attribute)

print(dog.fromstring('age is 18', 'Amy'))

print(dog.isValidAge(dog.age))
print(dog.isValidAge(30))