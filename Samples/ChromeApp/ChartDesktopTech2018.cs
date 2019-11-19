using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;
using TangramCLR;

namespace ChromeApp
{
    public partial class ChartDesktopTech2018 : UserControl
    {
        public ChartDesktopTech2018()
        {
            InitializeComponent();

            string[] categories = { "UWP", "WPF", "WinForms", "Electron", "Swing", "JavaFX", "Qt" };
            double startOffset = 0.5;
            double endOffset = 1.5;
            foreach (var category in categories)
            {
                CustomLabel categoryLabel = new CustomLabel(startOffset, endOffset, category, 0, LabelMarkStyle.None);
                chartDesktopTechnologies2018.ChartAreas[0].AxisX.CustomLabels.Add(categoryLabel);
                startOffset += 1;
                endOffset += 1;
            }

            // The data comes from https://data.stackexchange.com/stackoverflow/query/1071907/desktop-technologies-2018
            chartDesktopTechnologies2018.Series.Clear();
            int[] nTotalQuestions = { 3984, 10226, 5576, 2362, 3266, 5203, 6459 };
            Series sTotalQuestions = new Series();
            sTotalQuestions.Name = "Total Questions";
            for (int i = 0; i < nTotalQuestions.Length; i++)
            {
                sTotalQuestions.Points.AddXY(i + 1, nTotalQuestions[i]);
            }
            chartDesktopTechnologies2018.Series.Add(sTotalQuestions);
            int[] nWatchers = { 750, 973, 511, 426, 229, 613, 687 };
            Series sWatchers = new Series();
            sWatchers.Name = "Watchers";
            for (int i = 0; i < nWatchers.Length; i++)
            {
                sWatchers.Points.AddXY(i + 1, nWatchers[i]);
            }
            chartDesktopTechnologies2018.Series.Add(sWatchers);
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            thisNode.SendIPCMessage("test1", "message from test1");
            thisNode.SendIPCMessage("test2", "message from test2");
        }

        private WndNode thisNode;

        private void ChartDesktopTech2018_Load(object sender, EventArgs e)
        {
            thisNode = Tangram.CreatingNode;
        }
    }
}
