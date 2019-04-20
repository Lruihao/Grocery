package ui;

import address.Address;
import address.Contact;
import java.awt.Dimension;
import java.util.Vector;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.RowFilter;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableColumn;
import javax.swing.table.TableColumnModel;
import javax.swing.table.TableModel;
import javax.swing.table.TableRowSorter;

public class Table extends JPanel{
	
	private static final long serialVersionUID = 8448148140900945540L;
	private final Address address;//所有组件共用
    //private final ContactButton contactButton;//table单元格被选中，会影响contactButton的能否点击
    private final JTable table=new JTable();//在Check里面被用到
    private final Model model=new Model();//表格模式
    //private final Renderer render=new Renderer();//渲染器
    private final TableRowSorter<TableModel> sorter = new TableRowSorter<>(model);
    private final JScrollPane pane = new JScrollPane(table);

    public Table(Address address) {
        this.address = address;this.refreshData();
        table.setModel(model);       
        table.setRowSorter(sorter);
        this.add(pane);
        table.setShowVerticalLines(false);
        table.setRowHeight(40);
        table.setPreferredScrollableViewportSize(new Dimension(930,500));
    }
    public void setFilter(RowFilter rf){
        sorter.setRowFilter(rf);
    }
    public TableColumnModel getColumnModel(){
        return table.getColumnModel();
    }
    public int getSelectedRow() {
        return table.getSelectedRow();
    }
    public void deleteContact(){
        for(int i = 0; i < table.getSelectedRows().length; i++){
            address.deleteContact((Contact) table.getValueAt(table.getSelectedRows()[i], 0));
        }
    }
   
    public Contact getValueAt() {
        int selected = table.getSelectedRow();
        if (selected > -1) {
            return (Contact) table.getValueAt(table.getSelectedRow(), 0);
        } else {
            return null;
        }
    }
    public TableColumn getColumn(Object identifier){
        return table.getColumn(identifier);
    }
    public void fireTableDataChanged(){
        model.fireTableDataChanged();
    }

    public void refreshData(){model.ini();}
    public class Model extends DefaultTableModel{
		private static final long serialVersionUID = 1L;
		public Model(){    
            columnIdentifiers.add("姓名");columnIdentifiers.add("手机");
            columnIdentifiers.add("电子邮箱");columnIdentifiers.add("固定电话");
            columnIdentifiers.add("短号");columnIdentifiers.add("生日");
            columnIdentifiers.add("工作单位");columnIdentifiers.add("家庭地址");
            columnIdentifiers.add("邮编");columnIdentifiers.add("即时通讯");
            columnIdentifiers.add("个人主页");columnIdentifiers.add("备注");
        }
        public void ini(){
            dataVector.clear();
            for(Contact c:address.getAllContacts()){
                Vector<Object> v=new Vector<Object>();
                v.add(c);v.add(c.getMobilePhone());
                v.add(c.getEmail());v.add(c.getTelephone());
                v.add(c.getCornet());v.add(c.getBirthday());
                v.add(c.getWorkUnit());v.add(c.getFamilyAddress());
                v.add(c.getPostcode());v.add(c.getInstantMessaging());
                v.add(c.getPersonalHomepage());v.add(c.getComment());//没有photo和group
                dataVector.add(v);
            }
        }
        public boolean isCellEditable(int row, int column) {
            return false;
        }
    }
}
