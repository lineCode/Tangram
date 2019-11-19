using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DemoStart
{
    public partial class Form_Browser : Form
    {
        public Form_Browser()
        {
            InitializeComponent();
        }

        private void Form_Browser_Load(object sender, EventArgs e)
        {
            TangramCLR.CompositorManager CompositorManager = TangramCLR.Tangram.CreateCompositorManager(this, null);
            TangramCLR.Compositor Compositor = CompositorManager.CreateCompositor(panel1, "panel1");
            Compositor.Open("default", "Form_Browser.xml");
        }
    }
}
