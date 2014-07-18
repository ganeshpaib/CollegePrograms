Public Class Form4
    Inherits System.Windows.Forms.Form

#Region " Windows Form Designer generated code "

    Public Sub New()
        MyBase.New()

        'This call is required by the Windows Form Designer.
        InitializeComponent()

        'Add any initialization after the InitializeComponent() call

    End Sub

    'Form overrides dispose to clean up the component list.
    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing Then
            If Not (components Is Nothing) Then
                components.Dispose()
            End If
        End If
        MyBase.Dispose(disposing)
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label14 As System.Windows.Forms.Label
    Friend WithEvents ComboBox2 As System.Windows.Forms.ComboBox
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents DataGrid1 As System.Windows.Forms.DataGrid
    Friend WithEvents Button3 As System.Windows.Forms.Button
    Friend WithEvents Button4 As System.Windows.Forms.Button
    Friend WithEvents DataGrid2 As System.Windows.Forms.DataGrid
    Friend WithEvents TextBox5 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox4 As System.Windows.Forms.TextBox
    Friend WithEvents ComboBox3 As System.Windows.Forms.ComboBox
    Friend WithEvents TextBox3 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox2 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Friend WithEvents ComboBox1 As System.Windows.Forms.ComboBox
    Friend WithEvents OleDbDataAdapter1 As System.Data.OleDb.OleDbDataAdapter
    Friend WithEvents OleDbConnection1 As System.Data.OleDb.OleDbConnection
    Friend WithEvents Cat1 As GANPROJ.cat
    Friend WithEvents OleDbDataAdapter2 As System.Data.OleDb.OleDbDataAdapter
    Friend WithEvents Sup1 As GANPROJ.sup
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents Label10 As System.Windows.Forms.Label
    Friend WithEvents Label11 As System.Windows.Forms.Label
    Friend WithEvents TextBox6 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox7 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox8 As System.Windows.Forms.TextBox
    Friend WithEvents OleDbSelectCommand1 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbInsertCommand1 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbUpdateCommand1 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbDeleteCommand1 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbConnection2 As System.Data.OleDb.OleDbConnection
    Friend WithEvents OleDbSelectCommand2 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbInsertCommand2 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbUpdateCommand2 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbDeleteCommand2 As System.Data.OleDb.OleDbCommand
    Friend WithEvents Album1 As GANPROJ.ALBUM
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.TextBox8 = New System.Windows.Forms.TextBox
        Me.TextBox7 = New System.Windows.Forms.TextBox
        Me.TextBox6 = New System.Windows.Forms.TextBox
        Me.Label11 = New System.Windows.Forms.Label
        Me.Label10 = New System.Windows.Forms.Label
        Me.Label9 = New System.Windows.Forms.Label
        Me.Label6 = New System.Windows.Forms.Label
        Me.Button4 = New System.Windows.Forms.Button
        Me.Button3 = New System.Windows.Forms.Button
        Me.TextBox5 = New System.Windows.Forms.TextBox
        Me.TextBox4 = New System.Windows.Forms.TextBox
        Me.ComboBox3 = New System.Windows.Forms.ComboBox
        Me.Sup1 = New GANPROJ.sup
        Me.Label8 = New System.Windows.Forms.Label
        Me.Label7 = New System.Windows.Forms.Label
        Me.Label1 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.Label4 = New System.Windows.Forms.Label
        Me.Label5 = New System.Windows.Forms.Label
        Me.Label14 = New System.Windows.Forms.Label
        Me.TextBox3 = New System.Windows.Forms.TextBox
        Me.TextBox2 = New System.Windows.Forms.TextBox
        Me.ComboBox2 = New System.Windows.Forms.ComboBox
        Me.TextBox1 = New System.Windows.Forms.TextBox
        Me.ComboBox1 = New System.Windows.Forms.ComboBox
        Me.Cat1 = New GANPROJ.cat
        Me.Button1 = New System.Windows.Forms.Button
        Me.Button2 = New System.Windows.Forms.Button
        Me.DataGrid1 = New System.Windows.Forms.DataGrid
        Me.DataGrid2 = New System.Windows.Forms.DataGrid
        Me.OleDbDataAdapter1 = New System.Data.OleDb.OleDbDataAdapter
        Me.OleDbConnection1 = New System.Data.OleDb.OleDbConnection
        Me.OleDbDataAdapter2 = New System.Data.OleDb.OleDbDataAdapter
        Me.OleDbSelectCommand1 = New System.Data.OleDb.OleDbCommand
        Me.OleDbInsertCommand1 = New System.Data.OleDb.OleDbCommand
        Me.OleDbUpdateCommand1 = New System.Data.OleDb.OleDbCommand
        Me.OleDbDeleteCommand1 = New System.Data.OleDb.OleDbCommand
        Me.OleDbConnection2 = New System.Data.OleDb.OleDbConnection
        Me.OleDbSelectCommand2 = New System.Data.OleDb.OleDbCommand
        Me.OleDbInsertCommand2 = New System.Data.OleDb.OleDbCommand
        Me.OleDbUpdateCommand2 = New System.Data.OleDb.OleDbCommand
        Me.OleDbDeleteCommand2 = New System.Data.OleDb.OleDbCommand
        Me.Album1 = New GANPROJ.ALBUM
        Me.GroupBox1.SuspendLayout()
        CType(Me.Sup1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Cat1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.DataGrid1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.DataGrid2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Album1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.TextBox8)
        Me.GroupBox1.Controls.Add(Me.TextBox7)
        Me.GroupBox1.Controls.Add(Me.TextBox6)
        Me.GroupBox1.Controls.Add(Me.Label11)
        Me.GroupBox1.Controls.Add(Me.Label10)
        Me.GroupBox1.Controls.Add(Me.Label9)
        Me.GroupBox1.Controls.Add(Me.Label6)
        Me.GroupBox1.Controls.Add(Me.Button4)
        Me.GroupBox1.Controls.Add(Me.Button3)
        Me.GroupBox1.Controls.Add(Me.TextBox5)
        Me.GroupBox1.Controls.Add(Me.TextBox4)
        Me.GroupBox1.Controls.Add(Me.ComboBox3)
        Me.GroupBox1.Controls.Add(Me.Label8)
        Me.GroupBox1.Controls.Add(Me.Label7)
        Me.GroupBox1.Controls.Add(Me.Label1)
        Me.GroupBox1.Controls.Add(Me.Label2)
        Me.GroupBox1.Controls.Add(Me.Label3)
        Me.GroupBox1.Controls.Add(Me.Label4)
        Me.GroupBox1.Controls.Add(Me.Label5)
        Me.GroupBox1.Controls.Add(Me.Label14)
        Me.GroupBox1.Controls.Add(Me.TextBox3)
        Me.GroupBox1.Controls.Add(Me.TextBox2)
        Me.GroupBox1.Controls.Add(Me.ComboBox2)
        Me.GroupBox1.Controls.Add(Me.TextBox1)
        Me.GroupBox1.Controls.Add(Me.ComboBox1)
        Me.GroupBox1.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GroupBox1.Location = New System.Drawing.Point(96, 56)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(544, 472)
        Me.GroupBox1.TabIndex = 0
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "STOCK ENTRY"
        '
        'TextBox8
        '
        Me.TextBox8.Location = New System.Drawing.Point(368, 432)
        Me.TextBox8.Name = "TextBox8"
        Me.TextBox8.Size = New System.Drawing.Size(48, 20)
        Me.TextBox8.TabIndex = 45
        Me.TextBox8.Text = ""
        '
        'TextBox7
        '
        Me.TextBox7.Location = New System.Drawing.Point(296, 432)
        Me.TextBox7.Name = "TextBox7"
        Me.TextBox7.Size = New System.Drawing.Size(48, 20)
        Me.TextBox7.TabIndex = 44
        Me.TextBox7.Text = ""
        '
        'TextBox6
        '
        Me.TextBox6.Location = New System.Drawing.Point(224, 432)
        Me.TextBox6.Name = "TextBox6"
        Me.TextBox6.Size = New System.Drawing.Size(48, 20)
        Me.TextBox6.TabIndex = 43
        Me.TextBox6.Text = ""
        '
        'Label11
        '
        Me.Label11.Location = New System.Drawing.Point(368, 408)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(40, 16)
        Me.Label11.TabIndex = 42
        Me.Label11.Text = "YYYY"
        '
        'Label10
        '
        Me.Label10.Location = New System.Drawing.Point(304, 408)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(24, 16)
        Me.Label10.TabIndex = 40
        Me.Label10.Text = "MM"
        '
        'Label9
        '
        Me.Label9.Location = New System.Drawing.Point(240, 408)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(24, 16)
        Me.Label9.TabIndex = 38
        Me.Label9.Text = "DD"
        '
        'Label6
        '
        Me.Label6.Location = New System.Drawing.Point(96, 432)
        Me.Label6.Name = "Label6"
        Me.Label6.TabIndex = 36
        Me.Label6.Text = "Purchase Date"
        Me.Label6.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Button4
        '
        Me.Button4.Location = New System.Drawing.Point(376, 352)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(56, 23)
        Me.Button4.TabIndex = 35
        Me.Button4.Text = "SHOW"
        '
        'Button3
        '
        Me.Button3.Location = New System.Drawing.Point(376, 184)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(56, 23)
        Me.Button3.TabIndex = 34
        Me.Button3.Text = "SHOW"
        '
        'TextBox5
        '
        Me.TextBox5.Location = New System.Drawing.Point(232, 320)
        Me.TextBox5.Name = "TextBox5"
        Me.TextBox5.TabIndex = 33
        Me.TextBox5.Text = ""
        '
        'TextBox4
        '
        Me.TextBox4.Location = New System.Drawing.Point(232, 280)
        Me.TextBox4.Name = "TextBox4"
        Me.TextBox4.TabIndex = 32
        Me.TextBox4.Text = ""
        '
        'ComboBox3
        '
        Me.ComboBox3.DataSource = Me.Sup1
        Me.ComboBox3.DisplayMember = "A_MUSIC_SUPPLIER.SUPPLIER_ID"
        Me.ComboBox3.Location = New System.Drawing.Point(232, 357)
        Me.ComboBox3.Name = "ComboBox3"
        Me.ComboBox3.Size = New System.Drawing.Size(121, 21)
        Me.ComboBox3.TabIndex = 29
        '
        'Sup1
        '
        Me.Sup1.DataSetName = "sup"
        Me.Sup1.Locale = New System.Globalization.CultureInfo("en-US")
        '
        'Label8
        '
        Me.Label8.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label8.Location = New System.Drawing.Point(96, 357)
        Me.Label8.Name = "Label8"
        Me.Label8.TabIndex = 28
        Me.Label8.Text = "Supplier"
        Me.Label8.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label7
        '
        Me.Label7.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label7.Location = New System.Drawing.Point(96, 317)
        Me.Label7.Name = "Label7"
        Me.Label7.TabIndex = 27
        Me.Label7.Text = "Price"
        Me.Label7.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label1
        '
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(96, 229)
        Me.Label1.Name = "Label1"
        Me.Label1.TabIndex = 25
        Me.Label1.Text = "Language"
        Me.Label1.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label2
        '
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.Location = New System.Drawing.Point(96, 125)
        Me.Label2.Name = "Label2"
        Me.Label2.TabIndex = 22
        Me.Label2.Text = "Artist"
        Me.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label3
        '
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label3.Location = New System.Drawing.Point(96, 37)
        Me.Label3.Name = "Label3"
        Me.Label3.TabIndex = 18
        Me.Label3.Text = "Item Id"
        Me.Label3.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label4
        '
        Me.Label4.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label4.Location = New System.Drawing.Point(96, 277)
        Me.Label4.Name = "Label4"
        Me.Label4.TabIndex = 26
        Me.Label4.Text = "No. of Units"
        Me.Label4.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label5
        '
        Me.Label5.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label5.Location = New System.Drawing.Point(96, 77)
        Me.Label5.Name = "Label5"
        Me.Label5.TabIndex = 20
        Me.Label5.Text = "Album Name"
        Me.Label5.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label14
        '
        Me.Label14.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label14.Location = New System.Drawing.Point(96, 181)
        Me.Label14.Name = "Label14"
        Me.Label14.TabIndex = 24
        Me.Label14.Text = "Category"
        Me.Label14.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'TextBox3
        '
        Me.TextBox3.Location = New System.Drawing.Point(232, 128)
        Me.TextBox3.Name = "TextBox3"
        Me.TextBox3.TabIndex = 23
        Me.TextBox3.Text = ""
        '
        'TextBox2
        '
        Me.TextBox2.Location = New System.Drawing.Point(232, 80)
        Me.TextBox2.Name = "TextBox2"
        Me.TextBox2.TabIndex = 21
        Me.TextBox2.Text = ""
        '
        'ComboBox2
        '
        Me.ComboBox2.Items.AddRange(New Object() {"ENGLISH", "HINDI", "MALAYALAM", "KANNADA", "TAMIL", "KONKANI", "TELUGU"})
        Me.ComboBox2.Location = New System.Drawing.Point(232, 232)
        Me.ComboBox2.Name = "ComboBox2"
        Me.ComboBox2.Size = New System.Drawing.Size(121, 21)
        Me.ComboBox2.TabIndex = 31
        '
        'TextBox1
        '
        Me.TextBox1.Location = New System.Drawing.Point(232, 40)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.TabIndex = 19
        Me.TextBox1.Text = ""
        '
        'ComboBox1
        '
        Me.ComboBox1.DataSource = Me.Cat1
        Me.ComboBox1.DisplayMember = "A_MUSIC_CATEGORY.CATEGORY_ID"
        Me.ComboBox1.Location = New System.Drawing.Point(232, 184)
        Me.ComboBox1.Name = "ComboBox1"
        Me.ComboBox1.Size = New System.Drawing.Size(121, 21)
        Me.ComboBox1.TabIndex = 30
        '
        'Cat1
        '
        Me.Cat1.DataSetName = "cat"
        Me.Cat1.Locale = New System.Globalization.CultureInfo("en-US")
        '
        'Button1
        '
        Me.Button1.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Button1.Location = New System.Drawing.Point(216, 536)
        Me.Button1.Name = "Button1"
        Me.Button1.TabIndex = 34
        Me.Button1.Text = "ADD"
        '
        'Button2
        '
        Me.Button2.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Button2.Location = New System.Drawing.Point(432, 544)
        Me.Button2.Name = "Button2"
        Me.Button2.TabIndex = 35
        Me.Button2.Text = "EXIT"
        '
        'DataGrid1
        '
        Me.DataGrid1.DataMember = "A_MUSIC_CATEGORY"
        Me.DataGrid1.DataSource = Me.Cat1
        Me.DataGrid1.HeaderForeColor = System.Drawing.SystemColors.ControlText
        Me.DataGrid1.Location = New System.Drawing.Point(688, 216)
        Me.DataGrid1.Name = "DataGrid1"
        Me.DataGrid1.Size = New System.Drawing.Size(216, 80)
        Me.DataGrid1.TabIndex = 36
        '
        'DataGrid2
        '
        Me.DataGrid2.DataMember = "A_MUSIC_SUPPLIER"
        Me.DataGrid2.DataSource = Me.Sup1
        Me.DataGrid2.HeaderForeColor = System.Drawing.SystemColors.ControlText
        Me.DataGrid2.Location = New System.Drawing.Point(688, 392)
        Me.DataGrid2.Name = "DataGrid2"
        Me.DataGrid2.Size = New System.Drawing.Size(216, 80)
        Me.DataGrid2.TabIndex = 37
        '
        'OleDbDataAdapter1
        '
        Me.OleDbDataAdapter1.DeleteCommand = Me.OleDbDeleteCommand1
        Me.OleDbDataAdapter1.InsertCommand = Me.OleDbInsertCommand1
        Me.OleDbDataAdapter1.SelectCommand = Me.OleDbSelectCommand1
        Me.OleDbDataAdapter1.TableMappings.AddRange(New System.Data.Common.DataTableMapping() {New System.Data.Common.DataTableMapping("Table", "A_MUSIC_CATEGORY", New System.Data.Common.DataColumnMapping() {New System.Data.Common.DataColumnMapping("CATEGORY_ID", "CATEGORY_ID"), New System.Data.Common.DataColumnMapping("CATEGORY", "CATEGORY")})})
        Me.OleDbDataAdapter1.UpdateCommand = Me.OleDbUpdateCommand1
        '
        'OleDbConnection1
        '
        Me.OleDbConnection1.ConnectionString = "Provider=""MSDAORA.1"";User ID=scott;Data Source=ccfmitdb;Password=tiger"
        '
        'OleDbDataAdapter2
        '
        Me.OleDbDataAdapter2.DeleteCommand = Me.OleDbDeleteCommand2
        Me.OleDbDataAdapter2.InsertCommand = Me.OleDbInsertCommand2
        Me.OleDbDataAdapter2.SelectCommand = Me.OleDbSelectCommand2
        Me.OleDbDataAdapter2.TableMappings.AddRange(New System.Data.Common.DataTableMapping() {New System.Data.Common.DataTableMapping("Table", "A_MUSIC_SUPPLIER", New System.Data.Common.DataColumnMapping() {New System.Data.Common.DataColumnMapping("SUPPLIER_ID", "SUPPLIER_ID"), New System.Data.Common.DataColumnMapping("SUPPLIER_NAME", "SUPPLIER_NAME"), New System.Data.Common.DataColumnMapping("ADDRESS", "ADDRESS"), New System.Data.Common.DataColumnMapping("PHONE", "PHONE")})})
        Me.OleDbDataAdapter2.UpdateCommand = Me.OleDbUpdateCommand2
        '
        'OleDbSelectCommand1
        '
        Me.OleDbSelectCommand1.CommandText = "SELECT CATEGORY_ID, CATEGORY FROM A_MUSIC_CATEGORY"
        Me.OleDbSelectCommand1.Connection = Me.OleDbConnection2
        '
        'OleDbInsertCommand1
        '
        Me.OleDbInsertCommand1.CommandText = "INSERT INTO A_MUSIC_CATEGORY(CATEGORY_ID, CATEGORY) VALUES (?, ?)"
        Me.OleDbInsertCommand1.Connection = Me.OleDbConnection2
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 20, "CATEGORY_ID"))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("CATEGORY", System.Data.OleDb.OleDbType.VarChar, 20, "CATEGORY"))
        '
        'OleDbUpdateCommand1
        '
        Me.OleDbUpdateCommand1.CommandText = "UPDATE A_MUSIC_CATEGORY SET CATEGORY_ID = ?, CATEGORY = ? WHERE (CATEGORY_ID = ?)" & _
        " AND (CATEGORY = ? OR ? IS NULL AND CATEGORY IS NULL)"
        Me.OleDbUpdateCommand1.Connection = Me.OleDbConnection2
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 20, "CATEGORY_ID"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("CATEGORY", System.Data.OleDb.OleDbType.VarChar, 20, "CATEGORY"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY", System.Data.DataRowVersion.Original, Nothing))
        '
        'OleDbDeleteCommand1
        '
        Me.OleDbDeleteCommand1.CommandText = "DELETE FROM A_MUSIC_CATEGORY WHERE (CATEGORY_ID = ?) AND (CATEGORY = ? OR ? IS NU" & _
        "LL AND CATEGORY IS NULL)"
        Me.OleDbDeleteCommand1.Connection = Me.OleDbConnection2
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY", System.Data.DataRowVersion.Original, Nothing))
        '
        'OleDbConnection2
        '
        Me.OleDbConnection2.ConnectionString = "Provider=""MSDAORA.1"";User ID=scott;Password=tiger"
        '
        'OleDbSelectCommand2
        '
        Me.OleDbSelectCommand2.CommandText = "SELECT SUPPLIER_ID, SUPPLIER_NAME, ADDRESS, PHONE FROM A_MUSIC_SUPPLIER"
        Me.OleDbSelectCommand2.Connection = Me.OleDbConnection2
        '
        'OleDbInsertCommand2
        '
        Me.OleDbInsertCommand2.CommandText = "INSERT INTO A_MUSIC_SUPPLIER(SUPPLIER_ID, SUPPLIER_NAME, ADDRESS, PHONE) VALUES (" & _
        "?, ?, ?, ?)"
        Me.OleDbInsertCommand2.Connection = Me.OleDbConnection2
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, "SUPPLIER_ID"))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("SUPPLIER_NAME", System.Data.OleDb.OleDbType.VarChar, 20, "SUPPLIER_NAME"))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("ADDRESS", System.Data.OleDb.OleDbType.VarChar, 20, "ADDRESS"))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("PHONE", System.Data.OleDb.OleDbType.VarChar, 20, "PHONE"))
        '
        'OleDbUpdateCommand2
        '
        Me.OleDbUpdateCommand2.CommandText = "UPDATE A_MUSIC_SUPPLIER SET SUPPLIER_ID = ?, SUPPLIER_NAME = ?, ADDRESS = ?, PHON" & _
        "E = ? WHERE (SUPPLIER_ID = ?) AND (ADDRESS = ? OR ? IS NULL AND ADDRESS IS NULL)" & _
        " AND (PHONE = ? OR ? IS NULL AND PHONE IS NULL) AND (SUPPLIER_NAME = ? OR ? IS N" & _
        "ULL AND SUPPLIER_NAME IS NULL)"
        Me.OleDbUpdateCommand2.Connection = Me.OleDbConnection2
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, "SUPPLIER_ID"))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("SUPPLIER_NAME", System.Data.OleDb.OleDbType.VarChar, 20, "SUPPLIER_NAME"))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("ADDRESS", System.Data.OleDb.OleDbType.VarChar, 20, "ADDRESS"))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("PHONE", System.Data.OleDb.OleDbType.VarChar, 20, "PHONE"))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ADDRESS", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ADDRESS", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ADDRESS1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ADDRESS", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PHONE", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "PHONE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PHONE1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "PHONE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_NAME", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_NAME1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_NAME", System.Data.DataRowVersion.Original, Nothing))
        '
        'OleDbDeleteCommand2
        '
        Me.OleDbDeleteCommand2.CommandText = "DELETE FROM A_MUSIC_SUPPLIER WHERE (SUPPLIER_ID = ?) AND (ADDRESS = ? OR ? IS NUL" & _
        "L AND ADDRESS IS NULL) AND (PHONE = ? OR ? IS NULL AND PHONE IS NULL) AND (SUPPL" & _
        "IER_NAME = ? OR ? IS NULL AND SUPPLIER_NAME IS NULL)"
        Me.OleDbDeleteCommand2.Connection = Me.OleDbConnection2
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ADDRESS", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ADDRESS", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ADDRESS1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ADDRESS", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PHONE", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "PHONE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PHONE1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "PHONE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_NAME", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_NAME1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_NAME", System.Data.DataRowVersion.Original, Nothing))
        '
        'Album1
        '
        Me.Album1.DataSetName = "ALBUM"
        Me.Album1.Locale = New System.Globalization.CultureInfo("en-US")
        '
        'Form4
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(6, 13)
        Me.BackColor = System.Drawing.Color.DarkGray
        Me.ClientSize = New System.Drawing.Size(1028, 582)
        Me.Controls.Add(Me.DataGrid2)
        Me.Controls.Add(Me.DataGrid1)
        Me.Controls.Add(Me.GroupBox1)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Button2)
        Me.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Location = New System.Drawing.Point(500, 500)
        Me.Name = "Form4"
        Me.WindowState = System.Windows.Forms.FormWindowState.Maximized
        Me.GroupBox1.ResumeLayout(False)
        CType(Me.Sup1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Cat1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.DataGrid1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.DataGrid2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Album1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub

#End Region

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Dim F3 As New Form3
        F3.Show()
        Me.Hide()
        


    End Sub

    Private Sub Form4_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        DataGrid1.Hide()
        DataGrid2.Hide()

        Cat1.Clear()
        OleDbDataAdapter1.Fill(Cat1)

        Sup1.Clear()
        OleDbDataAdapter2.Fill(Sup1)
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        DataGrid1.Show()
        Cat1.Clear()
        OleDbDataAdapter1.Fill(Cat1)
    End Sub

    Private Sub ComboBox2_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox2.SelectedIndexChanged

    End Sub

    Private Sub ComboBox2_GotFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles ComboBox2.GotFocus
        DataGrid1.Hide()

    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        DataGrid2.Show()
        Sup1.Clear()
        OleDbDataAdapter2.Fill(Sup1)
    End Sub
    Dim ID, ALBUM, sup_id, CAT_ID, units As String
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim cnn As New OleDb.OleDbConnection
        cnn.ConnectionString = "Provider=MSDAORA.1;User ID=scott;Password=tiger; "
        cnn.Open()
        Dim cmd As New OleDb.OleDbCommand
        Dim cmd1 As New OleDb.OleDbCommand


        If TextBox1.Text = "" Or TextBox2.Text = "" Then
            MsgBox("please enter fields", MsgBoxStyle.Critical, "Fill entry")
            TextBox1.Focus()
            Exit Sub
        End If


        cmd.CommandText = "insert into A_MUSIC_PURCHASE values(?,?,?,?,?,?,?,?,?,?,?)"

        cmd.Connection = cnn

        cmd.Parameters.Add(New OleDb.OleDbParameter("A", Data.OleDb.OleDbType.VarChar))
        cmd.Parameters.Add(New OleDb.OleDbParameter("b", Data.OleDb.OleDbType.VarChar))
        cmd.Parameters.Add(New OleDb.OleDbParameter("c", Data.OleDb.OleDbType.VarChar))
        cmd.Parameters.Add(New OleDb.OleDbParameter("d", Data.OleDb.OleDbType.Integer))
        cmd.Parameters.Add(New OleDb.OleDbParameter("E", Data.OleDb.OleDbType.Integer))
        cmd.Parameters.Add(New OleDb.OleDbParameter("F", Data.OleDb.OleDbType.VarChar))
        cmd.Parameters.Add(New OleDb.OleDbParameter("G", Data.OleDb.OleDbType.VarChar))
        cmd.Parameters.Add(New OleDb.OleDbParameter("H", Data.OleDb.OleDbType.VarChar))
        cmd.Parameters.Add(New OleDb.OleDbParameter("I", Data.OleDb.OleDbType.Integer))
        cmd.Parameters.Add(New OleDb.OleDbParameter("J", Data.OleDb.OleDbType.Integer))
        cmd.Parameters.Add(New OleDb.OleDbParameter("K", Data.OleDb.OleDbType.Integer))

        
        cmd.Parameters(0).Value = (TextBox1.Text)

        cmd.Parameters(1).Value = (TextBox2.Text)
        cmd.Parameters(2).Value = (TextBox3.Text)




        cmd.Parameters(3).Value = Val(TextBox4.Text)
        cmd.Parameters(4).Value = Val(TextBox5.Text)
        cmd.Parameters(5).Value = ComboBox3.Text
        cmd.Parameters(6).Value = ComboBox1.Text
        cmd.Parameters(7).Value = ComboBox2.Text
        cmd.Parameters(8).Value = TextBox6.Text
        cmd.Parameters(9).Value = TextBox7.Text
        cmd.Parameters(10).Value = TextBox8.Text


        

        cmd.ExecuteNonQuery()


        ID = TextBox1.Text
        ALBUM = TextBox2.Text

        CAT_ID = ComboBox1.Text
        units = (TextBox4.Text)
        sup_id = ComboBox3.Text



        cmd.CommandText = "insert into A_MUSIC_STOCK values('" + ID + "','" + ALBUM + "','" + CAT_ID + "'," + units + ",'" + sup_id + "')"

        cmd.ExecuteReader()


        MsgBox("Record saved Successfully", MsgBoxStyle.Information, "SAVE")
        
        cnn.Close()
    End Sub

    Private Sub Button1_GotFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles Button1.GotFocus
        DataGrid2.Hide()

    End Sub

    Private Sub ComboBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox1.SelectedIndexChanged

    End Sub
End Class
