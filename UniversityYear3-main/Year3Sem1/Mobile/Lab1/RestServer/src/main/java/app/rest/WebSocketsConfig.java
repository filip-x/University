package app.rest;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.socket.config.annotation.EnableWebSocket;
import org.springframework.web.socket.config.annotation.WebSocketConfigurer;
import org.springframework.web.socket.config.annotation.WebSocketHandlerRegistry;

@CrossOrigin("*")
@Configuration
@EnableWebSocket

public class WebSocketsConfig implements WebSocketConfigurer {
    private SocketTexthandler socketTexthandler;
    @Autowired
    private void setSocketTexthandler(SocketTexthandler socketTexthandler)
    {
        this.socketTexthandler =socketTexthandler;
    }
    @Override
     public void registerWebSocketHandlers(WebSocketHandlerRegistry registry)
    {
        registry.addHandler(socketTexthandler,"/notification").setAllowedOrigins("*");
    }
}
