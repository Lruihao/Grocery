/*
 * 自定义文本框文字
 */
package ui;

import java.awt.Font;

public class JTextField extends javax.swing.JTextField{
	private static final long serialVersionUID = 1L;

	public JTextField(){
        super();
        this.setSize(180,30);
        this.setFont(new Font("华文隶书",0,18));
        this.setDocument(new StringDeal());
    } 
}
