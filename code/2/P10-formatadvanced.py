formatted_str = "{1:!^9} to {2:#>10,.6f} but not to {0:)<6}.".format("world", "hello", 10092830)  # 填充符必须是单个字符
print(formatted_str)
