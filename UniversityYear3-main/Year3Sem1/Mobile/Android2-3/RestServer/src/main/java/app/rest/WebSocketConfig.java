package app.rest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.socket.config.annotation.*;


@CrossOrigin("*")
@Configuration
@EnableWebSocket
public class WebSocketConfig implements WebSocketConfigurer {
    private SocketTextHandler socketTextHandler;

    @Autowired
    private void setSocketTextHandler(SocketTextHandler socketTextHandler) {
        this.socketTextHandler = socketTextHandler;
    }
    @Override
    public void registerWebSocketHandlers(WebSocketHandlerRegistry registry) {
        registry.addHandler(socketTextHandler, "/notification").setAllowedOrigins("*");
    }
}
