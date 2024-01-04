using Lab10.DAL;
using System.Web;
using System.Web.Mvc;

namespace Lab10
{
    public class FilterConfig
    {
        public static void RegisterGlobalFilters(GlobalFilterCollection filters)
        {
            filters.Add(new LoginAttribute());
            filters.Add(new HandleErrorAttribute());

        }
    }
    public class LoginAttribute : AuthorizeAttribute, IAuthorizationFilter
    {

        public override void OnAuthorization(AuthorizationContext filterContext)
        {
            string LocalPath = filterContext.RequestContext.HttpContext.Request.Url.LocalPath;
            if (LocalPath.EndsWith(".css") || (LocalPath.Contains("Session") && !LocalPath.EndsWith("Login")))
            {
                return;
            }
            HttpSessionStateBase Session = filterContext.HttpContext.Session;
            if (filterContext.RequestContext.HttpContext.Request.Url.LocalPath.EndsWith("Login"))
            {
                if (SessionDAL.IsValidSession(Session))
                {
                    filterContext.RequestContext.HttpContext.Response.Redirect("/");
                }
                else
                {
                    return;
                }
            }
            if (Session["LOGGED_IN"] != null && SessionDAL.IsValidSession(Session))
            {
                return;
            }
            else
            {
                filterContext.RequestContext.HttpContext.Response.Redirect("/Session/Login");
            }

        }
    }
}
