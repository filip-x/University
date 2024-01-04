using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Lab10.DAL;
using System.Web.Script.Serialization;
using Lab10.Domain;
using MySql.Data.MySqlClient;
using System.Diagnostics;

namespace Lab10.DAL
{
    public class BookDAL : Controller
    {
        private readonly MySqlConnection Connection;
        public BookDAL()
        {
            Connection = new MySqlConnection("server=localhost;user id=lab10;persistsecurityinfo=True;database=Lab10;port=3306;password=1234");
            Connection.Open();
        }

        public Boolean Add(Book book)
        {
            MySqlCommand Command = new MySqlCommand("INSERT INTO Books (Author, Title, Comment, Date) VALUES " +
            "(@author, @title, @comment, @date)", Connection);
            Command.Parameters.Add("@author", MySqlDbType.VarChar);
            Command.Parameters.Add("@title", MySqlDbType.VarChar);
            Command.Parameters.Add("@comment", MySqlDbType.VarChar);
            Command.Parameters.Add("@date", MySqlDbType.VarChar);
            Command.Parameters["@author"].Value = book.getAuthor();
            Command.Parameters["@title"].Value = book.getTitle();
            Command.Parameters["@comment"].Value = book.getComment();
            Command.Parameters["@date"].Value = book.getDate();
            
            if (Command.ExecuteNonQuery() == 1)
            {
                return true;
            }

            return false;
        }

        public Boolean Delete(int Id)
        {
            if (Exists(Id))
            {
                MySqlCommand Command = new MySqlCommand("DELETE FROM Books WHERE Id=@Id", Connection);
                Command.Parameters.Add("@Id", MySqlDbType.Int32);
                Command.Parameters["@Id"].Value = Id;
                if (Command.ExecuteNonQuery() == 1)
                    return true;
                return false;
            }

            return false;
        }

        public Book LoadId(int Id)
        {
            MySqlCommand Command = new MySqlCommand("SELECT * FROM Books WHERE Id = @Id", Connection);
            Command.Parameters.Add("@Id", MySqlDbType.Int32);
            Command.Parameters["@Id"].Value = Id;
            MySqlDataReader reader = Command.ExecuteReader();
            if (reader.Read())
            {
                int id = int.Parse(reader.GetString("Id"));
                string author = reader.GetString("Author");
                string title = reader.GetString("Title");
                string comment = reader.GetString("Comment");
                string date = reader.GetDateTime("Date").ToString("yyyy-MM-dd");
               
                return new Book(id, author, title, comment, date);
            }
            reader.Close();
            return null;
        }
        public Boolean Update(Book book)
        {
            MySqlCommand Command = new MySqlCommand(
                    "UPDATE Books SET Author = @author, Title = @title, Comment = @comment, Date = @date WHERE Id=@id", Connection);
            Command.Parameters.Add("@author", MySqlDbType.VarChar);
            Command.Parameters.Add("@title", MySqlDbType.VarChar);
            Command.Parameters.Add("@comment", MySqlDbType.VarChar);
            Command.Parameters.Add("@date", MySqlDbType.VarChar);
            Command.Parameters.Add("@id", MySqlDbType.Int32);
            Command.Parameters["@author"].Value = book.getAuthor();
            Command.Parameters["@title"].Value = book.getTitle();
            Command.Parameters["@comment"].Value = book.getComment();
            Command.Parameters["@date"].Value = book.getDate();
            Command.Parameters["@id"].Value = book.getId();

            if (Command.ExecuteNonQuery() == 1)
            {
                return true;
            }

            return false;
        }

        public List<Book> FilterBooks(string inputAuthor,string inpuTitle, int page, int pageCount)
        {
            List<Book> books = new List<Book>();
            int Limit = (page - 1) * pageCount;
            MySqlCommand Command = new MySqlCommand("SELECT * FROM Books WHERE Author = @author AND Title = @title LIMIT " + Limit + ", " + pageCount, Connection);
            Command.Parameters.Add("@author", MySqlDbType.VarChar);
            Command.Parameters.Add("@title", MySqlDbType.VarChar);
            Command.Parameters["@author"].Value = inputAuthor;
            Command.Parameters["@title"].Value = inpuTitle;
            MySqlDataReader reader = Command.ExecuteReader();
            while (reader.Read())
            {
                int id = int.Parse(reader.GetString("Id"));
                Debug.WriteLine(id.ToString() + "_");
                string author = reader.GetString("Author");
                string title = reader.GetString("Title");
                string comment = reader.GetString("Comment");
                string date = reader.GetString("Date");
                books.Add(new Book(id, author, title, comment, date));
            }
            reader.Close();
            return books;
        }

        public int GetCount(string author, string title)
        {
            MySqlCommand Command = new MySqlCommand("SELECT COUNT(*) AS 'Count' FROM Books WHERE Author = @author AND Title = @title", Connection);
            Command.Parameters.Add("@author", MySqlDbType.VarChar);
            Command.Parameters["@author"].Value = author;
            Command.Parameters.Add("@title", MySqlDbType.VarChar);
            Command.Parameters["@title"].Value = title;
            int count = Convert.ToInt32(Command.ExecuteScalar());
            return count;
        }

        public List<String> GetAuthor()
        {
            List<String> Books= new List<string>();
            MySqlCommand Command = new MySqlCommand("SELECT DISTINCT Author FROM Books", Connection);

            MySqlDataReader reader = Command.ExecuteReader();
            while (reader.Read())
            {
                Books.Add(reader.GetString(0));
            }
            reader.Close();
            return Books;
        }
        public List<String> GetTitle()
        {
            List<String> Books = new List<string>();
            MySqlCommand Command = new MySqlCommand("SELECT DISTINCT Title FROM Books", Connection);

            MySqlDataReader reader = Command.ExecuteReader();
            while (reader.Read())
            {
                Books.Add(reader.GetString(0));
            }
            reader.Close();
            return Books;
        }

        public Boolean Exists(int Id)
        {
            MySqlCommand Command = new MySqlCommand("SELECT Count(*) FROM Books WHERE Id=@Id", Connection);
            Command.Parameters.Add("@Id", MySqlDbType.Int32);
            Command.Parameters["@Id"].Value = Id;

            int Count = Convert.ToInt32(Command.ExecuteScalar());

            return Count == 1;
        }

        ~BookDAL()
        {
            Connection.Close();
        }
    }
}