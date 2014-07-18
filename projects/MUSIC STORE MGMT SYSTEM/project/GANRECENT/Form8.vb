Public Class Form8
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
    Friend WithEvents ComboBox1 As System.Windows.Forms.ComboBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents OleDbDataAdapter1 As System.Data.OleDb.OleDbDataAdapter
    Friend WithEvents OleDbConnection1 As System.Data.OleDb.OleDbConnection
    Friend WithEvents DisP_PID1 As GANPROJ.DISP_PID
    Friend WithEvents DataGrid1 As System.Windows.Forms.DataGrid
    Friend WithEvents OleDbDataAdapter2 As System.Data.OleDb.OleDbDataAdapter
    Friend WithEvents Display_all_items1 As GANPROJ.display_all_items
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
        Me.ComboBox1 = New System.Windows.Forms.ComboBox
        Me.DisP_PID1 = New GANPROJ.DISP_PID
        Me.Label1 = New System.Windows.Forms.Label
        Me.OleDbDataAdapter1 = New System.Data.OleDb.OleDbDataAdapter
        Me.OleDbConnection1 = New System.Data.OleDb.OleDbConnection
        Me.DataGrid1 = New System.Windows.Forms.DataGrid
        Me.Display_all_items1 = New GANPROJ.display_all_items
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
        CType(Me.DisP_PID1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.DataGrid1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Display_all_items1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'ComboBox1
        '
        Me.ComboBox1.DataSource = Me.DisP_PID1
        Me.ComboBox1.DisplayMember = "A_MUSIC_PURCHASE.P_ID"
        Me.ComboBox1.Location = New System.Drawing.Point(216, 56)
        Me.ComboBox1.Name = "ComboBox1"
        Me.ComboBox1.Size = New System.Drawing.Size(121, 21)
        Me.ComboBox1.TabIndex = 0
        '
        'DisP_PID1
        '
        Me.DisP_PID1.DataSetName = "DISP_PID"
        Me.DisP_PID1.Locale = New System.Globalization.CultureInfo("en-US")
        '
        'Label1
        '
        Me.Label1.Location = New System.Drawing.Point(96, 56)
        Me.Label1.Name = "Label1"
        Me.Label1.TabIndex = 1
        Me.Label1.Text = "PURCHASE ID:"
        '
        'OleDbDataAdapter1
        '
        Me.OleDbDataAdapter1.DeleteCommand = Me.OleDbDeleteCommand1
        Me.OleDbDataAdapter1.InsertCommand = Me.OleDbInsertCommand1
        Me.OleDbDataAdapter1.SelectCommand = Me.OleDbSelectCommand1
        Me.OleDbDataAdapter1.TableMappings.AddRange(New System.Data.Common.DataTableMapping() {New System.Data.Common.DataTableMapping("Table", "A_MUSIC_PURCHASE", New System.Data.Common.DataColumnMapping() {New System.Data.Common.DataColumnMapping("P_ID", "P_ID"), New System.Data.Common.DataColumnMapping("ALBUM_NAME", "ALBUM_NAME"), New System.Data.Common.DataColumnMapping("ARTIST", "ARTIST"), New System.Data.Common.DataColumnMapping("UNITS", "UNITS"), New System.Data.Common.DataColumnMapping("PRICE", "PRICE"), New System.Data.Common.DataColumnMapping("SUPPLIER_ID", "SUPPLIER_ID"), New System.Data.Common.DataColumnMapping("CATEGORY_ID", "CATEGORY_ID"), New System.Data.Common.DataColumnMapping("LANGUAGE", "LANGUAGE"), New System.Data.Common.DataColumnMapping("PDATE", "PDATE"), New System.Data.Common.DataColumnMapping("PMON", "PMON"), New System.Data.Common.DataColumnMapping("PYEAR", "PYEAR")})})
        Me.OleDbDataAdapter1.UpdateCommand = Me.OleDbUpdateCommand1
        '
        'OleDbConnection1
        '
        Me.OleDbConnection1.ConnectionString = "Provider=""MSDAORA.1"";User ID=scott;Data Source=ccfmitdb;Password=tiger"
        '
        'DataGrid1
        '
        Me.DataGrid1.DataMember = "A_MUSIC_PURCHASE"
        Me.DataGrid1.DataSource = Me.Display_all_items1
        Me.DataGrid1.HeaderForeColor = System.Drawing.SystemColors.ControlText
        Me.DataGrid1.Location = New System.Drawing.Point(8, 160)
        Me.DataGrid1.Name = "DataGrid1"
        Me.DataGrid1.Size = New System.Drawing.Size(672, 80)
        Me.DataGrid1.TabIndex = 2
        '
        'Display_all_items1
        '
        Me.Display_all_items1.DataSetName = "display_all_items"
        Me.Display_all_items1.Locale = New System.Globalization.CultureInfo("en-US")
        '
        'OleDbDataAdapter2
        '
        Me.OleDbDataAdapter2.DeleteCommand = Me.OleDbDeleteCommand2
        Me.OleDbDataAdapter2.InsertCommand = Me.OleDbInsertCommand2
        Me.OleDbDataAdapter2.SelectCommand = Me.OleDbSelectCommand2
        Me.OleDbDataAdapter2.TableMappings.AddRange(New System.Data.Common.DataTableMapping() {New System.Data.Common.DataTableMapping("Table", "A_MUSIC_PURCHASE", New System.Data.Common.DataColumnMapping() {New System.Data.Common.DataColumnMapping("P_ID", "P_ID"), New System.Data.Common.DataColumnMapping("ALBUM_NAME", "ALBUM_NAME"), New System.Data.Common.DataColumnMapping("ARTIST", "ARTIST"), New System.Data.Common.DataColumnMapping("UNITS", "UNITS"), New System.Data.Common.DataColumnMapping("PRICE", "PRICE"), New System.Data.Common.DataColumnMapping("SUPPLIER_ID", "SUPPLIER_ID"), New System.Data.Common.DataColumnMapping("CATEGORY_ID", "CATEGORY_ID"), New System.Data.Common.DataColumnMapping("LANGUAGE", "LANGUAGE"), New System.Data.Common.DataColumnMapping("PDATE", "PDATE"), New System.Data.Common.DataColumnMapping("PMON", "PMON"), New System.Data.Common.DataColumnMapping("PYEAR", "PYEAR")})})
        Me.OleDbDataAdapter2.UpdateCommand = Me.OleDbUpdateCommand2
        '
        'OleDbSelectCommand2
        '
        Me.OleDbSelectCommand2.CommandText = "SELECT P_ID, ALBUM_NAME, ARTIST, UNITS, PRICE, SUPPLIER_ID, CATEGORY_ID, LANGUAGE" & _
        ", PDATE, PMON, PYEAR FROM A_MUSIC_PURCHASE WHERE (P_ID = ?)"
        Me.OleDbSelectCommand2.Connection = Me.OleDbConnection2
        Me.OleDbSelectCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("P_ID", System.Data.OleDb.OleDbType.VarChar, 10, "P_ID"))
        '
        'OleDbInsertCommand2
        '
        Me.OleDbInsertCommand2.CommandText = "INSERT INTO A_MUSIC_PURCHASE(P_ID, ALBUM_NAME, ARTIST, UNITS, PRICE, SUPPLIER_ID," & _
        " CATEGORY_ID, LANGUAGE, PDATE, PMON, PYEAR) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?" & _
        ", ?)"
        Me.OleDbInsertCommand2.Connection = Me.OleDbConnection2
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("P_ID", System.Data.OleDb.OleDbType.VarChar, 10, "P_ID"))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, "ALBUM_NAME"))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("ARTIST", System.Data.OleDb.OleDbType.VarChar, 20, "ARTIST"))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("PRICE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, "SUPPLIER_ID"))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, "CATEGORY_ID"))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("LANGUAGE", System.Data.OleDb.OleDbType.VarChar, 20, "LANGUAGE"))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("PDATE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PDATE", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("PMON", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PMON", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbInsertCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("PYEAR", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(4, Byte), CType(0, Byte), "PYEAR", System.Data.DataRowVersion.Current, Nothing))
        '
        'OleDbUpdateCommand2
        '
        Me.OleDbUpdateCommand2.CommandText = "UPDATE A_MUSIC_PURCHASE SET P_ID = ?, ALBUM_NAME = ?, ARTIST = ?, UNITS = ?, PRIC" & _
        "E = ?, SUPPLIER_ID = ?, CATEGORY_ID = ?, LANGUAGE = ?, PDATE = ?, PMON = ?, PYEA" & _
        "R = ? WHERE (P_ID = ?) AND (ALBUM_NAME = ? OR ? IS NULL AND ALBUM_NAME IS NULL) " & _
        "AND (ARTIST = ? OR ? IS NULL AND ARTIST IS NULL) AND (CATEGORY_ID = ? OR ? IS NU" & _
        "LL AND CATEGORY_ID IS NULL) AND (LANGUAGE = ? OR ? IS NULL AND LANGUAGE IS NULL)" & _
        " AND (PDATE = ? OR ? IS NULL AND PDATE IS NULL) AND (PMON = ? OR ? IS NULL AND P" & _
        "MON IS NULL) AND (PRICE = ? OR ? IS NULL AND PRICE IS NULL) AND (PYEAR = ? OR ? " & _
        "IS NULL AND PYEAR IS NULL) AND (SUPPLIER_ID = ? OR ? IS NULL AND SUPPLIER_ID IS " & _
        "NULL) AND (UNITS = ? OR ? IS NULL AND UNITS IS NULL)"
        Me.OleDbUpdateCommand2.Connection = Me.OleDbConnection2
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("P_ID", System.Data.OleDb.OleDbType.VarChar, 10, "P_ID"))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, "ALBUM_NAME"))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("ARTIST", System.Data.OleDb.OleDbType.VarChar, 20, "ARTIST"))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("PRICE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, "SUPPLIER_ID"))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, "CATEGORY_ID"))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("LANGUAGE", System.Data.OleDb.OleDbType.VarChar, 20, "LANGUAGE"))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("PDATE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PDATE", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("PMON", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PMON", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("PYEAR", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(4, Byte), CType(0, Byte), "PYEAR", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_P_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "P_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ARTIST", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ARTIST", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ARTIST1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ARTIST", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_LANGUAGE", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "LANGUAGE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_LANGUAGE1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "LANGUAGE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PDATE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PDATE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PDATE1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PDATE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PMON", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PMON", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PMON1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PMON", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PRICE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PRICE1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PYEAR", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(4, Byte), CType(0, Byte), "PYEAR", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PYEAR1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(4, Byte), CType(0, Byte), "PYEAR", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        '
        'OleDbDeleteCommand2
        '
        Me.OleDbDeleteCommand2.CommandText = "DELETE FROM A_MUSIC_PURCHASE WHERE (P_ID = ?) AND (ALBUM_NAME = ? OR ? IS NULL AN" & _
        "D ALBUM_NAME IS NULL) AND (ARTIST = ? OR ? IS NULL AND ARTIST IS NULL) AND (CATE" & _
        "GORY_ID = ? OR ? IS NULL AND CATEGORY_ID IS NULL) AND (LANGUAGE = ? OR ? IS NULL" & _
        " AND LANGUAGE IS NULL) AND (PDATE = ? OR ? IS NULL AND PDATE IS NULL) AND (PMON " & _
        "= ? OR ? IS NULL AND PMON IS NULL) AND (PRICE = ? OR ? IS NULL AND PRICE IS NULL" & _
        ") AND (PYEAR = ? OR ? IS NULL AND PYEAR IS NULL) AND (SUPPLIER_ID = ? OR ? IS NU" & _
        "LL AND SUPPLIER_ID IS NULL) AND (UNITS = ? OR ? IS NULL AND UNITS IS NULL)"
        Me.OleDbDeleteCommand2.Connection = Me.OleDbConnection2
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_P_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "P_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ARTIST", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ARTIST", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ARTIST1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ARTIST", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_LANGUAGE", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "LANGUAGE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_LANGUAGE1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "LANGUAGE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PDATE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PDATE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PDATE1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PDATE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PMON", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PMON", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PMON1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PMON", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PRICE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PRICE1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PYEAR", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(4, Byte), CType(0, Byte), "PYEAR", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand2.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PYEAR1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(4, Byte), CType(0, Byte), "PYEAR", System.Data.DataRowVersion.Original, Nothing))
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
        Me.OleDbSelectCommand1.CommandText = "SELECT P_ID, ALBUM_NAME, ARTIST, UNITS, PRICE, SUPPLIER_ID, CATEGORY_ID, LANGUAGE" & _
        ", PDATE, PMON, PYEAR FROM A_MUSIC_PURCHASE"
        Me.OleDbSelectCommand1.Connection = Me.OleDbConnection2
        '
        'OleDbInsertCommand1
        '
        Me.OleDbInsertCommand1.CommandText = "INSERT INTO A_MUSIC_PURCHASE(P_ID, ALBUM_NAME, ARTIST, UNITS, PRICE, SUPPLIER_ID," & _
        " CATEGORY_ID, LANGUAGE, PDATE, PMON, PYEAR) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?" & _
        ", ?)"
        Me.OleDbInsertCommand1.Connection = Me.OleDbConnection2
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("P_ID", System.Data.OleDb.OleDbType.VarChar, 10, "P_ID"))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, "ALBUM_NAME"))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("ARTIST", System.Data.OleDb.OleDbType.VarChar, 20, "ARTIST"))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("PRICE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, "SUPPLIER_ID"))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, "CATEGORY_ID"))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("LANGUAGE", System.Data.OleDb.OleDbType.VarChar, 20, "LANGUAGE"))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("PDATE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PDATE", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("PMON", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PMON", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("PYEAR", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(4, Byte), CType(0, Byte), "PYEAR", System.Data.DataRowVersion.Current, Nothing))
        '
        'OleDbUpdateCommand1
        '
        Me.OleDbUpdateCommand1.CommandText = "UPDATE A_MUSIC_PURCHASE SET P_ID = ?, ALBUM_NAME = ?, ARTIST = ?, UNITS = ?, PRIC" & _
        "E = ?, SUPPLIER_ID = ?, CATEGORY_ID = ?, LANGUAGE = ?, PDATE = ?, PMON = ?, PYEA" & _
        "R = ? WHERE (P_ID = ?) AND (ALBUM_NAME = ? OR ? IS NULL AND ALBUM_NAME IS NULL) " & _
        "AND (ARTIST = ? OR ? IS NULL AND ARTIST IS NULL) AND (CATEGORY_ID = ? OR ? IS NU" & _
        "LL AND CATEGORY_ID IS NULL) AND (LANGUAGE = ? OR ? IS NULL AND LANGUAGE IS NULL)" & _
        " AND (PDATE = ? OR ? IS NULL AND PDATE IS NULL) AND (PMON = ? OR ? IS NULL AND P" & _
        "MON IS NULL) AND (PRICE = ? OR ? IS NULL AND PRICE IS NULL) AND (PYEAR = ? OR ? " & _
        "IS NULL AND PYEAR IS NULL) AND (SUPPLIER_ID = ? OR ? IS NULL AND SUPPLIER_ID IS " & _
        "NULL) AND (UNITS = ? OR ? IS NULL AND UNITS IS NULL)"
        Me.OleDbUpdateCommand1.Connection = Me.OleDbConnection2
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("P_ID", System.Data.OleDb.OleDbType.VarChar, 10, "P_ID"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, "ALBUM_NAME"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("ARTIST", System.Data.OleDb.OleDbType.VarChar, 20, "ARTIST"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("PRICE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, "SUPPLIER_ID"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, "CATEGORY_ID"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("LANGUAGE", System.Data.OleDb.OleDbType.VarChar, 20, "LANGUAGE"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("PDATE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PDATE", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("PMON", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PMON", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("PYEAR", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(4, Byte), CType(0, Byte), "PYEAR", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_P_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "P_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ARTIST", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ARTIST", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ARTIST1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ARTIST", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_LANGUAGE", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "LANGUAGE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_LANGUAGE1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "LANGUAGE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PDATE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PDATE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PDATE1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PDATE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PMON", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PMON", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PMON1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PMON", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PRICE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PRICE1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PYEAR", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(4, Byte), CType(0, Byte), "PYEAR", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PYEAR1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(4, Byte), CType(0, Byte), "PYEAR", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        '
        'OleDbDeleteCommand1
        '
        Me.OleDbDeleteCommand1.CommandText = "DELETE FROM A_MUSIC_PURCHASE WHERE (P_ID = ?) AND (ALBUM_NAME = ? OR ? IS NULL AN" & _
        "D ALBUM_NAME IS NULL) AND (ARTIST = ? OR ? IS NULL AND ARTIST IS NULL) AND (CATE" & _
        "GORY_ID = ? OR ? IS NULL AND CATEGORY_ID IS NULL) AND (LANGUAGE = ? OR ? IS NULL" & _
        " AND LANGUAGE IS NULL) AND (PDATE = ? OR ? IS NULL AND PDATE IS NULL) AND (PMON " & _
        "= ? OR ? IS NULL AND PMON IS NULL) AND (PRICE = ? OR ? IS NULL AND PRICE IS NULL" & _
        ") AND (PYEAR = ? OR ? IS NULL AND PYEAR IS NULL) AND (SUPPLIER_ID = ? OR ? IS NU" & _
        "LL AND SUPPLIER_ID IS NULL) AND (UNITS = ? OR ? IS NULL AND UNITS IS NULL)"
        Me.OleDbDeleteCommand1.Connection = Me.OleDbConnection2
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_P_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "P_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ARTIST", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ARTIST", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ARTIST1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ARTIST", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_CATEGORY_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "CATEGORY_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_LANGUAGE", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "LANGUAGE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_LANGUAGE1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "LANGUAGE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PDATE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PDATE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PDATE1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PDATE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PMON", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PMON", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PMON1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(2, Byte), CType(0, Byte), "PMON", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PRICE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PRICE1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PYEAR", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(4, Byte), CType(0, Byte), "PYEAR", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PYEAR1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(4, Byte), CType(0, Byte), "PYEAR", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_SUPPLIER_ID1", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "SUPPLIER_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        '
        'Form8
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
        Me.BackColor = System.Drawing.Color.DarkGray
        Me.ClientSize = New System.Drawing.Size(696, 382)
        Me.Controls.Add(Me.DataGrid1)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.ComboBox1)
        Me.Name = "Form8"
        Me.Text = "Form8"
        CType(Me.DisP_PID1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.DataGrid1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Display_all_items1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub

#End Region

    Private Sub Form8_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        DisP_PID1.Clear()
        OleDbDataAdapter1.Fill(DisP_PID1)
    End Sub

    Private Sub ComboBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox1.SelectedIndexChanged
        OleDbDataAdapter2.SelectCommand.Parameters("p_id").Value = ComboBox1.Text
        Display_all_items1.Clear()
        OleDbDataAdapter2.Fill(Display_all_items1)

    End Sub
End Class
