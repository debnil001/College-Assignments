/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author HP
 */
package BookList;
import java.util.HashSet;
import java.util.Scanner;
public class prog3_booklist {
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
