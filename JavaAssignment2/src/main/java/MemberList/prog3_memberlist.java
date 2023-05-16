/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package MemberList;

import java.util.Scanner;

/**
 *
 * @author HP
 */
public class prog3_memberlist {
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
