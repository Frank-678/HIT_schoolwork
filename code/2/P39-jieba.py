from jieba import lcut

text = "我爱北京天安门"
words = lcut(text)
print(words)
print(*words)