using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyCSharpBrowser
{
    public partial class ClassView : UserControl
    {
        public ClassView()
        {
            InitializeComponent();
        }

        private void ClassView_Load(object sender, EventArgs e)
        {
            if (!DesignMode)
            {
                treeView1.ExpandAll();
            }
        }
    }
}
