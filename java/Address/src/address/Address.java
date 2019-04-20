package address;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Vector;
import javax.swing.JOptionPane;

public class Address {
	/*
	 * 数据域
	 */
    private final Vector<Contact> allContacts;//所有联系人
    private final Vector <String> groupNames;//所有分组名

    public Address() {
        allContacts=new Vector<>();
        groupNames=new Vector<>();
        groupNames.add("所有联系人");
    }

    /**
     * 新增联系人
     */
    public void addContact(Contact c){
        allContacts.add(c);
    }
    /**
     * 删除联系人
     */
    public void deleteContact(Contact c){
        allContacts.remove(c);
    }
    /**
     * 新增分组 
     */
    public void addGroup(String newGroupName){
        groupNames.add(newGroupName);
    }
    /**
     * 删除分组
     */
    public void deleteGroup(String deleteGroupName){
        //先在所有组别中删除该组
        groupNames.remove(deleteGroupName);
        //找到属于该组的联系人，删除它所属组别的这个分组
        allContacts.stream().filter((c) -> (c.getGroup().contains(deleteGroupName))).forEach((c) -> {
            c.getGroup().remove(deleteGroupName);
        });
    }
    
    public int indexOfAllContacts(Contact contact){
        return allContacts.indexOf(contact);
    }
    
    public void set(int count, Contact contact){
        allContacts.set(count, contact);
    }
    /**
     * 联系人的属性用逗号分隔，联系人所在分组用空格分隔
     * 导入CSV文件
     */
    public final void readCSV(File file){
        try(Scanner input=new Scanner(file,"UTF-8")){
            allContacts.clear();//清除之前的联系人信息
            groupNames.clear();
            groupNames.add("所有联系人");//所有contact都属于“所有联系人”这个组
            String line=input.nextLine();//跳过表头
            while(input.hasNext()){
                line=input.nextLine();
                String[] data=line.split(",");//联系人的属性用逗号分隔
                Vector<String> group=(Vector<String>) convertToVector(data[13].split(" "));//联系人所在分组用空格分隔
                Contact c=new Contact(data[0],data[1],data[2],data[3],data[4],data[5],data[6],data[7],data[8],data[9],data[10],data[11],data[12],group);
                allContacts.add(c);//读取到一个新的联系人，加到所有联系人中
                //读取此人的所在分组，若遇到新的组别，加到所有分组中
                for(String s:group)
                    if(!groupNames.contains(s)) groupNames.add(s);
                //if(allContacts.size()<1) {System.out.println("jj");throw new Exception("文件格式错误");}
            }
        } catch (FileNotFoundException ex) {
            JOptionPane.showMessageDialog(null, "这个文件不存在呐！", "出错啦", JOptionPane.ERROR_MESSAGE);
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(null, "这个文件的格式不对！", "出错啦", JOptionPane.ERROR_MESSAGE);
        }
    }
    /**
     * 导出CSV文件，保存到当前目录下的address.csv
     */
    public void writeCSV(){
        File f;
        try (PrintWriter output=new PrintWriter(f=new File("address.csv"))){
            //表头
            output.println("姓名,手机,电子邮箱,固定电话,短号,生日,工作单位,家庭地址,邮编,即时通讯,相片,个人主页,备注,所属组别");
            allContacts.stream().forEach((c) -> {
                //具体信息
                output.print(c.getName()+","+c.getMobilePhone()+","+c.getEmail()+","+c.getTelephone()+","+c.getCornet()+","+c.getBirthday()+","+c.getWorkUnit()+","+c.getFamilyAddress()+","+c.getPostcode()+","+c.getInstantMessaging()+","+c.getPhoto()+","+c.getPersonalHomepage()+","+c.getComment()+",");
                //分组信息，该人是否有分组，每一行的最后至少要有一个空格（因为用了读取文件时split方法，split会抛弃后面没有的项），否则读取文件时候会抛出异常。
                for(String s:c.getGroup()) output.print(s+" ");
                output.println(" ");
            });
            JOptionPane.showMessageDialog(null,"已保存至"+f.getAbsolutePath());
        } catch (FileNotFoundException ex) {
            JOptionPane.showMessageDialog(null, "这个文件不存在呐！", "出错啦", JOptionPane.ERROR_MESSAGE);
        } catch (Exception ex){
            JOptionPane.showMessageDialog(null, "未知错误", "出错啦", JOptionPane.ERROR_MESSAGE);
        }
    }
    /**
     * 导出VCF文件(vcard3.0格式)，保存到当前目录下的address.vcf
     */
    public void writeVCF(){
        //先将所有联系人信息存进一个字符串中，再把字符串写入文件（速度应该会快点）
        StringBuilder result=new StringBuilder();
        for(Contact c:allContacts){//换行是用\r\n
            result.append("BEGIN:VCARD\r\n");
            result.append("VERSION:3.0\r\n");
            result.append("N:").append(c.getName()).append("\r\n");
            result.append("FN:").append(c.getName()).append("\r\n");
            if(!"".equals(c.getMobilePhone()))
                result.append("TEL;TYPE=CELL:").append(c.getMobilePhone()).append("\r\n");
            if(!"".equals(c.getCornet()))
                result.append("TEL;TYPE=CELL:").append(c.getCornet()).append("\r\n");
            if(!"".equals(c.getTelephone()))
                result.append("TEL;TYPE=HOME:").append(c.getTelephone()).append("\r\n");
            if(!"".equals(c.getEmail()))
                result.append("EMAIL;TYPE=HOME:").append(c.getEmail()).append("\r\n");
            if(!"".equals(c.getBirthday()))
                result.append("BDAY:").append(c.getBirthday()).append("\r\n");
            if(!"".equals(c.getWorkUnit()))
                result.append("ORG:").append(c.getWorkUnit()).append("\r\n");
            if(!"".equals(c.getFamilyAddress()))
                result.append("ADR;TYPE=HOME:").append(c.getFamilyAddress()).append("\r\n");
            if(!"".equals(c.getPostcode()))
                result.append("ADR;TYPE=POSTAL:").append(c.getPostcode()).append("\r\n");
            if(!"".equals(c.getInstantMessaging()))
                result.append("X-QQ:").append(c.getInstantMessaging()).append("\r\n");
            if(!"".equals(c.getPersonalHomepage()))
                result.append("URL:").append(c.getPersonalHomepage()).append("\r\n");
            if(!"".equals(c.getComment()))
                result.append("NOTE:").append(c.getComment()).append("\r\n");
            result.append("END:VCARD\r\n");
        }
            
        File f;
        try (PrintWriter output=new PrintWriter(f=new File("address.vcf"))){
            output.append(result);
            JOptionPane.showMessageDialog(null,"已保存至"+f.getAbsolutePath());
        } catch (FileNotFoundException ex) {
            JOptionPane.showMessageDialog(null, "这个文件不存在呐！", "出错啦", JOptionPane.ERROR_MESSAGE);
        } catch (Exception ex){
            JOptionPane.showMessageDialog(null, "未知错误。", "出错啦", JOptionPane.ERROR_MESSAGE);
        }
    }
    
    public void show(){
        for(Contact c:allContacts){
            System.out.println(c.getName()+","+c.getMobilePhone()+","+c.getEmail()+","+c.getTelephone()+","+c.getCornet()+","+c.getBirthday());
            System.out.println(c.getWorkUnit()+","+c.getFamilyAddress()+","+c.getPostcode()+","+c.getInstantMessaging()+","+c.getPhoto()+","+c.getPersonalHomepage()+","+c.getComment());
            c.getGroup().stream().forEach((s) -> {
                System.out.print(s+" ");
            });
            System.out.println();System.out.println();
        }
        for(String s:groupNames)
            System.out.println(s);
    }

    public Vector<Contact> getAllContacts() {
        return allContacts;
    }

    public Vector <String> getGroupNames() {
        return groupNames;
    }
    //来自DefaultTableModel的源代码
    private Vector<?> convertToVector(Object[] anArray) {
        if (anArray == null) {
            return null;
        }
        Vector<Object> v = new Vector<Object>(anArray.length);
        for (Object o : anArray) {
            v.addElement(o);
        }
        return v;
    }
}
