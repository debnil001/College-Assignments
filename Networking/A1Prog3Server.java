package Networking;
import java.io.*;
import java.net.*;

class UDPClientHandler extends Thread {
    private DatagramSocket serverSocket;
    private DatagramPacket receivePacket;

    public UDPClientHandler(DatagramSocket serverSocket, DatagramPacket receivePacket) {
        this.serverSocket = serverSocket;
        this.receivePacket = receivePacket;
    }

    @Override
    public void run() {
        try {
            System.out.println("Client requested for student info...");
            String studentName = new String(receivePacket.getData(), 0, receivePacket.getLength());

            String studentInfoFile = "C:\\Users\\HP\\Documents\\NetBeansProjects\\JavaSocket\\src\\main\\java\\Student.txt";
            String response = findStudentAddress(studentName, studentInfoFile);

            InetAddress clientAddress = receivePacket.getAddress();
            int clientPort = receivePacket.getPort();

            byte[] sendData = response.getBytes();
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, clientAddress, clientPort);
            serverSocket.send(sendPacket);
            System.out.println("Info sent to the client");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String findStudentAddress(String studentName, String studentInfoFile) {
        try (BufferedReader br = new BufferedReader(new FileReader(studentInfoFile))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(":");
                if (parts.length == 2 && parts[0].trim().equalsIgnoreCase(studentName)) {
                    return "OK\n" + parts[1].trim() + "\n";
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return "ERROR\nStudent not found.\n";
    }
}

class UDPServer {
    public static void main(String[] args) {
        final int serverPort = 12345;

        try (DatagramSocket serverSocket = new DatagramSocket(serverPort)) {
            System.out.println("Server listening on port " + serverPort);

            byte[] receiveData = new byte[1024];

            while (true) {
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                serverSocket.receive(receivePacket);

                UDPClientHandler clientHandler = new UDPClientHandler(serverSocket, receivePacket);
                clientHandler.start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
