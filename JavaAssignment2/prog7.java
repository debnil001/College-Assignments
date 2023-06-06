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
        System.out.println("Enter delimeter::");
        String del=new Scanner(System.in).nextLine();
        String[]arr;
        if(del.equals(" ")){
            arr=inputString.split(" ");
        }
        else{
            arr=inputString.split("@");
        }
        String s="and";
        for(String str:arr){
            System.out.println(str);
            if(str.compareTo(s)==0) 
                countOfA++;
        }
        System.out.println("Count of \"and\" in the input string "+countOfA);
        if(arr[0].equals("The")) 
        System.out.println("Starts with \"the\"");
        
    }
}
