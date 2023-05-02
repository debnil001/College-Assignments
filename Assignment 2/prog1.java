import java.util.*;
class Bank{
    private final long customerId;
    private String name;
    private double loan_amount;
    private long phone_number;
    static long id=100;
    double credit_limit;
    {
        this.customerId=id;
        id++;
    }

    public Bank(String name, long phone_number,boolean is_special) {
        this.name = name;
        this.loan_amount = 0;
        this.phone_number = phone_number;
        if(is_special)
        this.credit_limit = 10000000;
        else
        this.credit_limit = 5000000;
    }
    public void changeName(String name) {
        this.name = name;
    }
    public void changePhoneNumber(long phone_number) {
        this.phone_number=phone_number;
    }
    public void showDetails(){
        System.out.println("----------------------------------------------------------------");
        System.out.println("A/C No. :"+this.customerId);
        System.out.println("Name: "+this.name);
        System.out.println("Phone Number: "+this.phone_number);
        System.out.println("Current Loan Amount: "+String.format("%.2f",this.loan_amount));
        System.out.println("Credit Limit Left: "+String.format("%.2f",this.credit_limit));
        System.out.println("----------------------------------------------------------------");
        
    }

    public void seek_loan(double amount) {
        if(amount>this.credit_limit){
            System.out.println("Loan can't be granted...loan amount is crossing credit limit");
        }
        else{
            this.credit_limit-=amount;
            System.out.println("Loan has been granted");
            this.loan_amount+=amount;
        }
    }

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter customer name::");
        String name=sc.nextLine();
        System.out.println("Enter customer phone number::");
        long ph=sc.nextLong();
        System.out.println("Is it a privileged customer(true/false):");
        boolean is_privileged=sc.nextBoolean();
        Bank customer1=new Bank(name,ph,is_privileged);
        System.out.println("Customer Registered");

        System.out.println("Enter loan amount you seek::");
        double loan=sc.nextDouble();
        customer1.seek_loan(loan);
        customer1.showDetails();
        System.out.println("Enter new name to change::");
        name=new Scanner(System.in).nextLine();
        customer1.changeName(name);
        System.out.println("Enter new phone number to change::");
        ph=new Scanner(System.in).nextLong();
        customer1.changePhoneNumber(ph);
        customer1.showDetails();


        System.out.println("Enter customer name::");
        name=new Scanner(System.in).nextLine();
        System.out.println("Enter customer phone number::");
        ph=new Scanner(System.in).nextLong();
        System.out.println("Is it a privileged customer(true/false):");
        is_privileged=new Scanner(System.in).nextBoolean();
        Bank customer2=new Bank(name,ph,is_privileged);
        System.out.println("Customer Registered");
        customer2.showDetails();
        sc.close();
    }
}