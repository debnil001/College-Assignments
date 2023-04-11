// 2. Write a program that accepts a number of command line parameters and displays the parameters and

public class prog1{
    public static void main(String[] args) {
        int len=args.length;
        System.out.println("Argument length is:"+len);
	  System.out.println("Arguments are::");
        for(int i=0;i<len;i++){
            System.out.println("Argument "+i+" is "+args[i]);
        }
    }
}