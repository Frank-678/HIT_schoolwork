# 判断n位数是否是回文数
num = int(input('number: '))

# 计算位数
n = 0
while (num >= 1.0 * (10 ** n)):  
    n += 1

s = 0
for i in range(n):
    s += int(((num // (10 ** (n - 1 - i))) % 10) * (10 ** i))

if s == num:  # 算法可行：两个数字相等，当且仅当两个数字的每一位都相等。
    print('is a palindrome')
else:
    print('NOT a palindrome')