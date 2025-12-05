from struct import Struct

my_struct = Struct('i?f')
data = my_struct.pack(102, False, 8.90)

print('Packed Data: ',data)

hero = Struct('i?f')
unpacked_data = hero.unpack(data)
print('Unpacked Data: ', unpacked_data)