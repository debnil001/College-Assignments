# from scapy.all import *
# import sys
# from mac_vendor_lookup import MacLookup
# from prettytable import PrettyTable

# class NetworkScanner:
#     def __init__(self,hosts):
#         self.alive={}
#         for host in hosts:
#             self.host = host
#             self.create_packet()
#             self.send_packet()
#             self.get_alive()
#             self.print_alive()

#     def create_packet(self):
#         layer2 = Ether(dst="ff:ff:ff:ff:ff:ff")
#         layer3 = ARP(pdst=self.host)
#         packet=layer2 / layer3
#         self.packet=packet
    
#     def send_packet(self):
#         ans,unans=srp(self.packet,timeout=1,verbose=False)

#         if ans:
#             self.ans=ans
#         else:
#             print("No Host is up")
#             sys.exit()
#     def get_alive(self):
#         for sent,recv in self.ans:
#             self.alive[recv.psrc] = recv.hwsrc
#     def print_alive(self):
#         table=PrettyTable(["IP","MAC","VENDOR"])
#         for ip,mac in self.alive.items():
#             try:
#                 table.add_row([ip,mac,MacLookUp().lookup(mac)])
#             except:
#                 table.add_row([ip,mac,"Unknown"])
#         print(table)

# print("Enter hosts")
# hosts=[h for h in input().split(" ")]
# NetworkScanner(hosts)

from scapy.all import ARP, sniff
import subprocess

def get_mac(ip):
    try:
        result = subprocess.check_output(['arp', '-a', ip]).decode('utf-8')
        mac = result.split()[10]
        return mac
    except Exception as e:
        print(f"Error: {str(e)}")
        return None
# 1 broadcast packet
# 2 reply packets
def arp_poison_detection(packet): #arp packet
    if ARP in packet and packet[ARP].op == 2:  # Check if it's an ARP reply
        sender_ip = packet[ARP].psrc
        sender_mac = packet[ARP].hwsrc

        known_mac = get_mac(sender_ip)

        if known_mac is not None and sender_mac != known_mac:
            print(f"Possible ARP Poisoning Detected! Sender IP: {sender_ip}, Sender MAC: {sender_mac}, Known MAC: {known_mac}")


print("Detecting ARP Poisoning Attacks...")
try:
    sniff(filter="arp", prn=arp_poison_detection, store=0)
except KeyboardInterrupt:
        print("ARP Poison Detection Stopped.")
