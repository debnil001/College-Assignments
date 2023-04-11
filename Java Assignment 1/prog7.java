import java.util.Scanner;

// 7. Design and implement Student class with roll, name and score as attributes. It will have methods to
// set attributes (attribute values passed as arguments), display the attributes, copy (that copies the
// content of invoking object to another object passed as argument). Verify that methods are working
// properly.
public class prog7 {
    static class Student{
        int roll;
        String name;
        int score;

        public void setAttributes(int r,String n,int s){
            this.roll=r;
            this.name=n;
            this.score=s;
        }
        public void showAttributes(){
            System.out.println("Roll: "+this.roll+"\nName: "+this.name+"\nScore: "+this.score);
        }
        public void copyObject(Student other){
            other.roll=this.roll;
            other.name=this.name;
            other.score=this.score;
        }
    }
    public static void main(String[] args) {
        Student obj=new Student();
        System.out.println("Enter Student details::");
        obj.setAttributes(new Scanner(System.in).nextInt(),new Scanner(System.in).nextLine(),new Scanner(System.in).nextInt());
        obj.showAttributes();
        Student another=new Student();
        obj.copyObject(another);
        System.out.println("Copied object details::");
        another.showAttributes();
    }
}
