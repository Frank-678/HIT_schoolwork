from PIL import Image
import numpy

def main():
    with Image.open("building.bmp") as img:
        pixels =get_matrix(img)
        pil1 = reverse(pixels)

        
        pil_img = Image.fromarray(pil1)
        pil_img.show()
        pil_img.save("building_reversed.bmp")


def get_matrix(image):
    return numpy.array(image, dtype=numpy.uint8)

def reverse(matrix):
    return 255 - matrix


main()

# fromarray
# It takes a NumPy array as input, which represents the pixel data of an image.
# It then converts this array into a PIL.Image.Image object, allowing you to utilize Pillow's extensive image processing capabilities.
