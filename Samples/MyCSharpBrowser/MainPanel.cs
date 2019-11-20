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
                wb.OpenURL("https://www.chromium.org/user-experience/new-tab-page|", Disposition.NEW_POPUP, "", "");
            }
        }
    }
}
