import java.util.Scanner;

// 3. Write a program that accepts height in cm as int and displays the height in feet and inches. Assume, 1
// inch equals 2.54 cm and 1 foot equals 30.5 cm.
public class prog3 {
    private static float inch=2.54f;
    private static float foot=30.5f;

    public static void main(String[] args) {
        System.out.println("Enter height in cm::");
        int h=new Scanner(System.in).nextInt();
        System.out.println("Height in foot:"+String.format("%.2f", h/foot));
        System.out.println("Height in inch:"+String.format("%.2f", h/inch));

    }
}
