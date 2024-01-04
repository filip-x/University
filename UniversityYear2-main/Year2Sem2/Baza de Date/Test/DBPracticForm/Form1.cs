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


namespace DBPracticForm
{
    public partial class Form1 : Form
    {
        SqlConnection connection;
        DataSet dataSet;
        SqlDataAdapter cardsAdaptor, transactionsAdaptor;
        SqlCommandBuilder command;
        BindingSource cardsSource, transactionsSource;

        private void button1_Click(object sender, EventArgs e)//update button
        {
            transactionsAdaptor.Update(dataSet, "Transactions");//update database
        }
        //Transactions = Transaction = child // 
        //Cards card = parent // 
        private void Form1_Load(object sender, EventArgs e)
        {
            connection = new SqlConnection(@"Data Source = DESKTOP - PE6HT4H\SQLEXPRESS; Initial Catalog = Tracker; Integrated Security = True");
            dataSet = new DataSet();
            cardsAdaptor = new SqlDataAdapter("select * from Cards", connection);
            transactionsAdaptor = new SqlDataAdapter("select * from Transactions", connection);
            command = new SqlCommandBuilder(transactionsAdaptor);

            transactionsAdaptor.Fill(dataSet, "Transactions");//fill dataSet
            cardsAdaptor.Fill(dataSet, "Cards");
            DataRelation relationBetweenData = new DataRelation("FK__Cards__Transactions", dataSet.Tables["Cards"].Columns["CardID"], dataSet.Tables["Transactions"].Columns["CardID"] );
            //dataRelation helps us to not change(delete/update) the data that are in use (for integrity)
            dataSet.Relations.Add(relationBetweenData);


            cardsSource = new BindingSource();
            cardsSource.DataSource = dataSet;
            cardsSource.DataMember = "Cards";


            transactionsSource = new BindingSource();
            transactionsSource.DataSource = cardsSource;
            transactionsSource.DataMember = "FK__Cards__Transactions";

            
            dataGridView1.DataSource = cardsSource;
            dataGridView2.DataSource = transactionsSource;
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)// refresh button
        {
            dataSet.EnforceConstraints = false;
            dataSet.Tables["Transactions"].Clear();
            dataSet.Tables["Cards"].Clear();
            transactionsAdaptor.Fill(dataSet, "Transactions");//fill dataSet
            cardsAdaptor.Fill(dataSet, "Cards");
            dataSet.EnforceConstraints = true;
        }
    }
}
