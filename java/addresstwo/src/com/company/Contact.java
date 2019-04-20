package com.company;

/**
 * Created by Dudaizhong on 2016/3/12.
 */
public class Contact {

    private String name;
    private String address;
    private String telephone;
    private static int itemCount = 0;

    public Contact() {
        name = null;
        address = null;
        telephone = null;
        itemCount++;
    }

    public Contact(Contact aItem) {
        this(aItem.name, aItem.address, aItem.telephone);
    }

    public Contact(String name, String address, String telephone) {
        this.name = name;
        this.address = address;
        this.telephone = telephone;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getTelephone() {
        return telephone;
    }

    public void setTelephone(String telephone) {
        this.telephone = telephone;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    @Override
    public String toString() {
        return "Contact{" +
                "name='" + name + '\'' +
                ", address='" + address + '\'' +
                ", telephone='" + telephone + '\'' +
                '}';
    }
}
