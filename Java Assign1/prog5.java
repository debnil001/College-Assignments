import java.util.Scanner;

// 5. Write a program that accepts a String and assigns it to another. Check the outcome of comparison
// with == and equals() method. Take two Strings and put same input for them. Repeat the equality
// checking. Observe the outcome.

public class prog5 {
    public static void main(String[] args) {
        System.out.println("Enter a string::");
        String s1=new Scanner(System.in).nextLine();
        String s2=new String(s1);
        // System.out.println("Enter another string::");
        // String s2=new Scanner(System.in).nextLine();

        if(s1==s2){
            System.out.println("Strings are equal(==)");
        }
        if(s1.equals(s2)){
            System.out.println("Strings are equal(equals())");
        }
    }
}
