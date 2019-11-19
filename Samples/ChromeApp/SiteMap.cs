using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using TangramCLR;

namespace ChromeApp
{
    public partial class SiteMap : UserControl
    {
        private WndNode thisNode;
        public SiteMap()
        {
            InitializeComponent();
        }

        private void SiteMap_Load(object sender, EventArgs e)
        {
            thisNode = Tangram.CreatingNode;
            thisNode.OnRootNodeCreated += ThisNode_OnRootNodeCreated;
        }

        private void ThisNode_OnRootNodeCreated(IntPtr nHandle, string strUrl, WndNode pRootNode)
        {
            
        }
    }
}
