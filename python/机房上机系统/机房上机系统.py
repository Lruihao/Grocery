import time

class student():
	def __init__(self,stu_no="",stu_name="",stu_xi="",stu_time=""):
		self.stu_no = stu_no
		self.stu_name = stu_name
		self.stu_xi = stu_xi
		self.stu_time = stu_time

	def print(self):
		print("学号："+self.stu_no+"\t姓名："+self.stu_name+"\t系别："+self.stu_xi+"\t机时(h)："+self.stu_time)

	def get_stu_name(self):
		return self.stu_name

	def get_stu_time(self):
		return int(self.stu_time)

	def set_stu_time(self,add_time):
		self.stu_time = add_time

def menu():
	print("\t机房上机系统V0.1")
	print("********************************")
	print("\t—>1.录入学生信息")
	print("\t—>2.上机")
	print("\t—>3.下机")
	print("\t—>4.缴费")
	print("\t—>5.退出")
	print("********************************")
	select = eval(input("请输入序号："))
	while select not in [1,2,3,4,5]:
		print("输入错误，请重新输入！")
		select = eval(input("请输入序号："))
	return select

def get_time(): #获取当前时间
	return time.strftime("%H:%M:%S", time.localtime()) 

def main():
	# 全局变量
	text = [] # 上机记录列表
	start_time = ""
	end_time = ""
	sum = 0 # 本系统按小时计费，不足一小时按一小时算
	people = student()
	online_flag = False
	down_flag = False
	input_flag = False

	while True:
		select = menu() # 启用菜单

		if select == 1:
			if input_flag:
				print("已录入，无需重复操作，缴费请输入4:")
				continue
			else:
				input_flag = True
				stu_no = input("请输入学号：")
				stu_name = input("请输入姓名：")
				stu_xi = input("请输入系别：")
				stu_time = input("请输入机时：")
				people = student(stu_no,stu_name,stu_xi,stu_time)
				people.print()
				continue

		elif select == 2:
			if not input_flag:
				print("未录入学生信息，请录入！")
				continue
			if not online_flag:
				online_flag = True
				start_time = get_time()
				start_num = int(start_time[0:2])
				#print(start_num)

				text.append("上机时间："+start_time)
				print("已上机！上机时间为："+start_time)
				continue
			else:
				print("已上机！上机时间为："+start_time)
				continue
			
		elif select == 3:
			if not online_flag:
				print("还未上机，请上机！")
				continue
			else:
				end_time = get_time()
				end_num = int(end_time[0:2])
				sum = end_num - start_num
				sum = sum if(sum>=0) else sum+24
				sum = sum+1 if(sum==0) else sum
				print("已下机！下机时间为："+end_time+"\n上机时长(h)："+str(sum)+"\t剩余机时(h)："+str(people.get_stu_time()-sum))
				text.append("下机时间："+end_time+"\n上机时长(h)："+str(sum)+"\t"+people.get_stu_name()+"剩余机时(h)："+str(people.get_stu_time()-sum))
				down_flag = True
				continue

		elif select == 4:
			pass
		else:
			if down_flag:
				print("3s后退出系统，感谢使用！")
				time.sleep(3) # 延迟3s，显示提示文字
				break # 退出系统 写入文件
			else:
				print("请下机！")
				continue


	#写入computer.txt文件
	fo = open("D:\\computer.txt","w",encoding="utf-8")
	fo.write("\n".join(text)) 
	fo.close()
	
if __name__=="__main__":
	main()
