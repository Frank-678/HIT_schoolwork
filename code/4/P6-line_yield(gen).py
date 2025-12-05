def main(filename = 'demo.txt'):
    with open(filename, 'r+') as file:
        generator = obtain(file)
        count = 1
        for content_line in generator:
            print(f'Reading {count}: ', content_line)
            count += 1


def obtain(file):
    print('Before reading: ', file.tell())
    for line in file:
        yield line
    


main()