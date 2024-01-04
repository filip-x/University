import socket
import time

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
server.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
server.settimeout(0.2)
server.bind(("192.168.0.102", 44444))
message = "your very important message".encode()
while True:
    server.sendto(message, ('<broadcast>', 37021))
    print("message sent!")
    time.sleep(1)