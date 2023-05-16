package Transaction;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author HP
 */
public class prog3_transaction {
    public int memberid; // member]
    public int bookid; // book

    public void addEntry(int memberid, int bookid) {
        this.memberid = memberid;
        this.bookid = bookid;
    }

    public void modifyEntry(int bookid){
        this.bookid =bookid;
    }
}
