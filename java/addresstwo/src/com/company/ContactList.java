package com.company;

/**
 * Created by Dudaizhong on 2016/3/12.
 */
public class ContactList {

    private Contact contactList[] = new Contact[100];//使用对象数组存储条目

    private int total;    //数组中有效的条目数目

    public ContactList() {
        contactList[0] = new Contact("陈杰", "重庆市", "0124151087");
        contactList[1] = new Contact("林龙强", "北京市", "31791821");
        contactList[2] = new Contact("王晓玲", "上海市", "568790221");
        total = 3;
    }

    public int getTotal() {
        return total;
    }

    public void addContact(Contact aItem) {
        //添加的条目直接加入数组的尾部
        contactList[total] = new Contact(aItem);
        total++;
    }

    public void removeContact(String aName) {
        int k = -1;
        for (int i = 0; i < total; i++) {
            if (contactList[i].getName().equals(aName))
                k = i;
        }
        //把第k+1个条目移动到第K个位置，以此类推

        if (k != -1) {
            for (int i = k; i < total - 1; i++) {
                contactList[i] = contactList[i + 1];
            }
            total--;
            contactList[total] = null;
        } else {
            System.out.println("未查找到匹配条目");
        }

    }

    public Contact findContact(String aName) {
        int i, k;
        for (i = 0; i < total; i++) {
            if (contactList[i].getName().equals(aName)) {
                k = i;
                break;
            }
        }

        if (i < total) {
            return new Contact(contactList[i]);
        } else {
            return new Contact();
        }
    }

    @Override
    public String toString() {
        StringBuffer str = new StringBuffer("");
        for (int i = 0; i < total; i++) {
            str = str.append(contactList[i].toString()).append("\n");
        }
        return str.toString();
    }
}
