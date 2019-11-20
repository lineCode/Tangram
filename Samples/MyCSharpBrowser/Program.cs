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
            LoadDefaultNTPXML();
            Application.Run(Tangram.Context);
        }

        static void LoadDefaultNTPXML()
        {
            var assembly = Assembly.GetExecutingAssembly();
            var xmlResourceName = "MyCSharpBrowser.DefaultNTP.xml";
            using (Stream stream = assembly.GetManifestResourceStream(xmlResourceName))
            {
                using (StreamReader reader = new StreamReader(stream))
                {
                    Tangram.NTPXml = reader.ReadToEnd();
                }
            }
        }
    }
}
