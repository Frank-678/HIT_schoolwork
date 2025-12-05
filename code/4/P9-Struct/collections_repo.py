from collections import namedtuple
from struct import Struct

Person = namedtuple('Person', 'name, age, hobby, isStupid')

him = Person(
    bytes('Frank', encoding = 'UTF-8'),
    18,
    bytes('高尔夫球', encoding = 'UTF-8'),  # 为了与C语言交互
    False
)

print(him)

his_struct = Struct(f'{len(him.name)}si{len(him.hobby)}s?')  # len+s => 字符串
data = his_struct.pack(*him)
print(his_struct, data)


#
unpacked_data = his_struct.unpack(data)
person = Person._make(unpacked_data)
print()
print(str(person.name, encoding = 'UTF-8'), person.age)
