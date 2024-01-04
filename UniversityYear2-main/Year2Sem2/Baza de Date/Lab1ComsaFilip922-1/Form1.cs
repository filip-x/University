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


namespace Lab1ComsaFilip922_1
{
    public partial class Form1 : Form
    {
        SqlConnection connection;
        DataSet dataSet; 
        SqlDataAdapter artistAdaptor, bandAdaptor;
        SqlCommandBuilder command;
        BindingSource artistSource, bandSource; 

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
            dataSet.Tables["Band"].Clear();
            dataSet.Tables["Artist"].Clear();
            bandAdaptor.Fill(dataSet, "Band");//fill dataSet
            artistAdaptor.Fill(dataSet, "Artist");
            dataSet.EnforceConstraints = true;
        }

        private void buttonUpdate_Click(object sender, EventArgs e)
        {
            bandAdaptor.Update(dataSet, "Band");//update database
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            connection = new SqlConnection(@"Data Source = DESKTOP-PE6HT4H\SQLEXPRESS; Initial Catalog = Spopple_Music; Integrated Security = SSPI;");
            dataSet = new DataSet();
            artistAdaptor = new SqlDataAdapter("select * from Artist", connection);
            bandAdaptor = new SqlDataAdapter("select * from Band", connection);
            command = new SqlCommandBuilder(artistAdaptor);

            bandAdaptor.Fill(dataSet, "Band");//fill dataSet
            artistAdaptor.Fill(dataSet, "Artist");
            DataRelation relationBetweenData = new DataRelation("FK__Artist__Band",dataSet.Tables["Band"].Columns["Band_id"], dataSet.Tables["Artist"].Columns["Band_id"]);
            //dataRelation helps us to not change(delete/update) the data that are in use (for integrity)
            dataSet.Relations.Add(relationBetweenData);

            bandSource = new BindingSource();
            bandSource.DataSource = dataSet;
            bandSource.DataMember = "Band";

            artistSource = new BindingSource();
            artistSource.DataSource = bandSource;
            artistSource.DataMember = "FK__Artist__Band";

            

        

            bandTable.DataSource = bandSource;
            artistTable.DataSource = artistSource;
           
        }
    }
}
