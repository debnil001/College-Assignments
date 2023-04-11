// 6. Write a program where class contains void show(int) to display the argument passed. Call the
// function once with short as actual parameter and again double as actual parameter. Add another
// function as void show(double) . Repeat the calls. Observe the outcomes in each case.
public class prog6 {
    public void show(int val){
        System.out.println("Short value is "+val);
    }
    void show(double val){
        System.out.println("Double val is: "+val);
    }
    public static void main(String[] args) {
        short val=30;
        double d=94964.6646f;
        new prog6().show(val);
        new prog6().show(d);

    }
}
