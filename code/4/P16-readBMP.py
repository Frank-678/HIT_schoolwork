import struct
import os

# 1. 修复路径：使用正斜杠或 raw string
path = 'RelatedFiles/37FAAD350AB69723B131BFE4589F6043.bmp'

with open(path, 'rb') as f:
    # 2. 读取头部：BMP 头部标准长度是 54 字节
    bmp_header = f.read(54)
    
    # 3. 检查是否真的是 BMP
    # 头部的前2个字节必须是 b'BM'
    if bmp_header[:2] != b'BM':
        print("这不是一个标准的 BMP 文件！")
    else:
        # 4. 使用 struct 解析关键信息
        # '<' : 小端模式 (Little Endian, Windows标准)
        # 'I' : Unsigned Int (4字节) - 用于文件大小、偏移量等
        # 'i' : Signed Int (4字节) - 用于宽度、高度
        # 'H' : Unsigned Short (2字节) - 用于色深
        
        # 跳过前 2 个字节 'BM'，从第 2 字节开始解包
        # 格式字符串解释:
        # 'I' (文件大小 4B)
        # 'H' (保留 2B)
        # 'H' (保留 2B)
        # 'I' (像素数据偏移量 4B) - 很重要，告诉我们像素从哪里开始
        # 'I' (Header 剩余大小 4B)
        # 'i' (宽度 4B)
        # 'i' (高度 4B)
        # 'H' (平面数 2B)
        # 'H' (色深 2B, 比如 24位 或 32位)
        
        data = struct.unpack('<IIIIiiHH', bmp_header[2:30])
        
        file_size = data[0]
        pixel_offset = data[3] # 像素数据真正开始的位置
        width = data[5]
        height = data[6]
        bits_per_pixel = data[7]

        print(f"宽: {width} 像素")
        print(f"高: {height} 像素")
        print(f"色深: {bits_per_pixel} 位")
        
        # 5. 读取像素数据
        # 把指针移动到像素数据开始的地方
        f.seek(pixel_offset) 
        pixels = f.read() # 读剩下的所有内容
        print(f"读取了 {len(pixels)} 字节的像素数据")
        print(f"文件总大小: {file_size} 字节")