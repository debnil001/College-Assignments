package Transaction;

public class entry {
    public String book_id,mem_id;
    //default constructor
    public entry(){
        book_id="";
        mem_id="";
    }
    //parameterized constructor
    public entry(String bid,String mid){
        this.book_id=bid;
        this.mem_id=mid;
    }
    //copy constructor
    public entry(entry e){
        this.book_id=e.book_id;
        this.mem_id=e.mem_id;
    }
    //display an entry
    public void display(){
        System.out.println("Book_ID : "+this.book_id+" Member_ID : "+this.mem_id);
    }
}
