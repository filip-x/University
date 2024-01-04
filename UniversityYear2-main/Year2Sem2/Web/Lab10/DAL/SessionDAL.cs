using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Lab10.DAL
{
    public class SessionDAL
    {
        public static bool IsValidSession(HttpSessionStateBase session)
        {
            object sessionInfo = session["LOGGED_IN"];
            if (sessionInfo != null)
            {
                return true;
            }

            return false;
        }

        public static bool LogOut(HttpSessionStateBase session)
        {
            if (IsValidSession(session))
            {
                session["LOGGED_IN"] = null;
                return true;
            }

            return false;
        }
    }
}