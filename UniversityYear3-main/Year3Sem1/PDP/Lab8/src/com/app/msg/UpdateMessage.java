package com.app.msg;

public class UpdateMessage extends Message {
    public String var;
    public int val;

    public UpdateMessage(String var, int val) {
        this.var = var;
        this.val = val;
    }
}
