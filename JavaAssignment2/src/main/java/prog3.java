import java.util.Scanner;
import BookList.prog3_booklist;
import MemberList.prog3_memberlist;
import Transaction.prog3_transaction;
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
