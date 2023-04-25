public class prog8 {
    static class Student{
        int roll;
        String name;
        int score;
        public Student(){
            System.out.println("Default Constructor Called");
        }
        Student(int roll){
            this.roll=roll;
        }
         Student(int r,String name){
            this.roll=r;
            this.name=name;
        }
         Student(int r,String name,int s){
            this.roll=r;
            this.name=name;
            this.score=s;
        }
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
         Student(Student another){
            this.roll=another.roll;
            this.name=another.name;
            this.score=another.score;
        }
    }
    public static void main(String[] args) {
        // System.out.println();
        Student s2=new Student();
        Student s0=new Student(10,"Debnil",88);
        s0.copyObject(s2);
        s2.showAttributes();
        // Student s1=new Student();
        // Student s3=new Student(10,"Debnil",88);
        // Student s4=new Student(s3);
        // s4.name="Sarkar";
        // s4.showAttributes();
        // s3.showAttributes();
    }
}

