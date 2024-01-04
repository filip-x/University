import socket
import threading
import json

#TCP-client

adresa_server = ("127.0.0.1",7777)
tcp_server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
print("Connected to the server", adresa_server)
tcp_server.connect(adresa_server)

#UDP client
import socket
udp_client=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)



length = tcp_server.recv(100).decode()#size-ul de dincolo
tcp_server.send(str("-").encode())#confirmarea 
data = tcp_server.recv(int(length)).decode()# lista cu participantii
conected_people = (json.loads(data)) # o refac in lista 
tcp_server.send("-".encode()) #confirmarea
data = tcp_server.recv(100)# primesc adresa celui conectat adcia el insusi
print(data.decode())# print datele omului 
address = tuple(json.loads(data.decode()))# conversie spre touple ca primesc si port si ip


udp_client.bind(address) # fac conexiunea udp pt ca acum stiu adresa lui 

cont = True # continue 

def connect_thread():
    while cont:
        data = tcp_server.recv(100).decode()
        if data:
            print(data)
            conn_info = json.loads(data)
            if conn_info["type"] ==1:
                conected_people.append(conn_info["address"])# append in lista 
            elif conn_info["type"] == 0:
                conected_people.remove(conn_info["address"])# REMOVE DIN LISTA
            print(conected_people)

def wait_for_mess():
    while cont:
        size, address = udp_client.recvfrom(32)
        if size and size.decode() != "QUIT":# size == quit sau ii gol atunci nu intra in if 
            size = int(size.decode())# preia size 
            msg,address = udp_client.recvfrom(size)# mseajul  
            print(msg.decode()+str(address))# si da print la mesaj la toti 





saving_thread  = threading.Thread(target=connect_thread)# create thread aici am uitat
saving_thread.start()# start thread aici am uitat 

saving_thread2 = threading.Thread(target = wait_for_mess)
saving_thread2.start()


while True:
    msg = input("Write: ")
    if msg == "QUIT":
        break
    else:
        for member in conected_people:
            size = len(msg)
            udp_client.sendto(str(size).encode(),tuple(member))# aici trimit size-ul la  mesaj scris de client
            udp_client.sendto(msg.encode(),tuple(member))# aici trimit mesajul 
    
print("CLose")
cont = False
tcp_server.shutdown(0)
udp_client.sendto("QUIT".encode(),address)
tcp_server.close()
udp_client.close()
saving_thread.join()
saving_thread2.join()