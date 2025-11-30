name, gender, hobby = map(str.strip, input("Write with comma: ").split(",", 2))
print("This is {1}, a {0} who loves {2}".format(gender, name, hobby))


name2, score, h, m = ["Tom", 95.456, 7, 5]
print("名字: {}, 分数: {:.1f}".format(name2, score))
print("时间: {:02d}:{:02d}".format(h, m))
print("对齐: '{:>6}' '{:<6}' '{:^6}'".format("hi", "hi", "hi"))
