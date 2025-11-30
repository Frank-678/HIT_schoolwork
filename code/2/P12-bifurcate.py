def main():
    text = '我yes来harbin自哈institute尔滨of工业大学technology'
    zh = ""
    en = ""
    
    for t in text:
        # 这里的判断很简单：ord < 128 就是 ASCII (英文/数字/符号)
        if ord(t) < 128:
            en += t
        else:
            # 如果是汉字
            zh += t
            # 遇到汉字，说明前面的英文单词结束了，给英文串加个空格
            # 只有当英文串不为空，且最后一个不是空格时才加（防止连续汉字加多个空格）
            if en and en[-1] != ' ':
                en += ' '
                
    # strip() 去掉首尾多余空格
    print(zh)
    print(en.strip())

main()



# def main():
#     text = '我yes来harbin自哈institute尔滨of工业大学technology'
#     zh = ""
#     en = ""
#     for t in text:
#         if isCharacter(t):
#             zh += t
#         else:
#             en += t + ' '
#     print(zh, en, sep='\n')


# def isCharacter(letter):
#     if 0 <= ord(letter) <= 128:
#         return False
#     else:
#         return True

# main()