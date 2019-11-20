using System;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;
using System.Windows.Forms;
using TangramCLR;

namespace DemoStart
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            if (!Tangram.BuiltInBrowserModel)
            {
                Application.EnableVisualStyles();
                Application.SetCompatibleTextRenderingDefault(false);
                //Tangram.OnGetAppIcon += Tangram_OnGetAppIcon;
                Tangram.OnAppInit += Tangram_OnAppInit;
                Tangram.OnAppMsgLoop += Tangram_OnAppMsgLoop;
                Tangram.OnTangramIPCMsg += Tangram_OnTangramIPCMsg;
                Tangram.OnTangramRenderHTMLElement += Tangram_OnTangramRenderHTMLElement;
                Application.Run(Tangram.Context);
            }
        }

        private static void Tangram_OnTangramRenderHTMLElement(IntPtr hWnd, string strRuleName, string strHTML)
        {
            //throw new NotImplementedException();
        }

        private static void Tangram_OnTangramIPCMsg(IntPtr hWnd, string strType, string strParam1, string strParam2)
        {
            //throw new NotImplementedException();
        }

        private static void Tangram_OnAppMsgLoop(IntPtr hWnd, IntPtr msg, IntPtr wParam, IntPtr lParam)
        {
            Control ctrl = (Control)System.Windows.Forms.Form.FromHandle(hWnd);
            if (ctrl != null) 
            {
                String strName = ctrl.Name;
                System.Diagnostics.Debug.Print(strName);
            }
        }

        private static System.Drawing.Icon Tangram_OnGetAppIcon(int nIndex)
        {
            Type pType = TangramCLR.Tangram.GetType("DemoStart.Form1,DemoStart");
            System.ComponentModel.ComponentResourceManager  resources = new System.ComponentModel.ComponentResourceManager(pType);
            if (resources!=null)
            {
                System.Drawing.Icon pIcon = (System.Drawing.Icon ) (resources.GetObject("$this.Icon"));
                if (pIcon == null)
                {
                    pIcon = TangramCLR.Tangram.DefaultIcon;
                }
                return pIcon;
             }
            return null;
        }

        private static bool Tangram_OnAppInit()
        {
            Tangram.OnEclipseAppInit += Tangram_OnEclipseAppInit;
            return true;
        }

        private static void ThisForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }

        private static void Tangram_OnEclipseAppInit()
        {
            Form1 thisForm = new Form1();
            thisForm.Show();
        }
    }
}
