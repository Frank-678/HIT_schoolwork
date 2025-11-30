import sys

try:
    scores = []
    while True:
        score = int(input())
        scores.append(score)
except ValueError:
    print("This means end.\n\n--Sorting--\n")

scores.sort(key = lambda x: x, reverse = False)
print(', '.join(map(str, scores))) # 更pythonic的写法是print(*scores, sep=', ')


# str(list) 的行为非常简单粗暴：它会把列表的**“外貌”**原封不动地拍一张照片，变成一个字符串。
# 这就意味着，方括号 []、逗号 ,、空格 甚至引号 ' 都会成为这个新字符串的一部分。
# 1. 拆解 str([7, 'hello'])
# 当你运行 str([7, 'hello']) 时，Python 实际上生成了这样一个字符串：
# s = "[7, 'hello']"

# B. 使用 join() —— “无缝拼接”
# 这才是通常用来把列表转成纯文本的方法（前提是列表里全是字符串）。
# ls = ['1', '2'] # 注意：join只能处理字符串列表
# s = "".join(ls)
# print(s)      # 输出: '12'
# print(s.isdigit()) # ✅ True