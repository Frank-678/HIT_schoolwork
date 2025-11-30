print(ord('s'))  #注意''
print(chr(0), chr(1)) #they’re control characters, so they print as blank or boxes.
print(repr(chr(0)), repr(chr(1)))  # shows '\x00' '\x01'
print(chr(48), chr(49))            # prints 0 1
print(hex(10348738297), oct(182934638))