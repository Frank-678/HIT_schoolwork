s = "hello"
interactive_s = iter(s)
print(interactive_s.__iter__())
print(interactive_s.__next__())
print(interactive_s.__next__())

for char in interactive_s:
    print(char, end='')

print('\n\n')
print("Using for loop again:")
for char in interactive_s:
    print(char, end='')  # No output, as the iterator is exhausted

try:
    print(interactive_s.__next__())
except StopIteration:
    print("\nIterator is exhausted, no more elements to iterate.")
