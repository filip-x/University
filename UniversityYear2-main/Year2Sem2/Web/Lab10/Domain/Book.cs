using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Lab10.Domain
{
    public class Book
    {
        private int id = -1;
        private string author;
        private string title;
        private string comment;
        private string date;

        public Book(string author, string title, string comment, string date)
        {
            this.author = author;
            this.title = title;
            this.comment = comment;
            this.date = date;
        }
        public Book(int id ,string author, string title, string comment, string date)
        {
            this.id = id;
            this.author = author;
            this.title = title;
            this.comment = comment;
            this.date = date;
        }

        public int getId()
        {
            return id;
        }

        public string getAuthor()
        {
            return author;
        }

        public string getTitle()
        {
            return title;
        }

        public string getComment()
        {
            return comment;
        }

        public string getDate()
        {
            return date;
        }

    }
    
}