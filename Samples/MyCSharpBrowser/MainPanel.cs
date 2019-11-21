using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TangramCLR;

namespace MyCSharpBrowser
{
    public partial class MainPanel : UserControl
    {
        public MainPanel()
        {
            InitializeComponent();
        }

        private void btnWhatIsNtp_Click(object sender, EventArgs e)
        {
            ChromeWebBrowser wb = Tangram.ActiveBrowser();
            if (wb != null)
            {
                wb.OpenURL("https://demo.tangram.dev/new-tab-page.html", Disposition.NEW_POPUP, "", "");
            }
        }

        private void btnStyle1_Click(object sender, EventArgs e)
        {
            Common.LoadNTPXML("MyCSharpBrowser.Style1.xml");
            ChromeWebBrowser wb = Tangram.ActiveBrowser();
            if (wb != null)
            {
                wb.OpenURL("chrome://newtab", Disposition.NEW_FOREGROUND_TAB, "", "");
            }
        }

        private void btnStyle2_Click(object sender, EventArgs e)
        {
            Common.LoadNTPXML("MyCSharpBrowser.Style2.xml");
            ChromeWebBrowser wb = Tangram.ActiveBrowser();
            if (wb != null)
            {
                wb.OpenURL("chrome://newtab", Disposition.NEW_FOREGROUND_TAB, "", "");
            }
        }

        private void btnStyle3_Click(object sender, EventArgs e)
        {
            Common.LoadNTPXML("MyCSharpBrowser.Style3.xml");
            ChromeWebBrowser wb = Tangram.ActiveBrowser();
            if (wb != null)
            {
                wb.OpenURL("chrome://newtab", Disposition.NEW_FOREGROUND_TAB, "", "");
            }
        }
    }
}
