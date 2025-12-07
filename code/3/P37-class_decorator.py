# AI helps a lot 

def LogDecorator(message):
    def class_wrapper(cls):
        # We save the original __str__ method of the class
        original_str = cls.__str__

        # We create a new __str__ that adds the message
        def new_str(self):
            return message + original_str(self)

        # We replace the class's method with our new one
        cls.__str__ = new_str
        
        # Return the modified class
        return cls
    return class_wrapper


@LogDecorator(message="警察: ") #The Syntax: @LogDecorator(...) executes a function that takes the person class as input.
class person:
    def __init__(self, ide, name):
        self.ide = ide
        self.name = name
        
    def __str__(self):
        # Note: ide and name are just returned, not the prefix
        return f'身份证: {self.ide}\n姓名: {self.name}'

# --- The Result ---
p = person("12345", "John Doe")
print(p)