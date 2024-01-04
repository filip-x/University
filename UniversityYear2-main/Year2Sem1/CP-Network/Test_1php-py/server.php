<?php
    $Socket = socket_create(AF_INET, SOCK_STREAM, 0);
    socket_bind($Socket, "192.168.0.178", 9999);
    socket_listen($Socket);

    $ClientSocket = socket_accept($Socket);
    echo "User connected!" . "\n";

    socket_send($ClientSocket, utf8_encode("Hello"), 5, 0);
    socket_recv($ClientSocket, $Message, 100, 0);
    
    echo utf8_decode($Message) . "\n";
?>
