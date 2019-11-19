using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;
//using TangramCLR;

namespace DemoStart
{
    public partial class Form_TabbedBrowser : Form
    {
        public Form_TabbedBrowser()
        {
            InitializeComponent();
        }

        private void Form_TabbedBrowser_Load(object sender, EventArgs e)
        {
            TangramCLR.CompositorManager Manager = TangramCLR.Tangram.CreateCompositorManager(this, null);
            TangramCLR.Compositor Compositor = Manager.CreateCompositor(panel1, "panel1");
            Compositor.Open("default", "Form_TabbedBrowser.xml");
        }
    }
}
