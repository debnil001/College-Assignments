package Networking;
import java.io.*;
import java.net.*;
import java.util.*;


class DayTimeClient {
    public static void main(String[] args) {
        String serverAddress = "localhost"; // Change to the server's IP address if needed
        int serverPort = 12345; // Same port as the server
        while(true){
            try (Socket socket = new Socket(serverAddress, serverPort)) {
                // Create input and output streams
                System.out.println("Enter MSG to get date & time::");
                String msg=new Scanner(System.in).nextLine();
                if(msg.equals("exit"))  break;
                BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

                // Send a request to the server
                PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
                out.println(msg);

                // Receive and print the server's response
                String response = in.readLine();
                if(response.equals("No"))
                    System.out.println("Enter valid command!!!");
                else
                    System.out.println("Server Response: " + response);

            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
