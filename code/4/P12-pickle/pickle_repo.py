import pickle

aString = 'google.com'

aDict = {'a':3, 4:'b '}

f = open('hello.pkl', 'wb')

pickle.dump(aString, f ,True)  #protocal

pickle.dump(aDict, f ,True) 

f.close()

import os
print("文件被保存在了这里：", os.getcwd()) #含义：Get Current Working Directory（获取当前工作目录）。作用：它告诉你 Python 终端/命令行目前停留在哪个文件夹里。


file = open('hello.pkl', 'rb')

a = pickle.load(file)
b = pickle.load(file)
print('\n\n', a, b)

try:
    c = pickle.load(file)
except EOFError:
    print("\nReached end of file.\n")

file.close()

'''
# Note: Pickle files are not human-readable. They are meant for Python object serialization.
'''