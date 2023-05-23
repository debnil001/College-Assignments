import java.util.HashSet;
interface ADD_MODIFY{
	void addBook();
	void update();

}
interface 
	void viewAll();
	void addMember();
	void searchMember();
	void viewAllMember();
	void issueBook();
	void returnBook();
}
class prog3_booklist implements library{
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

class Main implements library{
	void addBook(){

	}

}
