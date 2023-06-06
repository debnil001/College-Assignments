package Memberlist;

import java.util.ArrayList;

public class memberlist {
    ArrayList<member> ml=new ArrayList<member>();
    //method to match book ids
    public boolean match(String mid){
        for(int i=0;i<ml.size();i++){
            member obj=ml.get(i);
            if(obj.mem_id.equals(mid))
                return true;
        }
        return false;
    }
    //method to add a new book to the booklist
    public void add_member(member m){
        ml.add(m);
        System.out.println("Successfully Added in the memberlist...");
    }
    //method to display all book details
    public void displayAll(){
        if(ml.size()==0){
            System.out.println("No member to Display...");
            return;
        }
        System.out.println("All member details are:");
        for(int i=0;i<ml.size();i++){
            member obj=ml.get(i);
            System.out.println("Member "+(i+1)+"=>");
            obj.display();
        }
    }
    //method to display a particular book details
    public void display(String mid){
        if(ml.size()!=0){
            for(int i=0;i<ml.size();i++){
                member obj=ml.get(i);
                if(obj.mem_id.equals(mid)){
                    System.out.println("Member detail is:");
                    obj.display();
                    return;
                }
            }
            System.out.println("Member has not found...");
        }
        else{
            System.out.println("List Empty...");
        }
    }
    //method to check whether issue of book is possible or not
    public boolean canIssue(String mid){
        for(int i=0;i<ml.size();i++){
            member obj=ml.get(i);
            if(obj.mem_id.equals(mid)){
                if(obj.books_issued==member.max_book_issue)
                    return false;
            }
        }
        return true;
    }
    //method to increment issued book amount
    public void inc_issued(String mid){
        for(int i=0;i<ml.size();i++){
            member obj=ml.get(i);
            if(obj.mem_id.equals(mid)){
                obj.books_issued+=1;
                break;
            }
        }
    }
    //method to increment issued book amount
    public void dec_issued(String mid){
        for(int i=0;i<ml.size();i++){
            member obj=ml.get(i);
            if(obj.mem_id.equals(mid)){
                obj.books_issued-=1;
                break;
            }
        }
    }
}

