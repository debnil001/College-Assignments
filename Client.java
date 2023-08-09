import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) throws IOException {
        String serverHost = "localhost";
        int serverPort = 12345;

        try (Socket socket = new Socket(serverHost, serverPort)) {
            System.out.println("Type something...");
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            // Thread for writing message to the server
            Thread userInputThread = new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        BufferedReader clientReader = new BufferedReader(new InputStreamReader(System.in));
                        String clientMessage;
                        while ((clientMessage = clientReader.readLine()) != null) {
                            out.println(clientMessage);
                            if (clientMessage.equalsIgnoreCase("bye")) {
                                System.exit(0);
                            }
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            });

            // Thread for receiving message from the server
            Thread serverResponseThread = new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        String serverMessage;
                        while ((serverMessage = in.readLine()) != null) {
                            System.out.println("Server MSG -> " + serverMessage);
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            });

            userInputThread.start();
            serverResponseThread.start();

            // Wait for both threads to finish
            try {
                userInputThread.join();
                serverResponseThread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
