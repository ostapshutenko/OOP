namespace lab6_oop
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.Numerals1 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.Denumerals1 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.Numerals2 = new System.Windows.Forms.TextBox();
            this.Denumerals2 = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.Add = new System.Windows.Forms.Button();
            this.Sub = new System.Windows.Forms.Button();
            this.Mult = new System.Windows.Forms.Button();
            this.Div = new System.Windows.Forms.Button();
            this.Comp = new System.Windows.Forms.Button();
            this.Exist = new System.Windows.Forms.Button();
            this.Numerals = new System.Windows.Forms.TextBox();
            this.Denumerals = new System.Windows.Forms.TextBox();
            this.isExist = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // Numerals1
            // 
            this.Numerals1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Numerals1.Location = new System.Drawing.Point(17, 40);
            this.Numerals1.Name = "Numerals1";
            this.Numerals1.Size = new System.Drawing.Size(120, 29);
            this.Numerals1.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(13, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(78, 24);
            this.label1.TabIndex = 1;
            this.label1.Text = "Дробь1";
            // 
            // Denumerals1
            // 
            this.Denumerals1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Denumerals1.Location = new System.Drawing.Point(17, 75);
            this.Denumerals1.Name = "Denumerals1";
            this.Denumerals1.Size = new System.Drawing.Size(120, 29);
            this.Denumerals1.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(150, 13);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(78, 24);
            this.label2.TabIndex = 3;
            this.label2.Text = "Дробь2";
            // 
            // Numerals2
            // 
            this.Numerals2.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Numerals2.Location = new System.Drawing.Point(154, 40);
            this.Numerals2.Name = "Numerals2";
            this.Numerals2.Size = new System.Drawing.Size(120, 29);
            this.Numerals2.TabIndex = 4;
            // 
            // Denumerals2
            // 
            this.Denumerals2.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Denumerals2.Location = new System.Drawing.Point(154, 75);
            this.Denumerals2.Name = "Denumerals2";
            this.Denumerals2.Size = new System.Drawing.Size(120, 29);
            this.Denumerals2.TabIndex = 5;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(280, 51);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(62, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "Числитель";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(280, 86);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(75, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Знаменатель";
            // 
            // Add
            // 
            this.Add.Location = new System.Drawing.Point(361, 40);
            this.Add.Name = "Add";
            this.Add.Size = new System.Drawing.Size(75, 23);
            this.Add.TabIndex = 8;
            this.Add.Text = "Add";
            this.Add.UseVisualStyleBackColor = true;
            this.Add.Click += new System.EventHandler(this.Add_Click);
            // 
            // Sub
            // 
            this.Sub.Location = new System.Drawing.Point(442, 40);
            this.Sub.Name = "Sub";
            this.Sub.Size = new System.Drawing.Size(75, 23);
            this.Sub.TabIndex = 9;
            this.Sub.Text = "Sub";
            this.Sub.UseVisualStyleBackColor = true;
            this.Sub.Click += new System.EventHandler(this.Sub_Click);
            // 
            // Mult
            // 
            this.Mult.Location = new System.Drawing.Point(523, 40);
            this.Mult.Name = "Mult";
            this.Mult.Size = new System.Drawing.Size(75, 23);
            this.Mult.TabIndex = 10;
            this.Mult.Text = "Mult";
            this.Mult.UseVisualStyleBackColor = true;
            this.Mult.Click += new System.EventHandler(this.Mult_Click);
            // 
            // Div
            // 
            this.Div.Location = new System.Drawing.Point(361, 75);
            this.Div.Name = "Div";
            this.Div.Size = new System.Drawing.Size(75, 23);
            this.Div.TabIndex = 11;
            this.Div.Text = "Div";
            this.Div.UseVisualStyleBackColor = true;
            this.Div.Click += new System.EventHandler(this.Div_Click);
            // 
            // Comp
            // 
            this.Comp.Location = new System.Drawing.Point(442, 76);
            this.Comp.Name = "Comp";
            this.Comp.Size = new System.Drawing.Size(75, 23);
            this.Comp.TabIndex = 12;
            this.Comp.Text = "Comp";
            this.Comp.UseVisualStyleBackColor = true;
            this.Comp.Click += new System.EventHandler(this.Comp_Click);
            // 
            // Exist
            // 
            this.Exist.Location = new System.Drawing.Point(523, 76);
            this.Exist.Name = "Exist";
            this.Exist.Size = new System.Drawing.Size(75, 23);
            this.Exist.TabIndex = 13;
            this.Exist.Text = "Exist";
            this.Exist.UseVisualStyleBackColor = true;
            this.Exist.Click += new System.EventHandler(this.Exist_Click);
            // 
            // Numerals
            // 
            this.Numerals.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Numerals.Location = new System.Drawing.Point(617, 40);
            this.Numerals.Name = "Numerals";
            this.Numerals.Size = new System.Drawing.Size(120, 29);
            this.Numerals.TabIndex = 14;
            // 
            // Denumerals
            // 
            this.Denumerals.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Denumerals.Location = new System.Drawing.Point(617, 75);
            this.Denumerals.Name = "Denumerals";
            this.Denumerals.Size = new System.Drawing.Size(120, 29);
            this.Denumerals.TabIndex = 15;
            // 
            // isExist
            // 
            this.isExist.AutoSize = true;
            this.isExist.Location = new System.Drawing.Point(743, 56);
            this.isExist.Name = "isExist";
            this.isExist.Size = new System.Drawing.Size(10, 13);
            this.isExist.TabIndex = 16;
            this.isExist.Text = " ";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(866, 143);
            this.Controls.Add(this.isExist);
            this.Controls.Add(this.Denumerals);
            this.Controls.Add(this.Numerals);
            this.Controls.Add(this.Exist);
            this.Controls.Add(this.Comp);
            this.Controls.Add(this.Div);
            this.Controls.Add(this.Mult);
            this.Controls.Add(this.Sub);
            this.Controls.Add(this.Add);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.Denumerals2);
            this.Controls.Add(this.Numerals2);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.Denumerals1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Numerals1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox Numerals1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox Denumerals1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox Numerals2;
        private System.Windows.Forms.TextBox Denumerals2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button Add;
        private System.Windows.Forms.Button Sub;
        private System.Windows.Forms.Button Mult;
        private System.Windows.Forms.Button Div;
        private System.Windows.Forms.Button Comp;
        private System.Windows.Forms.Button Exist;
        private System.Windows.Forms.TextBox Numerals;
        private System.Windows.Forms.TextBox Denumerals;
        private System.Windows.Forms.Label isExist;
    }
}

