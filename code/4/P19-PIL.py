from PIL import Image
import numpy as np

with Image.open("opp.png") as img:
    if img.mode != "RGB":
        img = img.convert('RGB')

    width, height = img.size
    channels = len(img.mode)

    print(width, height, channels)

    pixels = np.array(img)
    print(pixels.shape)
    print(pixels)