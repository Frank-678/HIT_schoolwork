class Animal(object):
    def __init__(self, name, age):
        self.name = name
        self.years = age

    def __str__(self): # Without this method, printing the object would show its memory address
        return f"Hello, I am {self.name}, {self.years}"
    
    def get_age(self):
        return self.years
    
    def set_color(self, color):
        self.color = color

    def get_color(self):
        try:
            return self.color
        except AttributeError:
            return "Color not set"
        
    def __del__(self):  # When any instance goes out of scope or its reference count(现在有多少个变量正在使用这个对象) drops to zero, the garbage collector will eventually call __del__.
        print(f"Animal {self.name} is being deleted.")
        
def main():
    dog = Animal("Buddy", 5)
    print(dog)
    print(dog.__str__())
    print(dog.get_color()) # Best to use the getter method to access color, while using the setter method to set color
    # Do not use dog.color directly to set color, as it may be not stet the literally exact "color" attribute for color



    list1 = [12, 14, 9]
    list2 = ['Amy', 'Ant', 'Cobt']

    newList = [Animal(a, b) for a, b in zip(list2, list1)] # The zip() function returns a zip object, which is an iterator. This iterator yields tuples. Each tuple contains the i-th element from each of the input iterables.
    # 注意，newList = [Animal(a, b) for a in list2 for b in list1]这么写是全排列写法。两者截然不同。

    print(newList[0].name, newList[1].years)

main()
print('is it deleted yet?')