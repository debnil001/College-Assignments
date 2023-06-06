package Booklist;

import java.util.ArrayList;

public class booklist {
        ArrayList<book> bl=new ArrayList<book>();
        //method to match book ids
        public boolean match(String bid){
            for(int i=0;i<bl.size();i++){
                book obj=bl.get(i);
                if(obj.book_id.equals(bid))
                    return true;
            }
            return false;
        }
        //method to add a new book to the booklist
        public void add_book(book b){
            bl.add(b);
            System.out.println("Successfully Added in the booklist...");
        }
        //method to display all book details
        public void displayAll(){
            if(bl.size()==0){
                System.out.println("No Book to Display...");
                return;
            }
            System.out.println("All book details are:");
            for(int i=0;i<bl.size();i++){
                book obj=bl.get(i);
                System.out.println("Book "+(i+1)+"=>");
                obj.display();
            }
        }
        //method to display a particular book details
        public void display(String bid){
            if(bl.size()!=0){
                for(int i=0;i<bl.size();i++){
                    book obj=bl.get(i);
                    if(obj.book_id.equals(bid)){
                        System.out.println("Book detail is:");
                        obj.display();
                        return;
                    }
                }
                System.out.println("Book not found...");
            }
            else{
                System.out.println("List Empty...");
            }
        }
        //method to check availability of book
        public boolean isAvialble(String bid){
            for(int i=0;i<bl.size();i++){
                book obj=bl.get(i);
                if(obj.book_id.equals(bid)){
                    if(obj.copies_available==0)
                        return false;
                }
            }
            return true;
        }
        //method to increment a particular book copy available
        public void increment(String bid,long val){
            if(bl.size()!=0){
                for(int i=0;i<bl.size();i++){
                    book obj=bl.get(i);
                    if(obj.book_id.equals(bid)){
                        obj.copies_purchased+=val;
                        obj.copies_available+=val;
                        return;
                    }
                }
                System.out.println("Book not found...");
            }
            else{
                System.out.println("Empty Booklist...");
            }
        }
        //method to decrement available copies value
        public void dec_avl(String bid){
            for(int i=0;i<bl.size();i++){
                book obj=bl.get(i);
                if(obj.book_id.equals(bid)){
                    obj.copies_available-=1;
                    break;
                }
            }
        }
        //method to increment available copies value
        public void inc_avl(String bid){
            for(int i=0;i<bl.size();i++){
                book obj=bl.get(i);
                if(obj.book_id.equals(bid)){
                    obj.copies_available+=1;
                    break;
                }
            }
        }
    }

