# 导入模块
from wxpy import *
# 初始化机器人，扫码登陆
bot = Bot()

my_friend = bot.friends().search('lrh')[0]
my_friend.send('Hello WeChat!')