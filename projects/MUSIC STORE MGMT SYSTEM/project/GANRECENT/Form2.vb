Public Class Form2
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
    Friend WithEvents grptype As System.Windows.Forms.GroupBox
    Friend WithEvents btnbilling As System.Windows.Forms.Button
    Friend WithEvents btnsearch As System.Windows.Forms.Button
    Friend WithEvents btnstock As System.Windows.Forms.Button
    Friend WithEvents MainMenu1 As System.Windows.Forms.MainMenu
    Friend WithEvents MenuItem1 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem5 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem6 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem2 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem3 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem4 As System.Windows.Forms.MenuItem
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents StatusBar1 As System.Windows.Forms.StatusBar
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents TextBox2 As System.Windows.Forms.TextBox
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents RichTextBox1 As System.Windows.Forms.RichTextBox
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents ComboBox2 As System.Windows.Forms.ComboBox
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Friend WithEvents OleDbDataAdapter1 As System.Data.OleDb.OleDbDataAdapter
    Friend WithEvents OleDbConnection1 As System.Data.OleDb.OleDbConnection
    Friend WithEvents Id1 As GANPROJ.ID
    Friend WithEvents TextBox3 As System.Windows.Forms.TextBox
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents MenuItem7 As System.Windows.Forms.MenuItem
    Friend WithEvents OleDbSelectCommand1 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbInsertCommand1 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbUpdateCommand1 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbDeleteCommand1 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbConnection2 As System.Data.OleDb.OleDbConnection
    Friend WithEvents Album1 As GANPROJ.ALBUM
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
        Dim resources As System.Resources.ResourceManager = New System.Resources.ResourceManager(GetType(Form2))
        Me.grptype = New System.Windows.Forms.GroupBox
        Me.btnbilling = New System.Windows.Forms.Button
        Me.btnsearch = New System.Windows.Forms.Button
        Me.btnstock = New System.Windows.Forms.Button
        Me.MainMenu1 = New System.Windows.Forms.MainMenu
        Me.MenuItem1 = New System.Windows.Forms.MenuItem
        Me.MenuItem5 = New System.Windows.Forms.MenuItem
        Me.MenuItem6 = New System.Windows.Forms.MenuItem
        Me.MenuItem2 = New System.Windows.Forms.MenuItem
        Me.MenuItem7 = New System.Windows.Forms.MenuItem
        Me.MenuItem3 = New System.Windows.Forms.MenuItem
        Me.MenuItem4 = New System.Windows.Forms.MenuItem
        Me.Label1 = New System.Windows.Forms.Label
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.StatusBar1 = New System.Windows.Forms.StatusBar
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.TextBox3 = New System.Windows.Forms.TextBox
        Me.TextBox1 = New System.Windows.Forms.TextBox
        Me.ComboBox2 = New System.Windows.Forms.ComboBox
        Me.Id1 = New GANPROJ.ID
        Me.Label4 = New System.Windows.Forms.Label
        Me.Button1 = New System.Windows.Forms.Button
        Me.Label3 = New System.Windows.Forms.Label
        Me.TextBox2 = New System.Windows.Forms.TextBox
        Me.Label2 = New System.Windows.Forms.Label
        Me.RichTextBox1 = New System.Windows.Forms.RichTextBox
        Me.OleDbDataAdapter1 = New System.Data.OleDb.OleDbDataAdapter
        Me.OleDbConnection1 = New System.Data.OleDb.OleDbConnection
        Me.Label5 = New System.Windows.Forms.Label
        Me.Label6 = New System.Windows.Forms.Label
        Me.Label7 = New System.Windows.Forms.Label
        Me.OleDbSelectCommand1 = New System.Data.OleDb.OleDbCommand
        Me.OleDbInsertCommand1 = New System.Data.OleDb.OleDbCommand
        Me.OleDbUpdateCommand1 = New System.Data.OleDb.OleDbCommand
        Me.OleDbDeleteCommand1 = New System.Data.OleDb.OleDbCommand
        Me.OleDbConnection2 = New System.Data.OleDb.OleDbConnection
        Me.Album1 = New GANPROJ.ALBUM
        Me.grptype.SuspendLayout()
        Me.GroupBox1.SuspendLayout()
        CType(Me.Id1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Album1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'grptype
        '
        Me.grptype.BackColor = System.Drawing.Color.DarkGray
        Me.grptype.Controls.Add(Me.btnbilling)
        Me.grptype.Controls.Add(Me.btnsearch)
        Me.grptype.Controls.Add(Me.btnstock)
        Me.grptype.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.grptype.Location = New System.Drawing.Point(8, 0)
        Me.grptype.Name = "grptype"
        Me.grptype.Size = New System.Drawing.Size(296, 56)
        Me.grptype.TabIndex = 2
        Me.grptype.TabStop = False
        '
        'btnbilling
        '
        Me.btnbilling.BackColor = System.Drawing.Color.LightGray
        Me.btnbilling.BackgroundImage = CType(resources.GetObject("btnbilling.BackgroundImage"), System.Drawing.Image)
        Me.btnbilling.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnbilling.Location = New System.Drawing.Point(104, 16)
        Me.btnbilling.Name = "btnbilling"
        Me.btnbilling.Size = New System.Drawing.Size(88, 32)
        Me.btnbilling.TabIndex = 2
        Me.btnbilling.Text = "BILLING"
        Me.btnbilling.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'btnsearch
        '
        Me.btnsearch.BackgroundImage = CType(resources.GetObject("btnsearch.BackgroundImage"), System.Drawing.Image)
        Me.btnsearch.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnsearch.Location = New System.Drawing.Point(8, 16)
        Me.btnsearch.Name = "btnsearch"
        Me.btnsearch.Size = New System.Drawing.Size(88, 32)
        Me.btnsearch.TabIndex = 1
        Me.btnsearch.Text = "SEARCH"
        Me.btnsearch.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'btnstock
        '
        Me.btnstock.BackgroundImage = CType(resources.GetObject("btnstock.BackgroundImage"), System.Drawing.Image)
        Me.btnstock.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnstock.Location = New System.Drawing.Point(200, 16)
        Me.btnstock.Name = "btnstock"
        Me.btnstock.Size = New System.Drawing.Size(88, 32)
        Me.btnstock.TabIndex = 3
        Me.btnstock.Text = "STOCK"
        Me.btnstock.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'MainMenu1
        '
        Me.MainMenu1.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem1, Me.MenuItem6, Me.MenuItem3, Me.MenuItem4})
        '
        'MenuItem1
        '
        Me.MenuItem1.Index = 0
        Me.MenuItem1.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem5})
        Me.MenuItem1.Text = "FILE"
        '
        'MenuItem5
        '
        Me.MenuItem5.Index = 0
        Me.MenuItem5.Text = "CLOSE"
        '
        'MenuItem6
        '
        Me.MenuItem6.Index = 1
        Me.MenuItem6.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem2, Me.MenuItem7})
        Me.MenuItem6.Text = "VIEW"
        '
        'MenuItem2
        '
        Me.MenuItem2.Index = 0
        Me.MenuItem2.Text = "STOCK"
        '
        'MenuItem7
        '
        Me.MenuItem7.Index = 1
        Me.MenuItem7.Text = "SEARCH"
        '
        'MenuItem3
        '
        Me.MenuItem3.Index = 2
        Me.MenuItem3.Text = "OPTIONS"
        '
        'MenuItem4
        '
        Me.MenuItem4.Index = 3
        Me.MenuItem4.Text = "HELP"
        '
        'Label1
        '
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, CType((System.Drawing.FontStyle.Bold Or System.Drawing.FontStyle.Italic), System.Drawing.FontStyle), System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(408, 16)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(296, 48)
        Me.Label1.TabIndex = 4
        Me.Label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        Me.Timer1.Interval = 300
        '
        'StatusBar1
        '
        Me.StatusBar1.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, CType((System.Drawing.FontStyle.Bold Or System.Drawing.FontStyle.Italic), System.Drawing.FontStyle), System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.StatusBar1.Location = New System.Drawing.Point(0, 435)
        Me.StatusBar1.Name = "StatusBar1"
        Me.StatusBar1.Size = New System.Drawing.Size(880, 22)
        Me.StatusBar1.TabIndex = 5
        Me.StatusBar1.Text = "BILLING"
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.TextBox3)
        Me.GroupBox1.Controls.Add(Me.TextBox1)
        Me.GroupBox1.Controls.Add(Me.ComboBox2)
        Me.GroupBox1.Controls.Add(Me.Label4)
        Me.GroupBox1.Controls.Add(Me.Button1)
        Me.GroupBox1.Controls.Add(Me.Label3)
        Me.GroupBox1.Controls.Add(Me.TextBox2)
        Me.GroupBox1.Controls.Add(Me.Label2)
        Me.GroupBox1.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GroupBox1.Location = New System.Drawing.Point(8, 96)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(240, 296)
        Me.GroupBox1.TabIndex = 6
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "ITEMS"
        '
        'TextBox3
        '
        Me.TextBox3.Location = New System.Drawing.Point(56, 256)
        Me.TextBox3.Name = "TextBox3"
        Me.TextBox3.TabIndex = 20
        Me.TextBox3.Text = "TextBox3"
        Me.TextBox3.Visible = False
        '
        'TextBox1
        '
        Me.TextBox1.Location = New System.Drawing.Point(120, 72)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.TabIndex = 19
        Me.TextBox1.Text = ""
        '
        'ComboBox2
        '
        Me.ComboBox2.DataSource = Me.Id1
        Me.ComboBox2.DisplayMember = "A_MUSIC_STOCK.ITEM_ID"
        Me.ComboBox2.Location = New System.Drawing.Point(120, 32)
        Me.ComboBox2.Name = "ComboBox2"
        Me.ComboBox2.Size = New System.Drawing.Size(96, 21)
        Me.ComboBox2.TabIndex = 18
        '
        'Id1
        '
        Me.Id1.DataSetName = "ID"
        Me.Id1.Locale = New System.Globalization.CultureInfo("en-US")
        '
        'Label4
        '
        Me.Label4.Location = New System.Drawing.Point(8, 72)
        Me.Label4.Name = "Label4"
        Me.Label4.TabIndex = 17
        Me.Label4.Text = "Album"
        Me.Label4.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Button1
        '
        Me.Button1.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Button1.Location = New System.Drawing.Point(88, 200)
        Me.Button1.Name = "Button1"
        Me.Button1.TabIndex = 15
        Me.Button1.Text = "ADD"
        '
        'Label3
        '
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label3.Location = New System.Drawing.Point(8, 120)
        Me.Label3.Name = "Label3"
        Me.Label3.TabIndex = 14
        Me.Label3.Text = "No. of Copies"
        Me.Label3.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'TextBox2
        '
        Me.TextBox2.Location = New System.Drawing.Point(120, 120)
        Me.TextBox2.Name = "TextBox2"
        Me.TextBox2.TabIndex = 13
        Me.TextBox2.Text = ""
        '
        'Label2
        '
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.Location = New System.Drawing.Point(8, 32)
        Me.Label2.Name = "Label2"
        Me.Label2.TabIndex = 11
        Me.Label2.Text = "Item Id"
        Me.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'RichTextBox1
        '
        Me.RichTextBox1.Location = New System.Drawing.Point(320, 104)
        Me.RichTextBox1.Name = "RichTextBox1"
        Me.RichTextBox1.Size = New System.Drawing.Size(328, 288)
        Me.RichTextBox1.TabIndex = 7
        Me.RichTextBox1.Text = ""
        '
        'OleDbDataAdapter1
        '
        Me.OleDbDataAdapter1.DeleteCommand = Me.OleDbDeleteCommand1
        Me.OleDbDataAdapter1.InsertCommand = Me.OleDbInsertCommand1
        Me.OleDbDataAdapter1.SelectCommand = Me.OleDbSelectCommand1
        Me.OleDbDataAdapter1.TableMappings.AddRange(New System.Data.Common.DataTableMapping() {New System.Data.Common.DataTableMapping("Table", "A_MUSIC_STOCK", New System.Data.Common.DataColumnMapping() {New System.Data.Common.DataColumnMapping("ITEM_ID", "ITEM_ID"), New System.Data.Common.DataColumnMapping("ALBUM_NAME", "ALBUM_NAME"), New System.Data.Common.DataColumnMapping("CATEGORY_ID", "CATEGORY_ID"), New System.Data.Common.DataColumnMapping("UNITS", "UNITS"), New System.Data.Common.DataColumnMapping("SUPPLIER_ID", "SUPPLIER_ID")})})
        Me.OleDbDataAdapter1.UpdateCommand = Me.OleDbUpdateCommand1
        '
        'OleDbConnection1
        '
        Me.OleDbConnection1.ConnectionString = "Provider=""MSDAORA.1"";User ID=scott;Data Source=ccfmitdb;Password=tiger"
        '
        'Label5
        '
        Me.Label5.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label5.Location = New System.Drawing.Point(544, 80)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(100, 16)
        Me.Label5.TabIndex = 8
        '
        'Label6
        '
        Me.Label6.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label6.Location = New System.Drawing.Point(336, 80)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(100, 16)
        Me.Label6.TabIndex = 9
        '
        'Label7
        '
        Me.Label7.Location = New System.Drawing.Point(464, 408)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(176, 23)
        Me.Label7.TabIndex = 10
        '
        'OleDbSelectCommand1
        '
        Me.OleDbSelectCommand1.CommandText = "SELECT ITEM_ID, ALBUM_NAME, CATEGORY_ID, UNITS, SUPPLIER_ID FROM A_MUSIC_STOCK"
        Me.OleDbSelectCommand1.Connection = Me.OleDbConnection2
        '
        'OleDbInsertCommand1
        '
        Me.OleDbInsertCommand1.CommandText = "INSERT INTO A_MUSIC_STOCK(ITEM_ID, ALBUM_NAME, CATEGORY_ID, UNITS, SUPPLIER_ID) V" & _
        "ALUES (?, ?, ?, ?, ?)"
        Me.OleDbInsertCommand1.Connection = Me.OleDbConnection2
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("ITEM_ID", System.Data.OleDb.OleDbType.VarChar, 10, "ITEM_ID"))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, "ALBUM_NAME"))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, "CATEGORY_ID"))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, "SUPPLIER_ID"))
        '
        'OleDbUpdateCommand1
        '
        Me.OleDbUpdateCommand1.CommandText = "UPDATE A_MUSIC_STOCK SET ITEM_ID = ?, ALBUM_NAME = ?, CATEGORY_ID = ?, UNITS = ?," & _
        " SUPPLIER_ID = ? WHERE (ALBUM_NAME = ?) AND (CATEGORY_ID = ? OR ? IS NULL AND CA" & _
        "TEGORY_ID IS NULL) AND (ITEM_ID = ? OR ? IS NULL AND ITEM_ID IS NULL) AND (SUPPL" & _
        "IER_ID = ? OR ? IS NULL AND SUPPLIER_ID IS NULL) AND (UNITS = ? OR ? IS NULL AND" & _
        " UNITS IS NULL)"
        Me.OleDbUpdateCommand1.Connection = Me.OleDbConnection2
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("ITEM_ID", System.Data.OleDb.OleDbType.VarChar, 10, "ITEM_ID"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, "ALBUM_NAME"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, "CATEGORY_ID"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, "SUPPLIER_ID"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ITEM_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ITEM_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ITEM_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ITEM_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        '
        'OleDbDeleteCommand1
        '
        Me.OleDbDeleteCommand1.CommandText = "DELETE FROM A_MUSIC_STOCK WHERE (ALBUM_NAME = ?) AND (CATEGORY_ID = ? OR ? IS NUL" & _
        "L AND CATEGORY_ID IS NULL) AND (ITEM_ID = ? OR ? IS NULL AND ITEM_ID IS NULL) AN" & _
        "D (SUPPLIER_ID = ? OR ? IS NULL AND SUPPLIER_ID IS NULL) AND (UNITS = ? OR ? IS " & _
        "NULL AND UNITS IS NULL)"
        Me.OleDbDeleteCommand1.Connection = Me.OleDbConnection2
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ITEM_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ITEM_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ITEM_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ITEM_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        '
        'OleDbConnection2
        '
        Me.OleDbConnection2.ConnectionString = "Provider=""MSDAORA.1"";User ID=scott;Password=tiger"
        '
        'Album1
        '
        Me.Album1.DataSetName = "ALBUM"
        Me.Album1.Locale = New System.Globalization.CultureInfo("en-US")
        '
        'Form2
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
        Me.BackColor = System.Drawing.Color.DarkGray
        Me.ClientSize = New System.Drawing.Size(880, 457)
        Me.Controls.Add(Me.Label7)
        Me.Controls.Add(Me.Label6)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.RichTextBox1)
        Me.Controls.Add(Me.GroupBox1)
        Me.Controls.Add(Me.StatusBar1)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.grptype)
        Me.Menu = Me.MainMenu1
        Me.Name = "Form2"
        Me.Text = "Form2"
        Me.WindowState = System.Windows.Forms.FormWindowState.Maximized
        Me.grptype.ResumeLayout(False)
        Me.GroupBox1.ResumeLayout(False)
        CType(Me.Id1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Album1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub

#End Region
    Dim cnn As New OleDb.OleDbConnection("Provider=MSDAORA.1;User ID=scott;Password=tiger; ")
    Dim cmd As New OleDb.OleDbCommand("", cnn)
    Dim DR As OleDb.OleDbDataReader


    Private Sub btnsearch_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnsearch.Click

        Dim F1 As New frm1
        F1.Show()
        Me.Hide()

    End Sub

    Private Sub MenuItem5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem5.Click
        End
    End Sub
    Dim billno As String

    Private Sub Form2_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Id1.Clear()
        OleDbDataAdapter1.Fill(Id1)

        cnn.Open()
        cmd.Connection = cnn
        cmd.CommandText = "select A_MUSIC_SEQBILL.nextval from dual"   'GETERATE BILL NUMBER



        cmd.ExecuteNonQuery()
        DR = cmd.ExecuteReader
        DR.Read()

        billno = DR.Item(0)
        Label6.Text = Now.Today

        Label5.Text = "BILL No. :" + billno.ToString
        DR.Close()
        cnn.Close()

        Timer1.Start()
        RichTextBox1.Text = "    ITEM ID      " + "ITEM NAME            " + "No. OF COPIES     " + "" + vbCrLf
        RichTextBox1.Text += "*******************************************************************************"
    End Sub
    Dim TITLE As String = "MUSIC WORLD"
    Dim i As Integer = 0
    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        If i >= TITLE.Length Then
            Label1.Text = ""
            i = 0
        End If
        Label1.Text = Label1.Text + TITLE.Chars(i)
        i = i + 1
    End Sub

   

    
    
    Private Sub btnstock_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnstock.Click
        Dim f3 As New Form3
        f3.Show()
        Me.Hide()

    End Sub
    Dim TEMP As Integer
    Dim price As Integer
    Dim total As Integer



    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        RichTextBox1.Text += "  "
        RichTextBox1.Text += ComboBox2.Text + "                     "
        RichTextBox1.Text += TextBox1.Text + "                      "
        RichTextBox1.Text += TextBox2.Text + vbCrLf + vbCrLf

        cnn.Open()

        cmd.CommandText = "select * from A_MUSIC_STOCK"
        cmd.Connection = cnn
        cmd.ExecuteNonQuery()
        DR = cmd.ExecuteReader
        While DR.Read()
            If ComboBox2.Text = DR.Item(0) Then
                TEMP = DR.Item(3)
                'price = DR.Item(4)
                'total = total + price
                'MsgBox(TEMP)
                'Label7.Text = "TOTAL : Rs." + total.ToString
            End If
        End While
        DR.Close()





        TEMP = TEMP - Val(TextBox2.Text)
        TextBox3.Text = TEMP            'TEXTBOX3 IS HIDDEN (USED JUST TO INITIALIZE)

        Try
            cmd.CommandText = "update A_MUSIC_STOCK set units=" + TextBox3.Text + " where ITEM_ID='" + ComboBox2.Text + "'"
            cmd.Connection = cnn
            cmd.ExecuteNonQuery()
        Catch ex As Exception
            MsgBox(ex.Message)
        End Try
        cnn.Close()

        cnn.Open()
        cmd.CommandText = "select * from A_MUSIC_PURCHASE"
        cmd.Connection = cnn
        cmd.ExecuteNonQuery()
        DR = cmd.ExecuteReader
        While DR.Read()
            If ComboBox2.Text = DR.Item(0) Then

                price = DR.Item(4)
                'RichTextBox1.Text += price.ToString + vbCrLf
                total = total + price * Val(TextBox2.Text)
                'MsgBox(TEMP)
                Label7.Text = "TOTAL : Rs." + total.ToString
            End If
        End While
        DR.Close()
        cnn.Close()
    End Sub

    Private Sub ComboBox2_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox2.SelectedIndexChanged
        'cnn.Close()
        cnn.Open()
        cmd.CommandText = "SELECT ALBUM_NAME,UNITS FROM A_MUSIC_STOCK WHERE ITEM_ID='" + ComboBox2.Text + "'"
        DR = cmd.ExecuteReader
        If DR.Read Then
            TextBox1.Text = DR(0)
        End If
        cnn.Close()


    End Sub

    
    Private Sub MenuItem2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem2.Click
        Dim F3 As New Form3
        F3.Show()
        Me.Hide()

    End Sub

    Private Sub MenuItem7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem7.Click
        Dim F1 As New frm1
        F1.Show()
        Me.Hide()

    End Sub
End Class
