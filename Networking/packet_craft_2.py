import ipaddress
from scapy.all import *

# Function to send ICMP echo request and receive echo reply
def send_ping(ip):
    icmp = IP(dst=str(ip))/ICMP()
    reply = sr1(icmp, timeout=2,verbose=False)
    if reply:
        print(f"Host {ip} is online.")
    # else:
    #     print(f"Host {ip} is offline.")

# Get a network address from the user
network_address = input("Enter a network address (e.g., 192.168.1.0/24): ")

try:
    network = ipaddress.IPv4Network(network_address, strict=False)
except ValueError:
    print("Invalid network address.")
    exit()

# Iterate through all host IP addresses in the network
for ip in network.hosts():
    send_ping(ip)