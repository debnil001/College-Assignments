from scapy.all import *

# Function to send TCP SYN segment and check for SYN+ACK response
def scan_port(ip, port):
    src_port = RandShort()  # Generate a random source port
    tcp = IP(dst=ip)/TCP(sport=src_port, dport=port, flags="S")

    response = sr1(tcp, timeout=2, verbose=False)
    if response and response.haslayer(TCP) and response[TCP].flags == 0x12:
        print(f"Port {port} is open.")
    else:
        print(f"Port {port} is closed.")

# Get a host IP address from the user
host_ip = input("Enter the host IP address: ")

# Iterate through ports 0 to 1023 and send TCP SYN segments
for port in range(1024):
    scan_port(host_ip, port)
