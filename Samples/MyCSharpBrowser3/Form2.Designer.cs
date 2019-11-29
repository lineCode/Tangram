namespace MyCSharpBrowser
{
    partial class Form2
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

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnHelloWebPage = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnHelloWebPage
            // 
            this.btnHelloWebPage.Location = new System.Drawing.Point(30, 30);
            this.btnHelloWebPage.Name = "btnHelloWebPage";
            this.btnHelloWebPage.Size = new System.Drawing.Size(150, 23);
            this.btnHelloWebPage.TabIndex = 0;
            this.btnHelloWebPage.Text = "Hello Webpage!";
            this.btnHelloWebPage.UseVisualStyleBackColor = true;
            this.btnHelloWebPage.Click += new System.EventHandler(this.btnHelloWebPage_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnHelloWebPage);
            this.Name = "Form2";
            this.Text = "Form2";
            this.Load += new System.EventHandler(this.Form2_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnHelloWebPage;
    }
}