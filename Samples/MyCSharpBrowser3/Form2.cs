using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TangramCLR;

namespace MyCSharpBrowser
{
    public partial class Form2 : Form
    {
        private WndNode thisNode;

        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            thisNode = Tangram.CreatingNode;
            thisNode.AddChannel("csharp");
            thisNode.OnIPCMessageReceived += ThisNode_OnIPCMessageReceived;
        }

        private void btnHelloWebPage_Click(object sender, EventArgs e)
        {
            thisNode.SendIPCMessage("web", "Hello Webpage!");
        }

        private void ThisNode_OnIPCMessageReceived(string strChannel, string strData)
        {
            if (strChannel.Equals("csharp"))
            {
                MessageBox.Show(strData);
            }
        }
    }
}
