import java.util.Scanner;

class prog10 {
    static class Metric{
        public  static float KilometerToMile(float km){
            return km*0.621371f;
        }
        public static float MileToKilometer(float mile){
            return mile*1.60934F;
        }
    }
    public static void main(String[]args){
        System.out.println("Enter distance in KM::");
        Scanner sc=new Scanner(System.in);
        System.out.println("Distance in Mile::"+Metric.KilometerToMile(sc.nextFloat()));
        System.out.println("Enter distance in Mile::");
        System.out.println("Distance in Kilometer"+Metric.MileToKilometer(sc.nextFloat()));
    }
}
