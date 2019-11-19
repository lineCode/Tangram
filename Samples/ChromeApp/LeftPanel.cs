using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TangramCLR;
using System.Windows.Forms.DataVisualization.Charting;
using System.IO;

namespace ChromeApp
{
    public partial class LeftPanel : UserControl
    {
        private WndNode thisNode;
        private ChromeWebBrowser browser;

        public LeftPanel()
        {
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            browser = Tangram.CreateBrowser(System.IntPtr.Zero, "https://www.tangram.dev|");
        }

        private void RadioButton2_CheckedChanged(object sender, EventArgs e)
        {
            WndNode rightNode = thisNode.ParentNode.GetNode(0, 1);
            if(rightNode != null)
            {
                String xmlLayout2 = File.ReadAllText("Layout2.xml");
                rightNode.Open("layout2", xmlLayout2);
            }
        }

        private void LeftPanel_Load(object sender, EventArgs e)
        {
            thisNode = Tangram.CreatingNode;
            thisNode.AddChannel("test1");
            thisNode.OnIPCMessageReceived += ThisNode_OnIPCMessageReceived;
            thisNode.OnRootNodeCreated += ThisNode_OnRootNodeCreated;
        }

        private void ThisNode_OnIPCMessageReceived(string strChannel, string strData)
        {
            MessageBox.Show(strData);
        }

        private void ThisNode_OnRootNodeCreated(IntPtr nHandle, string strUrl, WndNode pRootNode)
        {
            if (pRootNode.GetNode(0, 1).GetNode(1, 0).XObject is ChartDesktopTech2018)
            {

            }
        }

        private void Button4_Click(object sender, EventArgs e)
        {
            browser.OpenURL("https://www.baidu.com", Disposition.NEW_FOREGROUND_TAB, "xxx", "");
        }
    }
}
