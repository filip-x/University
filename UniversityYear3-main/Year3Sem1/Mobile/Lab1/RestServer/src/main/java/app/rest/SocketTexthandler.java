package app.rest;


import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.configurationprocessor.json.JSONException;
import org.springframework.boot.configurationprocessor.json.JSONObject;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.CloseStatus;
import org.springframework.web.socket.TextMessage;
import org.springframework.web.socket.WebSocketSession;
import org.springframework.web.socket.handler.TextWebSocketHandler;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

@Component
public class SocketTexthandler extends TextWebSocketHandler {
    Logger logger = LoggerFactory.getLogger("SocketTextHandler");
    List<WebSocketSession> sessionList = new ArrayList<>();
    @Override
    public void afterConnectionEstablished(WebSocketSession session) throws Exception {
        logger.info("connected with the websocket client : " + session.getId());
        sessionList.add(session);
    }

    @Override
    public void afterConnectionClosed(WebSocketSession session, CloseStatus status) throws Exception {
        sessionList.remove(session);
        logger.info("disconnected with the websocket client : " + session.getId());
    }

    public void sendToAll(TextMessage message) {
        logger.info("Sending message to all" + sessionList.size() + ": " + message);
        sessionList.forEach(session -> {
            try {
                session.sendMessage(message);
            } catch (IOException exception) {
                logger.info("Could not send message! " + exception.getMessage());
            }
        });
    }
    @Override
    public void handleTextMessage(WebSocketSession session, TextMessage message)
            throws InterruptedException, IOException, JSONException {
        logger.info("Message received.");
        String payload = message.getPayload();
        JSONObject jsonObject = new JSONObject(payload);
        logger.info(jsonObject.toString());
    }

}
