package Networking;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class A1Prog2CLIENT {
    public static void main(String[] args) throws IOException {
        Socket sc=new Socket("localhost",50000);
        PrintWriter out=null;
        BufferedReader in=null;
        while(true){
            out=new PrintWriter(sc.getOutputStream(),true);
            in=new BufferedReader(new InputStreamReader(sc.getInputStream()));
            Scanner console=new Scanner(System.in);
            System.out.println("Enter an arithmetic expression:");
            String exp=console.next();
            out.println(exp);

            System.out.println("Response from server::"+in.readLine());

            if(exp.equals("exit"))  break;
        }
    }
}
