#!/usr/bin/python
import requests
import json
import time
from wxpy import *

# 基本信息填写：
# 酒店id，酒店名称及群名列表数据，格式：["xxx","xxx","xxx"]
# 使用时请将以下三个列表一一对应
hotel=["xxxx","xxxx"] # 酒店后台数据接口二级域名，已匿名
hotel_name=["增城宾馆","百丽酒店"]
grouplist = ["麻小","富强民主文明和谐自由平等公正法治"] # "东营百丽-麻小合作群"

# post请求发送的数据
postData = {
    # 'username':'test',
    # 'password':'123456',
}

def get_data():
	result = [] #结果列表
	i = 0 #计数器
	for each in hotel:
		url="http://"+each+".maxiaokeji.com/xxx/xxxxxxx/xxx" # 为保护隐私及权益，这里不提供接口
		r = requests.post(url,data=postData)
		# print(r.text)

		# 把结果转化为json字符串
		response=json.dumps(r.json(),indent=4,ensure_ascii=False) #sort_keys=True 

		# 把json转换为dict字典作为中间结果，再取出昨日数据
		midresult=json.loads(response)
		result.append("早上好！"+hotel_name[i]+"小程序昨日数据如下：\n访问数："+str(midresult["data"]["yesterday_data"]["type1"])+"\n房间数："+str(midresult["data"]["yesterday_data"]["type2"])+"\n需求量："+str(midresult["data"]["yesterday_data"]["type3"])+"\n商品点击量："+str(midresult["data"]["yesterday_data"]["type4"]))
		i+=1
	# print(result)
	return result

def wechat_send(bot,result):
	# my_friend = bot.friends().search('lrh')[0]
	# my_friend.send(result)
	i = 0 # 计数器
	for group in grouplist:
		my_group = bot.groups().search(group)[0] #依次搜索每一个群名称，每次一个
		my_group.send(result[i])	
		print(result[i])
		print("已发送至群："+group)
		i+=1

def main(bot):
	# 设置最大休眠时间，防止程序长时间占用系统资源
	while True:
		now_hour = time.strftime("%H", time.localtime())
		now_min = time.strftime("%M", time.localtime())
		# 设置每天8点发送
		if now_hour < "08":
			rest = 8 - int(now_hour)
			sleeptime = (rest-1)*3600 + (60-int(now_min))*60
			print("启动时北京时间为："+time.strftime("%H:%M", time.localtime()),"\t软件将在",rest-1,"小时",int((sleeptime-(rest-1)*3600)/60),"分钟后发送数据")
			time.sleep(sleeptime)
		elif now_hour > "08":
			rest = 8 - int(now_hour) + 24
			sleeptime = (rest-1)*3600 + (60-int(now_min))*60
			print("启动时北京时间为："+time.strftime("%H:%M", time.localtime()),"\t软件将在",rest-1,"小时",int((sleeptime-(rest-1)*3600)/60),"分钟后发送数据")
			time.sleep(sleeptime)
		elif now_hour == "08":
			print("软件明天开始将在每天8点发送数据！")
			result=get_data() # 获取数据
			wechat_send(bot,result) # 发送数据
			time.sleep(86400-int(now_min)*60)

if __name__=="__main__":
	bot = Bot(cache_path=True) # 初始化机器人，扫码登陆 
	main(bot); 
