filename = 'RelatedFiles/后来的我们.lrc'

file = open(filename, 'r+', encoding = 'utf-8', buffering = -1, errors = 'replace', newline='\r\n')
content = file.read()
print(content)

file.close()


