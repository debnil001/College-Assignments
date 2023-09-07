import ipaddress
from scapy.all import IP, ICMP, sr1

# Get the network address from the user
network_address = input("Enter the network address (e.g., 192.168.1.0/24): ")

# Function to send an ICMP echo request and receive the response
def send_icmp_echo_request(host, timeout=1):
    try:
        packet = IP(dst=str(host)) / ICMP()
        response = sr1(packet, timeout=timeout, verbose=False)
        if response:
            return host
        return None
    except Exception as e:
        return None

# Iterate through all IP addresses in the network and send ICMP echo requests
reachable_hosts = []
for ip in ipaddress.IPv4Network(network_address, strict=False):
    print(ip)
    reachable_host = send_icmp_echo_request(ip)
    if reachable_host:
        reachable_hosts.append(reachable_host)

# Display reachable hosts
if reachable_hosts:
    print("Reachable Hosts:")
    for host in reachable_hosts:
        print(host)
else:
    print("No reachable hosts found.")
