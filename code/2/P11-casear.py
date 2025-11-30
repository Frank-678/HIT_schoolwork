casear_text = input("text: ")
result = ""  # 创建一个新的空容器

for letter in casear_text:
    if 'A' <= letter <= 'Z':  # 更 Pythonic 的判断范围写法
        # 1. 转为 0-25
        # 2. 移位 (+3)
        # 3. 取模 (%26)
        # 4. 加回基准 (+ord('A'))
        new_char = chr((ord(letter) - ord('A') + 3) % 26 + ord('A'))
        result += new_char
    elif 'a' <= letter <= 'z':
        new_char = chr((ord(letter) - ord('a') + 3) % 26 + ord('a'))
        result += new_char
    else:
        # 如果是标点或空格，直接加原字符
        result += letter

print(result)


# casear_text = input("text: ")
# for letter in casear_text:
#     if letter.isupper():
#         letter = chr((ord(letter) + 3 - ord('A')) % 26)
#     elif letter.islower():
#         letter = chr((ord(letter) + 3 - ord('a')) % 26)
# print(casear_text)

# 在 for letter in casear_text: 这行代码中：

# Python 从 casear_text 拿出第一个字符（比如 'A'）。

# Python 创建了一个临时变量 叫 letter，让它指向 'A'。

# 关键点来了： 当你执行 letter = chr(...) 时，你并没有修改 'A' 这个字符对象（因为它不可变），你也没有修改 casear_text 里的位置。

# 你实际上是做了一个**“重新贴标签”**的动作：你让 letter 这个标签撕下来，贴到了一个新的字符对象上。

# 原字符串 casear_text 毫发无损，它仍然由原来的字符组成。