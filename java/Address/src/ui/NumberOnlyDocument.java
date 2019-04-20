/*
 *  限制JTextField只能输入数字
 */
package ui;

import java.awt.Toolkit;
import javax.swing.text.AttributeSet;
import javax.swing.text.BadLocationException;
import javax.swing.text.PlainDocument;


public class NumberOnlyDocument  extends PlainDocument{    
	private static final long serialVersionUID = 4119809591372500503L;

	@Override
     public void insertString(int offs, String str, AttributeSet a)throws BadLocationException{     
      if (str == null)
       {
        return;
       }
      char[] upper = str.toCharArray();
      for (int i = 0; i < upper.length; i++)
       {
        if (!Character.isDigit(upper[i])){
         str = str.substring(0, i);
         Toolkit.getDefaultToolkit().beep();
        }       
       }
      super.insertString(offs, str , a);
     }
}
