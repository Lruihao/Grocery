import os
import requests

path="C:\\Users\\李瑞豪\\Desktop\\MMT_images\\" #下载路径： 绝对或者相对路径比如./image/
os.makedirs(path+"0\\", exist_ok=True) # 创建文件夹
os.makedirs(path+"1\\", exist_ok=True)

# 下载图片
def urllib_download(url,num):  # (下载链接,图片编号)
    from urllib.request import urlretrieve
    urlretrieve(url,path+num+".png")     

# 判断状态码
def get_status(url):  
    r = requests.get(url, allow_redirects = False)  
    return r.status_code

def main():
	BASE_URL = "https://image.xiezixiansheng.com/users/2010/700/unzip/579767/"
	n=33
	total=0
	print("正在爬取第1张图片!")

	while n < 65510:
		#分段爬取，不然会超时！！！# 33 ~ 126 # 8212 ~ 8243 # 12289 ~ 12305 # 19968 ~ 40864 # 65281 ~ 65509
		if n == 127:
			n = 8212
			continue
		elif n == 8244:
			n = 12289
			continue
		elif n ==12306:
			n = 19968
			continue
		elif n == 40865:
			n = 65281
			continue

	# for n in range(37341,40865):
		num = str(n)
		IMAGE_URL = BASE_URL+num+".png" # xxx.png是透明背景，xxx.png@50q是白色背景，分别存放在0，1文件夹 p是中小 w是小图
		if(get_status(IMAGE_URL)==200): # 同时下载透明和白色背景的图片
			total+=1
			urllib_download(IMAGE_URL,"0\\"+num)
			IMAGE_URL += "@50q"
			urllib_download(IMAGE_URL,"1\\"+num)
			print("Downloaded "+num+".png")
			print("正在爬取第",total+1,"张图片!")
		n+=1

	print("\n爬取完毕！共爬取",total,"张图片!")		
	print("图片存放路径："+path)
	print("作者博客：lruihao.cn")

if __name__=="__main__":  
    main(); 
