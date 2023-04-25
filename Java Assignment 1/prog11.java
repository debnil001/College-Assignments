import java.util.Scanner;
class prog11{
    static class Instructor{
        String name;
        long phone_no;
        public void setInfo(String n,long ph){
            this.name=n;
            this.phone_no=ph;
        }
        public void showInfo(){
            System.out.println("Instrutor name:"+this.name);
            System.out.println("Instrutor phone number:"+this.phone_no);
        }
    }
    static class TextBook{
        String title;
        String author_name;
        String publisher;

        public void setInfo(String t,String an,String p){
            this.title=t;
            this.author_name=an;
            this.publisher=p;
        }
        public void showInfo(){
            System.out.println("Text Book name:"+this.title);
            System.out.println("Text Book author name:"+this.author_name);
            System.out.println("Text Book publisher:"+this.publisher);
            System.out.println();
        }
    }
    static class Course{
        String name;
        Instructor i;
        TextBook t;
        public void setInfo(){
            System.out.println("Enter course name::");
            Scanner sc=new Scanner(System.in);
            this.name=sc.nextLine();
            System.out.println("Enter instructor name & phone number::");
            this.i=new Instructor();
            this.i.setInfo(sc.nextLine(),sc.nextLong());
            System.out.println("Enter text book name, author name and publisher::");
            this.t=new TextBook();
            this.t.setInfo(new Scanner(System.in).nextLine(),new Scanner(System.in).nextLine(),new Scanner(System.in).nextLine());
            System.out.println();
            sc.close();
        }
        public void showInfo(){
            System.out.println("Course name:"+this.name);
            this.i.showInfo();
            this.t.showInfo();
            System.out.println();
        }
    }
    public static void main(String[] args) {
        Course course=new Course();
        course.setInfo();
        course.showInfo();
    }
}