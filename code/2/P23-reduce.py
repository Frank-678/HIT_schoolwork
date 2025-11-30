from functools import reduce

# The reduce() function in Python, found within the functools module, is a tool for applying a function cumulatively to the items of an iterable, ultimately reducing the iterable to a single, aggregated value. It is based on the concept of "folding" or "reduction" in functional programming.
# [1, 2, 3, 4, 5]
#  \_/
#   3
#    \__/
#      6
#       \__/
#        10
#         \__/
#          15  <-- 最终结果
print("I have got 5 yuan. How many left if i get more?")
s = [1, 2, 3, 4, 5]
print(reduce(lambda x, y: x + y, s, 5))
sentence = ['i', 'am', 'Frank']
print(reduce(lambda x, y: x + ' ' + y, sentence, 'Hello!'))