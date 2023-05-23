import java.util.Scanner;
import java.util.HashSet;
class prog3_transaction {
    public int memberid;
    public int bookid;

    public void addEntry(int memberid, int bookid) {
        this.memberid = memberid;
        this.bookid = bookid;
    }

    public void modifyEntry(int bookid){
        this.bookid =bookid;
    }
}
class prog3_memberlist {
        public static int limit=5;
        
        public int memberid;
        String name;
        String DOB;
        public int booktaken;
        static int ID=100;
        public void addMember(){
            this.memberid = ID++;
            System.out.println("Enter the member name and DOB");
            this.name = new Scanner(System.in).nextLine();
            this.DOB = new Scanner(System.in).nextLine();
            System.out.println("Memeber registered with ID "+memberid);
        }
        public void showMember(){
            System.out.println("Member name: " + name);
            System.out.println("Member ID: " + memberid);
            System.out.println("Member DOB: " + DOB);
            System.out.println("Total book taken: "+this.booktaken);
        }
}
class prog3_booklist {
    HashSet<Integer> hs;
    public prog3_booklist() {
        hs=new HashSet<>();
    }
        public int bookid;
        String title;
        public int totalcount;
        public int totalleft;

        public void addBook(){
            System.out.println("Enter bookid,title and count: ");
            int bookid=new Scanner(System.in).nextInt();
            String title=new Scanner(System.in).nextLine();
            int totalcount=new Scanner(System.in).nextInt();
            if(!hs.contains(bookid)){
                hs.add(bookid);
                this.bookid = bookid;
                this.title = title;
                this.totalcount = totalcount;
                this.totalleft = totalcount;
            }
            else
                System.out.println("Book already exists with id " + this.bookid);
        }

        public void updateBookCount(int totalcount,boolean update){
            if(update){
                this.totalcount += totalcount;
                this.totalleft+= totalcount;
            }
            else{
                this.totalcount=Math.max(0,this.totalcount-totalcount);
                this.totalleft=Math.max(0,this.totalleft-totalcount);
            }
        }

        public void getBook(){
            System.out.println("Book title: "+this.title);
            System.out.println("Book count: "+this.totalcount);
            System.out.println("Book left: "+this.totalleft);
        }
}
class prog3 {
    public static prog3_booklist getBook(int id,prog3_booklist[]temp,int index){
        for(int i=0;i<index;i++){
            if(id==temp[i].bookid)
                return temp[i];
        }
        return null;
    }
    public static prog3_memberlist getMember(int id,prog3_memberlist[]temp,int index){
        for(int i=0;i<index;i++){
            if(id==temp[i].memberid)
                return temp[i];
        }
        return null;
    }
    public static void main(String[] args) {
        prog3_booklist []booklist = new prog3_booklist[100];
        prog3_memberlist[] memberlist = new prog3_memberlist[100];
        prog3_transaction []tx = new prog3_transaction[100];
        int bindex=0;
        int mindex=0;
        int txindex=0;
        while(true){
            System.out.println("1.Add book");
            System.out.println("2.Add more copies of a book");
            System.out.println("3.show all books");
            System.out.println("4.show details of a book");
            System.out.println("5.Add members");
            System.out.println("6.show details of a members");
            System.out.println("7.show all members");
            System.out.println("8.issue a book");
            System.out.println("9.Return Book");
            System.out.println("10.exit");
        
            System.out.println("Enter choice");
            int choice=new Scanner(System.in).nextInt();

            switch(choice) {
                case 1:
                    booklist[bindex]=new prog3_booklist();
                    booklist[bindex++].addBook();
                    break;
                case 2:
                    System.out.println("Enter bookid to add copy");
                    prog3_booklist book=getBook(new Scanner(System.in).nextInt(), 
                    booklist, bindex);

                    if(book==null){
                        System.out.println("No book found");
                    }
                    else{
                        System.out.println("Enter number of copies to add");
                        book.updateBookCount(new Scanner(System.in).nextInt(),
                         true);
                    }
                    break;
                case 3:
                    for(int i=0; i<bindex; i++){
                        booklist[i].getBook();
                    }
                    break;
                case 4:
                    System.out.println("Enter bookid to view");
                    prog3_booklist book1=getBook(new Scanner(System.in).nextInt(), 
                    booklist, bindex);

                    if(book1==null){
                        System.out.println("No book found");
                    }
                    else{
                        book1.getBook();
                    }
                    break;
                case 5:
                    memberlist[mindex]=new prog3_memberlist();
                    memberlist[mindex++].addMember();
                    break;
                case 6:
                    System.out.println("Enter memeber id to view");
                    prog3_memberlist mem1=getMember(new Scanner(System.in).nextInt(),
                    memberlist,mindex);
                    if(mem1==null){
                        System.out.println("No member found");
                    }
                    else{
                        mem1.showMember();
                    }
                    break;
                case 7:
                    for(int i=0; i<mindex; i++){
                        memberlist[i].showMember();
                    }
                    break;
                case 8:
                    System.out.println("Enter book id to be issued");
                    int bookid=new Scanner(System.in).nextInt();
                    prog3_booklist tempBook=getBook(bookid, booklist, bindex);
                    if(tempBook==null){    
                        System.out.println("Book not found: ");
                        break;
                    }
                    System.out.println("Enter memeber id for whom to be issued");
                    int memberid=new Scanner(System.in).nextInt();
                    prog3_memberlist tempMember=getMember(memberid, memberlist, mindex);
                    if(tempMember==null){
                        System.out.println("Member not found: ");
                        break;
                    }
                    if(tempMember.booktaken>prog3_memberlist.limit){
                        System.out.println("Member has reached limit of issuing");
                        break;
                    }
                    if(tempBook.totalleft==0){
                        System.out.println("Book is not available");
                        break;
                    }
                    System.out.println("Enter number of copies to be issued");
                    int copy=new Scanner(System.in).nextInt();
                    if(copy>tempBook.totalleft || copy<0 || copy>tempBook.totalcount){
                        System.out.println("Book is not available in that amount of copies");
                        break;
                    }
                    tempMember.booktaken+=copy;
                    tempBook.totalleft-=copy;
                    tx[txindex]=new prog3_transaction();
                    tx[txindex++].addEntry(memberid,bookid);
                    System.out.println("Transaction completed successfully");
                    break;
                case 9:
                    System.out.println("Enter member id and then book id to be returned");
                    int memberid1=new Scanner(System.in).nextInt();
                    int bookid1=new Scanner(System.in).nextInt();
                    int i;
                    for( i=0;i<txindex;i++) {
                        if(tx[i].memberid==memberid1 && tx[i].bookid==bookid1) {
                            prog3_booklist tempBook1=getBook(bookid1, booklist, bindex);
                            prog3_memberlist tempMember1=getMember(memberid1, memberlist, mindex);

                            tempBook1.totalleft+=tempMember1.booktaken;
                            tempMember1.booktaken=0;
                            System.out.println("Transaction complete successfully");
                            break;
                        }
                    }
                    if(i==txindex){
                        System.out.println("No book found");
                        break;
                    }
                    break;
                case 10:
                    System.exit(0);
            }


        }
        
    }
}