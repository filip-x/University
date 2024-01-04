#TCP
'''
import socket
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(("0.0.0.0",8888))
s.listen(5)
ip,port=s.accept()
msg=ip.recv(10)
print(msg.decode())
send_msg="Salut"
ip.send(send_msg.encode())
ip.close()
'''

''' EX1
import socket
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(("192.168.0.178",7777))
s.listen(5)

while True:
    a=[]
    sum=0
    ip,port=s.accept()
    msg_client=ip.recv(20)
    print(msg_client.decode())
    ip.send("-".encode())
    len_vector= int((ip.recv(10)).decode())

    print(len_vector)
    while len_vector!=0:
        ip.send("-".encode())
        a.append(int(ip.recv(1).decode()))
        len_vector-=1
    print(a)
    for i in range(0,len(a)):
        sum+=a[i]
    ip.send(str(sum).encode())
    ip.close()
    
'''
#8.   The client sends to the server two arrays of integers. The server returns an arrays containing the common numbers found in both arrays.



import socket
a,b = [],[]
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(("192.168.0.178",7777))
s.listen(5)
ip,port = s.accept()
initial_msg = ip.recv(20)
ip.send("-".encode())
print(initial_msg.decode())
len_first = int(ip.recv(10).decode())
ip.send("-".encode())
len_second = int(ip.recv(10).decode())


while len_first !=0:
    ip.send("-".encode())
    a.append(int(ip.recv(10).decode()))
    len_first-=1

while len_second !=0:
    ip.send("-".encode())
    b.append(int(ip.recv(10).decode()))
    len_second-=1

list_to_send=list(filter(lambda x: x in b,a))


ip.send((' '.join(str(elem) for elem in list_to_send)).encode())


print(a)
print("\n")
print(b)












