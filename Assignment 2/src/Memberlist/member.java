package Memberlist;

public class member {
    public String mem_id;
    public String name;
    public String dob;
    public long books_issued;
    public static long max_book_issue=4;
    //default constructor
    public member(){
        this.mem_id="";
        this.name="";
        this.dob="";
        this.books_issued=0;
    }
    //parameterized constructor
    public member(String mid,String name,String date,long books_issued){
        this.mem_id=mid;
        this.name=name;
        this.dob=date;
        this.books_issued=books_issued;
    }
    //copy constructor
    public member(member m){
        this.mem_id=m.mem_id;
        this.name=m.name;
        this.dob=m.dob;
        this.books_issued=m.books_issued;
    }
    //method to display the member data
    public void display(){
        System.out.println("Member ID : "+this.mem_id+" Name : "+this.name+" Date of Birth : "+this.dob+" Books Issued : "+this.books_issued);
    }
}
