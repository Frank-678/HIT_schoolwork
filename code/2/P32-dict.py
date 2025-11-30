dict1 = {1: 'one', 2: 'two', 3: 'three'}
dict2 = dict([(1, 'one'), (2, 'two'), (3, 'three')]) # 利用 dict() 函数

dict3 = dict(zip([1, 2, 3], ['one', 'two', 'three'])) 
# 利用 zip 函数把两个独立的列表缝合在一起。zip 就像衣服上的拉链，把左边的第1个和右边的第1个配对，第2个配第2个……最后 dict() 把配对好的结果变成字典。
# The zip() function in Python is a built-in function that takes one or more iterable objects (like lists, tuples, or strings) as arguments and returns an iterator of tuples. Each tuple contains the corresponding elements from the input iterables.
# If the input iterables have different lengths, zip() stops when the shortest iterable is exhausted. Elements from longer iterables beyond this point are not included in the resulting output.

dict4 = dict.fromkeys([1, 2, 3], 'three') # 批量初始化 (The Batch Maker) 快速创建一个字典，让所有的键都指向同一个值。

print(dict1)  # {1: 'one', 2: 'two', 3: 'three'}
print(dict2)  # {1: 'one', 2: 'two', 3: 'three'}
print(dict3.items())  # dict_items([(1, 'one'), (2, 'two'), (3, 'three')])

print(dict1.keys())  # dict_keys([1, 2, 3])
print(dict4.values())  # dict_values(['three', 'three', 'three'])

dict5 = {x: n for x in dict3.values() for n in dict4.keys()}
dict6 = {y: m for (y, m) in dict1.items()}

print(dict5, dict6)

print(dict(dict.fromkeys([key for key in dict1.keys()], [item for item in dict2.items()])))