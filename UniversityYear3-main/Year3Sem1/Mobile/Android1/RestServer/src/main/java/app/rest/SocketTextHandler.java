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
import org.w3c.dom.Text;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

@Component
public class SocketTextHandler extends TextWebSocketHandler {
    Logger logger = LoggerFactory.getLogger("SocketTextHandler");
    List<Pair<String, WebSocketSession>> sessionList = new ArrayList<>();

    @Override
    public void afterConnectionEstablished(WebSocketSession session) {
        logger.info("connected with the websocket client: " + session.getId() + " and username " + session.getPrincipal());
        sessionList.add(new Pair<>(session.getPrincipal().getName(), session));
    }

    @Override
    public void afterConnectionClosed(WebSocketSession session, CloseStatus status) {
        sessionList.remove(sessionList.stream().filter((p) -> {
            if(p != null)
                return p.getSecond().equals(session);
            return false;
        }).findFirst().get());
        logger.info("disconnected with the websocket client: " + session.getId());
    }

    public void sendToAll(TextMessage message) {
        logger.info("Sending message to all " + sessionList.size() + ": " + message);
        sessionList.forEach(sessionPair -> {
            try {
                sessionPair.getSecond().sendMessage(message);
            } catch (IOException exception) {
                logger.info("Could not send message! " + exception.getMessage());
            }
        });
    }

    public void sendToUser(String username, TextMessage textMessage) {
        sessionList.forEach(sessionPair -> {
            try {
                if (Objects.equals(sessionPair.getFirst(), username) && sessionPair.getSecond().isOpen())
                    sessionPair.getSecond().sendMessage(textMessage);
            } catch (IOException exception) {
                logger.info("Could not send message! " + exception.getMessage());
            }
        });
    }

    @Override
    public void handleTextMessage(WebSocketSession session, TextMessage message) throws JSONException {
        sessionList.forEach(sessionPair -> {
            if (sessionPair.getSecond() == session)
                logger.info("Message received from " + sessionPair.getFirst());
        });
        logger.info("Message received.");
        String payload = message.getPayload();
        JSONObject jsonObject = new JSONObject(payload);
        logger.info(jsonObject.toString());
    }
}
