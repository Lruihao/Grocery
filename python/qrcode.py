from MyQR import myqr
import os
version, level, qr_name = myqr.run(
    words='https://lruihao.cn',
    version=1,
    level='H',
    picture='2.jpg',
    colorized=True,
    contrast=1.0,
    brightness=1.0,
    save_name=None,
    save_dir=os.getcwd()
)

# help(myqr)
# https://github.com/sylnsfar/qrcode/
'''
Positional parameter
   words: str # 链接或者文字

Optional parameters
   version: int, from 1 to 40  # 控制边长
   level: str, just one of ('L','M','Q','H') # 控制纠错水平，从左到右依次升高。
   picutre: str, a filename of a image # 图片，需在同路径,默认None
   colorized: bool  # 是否彩色 默认False
   constrast: float # 对比度 默认1.0
   brightness: float # 亮度 默认1.0
   save_name: str, the output filename like 'example.png' #控制文件名，默认None,'qrcode.png'
   save_dir: str, the output directory # 储存路径
'''