public class prog9 {
    static class BankAcct{
        long accountNo;
        double balance;
        private static float interest;
        public static void setROI(){
            interest=6.5f;
        }
        public static void changeROI(float i){
            interest=i;
        }
        public static void showROI(){
            System.out.println("The rate of interest is:"+interest);
        }
        public double getBalance(){
            return balance;
        }
        public void getInterest(){
            System.out.println("Interest for 1 year on balance "+this.balance+" is "+balance*interest/100);
        }
        public BankAcct(long acc,double balance){
            this.accountNo=acc;
            this.balance=balance;
        }
    }
    public static void main(String[] args) {
        BankAcct.setROI();
        BankAcct user1=new BankAcct(545485749652L,96600.54);
        System.out.print("User 1 balance is::"+user1.getBalance());
        // System.out.println("User 1 interest is::"+user1.getInterest());
        user1.getInterest();
    }    
}
