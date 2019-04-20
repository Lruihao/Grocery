import itchat
import math
import PIL.Image as Image
import os
import shutil

# 变量
itchat.auto_login(hotReload=True,enableCmdQR=False)
roomslist = itchat.get_chatrooms(update=True)[0:]
itchat.dump_login_status() # 显示所有的群聊信息，默认是返回保存到通讯录中的群聊

for room in roomslist:
    print(room['UserName'])
    gsq=itchat.update_chatroom(room['UserName'], detailedMember=True)
    num = 0

    if not os.path.exists("./group-images/"):
        os.mkdir("./group-images/")

    for i in gsq['MemberList']:
        print(i["UserName"])
        img = itchat.get_head_img(userName=i["UserName"],chatroomUserName=room['UserName'])
        fileImage = open("./group-images/" + str(num) + ".jpg",'wb')
        fileImage.write(img)
        fileImage.close()
        num += 1

    ls = os.listdir('./group-images')
    each_size = int(math.sqrt(float(640*640)/len(ls)))
    lines = int(640/each_size)
    image = Image.new('RGB', (640, 640))
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
    image.save("all.jpg")
    itchat.send("写了个好玩的… 测试一下", room['UserName'])
    itchat.send_image("all.jpg", room['UserName'])
    shutil.rmtree("./group-images")