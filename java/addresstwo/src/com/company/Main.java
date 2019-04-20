package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // write your code here
        ContactList addressList = new ContactList();
        Scanner reader = new Scanner(System.in);
        String input = null;

        while (true) {
            init();
            if (reader.hasNextLine())
                input = reader.nextLine();
            if (input.equals("L")) {
                System.out.println("通讯录中的所有联系人信息如下：");
                System.out.println(addressList.toString());

            } else if (input.equals("A")) {
                System.out.println("请输入一个联系人的信息，输入格式为姓名，地址，电话，每句之间用英文逗号隔开：");
                if (reader.hasNextLine()) {
                    input = reader.nextLine();
                }

                String[] additem = input.split(",");//以逗号为分隔符，把输入的字符串分为若干个字符串存放在字符串数组additem[]中
                if (additem.length == 3) {
                    addressList.addContact(new Contact(additem[0], additem[1], additem[2]));
                    System.out.println("添加联系人成功");
                } else {
                    System.out.println("输入的格式有误，应该输入姓名，地址和电话");
                }
            } else if (input.equals("D")) {
                System.out.println("请输入要删除联系人的姓名：");
                if (reader.hasNextLine()) {
                    input = reader.nextLine();
                }
                addressList.removeContact(input);
                System.out.println("删除成功");
            } else if (input.equals("F")) {
                System.out.println("请输入要查找人的姓名：");
                if (reader.hasNextLine()) {
                    input = reader.nextLine();
                }
                Contact item = addressList.findContact(input);
                System.out.println("查找姓名为" + input + "的这条记录，查找结果为：");
                System.out.println(item.toString());
            } else if (input.equals("X")) {
                System.out.println("欢迎再次使用通讯录,再见");
                break;
            }
        }


    }

    public static void init() {
        System.out.println("L--列出通讯录中的所有联系人");
        System.out.println("A--添加一个联系人到通讯录中");
        System.out.println("D--删除通讯录中的指定联系人");
        System.out.println("F--查找通讯录中符合条件的联系人");
        System.out.println("X--退出通讯录");
    }
}
