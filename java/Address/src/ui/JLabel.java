/*
 * 自定义标签
 */
package ui;

import java.awt.Color;
import java.awt.Font;

public class JLabel extends javax.swing.JLabel{
	private static final long serialVersionUID = 1L;

	public JLabel(String text){
        super(text);
        this.setForeground(new Color(255,127,80)); //标签颜色
        this.setFont(new Font("华文隶书",0,20));//设置字体，0正常，1粗体
        this.setSize(100,40);
    }
}
