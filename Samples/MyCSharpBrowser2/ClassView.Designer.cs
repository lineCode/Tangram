namespace MyCSharpBrowser
{
    partial class ClassView
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
            System.Windows.Forms.TreeNode treeNode17 = new System.Windows.Forms.TreeNode("References");
            System.Windows.Forms.TreeNode treeNode18 = new System.Windows.Forms.TreeNode("Namespaces");
            System.Windows.Forms.TreeNode treeNode19 = new System.Windows.Forms.TreeNode("Tangram");
            System.Windows.Forms.TreeNode treeNode20 = new System.Windows.Forms.TreeNode("CompositorManager");
            System.Windows.Forms.TreeNode treeNode21 = new System.Windows.Forms.TreeNode("Compositor");
            System.Windows.Forms.TreeNode treeNode22 = new System.Windows.Forms.TreeNode("Node");
            System.Windows.Forms.TreeNode treeNode23 = new System.Windows.Forms.TreeNode("Classes", new System.Windows.Forms.TreeNode[] {
            treeNode19,
            treeNode20,
            treeNode21,
            treeNode22});
            System.Windows.Forms.TreeNode treeNode24 = new System.Windows.Forms.TreeNode("TangramCore", new System.Windows.Forms.TreeNode[] {
            treeNode17,
            treeNode18,
            treeNode23});
            System.Windows.Forms.TreeNode treeNode25 = new System.Windows.Forms.TreeNode("References");
            System.Windows.Forms.TreeNode treeNode26 = new System.Windows.Forms.TreeNode("Namespaces");
            System.Windows.Forms.TreeNode treeNode27 = new System.Windows.Forms.TreeNode("TangramCLR");
            System.Windows.Forms.TreeNode treeNode28 = new System.Windows.Forms.TreeNode("CompositorManager");
            System.Windows.Forms.TreeNode treeNode29 = new System.Windows.Forms.TreeNode("Compositor");
            System.Windows.Forms.TreeNode treeNode30 = new System.Windows.Forms.TreeNode("Node");
            System.Windows.Forms.TreeNode treeNode31 = new System.Windows.Forms.TreeNode("Classes", new System.Windows.Forms.TreeNode[] {
            treeNode27,
            treeNode28,
            treeNode29,
            treeNode30});
            System.Windows.Forms.TreeNode treeNode32 = new System.Windows.Forms.TreeNode("TangramCLR", new System.Windows.Forms.TreeNode[] {
            treeNode25,
            treeNode26,
            treeNode31});
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(300, 500);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.treeView1);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(292, 474);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Class View";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // treeView1
            // 
            this.treeView1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.treeView1.Location = new System.Drawing.Point(3, 3);
            this.treeView1.Name = "treeView1";
            treeNode17.Name = "Node3";
            treeNode17.Text = "References";
            treeNode18.Name = "Node6";
            treeNode18.Text = "Namespaces";
            treeNode19.Name = "Node8";
            treeNode19.Text = "Tangram";
            treeNode20.Name = "Node19";
            treeNode20.Text = "CompositorManager";
            treeNode21.Name = "Node9";
            treeNode21.Text = "Compositor";
            treeNode22.Name = "Node10";
            treeNode22.Text = "Node";
            treeNode23.Name = "Node7";
            treeNode23.Text = "Classes";
            treeNode24.Name = "Node0";
            treeNode24.Text = "TangramCore";
            treeNode25.Name = "Node12";
            treeNode25.Text = "References";
            treeNode26.Name = "Node13";
            treeNode26.Text = "Namespaces";
            treeNode27.Name = "Node15";
            treeNode27.Text = "TangramCLR";
            treeNode28.Name = "Node16";
            treeNode28.Text = "CompositorManager";
            treeNode29.Name = "Node17";
            treeNode29.Text = "Compositor";
            treeNode30.Name = "Node18";
            treeNode30.Text = "Node";
            treeNode31.Name = "Node14";
            treeNode31.Text = "Classes";
            treeNode32.Name = "Node1";
            treeNode32.Text = "TangramCLR";
            this.treeView1.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode24,
            treeNode32});
            this.treeView1.Size = new System.Drawing.Size(286, 468);
            this.treeView1.TabIndex = 0;
            // 
            // ClassView
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.tabControl1);
            this.Name = "ClassView";
            this.Size = new System.Drawing.Size(300, 500);
            this.Load += new System.EventHandler(this.ClassView_Load);
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TreeView treeView1;
    }
}
