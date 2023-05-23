import java.util.Scanner;

class Person{
    String name;
    String premises_no;
    String street;
    String city;
    String pin;
    String state;
    long phoneNumber;
    byte age;
    String email_id;
    public Person(){
    }
    public Person(String name, String premises_no, String street, String city,String pin, String state, long phoneNumber, byte age, String email_id){
        this.name = name;
        this.premises_no = premises_no;
        this.street = street;
        this.city = city;
        this.pin = pin;
        this.state = state;
        this.phoneNumber = phoneNumber;
        this.age = age;
        this.email_id = email_id;
    }
    public void showDetails(){
        System.out.println("----------------------------------------------------------------");

        System.out.println("Showing Person details::");
        System.out.println("Name: "+name);
        System.out.println("Premises No: "+premises_no);
        System.out.println("Street: "+street);
        System.out.println("City: "+city);
        System.out.println("Pin: "+pin);
        System.out.println("State: "+state);
        System.out.println("Phone Number: "+phoneNumber);
        System.out.println("Age: "+age);
        System.out.println("Email Id: "+email_id);
        System.out.println("----------------------------------------------------------------");
    }
    public void setDetails(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Name: ");
        this.name = sc.nextLine();
        System.out.println("Enter Premises No: ");
        this.premises_no = sc.nextLine();
        System.out.println("Enter Street: ");
        this.street = sc.nextLine();
        System.out.println("Enter City: ");
        this.city = sc.nextLine();
        System.out.println("Enter Pin: ");
        this.pin = sc.nextLine();
        System.out.println("Enter State: ");
        this.state = sc.nextLine();
        System.out.println("Enter Phone Number: ");
        this.phoneNumber = sc.nextLong();
        System.out.println("Enter Age: ");
        this.age = sc.nextByte();
        System.out.println("Enter Email Id: ");
        this.email_id = new Scanner(System.in).nextLine();
    }
    public void changePremisesNo(String premises_no){
        this.premises_no = premises_no;
    }
    public void changeStreet(String street){
        this.street = street;
    }
    public void changeCity(String city){
        this.city = city;
    }
    public void changePin(String pin){
        this.pin = pin;
    }
    public void changeState(String state){
        this.state = state;
    }
}
class Student extends Person{
    String course;
    long roll;
    public Student(){

    }
    public Student(String name, String premises_no, String street, String city,
    String pin, String state, long phoneNumber, byte age, 
    String email_id, String course, long roll){
        super(name, premises_no, street, city,pin, state, phoneNumber, age, email_id);
        this.course = course;
        this.roll = roll;
    }
    public void showDetails(){
        System.out.println("----------------------------------------------------------------");

        System.out.println("Showing Student details::");
        super.showDetails();
        System.out.println("Course: "+course);
        System.out.println("Roll: "+roll);
        System.out.println("----------------------------------------------------------------");
    }

    public void changeCourse(String course){
        this.course = course;
    }
    public void setDetails(){
        super.setDetails();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Course: ");
        this.course = sc.nextLine();
        System.out.println("Enter Roll: ");
        this.roll = sc.nextLong();
    }
}
class Faculty extends Person{
    String department;
    long eid;
    String specialisation;
    public Faculty(){

    }
    public Faculty(String name, String premises_no, String street, String city,
    String pin, String state, long phoneNumber, byte age, 
    String email_id, String department, long eid, String specialisation){
        super(name, premises_no, street, city,pin, state, phoneNumber, age, email_id);
        this.department = department;
        this.eid = eid;
        this.specialisation = specialisation;
    }
    public void showDetails(){
        System.out.println("----------------------------------------------------------------");

        System.out.println("Showing Faculty details::");
        super.showDetails();
        System.out.println("Department: "+department);
        System.out.println("Eid: "+eid);
        System.out.println("Specialisation: "+specialisation);
        System.out.println("----------------------------------------------------------------");
    }

    public void setDetails(){
        super.setDetails();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Department: ");
        this.department = sc.nextLine();
        System.out.println("Enter Eid: ");
        this.eid = sc.nextLong();
        System.out.println("Enter Specialisation: ");
        this.specialisation = sc.nextLine();
    }
}
class Main{
    public static void main(String[] args) {
        Person person=new Person();        
        person.setDetails();
        person.showDetails();
        Student student=new Student();
        student.setDetails();
        student.showDetails();
        Faculty faculty=new Faculty();
        faculty.setDetails();
        faculty.showDetails();
    }
}
