import socket
Socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
Socket.bind(("192.168.0.178", 9999))
Socket.listen(5)

ClientSocket, Address = Socket.accept()
print("User connected!")

msg = "Hello there!!"
ClientSocket.send(msg.encode())

b = ClientSocket.recv(10)
print(b.decode())

ClientSocket.close()
Socket.close()