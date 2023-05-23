public class prog6 {
    public static void main(String[] args) {
        int a=10;
        Integer integer=Integer.valueOf(a);
        int b=integer.intValue();
        String num=String.valueOf(b);
        Integer newNum=Integer.parseInt(num);
        String newString=Integer.toString(b);
    }
}
