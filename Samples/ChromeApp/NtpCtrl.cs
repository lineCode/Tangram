using System;
using System.Windows.Forms;

namespace ChromeApp
{
    public partial class NtpCtrl : UserControl
    {
        public NtpCtrl()
        {
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            TangramCLR.Tangram.CreateBrowser(System.IntPtr.Zero, "https://www.tangram.dev/cloud/newtangrampage.html|");
        }
    }
}
