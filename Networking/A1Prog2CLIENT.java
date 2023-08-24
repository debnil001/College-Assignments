package Networking;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class A1Prog2CLIENT {
    public static void main(String[] args) throws IOException {
        Socket sc=new Socket("localhost",50000);//creating connection to the server's port and address
        PrintWriter out=null;
        BufferedReader in=null;
        while(true){
            out=new PrintWriter(sc.getOutputStream(),true);// output stream object for getting output from server
            in=new BufferedReader(new InputStreamReader(sc.getInputStream()));// input stream object for getting input from server
            Scanner console=new Scanner(System.in);
            System.out.println("Enter an arithmetic expression:");
            String exp=console.next();//reading expression from console of the client
            out.println(exp);//sending to the server in form of output stream

            System.out.println(in.readLine());//getting the result and printing on the screen

            if(exp.equals("exit"))  break;//if the console message is exit then exit from the program
        }
    }
}
