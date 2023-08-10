package com.mycompany.javasocket;
//import java.io.*;
//import java.net.*;
//
//public class Client {
//    public static void main(String[] args) throws IOException {
//        String serverHost = "localhost";
//        int serverPort = 12345;
//
//        try (Socket socket = new Socket(serverHost, serverPort)) {
//            System.out.println("Type something...");
//            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
//            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
//
//            //thread 1 for writing message to the server
//            Thread userInputThread = new Thread(new Runnable() {
//                @Override
//                public void run() {
//                    try {
//                        BufferedReader clientReader = new BufferedReader(new InputStreamReader(System.in));
//                        String clientMessage;
//                        while ((clientMessage = clientReader.readLine()) != null) {
//                            out.println(clientMessage);
//                        }
//                    } catch (IOException e) {
//                        e.printStackTrace();
//                    }
//                }
//            });
//            //thread 2 for receiving message from the server
//            Thread serverResponseThread = new Thread(new Runnable() {
//                @Override
//                public void run() {
//                    try {
//                        String serverMessage;
//                        while ((serverMessage = in.readLine()) != null) {
//                            System.out.println("Server MSG->"+serverMessage);
//                        }
//                    } catch (IOException e) {
//                        e.printStackTrace();
//                    }
//                }
//            });
//
//            userInputThread.start();
//            serverResponseThread.start();
//
//            // Wait for both threads to finish
//            try {
//                userInputThread.join();
//                serverResponseThread.join();
//            } catch (InterruptedException e) {
//                e.printStackTrace();
//            }
//        }
//    }
//}

//import java.io.*;  
//import java.net.Socket;  
//import java.util.Scanner;  
//  
//public class client {  
//
//    public static void main(String[] args) {  
//        Socket socket = null;  
//        InputStreamReader inputStreamReader = null;  
//        OutputStreamWriter outputStreamWriter = null;  
//        BufferedReader bufferedReader = null;  
//        BufferedWriter bufferedWriter = null;  
//        
//        try {  
//            socket = new Socket("localhost", 5000);  
//            inputStreamReader = new InputStreamReader(socket.getInputStream());  
//            outputStreamWriter = new OutputStreamWriter(socket.getOutputStream());  
//            bufferedReader = new BufferedReader(inputStreamReader);  
//            bufferedWriter = new BufferedWriter(outputStreamWriter);  
//
//            Scanner scanner = new Scanner(System.in);  
//            while (true){  
//                String msgToSend = scanner.nextLine();  
//                bufferedWriter.write(msgToSend);  
//                bufferedWriter.newLine();  
//                bufferedWriter.flush();  
//                
//                System.out.println("Server: " + bufferedReader.readLine());  //printing the server message
//                
//                if (msgToSend.equalsIgnoreCase("BYE"))  
//                    break;  
//            }  
//        } catch (IOException e) {  
//            e.printStackTrace();  
//        } finally {  
//             try {  
//                  if (socket != null)  
//                  socket.close();  
//                  if (inputStreamReader != null)  
//                    inputStreamReader.close();  
//                  if (outputStreamWriter != null)  
//                  outputStreamWriter.close();  
//                  if (bufferedReader != null)  
//                  bufferedReader.close();  
//                  if (bufferedWriter != null)  
//                  bufferedWriter.close();  
//             } catch (IOException e) {  
//            e.printStackTrace();  
//          }  
//       }  
//    }  
//}