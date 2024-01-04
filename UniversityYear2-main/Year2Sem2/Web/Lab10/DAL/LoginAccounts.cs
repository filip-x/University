
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

using MySql.Data.MySqlClient;

namespace Lab10.DAL
{
    public class LoginAccounts
    {
        private readonly MySqlConnection Connection;
        public LoginAccounts()
        {
            Connection = new MySqlConnection("server=localhost;user id=lab10;persistsecurityinfo=True;database=Lab10;port=3306;password=1234");
            Connection.Open();
        }

        public Boolean UserExists(string username)
        {
            MySqlCommand Command = new MySqlCommand("SELECT Count(*) FROM Accounts WHERE Username=@Username", Connection);
            Command.Parameters.Add("@Username", MySqlDbType.VarChar);
            Command.Parameters["@Username"].Value = username;

            int Count = Convert.ToInt32(Command.ExecuteScalar());

            return Count == 1;
        }

        public Boolean Register(string username, string password)
        {
            if (UserExists(username) == false)
            {
                MySqlCommand Command = new MySqlCommand("INSERT INTO Accounts (Username, Password) VALUES (@Username, @Password)", Connection);
                Command.Parameters.Add("@Username", MySqlDbType.VarChar);
                Command.Parameters.Add("@Password", MySqlDbType.VarChar);
                Command.Parameters["@Username"].Value = username;
                Command.Parameters["@Password"].Value = password;

                if (Command.ExecuteNonQuery() == 1)
                {
                    return true;
                }
            }
            return false;
        }

        public bool Login(string username, string password)
        {
            MySqlCommand CheckCommand = new MySqlCommand("SELECT Id FROM Accounts WHERE Username=@Username AND Password=@Password", Connection);
            CheckCommand.Parameters.Add("@Username", MySqlDbType.VarChar);
            CheckCommand.Parameters.Add("@Password", MySqlDbType.VarChar);
            CheckCommand.Parameters["@Username"].Value = username;
            CheckCommand.Parameters["@Password"].Value = password;

            object Result = CheckCommand.ExecuteScalar();

            if (Result != null)
            {
                return true;
            }
            return false;
        }

        ~LoginAccounts()
        {
            Connection.Close();
        }

    }
}