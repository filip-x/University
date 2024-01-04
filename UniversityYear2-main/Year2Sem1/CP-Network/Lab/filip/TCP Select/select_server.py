import socket
import select
import sys
from queue import Queue, Empty as EmptyQueueError

debug = True
# setting up the server socket...
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("", 1337))
server.listen(5) # 5 connections max ?

# setting up the select lists...
inputs, outputs, queues = [server], [], {}
readers, writers, erroring = None, None, None

def display(*argv):
    args = list(arg for arg in argv)
    if debug == True:
        print(*args)
# setting up different functions to deal with
# each select list...
def handleErroringSockets():
    # We handle sockets that are in an error state here
    # we stop listening on that connection and we remove
    #  it's message from the queue
    for eSocket in erroring:
        display("Handling error state for", eSocket.getpeername())
        inputs.remove(eSocket)
        if eSocket in outputs:
            outputs.remove(eSocket)
        eSocket.close()
        del queues[eSocket]

def handleWritingSockets():
    # We handle writing to sockets here
    # we take the message to send from the queue
    # if there isnt a message for that specific socket
    # we stop checking for writability.
    for wSocket in writers:
        try:
            nextMessage = queues[wSocket].get_nowait()
        except EmptyQueueError:
            display("Output queue for", wSocket.getpeername(), "is empty")
            outputs.remove(wSocket)
        else:
            display("Sending \"", nextMessage, "\" to ", wSocket.getpeername())
            wSocket.send(nextMessage)

def receiveNewConnection(server):
    # we call this when a new client connects to the server
    connection, client_address = server.accept()
    display("New connection from", client_address)
    inputs.append(connection)
    queues[connection] = Queue()

def closeConnection(rSocket):
    # this happens when we receive 0 bytes of data
    display("Closing", rSocket.getpeername(), "after reading no data")
    if rSocket in outputs:
        outputs.remove(rSocket)
    inputs.remove(rSocket)
    rSocket.close()
    del queues[rSocket]

def receiveData(rSocket, data):
    # if we receive more than 0 bytes of data :)
    display("Received", data, "from", rSocket.getpeername())
    if rSocket not in outputs:
        outputs.append(rSocket)
    for Socket in queues:
        queues[Socket].put(data)
        if Socket not in outputs:
            outputs.append(Socket)

def handleReadingSockets():
    # different situations here
    for rSocket in readers:
        if rSocket is server:
            receiveNewConnection(rSocket)
        else:
            data = rSocket.recv(1024) # interesting number ?
            if data:
                receiveData(rSocket, data)
            else:
                closeConnection(rSocket)

# waiting for events using select...
while inputs:
    display("Waiting for the next event...")
    readers, writers, erroring = select.select(inputs, outputs, queues)
    handleReadingSockets()
    handleWritingSockets()
    handleErroringSockets()
    
    
    