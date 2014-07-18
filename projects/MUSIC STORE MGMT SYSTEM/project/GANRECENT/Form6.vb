Public Class Form6
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
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents DataGrid1 As System.Windows.Forms.DataGrid
    Friend WithEvents OleDbDataAdapter1 As System.Data.OleDb.OleDbDataAdapter
    Friend WithEvents OleDbConnection1 As System.Data.OleDb.OleDbConnection
    Friend WithEvents Display1 As GANPROJ.DISPLAY
    Friend WithEvents OleDbDataAdapter2 As System.Data.OleDb.OleDbDataAdapter
    Friend WithEvents DisP_ID1 As GANPROJ.DISP_ID
    Friend WithEvents ComboBox1 As System.Windows.Forms.ComboBox
    Friend WithEvents OleDbSelectCommand2 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbInsertCommand2 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbUpdateCommand2 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbDeleteCommand2 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbConnection2 As System.Data.OleDb.OleDbConnection
    Friend WithEvents OleDbSelectCommand1 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbInsertCommand1 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbUpdateCommand1 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbDeleteCommand1 As System.Data.OleDb.OleDbCommand
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.ComboBox1 = New System.Windows.Forms.ComboBox
        Me.DisP_ID1 = New GANPROJ.DISP_ID
        Me.DataGrid1 = New System.Windows.Forms.DataGrid
        Me.Display1 = New GANPROJ.DISPLAY
        Me.Label1 = New System.Windows.Forms.Label
        Me.Button1 = New System.Windows.Forms.Button
        Me.Button2 = New System.Windows.Forms.Button
        Me.OleDbDataAdapter1 = New System.Data.OleDb.OleDbDataAdapter
        Me.OleDbConnection1 = New System.Data.OleDb.OleDbConnection
        Me.OleDbDataAdapter2 = New System.Data.OleDb.OleDbDataAdapter
        Me.OleDbSelectCommand2 = New System.Data.OleDb.OleDbCommand
        Me.OleDbInsertCommand2 = New System.Data.OleDb.OleDbCommand
        Me.OleDbUpdateCommand2 = New System.Data.OleDb.OleDbCommand
        Me.OleDbDeleteCommand2 = New System.Data.OleDb.OleDbCommand
        Me.OleDbConnection2 = New System.Data.OleDb.OleDbConnection
        Me.OleDbSelectCommand1 = New System.Data.OleDb.OleDbCommand
        Me.OleDbInsertCommand1 = New System.Data.OleDb.OleDbCommand
        Me.OleDbUpdateCommand1 = New System.Data.OleDb.OleDbCommand
        Me.OleDbDeleteCommand1 = New System.Data.OleDb.OleDbCommand
        Me.GroupBox1.SuspendLayout()
        CType(Me.DisP_ID1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.DataGrid1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Display1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.ComboBox1)
        Me.GroupBox1.Controls.Add(Me.DataGrid1)
        Me.GroupBox1.Controls.Add(Me.Label1)
        Me.GroupBox1.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GroupBox1.Location = New System.Drawing.Point(56, 32)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(544, 288)
        Me.GroupBox1.TabIndex = 0
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "STOCK DISPLAY"
        '
        'ComboBox1
        '
        Me.ComboBox1.DataSource = Me.DisP_ID1
        Me.ComboBox1.DisplayMember = "A_MUSIC_STOCK.ITEM_ID"
        Me.ComboBox1.Location = New System.Drawing.Point(200, 32)
        Me.ComboBox1.Name = "ComboBox1"
        Me.ComboBox1.Size = New System.Drawing.Size(121, 21)
        Me.ComboBox1.TabIndex = 3
        '
        'DisP_ID1
        '
        Me.DisP_ID1.DataSetName = "DISP_ID"
        Me.DisP_ID1.Locale = New System.Globalization.CultureInfo("en-US")
        '
        'DataGrid1
        '
        Me.DataGrid1.DataMember = "A_MUSIC_STOCK"
        Me.DataGrid1.DataSource = Me.Display1
        Me.DataGrid1.HeaderForeColor = System.Drawing.SystemColors.ControlText
        Me.DataGrid1.Location = New System.Drawing.Point(72, 136)
        Me.DataGrid1.Name = "DataGrid1"
        Me.DataGrid1.Size = New System.Drawing.Size(416, 80)
        Me.DataGrid1.TabIndex = 2
        '
        'Display1
        '
        Me.Display1.DataSetName = "DISPLAY"
        Me.Display1.Locale = New System.Globalization.CultureInfo("en-US")
        '
        'Label1
        '
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(80, 32)
        Me.Label1.Name = "Label1"
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Item Id"
        Me.Label1.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Button1
        '
        Me.Button1.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Button1.Location = New System.Drawing.Point(192, 360)
        Me.Button1.Name = "Button1"
        Me.Button1.TabIndex = 1
        Me.Button1.Text = "SEARCH"
        '
        'Button2
        '
        Me.Button2.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Button2.Location = New System.Drawing.Point(344, 360)
        Me.Button2.Name = "Button2"
        Me.Button2.TabIndex = 2
        Me.Button2.Text = "EXIT"
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
        'OleDbDataAdapter2
        '
        Me.OleDbDataAdapter2.DeleteCommand = Me.OleDbDeleteCommand2
        Me.OleDbDataAdapter2.InsertCommand = Me.OleDbInsertCommand2
        Me.OleDbDataAdapter2.SelectCommand = Me.OleDbSelectCommand2
        Me.OleDbDataAdapter2.TableMappings.AddRange(New System.Data.Common.DataTableMapping() {New System.Data.Common.DataTableMapping("Table", "A_MUSIC_STOCK", New System.Data.Common.DataColumnMapping() {New System.Data.Common.DataColumnMapping("ITEM_ID", "ITEM_ID"), New System.Data.Common.DataColumnMapping("ALBUM_NAME", "ALBUM_NAME"), New System.Data.Common.DataColumnMapping("CATEGORY_ID", "CATEGORY_ID"), New System.Data.Common.DataColumnMapping("UNITS", "UNITS"), New System.Data.Common.DataColumnMapping("SUPPLIER_ID", "SUPPLIER_ID")})})
        Me.OleDbDataAdapter2.UpdateCommand = Me.OleDbUpdateCommand2
        '
        'OleDbSelectCommand2
        '
        Me.OleDbSelectCommand2.CommandText = "SELECT ITEM_ID, ALBUM_NAME, CATEGORY_ID, UNITS, SUPPLIER_ID FROM A_MUSIC_STOCK"
        Me.OleDbSelectCommand2.Connection = Me.OleDbConnection2
        '
        'OleDbInsertCommand2
        '
        Me.OleDbInsertCommand2.CommandText = "INSERT INTO A_MUSIC_STOCK(ITEM_ID, ALBUM_NAME, CATEGORY_ID, UNITS, SUPPLIER_ID) V" & _
        "ALUES (?, ?, ?, ?, ?)"
        Me.OleDbInsertCommand2.Connection = Me.OleDbConnection2
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("ITEM_ID", System.Data.OleDb.OleDbType.VarChar, 10, "ITEM_ID"))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, "ALBUM_NAME"))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, "CATEGORY_ID"))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, "SUPPLIER_ID"))
        '
        'OleDbUpdateCommand2
        '
        Me.OleDbUpdateCommand2.CommandText = "UPDATE A_MUSIC_STOCK SET ITEM_ID = ?, ALBUM_NAME = ?, CATEGORY_ID = ?, UNITS = ?," & _
        " SUPPLIER_ID = ? WHERE (ALBUM_NAME = ?) AND (CATEGORY_ID = ? OR ? IS NULL AND CA" & _
        "TEGORY_ID IS NULL) AND (ITEM_ID = ? OR ? IS NULL AND ITEM_ID IS NULL) AND (SUPPL" & _
        "IER_ID = ? OR ? IS NULL AND SUPPLIER_ID IS NULL) AND (UNITS = ? OR ? IS NULL AND" & _
        " UNITS IS NULL)"
        Me.OleDbUpdateCommand2.Connection = Me.OleDbConnection2
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("ITEM_ID", System.Data.OleDb.OleDbType.VarChar, 10, "ITEM_ID"))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, "ALBUM_NAME"))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, "CATEGORY_ID"))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, "SUPPLIER_ID"))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ITEM_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ITEM_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ITEM_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ITEM_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        '
        'OleDbDeleteCommand2
        '
        Me.OleDbDeleteCommand2.CommandText = "DELETE FROM A_MUSIC_STOCK WHERE (ALBUM_NAME = ?) AND (CATEGORY_ID = ? OR ? IS NUL" & _
        "L AND CATEGORY_ID IS NULL) AND (ITEM_ID = ? OR ? IS NULL AND ITEM_ID IS NULL) AN" & _
        "D (SUPPLIER_ID = ? OR ? IS NULL AND SUPPLIER_ID IS NULL) AND (UNITS = ? OR ? IS " & _
        "NULL AND UNITS IS NULL)"
        Me.OleDbDeleteCommand2.Connection = Me.OleDbConnection2
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ITEM_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ITEM_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ITEM_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ITEM_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        '
        'OleDbConnection2
        '
        Me.OleDbConnection2.ConnectionString = "Provider=""MSDAORA.1"";User ID=scott;Password=tiger"
        '
        'OleDbSelectCommand1
        '
        Me.OleDbSelectCommand1.CommandText = "SELECT ITEM_ID, ALBUM_NAME, CATEGORY_ID, UNITS, SUPPLIER_ID FROM A_MUSIC_STOCK WH" & _
        "ERE (ITEM_ID = ?)"
        Me.OleDbSelectCommand1.Connection = Me.OleDbConnection2
        Me.OleDbSelectCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("ITEM_ID", System.Data.OleDb.OleDbType.VarChar, 10, "ITEM_ID"))
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
        'Form6
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
        Me.BackColor = System.Drawing.Color.DarkGray
        Me.ClientSize = New System.Drawing.Size(640, 574)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.GroupBox1)
        Me.Name = "Form6"
        Me.Text = "Form6"
        Me.GroupBox1.ResumeLayout(False)
        CType(Me.DisP_ID1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.DataGrid1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Display1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub

#End Region

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        
        Me.Hide()

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        
    End Sub

    Private Sub Form6_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        DisP_ID1.Clear()
        OleDbDataAdapter2.Fill(DisP_ID1)
    End Sub

    Private Sub ComboBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox1.SelectedIndexChanged
        OleDbDataAdapter1.SelectCommand.Parameters("ITEM_ID").Value = ComboBox1.Text
        Display1.Clear()
        OleDbDataAdapter1.Fill(Display1)
    End Sub
End Class
