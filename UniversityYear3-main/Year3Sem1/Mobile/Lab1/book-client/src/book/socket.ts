function setupSocket(callback: Function){

    let socket: WebSocket = new WebSocket("ws://localhost:8080/notification");
    socket.onmessage = function(response){
        callback(response);
        console.log(response);
    }

    socket.onopen = function() {
        console.log("opening socket");
    }
    socket.onclose = function(){
        console.log("close socket");
    }
    socket.onerror = function(){
        console.log("error socket");
    }
}
export {setupSocket};