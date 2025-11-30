print("42".zfill(5))      # 00042
print("-7".zfill(4))      # -007  # 负号保留，零填在后面
print("+9".zfill(3))      # +09   # 正号同理
print("abc".zfill(2))     # abc   # 原本就比 2 长，不截断
