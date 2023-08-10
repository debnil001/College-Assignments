package Networking;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

class UDPStudentClient {
    public static void main(String[] args) {
        final String serverAddress = "localhost";
        final int serverPort = 9876;

        try {
            DatagramSocket clientSocket = new DatagramSocket();
            InetAddress serverInetAddress = InetAddress.getByName(serverAddress);

            Scanner scanner = new Scanner(System.in);

            while (true) {
                System.out.print("Enter student name (or 'exit' to quit): ");
                String studentName = scanner.nextLine();

                if (studentName.equalsIgnoreCase("exit")) {
                    break;
                }

                byte[] sendData = studentName.getBytes();
                DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, serverInetAddress, serverPort);
                clientSocket.send(sendPacket);

                byte[] receiveData = new byte[1024];
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                clientSocket.receive(receivePacket);

                String serverResponse = new String(receivePacket.getData(), 0, receivePacket.getLength());
                System.out.println("Server response: " + serverResponse);
            }

            clientSocket.close();
            System.out.println("Client has been closed.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

