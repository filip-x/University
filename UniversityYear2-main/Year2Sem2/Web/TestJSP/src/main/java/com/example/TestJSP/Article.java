package com.example.TestJSP;

import java.sql.Timestamp;

public class Article {
    private int id;
    private String user;
    private int journalid;
    private String summary;
    private Timestamp date;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getUser() {
        return user;
    }

    public void setUser(String user) {
        this.user = user;
    }

    public int getJournalid() {
        return journalid;
    }

    public void setJournalid(int journalid) {
        this.journalid = journalid;
    }

    public String getSummary() {
        return summary;
    }

    public void setSummary(String summary) {
        this.summary = summary;
    }

    public Timestamp getDate() {
        return date;
    }

    public void setDate(Timestamp date) {
        this.date = date;
    }

    public Article(int id, String user, int journalid, String summary, Timestamp date)
    {
        this.id = id;
        this.user = user;
        this.journalid = journalid;
        this.summary = summary;
        this.date = date;

    }

    @Override
    public String toString() {
        return "Article{" +
                "id=" + id +
                ", user='" + user + '\'' +
                ", journalid=" + journalid +
                ", summary='" + summary + '\'' +
                ", date=" + date +
                '}';
    }
}
