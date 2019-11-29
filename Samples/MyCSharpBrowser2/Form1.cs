using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TangramCLR;

namespace MyCSharpBrowser
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnNewTabPageStyle1_Click(object sender, EventArgs e)
        {
            string newTabPageLayout = Helper.LoadResourceFile("MyCSharpBrowser.Style1.xml");
            Tangram.UpdateNewTabPageLayout(newTabPageLayout);
            ChromeWebBrowser wb = Tangram.GetHostBrowser(this);
            if (wb != null)
            {
                wb.OpenURL("chrome://newtab", Disposition.NEW_FOREGROUND_TAB, "", "");
            }
        }

        private void btnNewTabPageStyle2_Click(object sender, EventArgs e)
        {
            string newTabPageLayout = Helper.LoadResourceFile("MyCSharpBrowser.Style2.xml");
            Tangram.UpdateNewTabPageLayout(newTabPageLayout);
            ChromeWebBrowser wb = Tangram.GetHostBrowser(this);
            if (wb != null)
            {
                wb.OpenURL("chrome://newtab", Disposition.NEW_FOREGROUND_TAB, "", "");
            }
        }

        private void btnNewTabPageStyle3_Click(object sender, EventArgs e)
        {
            string newTabPageLayout = Helper.LoadResourceFile("MyCSharpBrowser.Style3.xml");
            Tangram.UpdateNewTabPageLayout(newTabPageLayout);
            ChromeWebBrowser wb = Tangram.GetHostBrowser(this);
            if (wb != null)
            {
                wb.OpenURL("chrome://newtab", Disposition.NEW_FOREGROUND_TAB, "", "");
            }
        }
    }
}
