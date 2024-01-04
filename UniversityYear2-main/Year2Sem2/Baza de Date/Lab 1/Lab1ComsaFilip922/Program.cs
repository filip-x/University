using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Data;
// SqlConnection, SqlCommand, SqlDataReader, SqlDataAdaptor

namespace Lab1ComsaFilip922
{
    class Program
    {
        static void Main(string[] args)
        {
            lab1();
        }

        static void lab1()
        {
            SqlConnection conn = new SqlConnection();
            conn.ConnectionString = " Data Source = DESKTOP-PE6HT4H\\SQLEXPRESS; Initial Catalog = Northwind; " + "Integrated Security == SSPI";
            DataSet ds = new DataSet();
            SqlDataAdapter da = new SqlDataAdapter("SELECT * From Y", conn);
            da.Fill
        }
    }
}
