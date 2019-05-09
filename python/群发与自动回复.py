import itchat
import time
from itchat.content import *



gname = '富强民主文明和谐自由平等公正法治'

context = '测试test...'


def SendChatRoomsMsg(gname, context):
    # 获取所有群的相关信息，update=True表示信息更新
    myroom = itchat.get_chatrooms(update=True)
    # myroom = itchat.get_chatrooms()
    # print(room1)
    global username

    # 搜索群名
    myroom = itchat.search_chatrooms(name=gname)
    # print(myroom.key())
    for room in myroom:
        # print(room)
        if room['NickName'] == gname:
            username = room['UserName']
            itchat.send_msg(context, username)
        else:
            print('No groups found')


# 监听是谁给我发消息
@itchat.msg_register([TEXT])
def text_reply(msg):
    # 打印获取到的信息
    # print(msg)
    itchat.send("您发送了：\'%s\'\n微信目前处于python托管!" %
                (msg['Text']), toUserName=msg['FromUserName'])


itchat.auto_login(hotReload=True,enableCmdQR=False)
SendChatRoomsMsg(gname, context)
itchat.run()