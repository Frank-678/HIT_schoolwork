# 集合（Set）和字典（Dict）之所以必须用不可变类型、无序，完全是为了换取一个超能力：极速查找。(哈希表（Hash Table）)
# 只要你用不可变类型做集合的元素或字典的键，Python 就能通过哈希算法（Hashing）在 O(1) 时间复杂度内完成查找。
# 可变类型由于内容可变，哈希值也会随之改变，无法保证查找的准确性，因此不能作为集合的元素或字典的键。
# 如果你尝试使用可变类型作为集合的元素或字典的键，Python 会抛出 TypeError 异常。

set1 = {1, 2, 3} 
set2 = {1, 2, 3, 3.0, 'hello'}
set3 = {'a', 'b', 'c', 'hello'}
set4 = {(1, 2), (3, 4)}

# 输出的顺序每次都变!
print(set1 & set2)  # 输出: {1, 2, 3}
print(set3 | set4)  # 输出: {'c', (1, 2), (3, 4), 'hello', 'b', 'a'}
print(set2 - set1)  # 输出: {'hello'}
print(set4 ^ set1)  # 输出: {1, 2, (1, 2), 3, (3, 4)} XOR (异或)。只属于 A 或者只属于 B 的元素。

set = {1, 2, 3}
set.add(4)
set.discard(2)
set.discard(5)

n = int(input())
try:
    set.remove(n)
    print(set)
except KeyError:
    print(f'no {n}! and how many? {len(set)}, {n in set}')
