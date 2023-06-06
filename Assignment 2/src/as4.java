import Booklist.book;
import Memberlist.member;
import Transaction.entry;
import java.util.*;

interface booklist{
    ArrayList<book> bl=new ArrayList<book>();
    public boolean matchBook(String bid);
    public void displayAllBook();
    public void searchBook(String bid);
    public void increment(String bid,long val);
    public boolean isAvialble(String bid);
    public void dec_avl(String bid);
    public void inc_avl(String bid);
}

interface memberlist{
    ArrayList<member> ml=new ArrayList<member>();
    boolean matchMember(String mid);
    public void add_member(member m);
    public void displayAllMember();
    public void searchMember(String mid);
    public boolean canIssue(String mid);
    public void inc_issued(String mid);
    public void dec_issued(String mid);
}
interface transaction{
    ArrayList<entry> ts=new ArrayList<entry>();
    public boolean matchTransaction(String bid,String mid);
    public void Issue(entry e);
    public void displayAllTransactions();
}

class LMS implements booklist,memberlist,transaction{
public boolean matchBook(String bid){
for(int i=0;i<bl.size();i++){
        book obj=bl.get(i);
        if(obj.book_id.equals(bid))
            return true;
    }
return false;
}
    public void add_book(book b){
        bl.add(b);
        System.out.println("Successfully Added in the booklist...");
    }
    public void displayAllBook(){
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
    public void searchBook(String bid){
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
    public boolean isAvialble(String bid){for(int i=0;i<bl.size();i++){
        book obj=bl.get(i);
        if(obj.book_id.equals(bid)){
            if(obj.copies_available==0)
                return false;
        }
    }
        return true;
    }
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
    public void dec_avl(String bid){
        for(int i=0;i<bl.size();i++){
            book obj=bl.get(i);
            if(obj.book_id.equals(bid)){
                obj.copies_available-=1;
                break;
            }
        }
    }
    public void inc_avl(String bid){
        for(int i=0;i<bl.size();i++){
            book obj=bl.get(i);
            if(obj.book_id.equals(bid)){
                obj.copies_available+=1;
                break;
            }
        }}
    public boolean matchMember(String mid){
        for(int i=0;i<ml.size();i++){
            member obj=ml.get(i);
            if(obj.mem_id.equals(mid))
                return true;
        }
        return false;
    }
    public void add_member(member m){
        ml.add(m);
        System.out.println("Successfully Added in the memberlist...");
    }
    //method to display all book details
    public void displayAllMember(){
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
    public void searchMember(String mid){
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
    public void inc_issued(String mid){
        for(int i=0;i<ml.size();i++){
            member obj=ml.get(i);
            if(obj.mem_id.equals(mid)){
                obj.books_issued+=1;
                break;
            }
        }
    }
    public void dec_issued(String mid){
        for(int i=0;i<ml.size();i++){
            member obj=ml.get(i);
            if(obj.mem_id.equals(mid)){
                obj.books_issued-=1;
                break;
            }
        }
    }
    public boolean matchTransaction(String bid,String mid){
        for(int i=0;i<ts.size();i++){
            entry obj=ts.get(i);
            if(obj.book_id.equals(bid) && obj.mem_id.equals(mid)){
                obj.mem_id="xxxx";
                return true;
            }
        }
        return false;
    }
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
    public void displayAllTransactions(){
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
};
public class as4 {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        LMS l=new LMS();
        System.out.println("1.Add new book in the list");
        System.out.println("2.Search for a book");
        System.out.println("3.Show all book details");
        System.out.println("4.Add new member");
        System.out.println("5.Search for a member");
        System.out.println("6.Show details of all members");
        System.out.println("7.Issue a book");
        System.out.println("8.Return a book");
        System.out.println("9.Display All Transaction Details");
        int ch;
        do{
            System.out.println("Enter your choice:");
            ch=sc.nextInt();
            sc.nextLine();
            switch(ch){
                case 1:System.out.println("Enter book_id,title,copies purchased:");
                    String bid=sc.nextLine();
                    if(!l.matchBook(bid)){
                        String title=sc.nextLine();
                        long copies=sc.nextLong();
                        book b=new book(bid,title,copies);
                        l.add_book(b);
                    }
                    else{
                        System.out.println("Already Present.Copies incremented... ");
                                l.increment(bid,1);
                    }
                    break;
                case 2:
                    System.out.print("Enter book id:");
                    bid=sc.nextLine();
                    l.searchBook(bid);
                    break;
                case 3:
                    l.displayAllBook();
                    break;
                case 4:
                    System.out.println("Enter member_id,name,date of birth(dd/mm/ yyyy) and number of books issued:");
                    String mid=sc.nextLine();
                    if(!l.matchMember(mid)){
                        String name=sc.nextLine();
                        String date=sc.nextLine();
                        long issued=sc.nextLong();
                        member m=new member(mid,name,date,issued);
                        l.add_member(m);
                    }
                    else{
                        System.out.println("Memeber ID should be unique...");
                    }
                    break;
                case 5:
                    System.out.print("Enter member id:");
                    mid=sc.nextLine();
                    l.searchMember(mid);
                    break;
                case 6:
                    l.displayAllMember();
                    break;case 7:
                    System.out.println("Enter valid book_id:");
                    bid=sc.nextLine();
                    if(l.matchBook(bid)){
                        System.out.println("Enter valid member_id:");
                        mid=sc.nextLine();
                        if(l.matchMember(mid)){
                            if(l.canIssue(mid)){
                                if(l.isAvialble(bid)){
                                    entry e=new entry(bid,mid);
                                    l.Issue(e);
                                    l.dec_avl(bid);
                                    l.inc_issued(mid);
                                }
                                else{
                                    System.out.println("Sorry ! Books Shortage... ");
                                }
                            }
                            else{
                                System.out.println("Maximum number of books already issued...");
                            }
                        }
                        else{
                            System.out.println("Invalid Member ID...");
                        }
                    }
                    else{
                        System.out.println("Invalid Book ID...");
                    }
                    break;
                case 8:
                    System.out.println("Enter valid book_id and member_ID:");
                    bid=sc.nextLine();
                    mid=sc.nextLine();
                    if(l.matchTransaction(bid,mid)){
                        System.out.println("Book Returned successfully...");
                        l.inc_avl(bid);
                        l.dec_issued(mid);
                    }else{
                        System.out.println("Wrong entry details...");
                    }
                    break;
                case 9:
                    l.displayAllTransactions();
                    break;
            }
        }while(ch>=1&&ch<=9);
    }
}
