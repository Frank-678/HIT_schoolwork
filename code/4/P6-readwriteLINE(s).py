def main(filename = 'demo.txt'):
    with open(filename, 'r+') as file:
        print('Before reading: ', file.tell())
        generator = obtain(file)
        count = 1
        for content_line in generator:
            print(f'Reading {count}: ', file.tell(), content_line)
            count += 1


def obtain(file):
    for line in file:
        yield file.readline()


main()