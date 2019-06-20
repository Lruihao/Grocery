import itchat
import math
import PIL.Image as Image
import os
import shutil

# 变量
itchat.auto_login(hotReload=True,enableCmdQR=False)
roomslist = itchat.get_chatrooms(update=True)[0:]
itchat.dump_login_status() # 显示所有的群聊信息，默认是返回保存到通讯录中的群聊
myroom=itchat.search_chatrooms(name=u'绥宁一中高396班') #群聊名称
gsq=itchat.update_chatroom(myroom[0]['UserName'], detailedMember=True)

num = 0

if not os.path.exists("./group-images/"):
    os.mkdir("./group-images/")

for i in gsq['MemberList']:
    print(i["UserName"])
    img = itchat.get_head_img(userName=i["UserName"],chatroomUserName=myroom[0]['UserName'])
    fileImage = open("./group-images/" + str(num) + ".jpg",'wb')
    fileImage.write(img)
    fileImage.close()
    num += 1

ls = os.listdir('./group-images')
each_size = int(math.sqrt(float(640*640)/len(ls)))
lines = int(640/each_size)
image = Image.new('RGBA', (640, 640))
x = 0
y = 0
for i in range(0,len(ls)+1):
    try:
        img = Image.open("./group-images/" + str(i) + ".jpg")
    except IOError:
        print("Error")
    else:
        img = img.resize((each_size, each_size), Image.ANTIALIAS)
        image.paste(img, (x * each_size, y * each_size))
        x += 1
        if x == lines:
            x = 0
            y += 1
image.save("all.png")
shutil.rmtree("./group-images")