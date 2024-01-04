package com.app.msg;

public class SubscribeMessage extends Message {
    public String var;
    public int rank;

    public SubscribeMessage(String var, int rank) {
        this.var = var;
        this.rank = rank;
    }
}