#TCP-server
import socket
import select
import sys
from queue import Queue, Empty as EmptyQueueError
import json
prints = True


server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("127.0.0.1", 7777))
server.listen(5) 


inputs, outputs, queues = [server], [], {}
connections={}
readers, writers, erroring = None, None, None
#print
def display(*argv):
    args = list(arg for arg in argv)
    if prints == True:
        print(*args)


#error
def erroring_sockets():
    
    for error_socket in erroring:
        display("Handling error state for", error_socket.getpeername())
        inputs.remove(error_socket)
        if error_socket in outputs:
            outputs.remove(error_socket)
        error_socket.close()
        del queues[error_socket]
#write
def writing_sockets():
   
    for write_socket in writers:
        try:
            nextMessage = queues[write_socket].get_nowait()
        except EmptyQueueError:
            display("Output queue for", write_socket.getpeername(), "is empty")
            outputs.remove(write_socket)
        else:
            display("Sending \"", nextMessage, "\" to ", write_socket.getpeername())
            write_socket.send(nextMessage.encode())
#new_conn
#here
def rec_new_connection(server):
    
    connection, client_address = server.accept()
    display("New connection from", client_address)
    inputs.append(connection)
    queues[connection] = Queue()

    #here
    list_data = json.dumps(list(connections.values()))
    connections[connection] = client_address
    size =len(list_data)
    connection.send(str(size).encode())
    connection.recv(1)
    connection.send(list_data.encode())#lista cu toti
    connection.recv(1)# asta am adaugat
    connection.send(json.dumps(client_address).encode())#doar el


    new_conection  ={"type": 1, "address":client_address}
    for queue in queues:
        if queue != connection:
            if queue not in outputs:
                outputs.append(queue)
            queues[queue].put(json.dumps(new_conection))
            #we anuntam pe toti ceilalti ca cineva s-a conectat

#close
#here

def close_connection(read_socket):
    
    display("Closing", read_socket.getpeername(), "after reading no data")
    if read_socket in outputs:
        outputs.remove(read_socket)
    inputs.remove(read_socket)
    read_socket.close()
    close_con={"type": 0, "address": connections[read_socket]}
    for queue in queues:
        if queue != read_socket:
            if  queue not in outputs:
                outputs.append(queue)
            queues[queue].put(json.dumps(close_con))
            #anuntam ca cienva s-a deconectat
    del queues[read_socket]
    del connections[read_socket]

#rec-data
def receive_data(read_socket, data):
    
    
    display("Received", data, "from", read_socket.getpeername())
    #send- in select
    if read_socket not in outputs:
        outputs.append(read_socket)
    for Socket in queues:
        queues[Socket].put(data)
        if Socket not in outputs:
            outputs.append(Socket)
    

#eead
def reading_sockets():
   
    for read_socket in readers:
        if read_socket is server:#if it's a new connection
            rec_new_connection(read_socket)
        else:
            data = read_socket.recv(1024).decode() # interesting number ?
            if data:
                receive_data(read_socket, data)#if it has data to give
            else:
                close_connection(read_socket)#no data 


while inputs:
    display("Waiting for the next event...")
    readers, writers, erroring = select.select(inputs, outputs, queues)
    reading_sockets()
    writing_sockets()
    erroring_sockets()
    
    
    