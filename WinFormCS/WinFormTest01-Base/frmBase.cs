using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormTest01_Base
{
    public partial class frmBase : Form
    {
        public frmBase()
        {
            InitializeComponent();
        }

        private void btnOpen_Click(object sender, EventArgs e)
        {
            mnuOpen_Click(sender, e);   
        }

        private void mnuOpen_Click(object sender, EventArgs e)
        {
            DialogResult ret = openFileDialog1.ShowDialog();
            if (ret == DialogResult.OK)
            {
                string fn = openFileDialog1.FileName;
                FileStream fs = new FileStream(fn, FileMode.Open); //Opne -> enum -> int
                StreamReader sr = new StreamReader(fs);
                tbMemo.Text += sr.ReadToEnd();

                //while(true) // C#에서 무한루프 사용 
                //{
                //    string str = sr.ReadLine();
                //    if (str == null) break;
                //    tbMemo.Text += str;
                //}
            }
        }

        private void mnuAnsi_Click(object sender, EventArgs e)
        {
            sbLabel1.Text = "ANSI";
            mnuAnsi.Checked = true;
            mnuUtf8.Checked = false;
        }

        private void mnuUtf8_Click(object sender, EventArgs e)
        {
            sbLabel1.Text = "UTF-8";
            mnuAnsi.Checked = false;
            mnuUtf8.Checked = true;
        }
    }
}
