using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Lab10.DAL;

namespace Lab10.Controllers
{
    public class SessionController: Controller
    {
        // GET: Session
        public ActionResult Login()
        {
            return View();
        }

        public string SignUp()
        {
            if (!string.IsNullOrEmpty(Request.Form["username"]) && !string.IsNullOrEmpty(Request.Form["password"]))
            {
                string Username = Request.Form["username"];
                string Password = Request.Form["password"];
                LoginAccounts accountDal = new LoginAccounts();
                if (accountDal.Register(Username, Password))
                {
                    return "Successfully registered!";
                }

                return "Could not register! Perhaps the username exists already?";
            }
            else
            {
                return "Invalid Username or Password! Cannot be empty!";
            }
        }

        public string UserLogIn()
        {
            if (!string.IsNullOrEmpty(Request.Form["username"]) && !string.IsNullOrEmpty(Request.Form["password"]))
            {
                string Username = Request.Form["username"];
                string Password = Request.Form["password"];
                LoginAccounts accountDal = new LoginAccounts();
                bool success = accountDal.Login(Username, Password);
                if (success == true)
                {
                    Session["LOGGED_IN"] = Username;
                    return "0\nSuccessfully logged in!";
                }
                return "1\nCould not register! Perhaps the username exists already?";
            }
            else
            {
                return "1\nInvalid Username or Password! Cannot be empty!";
            }
        }

        public string LogOut()
        {
            if (SessionDAL.IsValidSession(Session))
            {
                bool success = SessionDAL.LogOut(Session);
                if (success == true)
                {
                    return "0\nSuccessfully logged out!";
                }
                return "1\nCannot log out from an invalid session!";
            }
            else
            {
                return "1\nCannot log out from an invalid session!";
            }
        }
    }
}