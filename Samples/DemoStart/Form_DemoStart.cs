using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
//using TangramCLR;

namespace DemoStart
{
    public partial class Form_DemoStart : Form
    {
        public Form_DemoStart()
        {
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            //TangramCLR.Tangram.InitTangramApp(false,TangramCLR.TangramAppType.APP_BROWSER);
            TangramCLR.Tangram.AppType = TangramCLR.TangramAppType.APP_BROWSER_ECLIPSE;
            TangramCLR.Tangram.CreateBrowser(System.IntPtr.Zero, "https://dotnet.microsoft.com/|");
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            TangramCLR.Tangram.CreateBrowser(System.IntPtr.Zero, "https://demo.tangram.dev/form_a.html|https://demo.tangram.dev/form_mdi.html|https://demo.tangram.dev/form_a_b.html|https://demo.tangram.dev/form_a_2.html|");
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            Form_Browser form = new Form_Browser();
            form.Show(this);
            Form_TabbedBrowser form_tabbed = new Form_TabbedBrowser();
            form_tabbed.Show(this);
        }

        private void Button4_Click(object sender, EventArgs e)
        {
            Form_DynamicUI form = new Form_DynamicUI();
            form.Show(this);
        }

        private void Button5_Click(object sender, EventArgs e)
        {
            TangramCLR.Tangram.InitEclipse();
        }

        private void Button6_Click(object sender, EventArgs e)
        {
        }

        private void Button7_Click(object sender, EventArgs e)
        {
        }

        private void Button8_Click(object sender, EventArgs e)
        {
            TangramCLR.Tangram.CreateBrowser(System.IntPtr.Zero, "https://github.com/TangramDev/demo-pages|");
        }

        private void Button9_Click(object sender, EventArgs e)
        {
        }

        private void Tangram_OnCloudAppInit()
        {
            //Form_DemoStart thisform = new Form_DemoStart();
            //thisform.Show();
        }

        private void Button10_Click(object sender, EventArgs e)
        {
            TangramCLR.Tangram.InitEclipse();
        }
    }
}
