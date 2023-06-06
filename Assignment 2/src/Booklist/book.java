package Booklist;

public class book {
    public String book_id;
    public String title;
    public long copies_purchased;
    public long copies_available;
    //default constructor to initialize objects
    public book(){
        book_id="";
        title="";
        copies_purchased=0;
        copies_available=0;
    }
    //parameterized constructor
    public book(String bid,String title,long cp){
        this.book_id=bid;
        this.title=title;
        this.copies_purchased=cp;
        this.copies_available=cp;
    }
    //copy constructor
    public book(book b){
        this.book_id=b.book_id;
        this.title=b.title;
        this.copies_purchased=b.copies_purchased;
        this.copies_available=b.copies_available;
    }
    public void display(){
        System.out.println("ID : "+this.book_id+" Title: "+this.title+" Copies_Purchased : "+this.copies_purchased+" Copies_Available : "+this.copies_available);
    }
}


