package com.mycompany.javasocket;

//import java.io.*;
//import java.net.*;
//
//public class Server {
//    public static void main(String[] args) throws IOException {
//        ServerSocket serverSocket = new ServerSocket(12345);
//        System.out.println("Server started to listen...");
//
//        while (true) {
//            Socket clientSocket = serverSocket.accept();
//            System.out.println("Client connected: " + clientSocket);
//
//            // Create a new thread to handle every new client
//            Thread thread = new Thread(new ClientHandler(clientSocket));
//            thread.start();
//        }
//    }
//}
//
//class ClientHandler implements Runnable {
//    private final Socket clientSocket;
//    private PrintWriter out;
//    private BufferedReader in;
//
//    public ClientHandler(Socket clientSocket) {
//        this.clientSocket = clientSocket;
//    }
//
//    @Override
//    public void run() {
//        try {
//            out = new PrintWriter(clientSocket.getOutputStream(), true);
//            in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
//
//            // Start a separate thread to read client's messages
//            Thread readThread = new Thread(() -> {
//                try {
//                    String clientMessage;
//                    while ((clientMessage = in.readLine()) != null) {
//                        System.out.println("Client: " + clientMessage);
//                    }
//                } catch (IOException e) {
//                }
//            });
//            readThread.start();
//
//            // Read messages from server console and send to client
//            BufferedReader serverReader = new BufferedReader(new InputStreamReader(System.in));
//            String serverMessage;
//            while ((serverMessage = serverReader.readLine()) != null) {
//                out.println("Server: " + serverMessage);
//            }
//
//            // Clean up
//            out.close();
//            in.close();
//            clientSocket.close();
//            System.out.println("Server stopped");
//        }
//        catch (IOException e) {
//        }
//    }
//}
import java.io.*;  
import java.net.ServerSocket;  
import java.net.Socket;  
  
public class Server {  
  public static void main(String[] args) throws IOException {   
      Socket socket ;  
      InputStreamReader inputStreamReader ;  
      OutputStreamWriter outputStreamWriter ;  
      BufferedReader bufferedReader ;  
      BufferedWriter bufferedWriter ;  
      ServerSocket serversocket ;  
  
      serversocket = new ServerSocket(5000);  
  
      while (true) {  
          try {  
         
              socket = serversocket.accept();  
      
              inputStreamReader = new InputStreamReader(socket.getInputStream());  
              outputStreamWriter = new OutputStreamWriter(socket.getOutputStream());  
              bufferedReader = new BufferedReader(inputStreamReader);  
              bufferedWriter = new BufferedWriter(outputStreamWriter);  

              while (true){  
                  String msgFromClient = bufferedReader.readLine();  
                  System.out.println("Client: " + msgFromClient);   
                  bufferedWriter.write(" MSG Received"); 
                  bufferedWriter.newLine();  
                  bufferedWriter.flush(); 

                  if (msgFromClient.equalsIgnoreCase("BYE"))  
                  break;  
              }  
              socket.close();  
              inputStreamReader.close();  
              outputStreamWriter.close();  
              bufferedReader.close();  
              bufferedWriter.close();  

          } catch (IOException e) {  
              e.printStackTrace();  
          }  
        }  
    }  
}