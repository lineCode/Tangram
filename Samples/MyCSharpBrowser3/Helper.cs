using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace MyCSharpBrowser
{
    public class Helper
    {
        /// <summary>
        /// Loads the specified resource from this assembly.
        /// </summary>
        /// <param name="resourceName">The case-sensitive name of the manifest resource being requested.</param>
        /// <returns>Resource content</returns>
        public static string LoadResourceFile(string resourceName)
        {
            var assembly = Assembly.GetExecutingAssembly();
            using (Stream stream = assembly.GetManifestResourceStream(resourceName))
            {
                using (StreamReader reader = new StreamReader(stream))
                {
                    return reader.ReadToEnd();
                }
            }
        }

    }
}
