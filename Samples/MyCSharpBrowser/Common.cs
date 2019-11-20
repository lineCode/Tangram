using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using TangramCLR;

namespace MyCSharpBrowser
{
    public class Common
    {
        public static void LoadNTPXML(string xmlResourceName)
        {
            var assembly = Assembly.GetExecutingAssembly();
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
