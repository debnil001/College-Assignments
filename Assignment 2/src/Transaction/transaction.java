package Transaction;

import java.util.ArrayList;

public class transaction {
    ArrayList<entry> ts=new ArrayList<entry>();
    //method to match presence of an entry and if presente update mem_id
    public boolean match(String bid,String mid){
        for(int i=0;i<ts.size();i++){
            entry obj=ts.get(i);
            if(obj.book_id.equals(bid) && obj.mem_id.equals(mid)){
                obj.mem_id="xxxx";
                return true;
            }
        }
        return false;
    }
    //method to issue a book to a member
    public void Issue(entry e){
        System.out.println("Transaction has been done successfully...");
        for(int i=0;i<ts.size();i++){
            entry obj=ts.get(i);
            if(obj.book_id.equals(e.book_id)){
                if(obj.mem_id.equals("xxxx")){
                    obj.mem_id=e.mem_id;
                    return;
                }
            }
        }
        ts.add(e);
    }
    //method to display all transaction details
    public void displayAll(){
        if(ts.size()==0){
            System.out.println("No transactions to Display...");
            return;
        }
        System.out.println("All transaction details are:");
        for(int i=0;i<ts.size();i++){
            entry obj=ts.get(i);
            System.out.println("Transaction "+(i+1)+"=>");
            obj.display();
        }
    }
}
