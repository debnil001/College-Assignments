package Networking;
import java.io.*;
import java.net.*;

class UDPClient {
    public static void main(String[] args) {
        final String serverAddress = "127.0.0.1"; // server's IP address
        final int serverPort = 12345; //server port

        try (DatagramSocket clientSocket = new DatagramSocket()) {//creating UDP connection
            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));

            System.out.print("Enter student name: ");
            String studentName = userInput.readLine();//getting the student name to search in server

            byte[] sendData = studentName.getBytes();//converting the data into bytes
            InetAddress serverIPAddress = InetAddress.getByName(serverAddress);
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, serverIPAddress, serverPort);
            clientSocket.send(sendPacket);//sending the data in form of packet through UDP connection

            byte[] receiveData = new byte[1024];
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            clientSocket.receive(receivePacket);//response received from client

            String response = new String(receivePacket.getData(), 0, receivePacket.getLength());
            System.out.println("Server response: " + response);//printing the response
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
