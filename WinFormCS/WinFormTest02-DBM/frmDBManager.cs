using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.Remoting.Contexts;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormTest02_DBM
{
    public partial class frmDBManager : Form
    {
        public frmDBManager()
        {
            InitializeComponent();
        }

        string GetFileName(string sPath)
        {//전체 경로에 맨뒤 파일이름 문자열만 가져오는 함수
            string[] sa = sPath.Split('\\');
            return sa[sa.Length - 1];    
        }
        SqlConnection sqlConn = new SqlConnection();
        SqlCommand sqlCom = new SqlCommand();
        string sConn; 
        private void mnuOpen_Click(object sender, EventArgs e)
        {   //DB file select
            openFileDialog1.Filter = "MS-SQL Database file|*.mdf";
            if(DialogResult.OK ==openFileDialog1.ShowDialog())
            {
                sConn = $"Data Source=(LocalDB)\\MSSQLLocalDB;AttachDbFilename={openFileDialog1.FileName};Integrated Security = True; Connect Timeout = 30";
                sqlConn.ConnectionString = sConn;
                sqlConn.Open();
                sqlCom.Connection = sqlConn;
                sbLabel1.BackColor = Color.Yellow;
                sbLabel1.Text = GetFileName(openFileDialog1.FileName);
            }
        }

        ArrayList ColName = new ArrayList();  //필드이름 List
        List<object[]> RunSql(string sql)  // Select vs Others
        {
            List<object[]> result = new List<object[]>();
            sqlCom.CommandText = sql;
            try
            {
                if (sql.Trim().ToLower().Substring(0, 6) == "select") // Trim : 공백문자 제거 // ToLower : 소문자로 변경 // SubString : 문자열의 부분을 자르기(자르기 시작점, 자르기 끝점)
                {
                    SqlDataReader sr = sqlCom.ExecuteReader();
                    ColName.Clear();
                    for (int i = 0; i < sr.FieldCount; i++) // Column Name
                    {
                        ColName.Add(sr.GetName(i));
                    }
                    for (; sr.Read();) // 1 record read
                    {
                        object[] oarr = new object[sr.FieldCount];
                        sr.GetValues(oarr);
                        result.Add(oarr);
                        //string str = "";
                        //for (int i = 0; i < sr.FieldCount; i++) // Column 생성
                        //{
                        //    object o = sr.GetName(i);
                        //    if (i == 0) str = $"{o}";
                        //    else        str += $"{o}";
                        //}
                    }
                    sr.Close();
                }
                else
                {
                    int n = sqlCom.ExecuteNonQuery();
                }
                sbLabel3.Text = "OK";
                return result;
            }
            catch(Exception ex)
            {
                //MessageBox.Show(ex.Message);
                sbLabel3.AutoSize = true;
                sbLabel3.Text = ex.Message;
                return null;
            }
        }
        
        private void mnuRun_Click(object sender, EventArgs e)
        {
            string sql = tbSQL.SelectedText;
            if(sql == "") sql = tbSQL.Text;
            List<object[]> r = RunSql(sql);
            if (r == null) return;
            
            dataView.Rows.Clear();
            dataView.Columns.Clear();   
            for (int i = 0; i < ColName.Count; i++) // Column 생성
            {
                string colName = (string)ColName[i];
                dataView.Columns.Add(colName, colName);
            }
            for (int i = 0; i < r.Count; i++) // 1 record read
            { 
                int nRow = dataView.Rows.Add(); // 1Line Add
                object[] o = r[i];
                for (int j = 0; j < ColName.Count; j++)
                {
                    dataView.Rows[nRow].Cells[j].Value = o[j];
                }
            }
        }

        private void mnuFont_Click(object sender, EventArgs e)
        {
            if(fontDialog1.ShowDialog() == DialogResult.OK)
            {
                tbSQL.Font = fontDialog1.Font;
                sbLabel2.Text = tbSQL.Font.Name;
            }

        }

        private void mnuSave_Click(object sender, EventArgs e)
        {
            DialogResult ret = saveFileDialog1.ShowDialog();
            if (ret == DialogResult.OK)
            {
                string fn = saveFileDialog1.FileName;
                FileStream fs = new FileStream(fn, FileMode.Create);
                StreamWriter sw = new StreamWriter(fs);
                sw.Write(tbSQL.Text);
                sw.Close();
                fs.Close();
            }
        }
    }
}
