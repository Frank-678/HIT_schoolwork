ls1 = [1, 2, 3, [7, 'hello'], ('hum', 3), {'2':4,'ij':'pol9'}]

print(ls1)

# ls = ls.reverse() * 3  reverse不返回list，这是一个操作，返回的是none
ls1.reverse()
ls = ls1 * 3
ls = ls[::-1]*3  #[start : end : step]

print(ls)

ls1.insert(1,'x')
print(ls1[:])

o = ls1.pop(0)
print(o)
print(ls1)

lt = [2,3,4]
ls1.extend(lt)
print(ls1)

print([i if isinstance(i, int) or (isinstance(i, str) and i.isdigit()) else 'NOT' for i in ls1])