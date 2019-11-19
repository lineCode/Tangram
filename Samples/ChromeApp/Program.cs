using System;
using System.Windows.Forms;
using TangramCLR;

namespace ChromeApp
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            if (Tangram.CloudAppSupport)
            {
                Tangram.OnCloudAppInit += Program_OnCloudAppInit;
                //Tangram.OnInitTangramApp += Tangram_OnInitTangramApp;
                //Tangram.OnGetAppIcon += Tangram_OnGetAppIcon;
                Tangram.OnFormNodeCreated += Tangram_OnFormNodeCreated;
                Tangram.OnOpenComplete += Tangram_OnOpenComplete;
                Tangram.InitCloudApp(false);
            }
            else
            {
                Application.Run(new ChromeForm1());
            }
        }

        private static void Tangram_OnOpenComplete(IntPtr hWnd, string bstrUrl, WndNode pRootNode)
        {
            if (pRootNode.NodeType == WndNodeType.TNT_Splitter)
            {

            }
        }

        private static void Tangram_OnFormNodeCreated(string bstrObjID, Form pForm, WndNode pNode)
        {
            
        }

        private static System.Drawing.Icon Tangram_OnGetAppIcon(int nIndex)
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(TangramMDIParent));
            return ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
        }

        private static string Tangram_OnGetTangramNtpXml(string strKey)
        {
            return "<tangram><window><node id='splitter' name='container' rows='1' cols='2' height ='100,100,' width='300,500,' borderwidth='0' splitterwidth='4' middlecolor='RGB(240,240,240)'><node name='launcher' id='ClrCtrl' cnnid='ChromeApp.NtpCtrl,ChromeApp' caption='' borderwidth='0' /><node name='host' caption='host' id='hostview' borderwidth='0' /></node></window></tangram>";
        }

        private static IntPtr Tangram_OnInitTangramApp()
        {
            TangramMDIParent thisForm = new TangramMDIParent();
            thisForm.Text = "main form";
            thisForm.Show();
            return thisForm.Handle;
        }

        private static void Program_OnCloudAppInit()
        {
            //TangramMDIParent thisForm = new TangramMDIParent();
            //thisForm.Show();
        }
    }
}
