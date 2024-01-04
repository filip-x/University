using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Configuration;


namespace Lab1ComsaFilip922_1
{
    public partial class Form1 : Form
    {
        SqlConnection connection;
        DataSet dataSet; 
        SqlDataAdapter secondAdaptor, firstAdaptor;
        SqlCommandBuilder command;
        BindingSource secondSource, firstSource;


        string first = ConfigurationManager.AppSettings["first"];
        string second = ConfigurationManager.AppSettings["second"];
        string firstFKColumnName = ConfigurationManager.AppSettings["firstFKColumnName"];
        string secondFKColumnName = ConfigurationManager.AppSettings["secondFKColumnName"];
        string foreignKey = ConfigurationManager.AppSettings["foreignKey"];

        public Form1()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            dataSet.EnforceConstraints = false;
            dataSet.Tables[first].Clear();
            dataSet.Tables[second].Clear();
            firstAdaptor.Fill(dataSet, first);//fill dataSet
            secondAdaptor.Fill(dataSet, second);
            dataSet.EnforceConstraints = true;
        }

        private void buttonUpdate_Click(object sender, EventArgs e)
        {
            secondAdaptor.Update(dataSet, second);//update database
        }// i had band so i put first bcs i have the band in first 

        private void Form1_Load(object sender, EventArgs e)
        {
            connection = new SqlConnection(@"Data Source = DESKTOP-PE6HT4H\SQLEXPRESS; Initial Catalog = Spopple_Music; Integrated Security = SSPI;");
            dataSet = new DataSet();
            secondAdaptor = new SqlDataAdapter("select * from " + second, connection);
            firstAdaptor = new SqlDataAdapter("select * from " + first, connection);
            command = new SqlCommandBuilder(secondAdaptor);

            firstAdaptor.Fill(dataSet, first);//fill dataSet
            secondAdaptor.Fill(dataSet, second);
            DataRelation relationBetweenData = new DataRelation(foreignKey,dataSet.Tables[first].Columns[firstFKColumnName], dataSet.Tables[second].Columns[secondFKColumnName]);
            //dataRelation helps us to not change(delete/update) the data that are in use (for integrity)
            dataSet.Relations.Add(relationBetweenData);

            firstSource = new BindingSource();
            firstSource.DataSource = dataSet;
            firstSource.DataMember = first;

            secondSource = new BindingSource();
            secondSource.DataSource = firstSource;
            secondSource.DataMember = foreignKey;

            bandTable.DataSource = firstSource;
            artistTable.DataSource = secondSource;
           
        }
    }
}
