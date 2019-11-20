using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Threading.Tasks;
using System.Windows.Forms;
using TangramCLR;

namespace MyCSharpBrowser
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
            Common.LoadNTPXML("MyCSharpBrowser.DefaultNTP.xml");
            Application.Run(Tangram.Context);
        }
    }
}
