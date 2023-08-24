package Networking;
import java.io.*;
import java.net.*;
import java.util.*;
class Server {
    //calculate function for the expression evaluation
    public static int calculate(String s) {
        int len=s.length();
        int res=0;
        char sign='+';
        Stack<Integer> st=new Stack<>();
        int i;
        for(i=0;i<len;i++){
            char c=s.charAt(i);
            if(Character.isDigit(c)){
                int val=c-48;
                while(i+1<len && Character.isDigit(s.charAt(i+1))){
                    val=val*10+(s.charAt(i+1)-48);
                    i++;
                }
                if(sign=='+'){
                    st.push(val);
                }
                else if(sign=='-'){
                    st.push(-val);
                }
                else if(sign=='*'){
                    res=st.pop();
                    st.push(val*res);
                }
                else if(sign=='/'){
                    res=st.pop();
                    st.push(res/val);
                }
            }
            else if(c!=' '){//must be sign
                if(i>0 && s.charAt(i-1)!=' ' && !Character.isDigit(s.charAt(i-1))){
                    System.out.println("Invalid Expression!");
                    break;
                }
                sign=c;
            }
        }
        if(i!=len)  return Integer.MAX_VALUE;
        res=0;
        while(!st.isEmpty()){
            res+=st.pop();
        }
        return res;
    }
    public static void main(String[] args) throws IOException{
        ServerSocket ss=new ServerSocket(50000);//server is initialized on port 50000 with default loop back address
        System.out.println("Server started...ready to accept client");
        PrintWriter out=null;//to send output to the client side
        BufferedReader in=null;//to get input from the client side
        while(true){
            Socket client=ss.accept();//ready to listen to the client
            System.out.println("Client connected"+client);//new client has arrived
            out=new PrintWriter(client.getOutputStream(),true);//setting output stream with the client
            in=new BufferedReader(new InputStreamReader(client.getInputStream()));//setting input stream with the client

            while(true){// as long as client sends expression, server will evaluate until exit is sent
                String exp=in.readLine();//reading the expression from the client side
                System.out.println("Client: "+exp);//printing the current expression on the console
                if(exp.equals("exit")) break;//if exit is sent
                int res=Server.calculate(exp);//evaluating the result for the given expression
                if(res==Integer.MAX_VALUE)
                    out.println("Invalid Expression!!! Please enter valid expression");
                else
                    out.println("Evaluated result from server "+res);//sending the result back to the client
            }
            //freeing up all the resources
            client.close();
            out.close();
            in.close();
        }
    }
}
