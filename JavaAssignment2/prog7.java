import java.util.*;
public class prog7 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String inputString=sc.nextLine();
        char[]chars=inputString.toCharArray();
        int count=0;
        for(char c:chars) {
            if(c=='a')  count++;
        }
        System.out.println("Count of \'a\' is "+count);
        int countOfA=0;
        String arr[]=inputString.split(" ");
        for(String str:arr) {
            System.out.println(str);
            if(arr.equals("and")) countOfA++;

        }
        System.out.println("Count of \"and\" in the input string"+countOfA);
        if(arr[0].equals("The")) System.out.println("Starts with \"the\"");
        
    }
}
