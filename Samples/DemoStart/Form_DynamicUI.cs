using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DemoStart
{
    public partial class Form_DynamicUI : Form
    {
        public Form_DynamicUI()
        {
            InitializeComponent();
        }

        private void Form_DynamicUI_Load(object sender, EventArgs e)
        {
            TangramCLR.CompositorManager Manager = TangramCLR.Tangram.CreateCompositorManager(this, null);
            TangramCLR.Compositor Compositor = Manager.CreateCompositor(panel1, "panel1");
            Compositor.Open("default", "Form_DynamicUI.xml");
        }
    }
}
