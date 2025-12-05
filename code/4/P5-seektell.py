filename = 'hello.txt'

# 为了演示，先创建一个初始文件
with open(filename, 'w') as f:
    f.write('Hello World!')

try:
    with open(filename, 'r+') as file:
        # 1. 刚打开文件
        print(f"[1] 刚打开时 (ftell): {file.tell()}") 
        
        # 2. 读取全部内容
        content = file.read()
        print(f"    读取到的内容: {content}")
        print(f"[2] read() 之后 (ftell): {file.tell()}") 
        
        # 3. 移动指针回到开头
        file.seek(0)
        print(f"[3] seek(0) 之后 (ftell): {file.tell()}") 
        
        # 4. 写入新数据(覆盖)
        write_str = 'Hi!\n'
        file.write(write_str) 
        print(f"    写入了: {repr(write_str)} (长度: {len(write_str)})")
        
        # 5. 写入之后的指针位置
        print(f"[4] 写入之后 (ftell): {file.tell()}")

        # 看看最终结果
        file.seek(0)
        print(f"\n最终文件内容: {file.read()}")

except Exception as e:
    print(f"发生错误: {e}")