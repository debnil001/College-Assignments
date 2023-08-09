import java.io.*;
import java.net.*;

public class Server {
    private static ServerSocket serverSocket;

    public static void main(String[] args) throws IOException {
        serverSocket = new ServerSocket(12345);
        System.out.println("Server started to listen...");

        while (true) {
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected: " + clientSocket);

            // Create a new thread to handle every new client
            Thread thread = new Thread(new ClientHandler(clientSocket));
            thread.start();
        }
    }

    public static void closeServer() throws IOException {
        serverSocket.close();
        System.out.println("Server closed.");
    }
}

class ClientHandler implements Runnable {
    private final Socket clientSocket;
    private PrintWriter out;
    private BufferedReader in;

    public ClientHandler(Socket clientSocket) {
        this.clientSocket = clientSocket;
    }

    @Override
    public void run() {
        try {
            out = new PrintWriter(clientSocket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

            // Start a separate thread to read client's messages
            Thread readThread = new Thread(() -> {
                try {
                    String clientMessage;
                    while ((clientMessage = in.readLine()) != null) {
                        System.out.println("Client: " + clientMessage);
                        if (clientMessage.equalsIgnoreCase("bye")) {
                            System.exit(0);
                        }
                    }
                } catch (IOException e) {
                }
            });
            readThread.start();

            // Read messages from server console and send to client
            BufferedReader serverReader = new BufferedReader(new InputStreamReader(System.in));
            String serverMessage;
            while ((serverMessage = serverReader.readLine()) != null) {
                out.println("Server: " + serverMessage);
            }

            // Clean up
            out.close();
            in.close();
            clientSocket.close();
        } catch (IOException e) {
        }
    }
}
