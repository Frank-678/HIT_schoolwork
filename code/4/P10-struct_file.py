from os import getcwd
from struct import *

path = getcwd() + '/RelatedFiles/37FAAD350AB69723B131BFE4589F6043.bmp'

with open(path, 'rb') as f:
    data = unpack('i', f.read(4))   # unpack (解包): 把二进制字节流（你刚从文件读出来的 content）还原成 Python 变量。
    print(data)