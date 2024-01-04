using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Lab10.DAL;
using System.Web.Script.Serialization;
using Lab10.Domain;
using System.Diagnostics;

namespace Lab10.Controllers
{
    public class MainController : Controller
    {
        // GET: Main
        public Boolean isPost()
        {
            if (this.HttpContext.Request.RequestType == "POST")
                return true;
            else return false;
        }

        public ActionResult Add()
        {
            return View();
        }

        public ActionResult Remove()
        {
            return View();
        }

        public ActionResult Modify()
        {
            return View();
        }

        public ActionResult Browse()
        {
            return View();
        }


        public string RunAdd()
        {
            if (string.IsNullOrEmpty(Request.Params["author"]) || string.IsNullOrEmpty(Request.Params["title"]) ||
                string.IsNullOrEmpty(Request.Params["comment"]) || string.IsNullOrEmpty(Request.Params["date"]))
            {
                return "Missing parameters.";
            }
            string author = Request.Params["author"];
            string title = Request.Params["title"];
            string comment = Request.Params["comment"];
            string date = Request.Params["date"];
            Book newBook = new Book(author, title, comment, date);
            BookDAL bookDal = new BookDAL();
            if (bookDal.Add(newBook))
            {
                return "Ended";
            }
            else
            {
                return "Could not insert!";
            }
        }


        public string getAuthor()
        {
            BookDAL bookDal = new BookDAL();
            List<String> authors = bookDal.GetAuthor();

            return new JavaScriptSerializer().Serialize(authors);
        }

        public string getTitle()
        {
            BookDAL bookDal = new BookDAL();
            List<String> titles = bookDal.GetTitle();

            return new JavaScriptSerializer().Serialize(titles);
        }

        public ActionResult Index()
        {
            return View();
        }

        public ActionResult Client()
        {
            return View();
        }

        public ActionResult Admin()
        {
            return View();
        }

        public string loadBrowse()
        {
            if (string.IsNullOrEmpty(Request.Params["pageSize"]) || string.IsNullOrEmpty(Request.Params["page"]) ||
                string.IsNullOrEmpty(Request.Params["Title"]) || string.IsNullOrEmpty(Request.Params["Author"]))
            {
                return "Missing parameters.";
            }
            int pageSize = int.Parse(Request.Params["pageSize"]);
            int page = int.Parse(Request.Params["page"]);
            string title = Request.Params["Title"];
            string author = Request.Params["Author"];
            Debug.WriteLine(title + "_" + author);
            List<List<string>> result = new List<List<string>>();
            BookDAL bookDal = new BookDAL();
            List<Book> books = bookDal.FilterBooks(author, title, page, pageSize);
            foreach (Book book in books)
            {
                List<string> info = new List<string>();
                info.Add(book.getId().ToString());
                info.Add(book.getAuthor());
                info.Add(book.getTitle());
                info.Add(book.getComment());
                info.Add(book.getDate());
                result.Add(info);
            }
            int count = bookDal.GetCount(author, title);
            count = (count - 1) / pageSize;
            Dictionary<string, object> finalResult = new Dictionary<string, object>();
            finalResult.Add("page_count", count);
            finalResult.Add("page_content", result);
            return new JavaScriptSerializer().Serialize(finalResult);
        }

        public ActionResult Delete()
        {
            return View();
        }

        public string RunDelete()
        {
            if (string.IsNullOrEmpty(Request.Params["id"]))
            {
                return "Missing parameters.";
            }

            int id = int.Parse(Request.Params["id"]);
            BookDAL bookDal = new BookDAL();
            bool deleted = bookDal.Delete(id);
            if (deleted == false)
                return "1The book has not been removed, perhaps it has been removed already?";
            else
                return "0The book has been successfully removed!";
        }


        public string Id()
        {
            if (string.IsNullOrEmpty(Request.Params["id"]))
            {
                return "Missing parameters.";
            }

            int id = int.Parse(Request.Params["id"]);
            BookDAL bookDal = new BookDAL();
            Book book = bookDal.LoadId(id);
            if (book == null)
                return "false";
            else {
                List<string> info = new List<string>();
                info.Add(book.getAuthor());
                info.Add(book.getTitle());
                info.Add(book.getComment());
                info.Add(book.getDate());
                return new JavaScriptSerializer().Serialize(info);
            }
        }
        public string RunModify()
        {
            if (string.IsNullOrEmpty(Request.Params["id"]) || string.IsNullOrEmpty(Request.Params["author"]) || string.IsNullOrEmpty(Request.Params["title"]) ||
                string.IsNullOrEmpty(Request.Params["comment"]) || string.IsNullOrEmpty(Request.Params["date"]))
            {
                return "Missing parameters.";
            }
            int id = int.Parse(Request.Params["id"]);
            string author = Request.Params["author"];
            string title = Request.Params["title"];
            string comment = Request.Params["comment"];
            string date = Request.Params["date"];
            BookDAL bookDal = new BookDAL();
            bool updated = bookDal.Update(new Book(id, author, title,comment,date));
            if (updated)
                return "ended";
            else return "Could not update!";
        }
    }
}