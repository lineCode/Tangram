namespace ChromeApp
{
    partial class ChartDesktopTech2018
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea2 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend2 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.chartDesktopTechnologies2018 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.chartDesktopTechnologies2018)).BeginInit();
            this.SuspendLayout();
            // 
            // chartDesktopTechnologies2018
            // 
            chartArea2.Name = "ChartArea1";
            this.chartDesktopTechnologies2018.ChartAreas.Add(chartArea2);
            legend2.Name = "Legend1";
            this.chartDesktopTechnologies2018.Legends.Add(legend2);
            this.chartDesktopTechnologies2018.Location = new System.Drawing.Point(16, 19);
            this.chartDesktopTechnologies2018.Name = "chartDesktopTechnologies2018";
            series2.ChartArea = "ChartArea1";
            series2.Legend = "Legend1";
            series2.Name = "Series1";
            this.chartDesktopTechnologies2018.Series.Add(series2);
            this.chartDesktopTechnologies2018.Size = new System.Drawing.Size(861, 268);
            this.chartDesktopTechnologies2018.TabIndex = 0;
            this.chartDesktopTechnologies2018.Text = "chart1";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(16, 3);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.Button1_Click);
            // 
            // ChartDesktopTech2018
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.button1);
            this.Controls.Add(this.chartDesktopTechnologies2018);
            this.Name = "ChartDesktopTech2018";
            this.Size = new System.Drawing.Size(913, 311);
            this.Load += new System.EventHandler(this.ChartDesktopTech2018_Load);
            ((System.ComponentModel.ISupportInitialize)(this.chartDesktopTechnologies2018)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataVisualization.Charting.Chart chartDesktopTechnologies2018;
        private System.Windows.Forms.Button button1;
    }
}
