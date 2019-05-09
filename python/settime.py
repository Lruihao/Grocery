import time
while True:
    now_hour = time.strftime("%H", time.localtime())
    now_min = time.strftime("%M", time.localtime())
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
        print("启动时北京时间为：" + time.strftime("%H:%M", time.localtime()), "\t软件将在每天8点发送数据！")
        # 以下为定时任务
        print("数据")
        time.sleep(86400-int(now_min)*60)