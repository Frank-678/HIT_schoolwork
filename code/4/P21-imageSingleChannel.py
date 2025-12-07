from PIL import Image
import numpy as np

def main():
    filename = 'building.bmp'
    try:
        with Image.open(filename) as img:
            img_array = np.array(img)
            red_channel_img = keep_single_channel(img_array, 'R')
            green_channel_img = keep_single_channel(img_array, 'G')
            blue_channel_img = keep_single_channel(img_array, 'B')

            Image.fromarray(red_channel_img).save('building_red.bmp')
            Image.fromarray(green_channel_img).save('building_green.bmp')
            Image.fromarray(blue_channel_img).save('building_blue.bmp')
            print("搞定！三张单通道图片已生成。")
            
    except FileNotFoundError:
        print(f"找不到文件 {filename}，请检查文件名或路径。")

# Keep single channel of a RGB image
def keep_single_channel(img_array, channel):
    channel_indice = {'R':0, 'G':1, 'B':2}  #indice means index
    index = channel_indice[channel]
    single_channel_image = np.zeros_like(img_array)

    # 一个图片数组的形状是这样的：[ 高度(行), 宽度(列), 颜色通道(层) ]
    # ... 代表“前面的行和列我都要，我只关心最后一个维度”
    single_channel_image[..., index] = img_array[..., index]
    # 也是对的：single_channel_image[: , :, index] = img_array[:, :, index]
    
    return single_channel_image


main()