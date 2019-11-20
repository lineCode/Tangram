namespace MyCSharpBrowser
{
    partial class MainPanel
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
            this.label1 = new System.Windows.Forms.Label();
            this.btnWhatIsNtp = new System.Windows.Forms.Button();
            this.btnStyle1 = new System.Windows.Forms.Button();
            this.btnStyle2 = new System.Windows.Forms.Button();
            this.btnStyle3 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(16, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(146, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Welcome to CSharp Browser!";
            // 
            // btnWhatIsNtp
            // 
            this.btnWhatIsNtp.Location = new System.Drawing.Point(19, 49);
            this.btnWhatIsNtp.Name = "btnWhatIsNtp";
            this.btnWhatIsNtp.Size = new System.Drawing.Size(189, 23);
            this.btnWhatIsNtp.TabIndex = 1;
            this.btnWhatIsNtp.Text = "What is NTP?";
            this.btnWhatIsNtp.UseVisualStyleBackColor = true;
            this.btnWhatIsNtp.Click += new System.EventHandler(this.btnWhatIsNtp_Click);
            // 
            // btnStyle1
            // 
            this.btnStyle1.Location = new System.Drawing.Point(19, 90);
            this.btnStyle1.Name = "btnStyle1";
            this.btnStyle1.Size = new System.Drawing.Size(189, 43);
            this.btnStyle1.TabIndex = 2;
            this.btnStyle1.Text = "Style 1: Show the panel at the bottom of the NTP.";
            this.btnStyle1.UseVisualStyleBackColor = true;
            this.btnStyle1.Click += new System.EventHandler(this.btnStyle1_Click);
            // 
            // btnStyle2
            // 
            this.btnStyle2.Location = new System.Drawing.Point(19, 151);
            this.btnStyle2.Name = "btnStyle2";
            this.btnStyle2.Size = new System.Drawing.Size(189, 43);
            this.btnStyle2.TabIndex = 3;
            this.btnStyle2.Text = "Style 2: More complex NTP layout.";
            this.btnStyle2.UseVisualStyleBackColor = true;
            this.btnStyle2.Click += new System.EventHandler(this.btnStyle2_Click);
            // 
            // btnStyle3
            // 
            this.btnStyle3.Location = new System.Drawing.Point(19, 212);
            this.btnStyle3.Name = "btnStyle3";
            this.btnStyle3.Size = new System.Drawing.Size(189, 43);
            this.btnStyle3.TabIndex = 4;
            this.btnStyle3.Text = "Style 3: NTP with tabs.";
            this.btnStyle3.UseVisualStyleBackColor = true;
            this.btnStyle3.Click += new System.EventHandler(this.btnStyle3_Click);
            // 
            // MainPanel
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.btnStyle3);
            this.Controls.Add(this.btnStyle2);
            this.Controls.Add(this.btnStyle1);
            this.Controls.Add(this.btnWhatIsNtp);
            this.Controls.Add(this.label1);
            this.Name = "MainPanel";
            this.Size = new System.Drawing.Size(240, 464);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnWhatIsNtp;
        private System.Windows.Forms.Button btnStyle1;
        private System.Windows.Forms.Button btnStyle2;
        private System.Windows.Forms.Button btnStyle3;
    }
}
