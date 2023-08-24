package Networking;
import java.io.*;
import java.net.*;

class ClientHandler extends Thread {
    private Socket clientSocket;
    PrintWriter out;
    public ClientHandler(Socket clientSocket) {
        this.clientSocket = clientSocket;
    }

    @Override
    public void run() {
        try {
            System.out.println("Client connected: " + clientSocket.getInetAddress());
            BufferedReader br = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            String msg = br.readLine();

            if (msg == null) return;

            if (msg.equals("GetTime")) {
                // Get current time and date
                String dateTime = java.time.LocalDateTime.now().toString();
                System.out.println("Client requested for date and time...");
                // Send the response to the client
                out = new PrintWriter(clientSocket.getOutputStream(), true);
                out.println("Server Date and Time: " + dateTime);
            }

            // Close the client socket
            else if (msg.equals("exit")) {
                clientSocket.close();
            }
            else{
                out=new PrintWriter(clientSocket.getOutputStream(),true);
                out.println("No");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class DayTimeServer {
    public static void main(String[] args) {
        int port = 12345; // Choose a suitable port number

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Server is listening on port " + port);

            while (true) {
                try {
                    Socket clientSocket = serverSocket.accept();
                    ClientHandler clientHandler = new ClientHandler(clientSocket);
                    clientHandler.start();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
