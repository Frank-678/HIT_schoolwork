ls = [1, 3, 5, 7, 9 ,0 ,2 ,3]

# The filter() function returns a filter object, which is an iterator. 
# This iterator yields only those elements from the iterable for which the function returned True. 
# To see the filtered elements as a list, you typically convert the filter object to a list using list(). 
lt_interator = filter(lambda x: x % 2 == 1, ls)
lt = list(lt_interator)

print(*lt)