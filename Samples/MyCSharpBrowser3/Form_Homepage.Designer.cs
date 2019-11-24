namespace MyCSharpBrowser
{
    partial class Form_Homepage
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
            this.btnLeftRight = new System.Windows.Forms.Button();
            this.btnGrid = new System.Windows.Forms.Button();
            this.btnFull = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btnLeftRight
            // 
            this.btnLeftRight.Location = new System.Drawing.Point(42, 94);
            this.btnLeftRight.Name = "btnLeftRight";
            this.btnLeftRight.Size = new System.Drawing.Size(118, 23);
            this.btnLeftRight.TabIndex = 0;
            this.btnLeftRight.Text = "Half left and right";
            this.btnLeftRight.UseVisualStyleBackColor = true;
            this.btnLeftRight.Click += new System.EventHandler(this.btnLeftRight_Click);
            // 
            // btnGrid
            // 
            this.btnGrid.Location = new System.Drawing.Point(175, 94);
            this.btnGrid.Name = "btnGrid";
            this.btnGrid.Size = new System.Drawing.Size(118, 23);
            this.btnGrid.TabIndex = 1;
            this.btnGrid.Text = "Grid";
            this.btnGrid.UseVisualStyleBackColor = true;
            this.btnGrid.Click += new System.EventHandler(this.btnGrid_Click);
            // 
            // btnFull
            // 
            this.btnFull.Location = new System.Drawing.Point(308, 94);
            this.btnFull.Name = "btnFull";
            this.btnFull.Size = new System.Drawing.Size(118, 23);
            this.btnFull.TabIndex = 2;
            this.btnFull.Text = "Full";
            this.btnFull.UseVisualStyleBackColor = true;
            this.btnFull.Click += new System.EventHandler(this.btnFull_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.Location = new System.Drawing.Point(42, 43);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(373, 16);
            this.label1.TabIndex = 3;
            this.label1.Text = "Click on the button below to show more hybrid pages.";
            // 
            // Form_Homepage
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnFull);
            this.Controls.Add(this.btnGrid);
            this.Controls.Add(this.btnLeftRight);
            this.Name = "Form_Homepage";
            this.Text = "Form_Homepage";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnLeftRight;
        private System.Windows.Forms.Button btnGrid;
        private System.Windows.Forms.Button btnFull;
        private System.Windows.Forms.Label label1;
    }
}