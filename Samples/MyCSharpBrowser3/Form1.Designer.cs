namespace MyCSharpBrowser
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.label1 = new System.Windows.Forms.Label();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.richTextBox2 = new System.Windows.Forms.RichTextBox();
            this.btnNewTabPageStyle1 = new System.Windows.Forms.Button();
            this.btnNewTabPageStyle2 = new System.Windows.Forms.Button();
            this.btnNewTabPageStyle3 = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.richTextBox3 = new System.Windows.Forms.RichTextBox();
            this.btnHybridWebPage = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.Location = new System.Drawing.Point(30, 25);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(182, 16);
            this.label1.TabIndex = 0;
            this.label1.Text = "What is CSharp Browser?";
            // 
            // richTextBox1
            // 
            this.richTextBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.richTextBox1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.richTextBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.richTextBox1.Location = new System.Drawing.Point(30, 60);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.ReadOnly = true;
            this.richTextBox1.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.None;
            this.richTextBox1.Size = new System.Drawing.Size(264, 115);
            this.richTextBox1.TabIndex = 2;
            this.richTextBox1.Text = "CSharp Browser is a browser framework based on the Chromium open source project t" +
    "hat allows developers to develop their own browsers using C#. And create a hybri" +
    "d web page based on C# and HTML.";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label2.Location = new System.Drawing.Point(30, 190);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(189, 16);
            this.label2.TabIndex = 0;
            this.label2.Text = "A different New Tab Page.";
            // 
            // richTextBox2
            // 
            this.richTextBox2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.richTextBox2.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.richTextBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.richTextBox2.Location = new System.Drawing.Point(30, 230);
            this.richTextBox2.Name = "richTextBox2";
            this.richTextBox2.ReadOnly = true;
            this.richTextBox2.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.None;
            this.richTextBox2.Size = new System.Drawing.Size(264, 134);
            this.richTextBox2.TabIndex = 2;
            this.richTextBox2.Text = resources.GetString("richTextBox2.Text");
            // 
            // btnNewTabPageStyle1
            // 
            this.btnNewTabPageStyle1.Location = new System.Drawing.Point(30, 390);
            this.btnNewTabPageStyle1.Name = "btnNewTabPageStyle1";
            this.btnNewTabPageStyle1.Size = new System.Drawing.Size(264, 25);
            this.btnNewTabPageStyle1.TabIndex = 3;
            this.btnNewTabPageStyle1.Text = "New Tab Page Style 1: Bottom panel";
            this.btnNewTabPageStyle1.UseVisualStyleBackColor = true;
            this.btnNewTabPageStyle1.Click += new System.EventHandler(this.btnNewTabPageStyle1_Click);
            // 
            // btnNewTabPageStyle2
            // 
            this.btnNewTabPageStyle2.Location = new System.Drawing.Point(30, 420);
            this.btnNewTabPageStyle2.Name = "btnNewTabPageStyle2";
            this.btnNewTabPageStyle2.Size = new System.Drawing.Size(264, 25);
            this.btnNewTabPageStyle2.TabIndex = 3;
            this.btnNewTabPageStyle2.Text = "New Tab Page Style 2: Multiple panels";
            this.btnNewTabPageStyle2.UseVisualStyleBackColor = true;
            this.btnNewTabPageStyle2.Click += new System.EventHandler(this.btnNewTabPageStyle2_Click);
            // 
            // btnNewTabPageStyle3
            // 
            this.btnNewTabPageStyle3.Location = new System.Drawing.Point(30, 450);
            this.btnNewTabPageStyle3.Name = "btnNewTabPageStyle3";
            this.btnNewTabPageStyle3.Size = new System.Drawing.Size(264, 25);
            this.btnNewTabPageStyle3.TabIndex = 3;
            this.btnNewTabPageStyle3.Text = "New Tab Page Style 3: Tabs";
            this.btnNewTabPageStyle3.UseVisualStyleBackColor = true;
            this.btnNewTabPageStyle3.Click += new System.EventHandler(this.btnNewTabPageStyle3_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label3.Location = new System.Drawing.Point(30, 500);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(135, 16);
            this.label3.TabIndex = 0;
            this.label3.Text = "Hybrid Web Page.";
            // 
            // richTextBox3
            // 
            this.richTextBox3.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.richTextBox3.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.richTextBox3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.richTextBox3.Location = new System.Drawing.Point(30, 546);
            this.richTextBox3.Name = "richTextBox3";
            this.richTextBox3.ReadOnly = true;
            this.richTextBox3.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.None;
            this.richTextBox3.Size = new System.Drawing.Size(264, 82);
            this.richTextBox3.TabIndex = 2;
            this.richTextBox3.Text = "In CSharp Browser, developers have the opportunity to display WinForm components " +
    "into web pages by writing HTML tags.";
            // 
            // btnHybridWebPage
            // 
            this.btnHybridWebPage.Location = new System.Drawing.Point(30, 643);
            this.btnHybridWebPage.Name = "btnHybridWebPage";
            this.btnHybridWebPage.Size = new System.Drawing.Size(142, 40);
            this.btnHybridWebPage.TabIndex = 3;
            this.btnHybridWebPage.Text = "Show a hybrid web page.";
            this.btnHybridWebPage.UseVisualStyleBackColor = true;
            this.btnHybridWebPage.Click += new System.EventHandler(this.btnHybridWebPage_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(337, 846);
            this.Controls.Add(this.btnHybridWebPage);
            this.Controls.Add(this.btnNewTabPageStyle3);
            this.Controls.Add(this.btnNewTabPageStyle2);
            this.Controls.Add(this.btnNewTabPageStyle1);
            this.Controls.Add(this.richTextBox3);
            this.Controls.Add(this.richTextBox2);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.RichTextBox richTextBox2;
        private System.Windows.Forms.Button btnNewTabPageStyle1;
        private System.Windows.Forms.Button btnNewTabPageStyle2;
        private System.Windows.Forms.Button btnNewTabPageStyle3;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.RichTextBox richTextBox3;
        private System.Windows.Forms.Button btnHybridWebPage;
    }
}

