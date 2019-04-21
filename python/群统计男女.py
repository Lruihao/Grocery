#encoding=utf-8
from wxpy import *
import numpy
	
def removeAll(the_list, val):
	return [value for value in the_list if value != val]

def stats_text(target_group, group_name):
	print(group_name + "群共有：" + str(len(target_group)) + "人，其中：")
	all_stats_text = []
	all_dict = {}
	
	# 乱序先整理一份省份 + 地点的列表
	for user in target_group.members:
		trimed_data = user.province.replace(' ', '') + user.city.replace(' ', '')
		if trimed_data != '':
			all_stats_text.append(trimed_data)
	# 计数
	for data in all_stats_text:
		if all_stats_text.count(data) != 0:
			all_dict[data] = all_stats_text.count(data)
			all_stats_text = removeAll(all_stats_text, data)		
	final_dict = {}
	for i in sorted(all_dict.keys()):
		final_dict[i] = all_dict[i]
	return final_dict

def stats_sex(target_group):
	male = 0
	female = 0
	other = 0
	
	for user in target_group.members:
		if user.sex == 1:
			male = male + 1
		if user.sex == 2:
			female = female + 1
		else:
			other = other + 1
	
	print("男的有：" + str(male) + "人")
	print("女的有：" + str(female) + "人")
	msg = "男的有：" + str(male) + "人\n" + "女的有：" + str(female) + "人\n"
	return msg

bot = Bot()

target_group = bot.groups(update=True, contact_only=False)

for curr_group in target_group:
	# 小于 10 人的群过滤掉
	if len(curr_group) < 10:
		continue
	curr_group.update_group(members_details=True)
	print(curr_group.name + "一共有：" + str(len(curr_group)) + "人\n")
	msg = stats_sex(curr_group)
	curr_group.send(curr_group.name + "群，一共有：" + str(len(curr_group)) + "人\n" + msg)
