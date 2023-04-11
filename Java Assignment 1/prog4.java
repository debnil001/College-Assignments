import java.util.Scanner;

// 4. Write a program that accepts the radius of a circle and displays the area of the circle. Declare a constant pi
// equals 3.14.
public class prog4 {
    private static final float PI=3.14f;
    public static void main(String[] args) {
        System.out.println("Enter radius of the circle::");
        Scanner sc=new Scanner(System.in);
        int rad=sc.nextInt();
        System.out.print("Area of the circle is ::"+String.format("%.2f", rad*PI));
        sc.close();
    }
}
