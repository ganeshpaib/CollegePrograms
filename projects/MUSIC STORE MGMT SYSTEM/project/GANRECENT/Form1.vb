Public Class frm1
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
    Friend WithEvents MainMenu1 As System.Windows.Forms.MainMenu
    Friend WithEvents MenuItem1 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem5 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem6 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem2 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem4 As System.Windows.Forms.MenuItem
    Friend WithEvents StatusBar1 As System.Windows.Forms.StatusBar
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents grpsearch As System.Windows.Forms.GroupBox
    Friend WithEvents grptype As System.Windows.Forms.GroupBox
    Friend WithEvents btnbilling As System.Windows.Forms.Button
    Friend WithEvents btnsearch As System.Windows.Forms.Button
    Friend WithEvents btnstock As System.Windows.Forms.Button
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents btnaudio As System.Windows.Forms.Button
    Friend WithEvents btnvideo As System.Windows.Forms.Button
    Friend WithEvents btnmovie As System.Windows.Forms.Button
    Friend WithEvents btndvd As System.Windows.Forms.Button
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents grpaudio As System.Windows.Forms.GroupBox
    Friend WithEvents grpvideo As System.Windows.Forms.GroupBox
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents Label10 As System.Windows.Forms.Label
    Friend WithEvents Label11 As System.Windows.Forms.Label
    Friend WithEvents Label12 As System.Windows.Forms.Label
    Friend WithEvents TXTAARTIST As System.Windows.Forms.TextBox
    Friend WithEvents TXTVARTIST As System.Windows.Forms.TextBox
    Friend WithEvents TXTVTITLE As System.Windows.Forms.TextBox
    Friend WithEvents BTNASEARCH As System.Windows.Forms.Button
    Friend WithEvents BTNVSEARCH As System.Windows.Forms.Button
    Friend WithEvents CBACATEGORY As System.Windows.Forms.ComboBox
    Friend WithEvents TXTVALBUM As System.Windows.Forms.TextBox
    Friend WithEvents CBAYEAR As System.Windows.Forms.ComboBox
    Friend WithEvents CBVYEAR As System.Windows.Forms.ComboBox
    Friend WithEvents CBVCATEGORY As System.Windows.Forms.ComboBox
    Friend WithEvents OleDbConnection2 As System.Data.OleDb.OleDbConnection
    Friend WithEvents OleDbDataAdapter1 As System.Data.OleDb.OleDbDataAdapter
    Friend WithEvents Searc1 As GANPROJ.searc
    Friend WithEvents DataGrid1 As System.Windows.Forms.DataGrid
    Friend WithEvents OleDbDataAdapter2 As System.Data.OleDb.OleDbDataAdapter
    Friend WithEvents ComboBox1 As System.Windows.Forms.ComboBox
    Friend WithEvents DisP_ALBUM1 As GANPROJ.DISP_ALBUM
    Friend WithEvents MenuItem7 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem3 As System.Windows.Forms.MenuItem
    Friend WithEvents OleDbConnection1 As System.Data.OleDb.OleDbConnection
    Friend WithEvents OleDbSelectCommand1 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbInsertCommand1 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbUpdateCommand1 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbDeleteCommand1 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbSelectCommand2 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbInsertCommand2 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbUpdateCommand2 As System.Data.OleDb.OleDbCommand
    Friend WithEvents OleDbDeleteCommand2 As System.Data.OleDb.OleDbCommand
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
        Dim resources As System.Resources.ResourceManager = New System.Resources.ResourceManager(GetType(frm1))
        Me.grpsearch = New System.Windows.Forms.GroupBox
        Me.btndvd = New System.Windows.Forms.Button
        Me.btnmovie = New System.Windows.Forms.Button
        Me.btnvideo = New System.Windows.Forms.Button
        Me.btnaudio = New System.Windows.Forms.Button
        Me.Label2 = New System.Windows.Forms.Label
        Me.MainMenu1 = New System.Windows.Forms.MainMenu
        Me.MenuItem1 = New System.Windows.Forms.MenuItem
        Me.MenuItem5 = New System.Windows.Forms.MenuItem
        Me.MenuItem6 = New System.Windows.Forms.MenuItem
        Me.MenuItem2 = New System.Windows.Forms.MenuItem
        Me.MenuItem7 = New System.Windows.Forms.MenuItem
        Me.MenuItem4 = New System.Windows.Forms.MenuItem
        Me.MenuItem3 = New System.Windows.Forms.MenuItem
        Me.grptype = New System.Windows.Forms.GroupBox
        Me.btnbilling = New System.Windows.Forms.Button
        Me.btnsearch = New System.Windows.Forms.Button
        Me.btnstock = New System.Windows.Forms.Button
        Me.StatusBar1 = New System.Windows.Forms.StatusBar
        Me.Label1 = New System.Windows.Forms.Label
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.grpaudio = New System.Windows.Forms.GroupBox
        Me.ComboBox1 = New System.Windows.Forms.ComboBox
        Me.DisP_ALBUM1 = New GANPROJ.DISP_ALBUM
        Me.Label9 = New System.Windows.Forms.Label
        Me.CBACATEGORY = New System.Windows.Forms.ComboBox
        Me.Label8 = New System.Windows.Forms.Label
        Me.Label7 = New System.Windows.Forms.Label
        Me.BTNASEARCH = New System.Windows.Forms.Button
        Me.Label4 = New System.Windows.Forms.Label
        Me.TXTAARTIST = New System.Windows.Forms.TextBox
        Me.CBAYEAR = New System.Windows.Forms.ComboBox
        Me.grpvideo = New System.Windows.Forms.GroupBox
        Me.Label12 = New System.Windows.Forms.Label
        Me.Label11 = New System.Windows.Forms.Label
        Me.Label10 = New System.Windows.Forms.Label
        Me.CBVCATEGORY = New System.Windows.Forms.ComboBox
        Me.CBVYEAR = New System.Windows.Forms.ComboBox
        Me.TXTVALBUM = New System.Windows.Forms.TextBox
        Me.BTNVSEARCH = New System.Windows.Forms.Button
        Me.Label6 = New System.Windows.Forms.Label
        Me.Label5 = New System.Windows.Forms.Label
        Me.TXTVARTIST = New System.Windows.Forms.TextBox
        Me.TXTVTITLE = New System.Windows.Forms.TextBox
        Me.OleDbConnection2 = New System.Data.OleDb.OleDbConnection
        Me.OleDbDataAdapter1 = New System.Data.OleDb.OleDbDataAdapter
        Me.OleDbDeleteCommand1 = New System.Data.OleDb.OleDbCommand
        Me.OleDbConnection1 = New System.Data.OleDb.OleDbConnection
        Me.OleDbInsertCommand1 = New System.Data.OleDb.OleDbCommand
        Me.OleDbSelectCommand1 = New System.Data.OleDb.OleDbCommand
        Me.OleDbUpdateCommand1 = New System.Data.OleDb.OleDbCommand
        Me.Searc1 = New GANPROJ.searc
        Me.DataGrid1 = New System.Windows.Forms.DataGrid
        Me.OleDbDataAdapter2 = New System.Data.OleDb.OleDbDataAdapter
        Me.OleDbDeleteCommand2 = New System.Data.OleDb.OleDbCommand
        Me.OleDbInsertCommand2 = New System.Data.OleDb.OleDbCommand
        Me.OleDbSelectCommand2 = New System.Data.OleDb.OleDbCommand
        Me.OleDbUpdateCommand2 = New System.Data.OleDb.OleDbCommand
        Me.grpsearch.SuspendLayout()
        Me.grptype.SuspendLayout()
        Me.grpaudio.SuspendLayout()
        CType(Me.DisP_ALBUM1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.grpvideo.SuspendLayout()
        CType(Me.Searc1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.DataGrid1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'grpsearch
        '
        Me.grpsearch.BackColor = System.Drawing.Color.DarkGray
        Me.grpsearch.Controls.Add(Me.btndvd)
        Me.grpsearch.Controls.Add(Me.btnmovie)
        Me.grpsearch.Controls.Add(Me.btnvideo)
        Me.grpsearch.Controls.Add(Me.btnaudio)
        Me.grpsearch.Controls.Add(Me.Label2)
        Me.grpsearch.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.grpsearch.Location = New System.Drawing.Point(0, 64)
        Me.grpsearch.Name = "grpsearch"
        Me.grpsearch.Size = New System.Drawing.Size(232, 128)
        Me.grpsearch.TabIndex = 0
        Me.grpsearch.TabStop = False
        '
        'btndvd
        '
        Me.btndvd.BackColor = System.Drawing.Color.Silver
        Me.btndvd.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btndvd.Location = New System.Drawing.Point(112, 80)
        Me.btndvd.Name = "btndvd"
        Me.btndvd.Size = New System.Drawing.Size(88, 32)
        Me.btndvd.TabIndex = 4
        Me.btndvd.Text = "DVD"
        '
        'btnmovie
        '
        Me.btnmovie.BackColor = System.Drawing.Color.Silver
        Me.btnmovie.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnmovie.Location = New System.Drawing.Point(8, 80)
        Me.btnmovie.Name = "btnmovie"
        Me.btnmovie.Size = New System.Drawing.Size(88, 32)
        Me.btnmovie.TabIndex = 3
        Me.btnmovie.Text = "MOVIE"
        '
        'btnvideo
        '
        Me.btnvideo.BackColor = System.Drawing.Color.Silver
        Me.btnvideo.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnvideo.Location = New System.Drawing.Point(112, 40)
        Me.btnvideo.Name = "btnvideo"
        Me.btnvideo.Size = New System.Drawing.Size(88, 32)
        Me.btnvideo.TabIndex = 2
        Me.btnvideo.Text = "VIDEO"
        '
        'btnaudio
        '
        Me.btnaudio.BackColor = System.Drawing.Color.Silver
        Me.btnaudio.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btnaudio.Location = New System.Drawing.Point(8, 40)
        Me.btnaudio.Name = "btnaudio"
        Me.btnaudio.Size = New System.Drawing.Size(88, 32)
        Me.btnaudio.TabIndex = 1
        Me.btnaudio.Text = "AUDIO"
        '
        'Label2
        '
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.Location = New System.Drawing.Point(8, 8)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(120, 24)
        Me.Label2.TabIndex = 0
        Me.Label2.Text = "Select Search Type :"
        Me.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'MainMenu1
        '
        Me.MainMenu1.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem1, Me.MenuItem6, Me.MenuItem4})
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
        Me.MenuItem2.Text = "BILLING"
        '
        'MenuItem7
        '
        Me.MenuItem7.Index = 1
        Me.MenuItem7.Text = "STOCK"
        '
        'MenuItem4
        '
        Me.MenuItem4.Index = 2
        Me.MenuItem4.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem3})
        Me.MenuItem4.Text = "HELP"
        '
        'MenuItem3
        '
        Me.MenuItem3.Index = 0
        Me.MenuItem3.Text = "ABOUT"
        '
        'grptype
        '
        Me.grptype.BackColor = System.Drawing.Color.DarkGray
        Me.grptype.Controls.Add(Me.btnbilling)
        Me.grptype.Controls.Add(Me.btnsearch)
        Me.grptype.Controls.Add(Me.btnstock)
        Me.grptype.Location = New System.Drawing.Point(8, 0)
        Me.grptype.Name = "grptype"
        Me.grptype.Size = New System.Drawing.Size(296, 56)
        Me.grptype.TabIndex = 1
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
        'StatusBar1
        '
        Me.StatusBar1.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, CType((System.Drawing.FontStyle.Bold Or System.Drawing.FontStyle.Italic), System.Drawing.FontStyle), System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.StatusBar1.Location = New System.Drawing.Point(0, 563)
        Me.StatusBar1.Name = "StatusBar1"
        Me.StatusBar1.Size = New System.Drawing.Size(848, 22)
        Me.StatusBar1.TabIndex = 2
        Me.StatusBar1.Text = "SEARCH"
        '
        'Label1
        '
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 14.25!, CType((System.Drawing.FontStyle.Bold Or System.Drawing.FontStyle.Italic), System.Drawing.FontStyle), System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(392, 8)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(296, 48)
        Me.Label1.TabIndex = 3
        Me.Label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        Me.Timer1.Interval = 300
        '
        'grpaudio
        '
        Me.grpaudio.BackColor = System.Drawing.Color.DarkGray
        Me.grpaudio.Controls.Add(Me.ComboBox1)
        Me.grpaudio.Controls.Add(Me.Label9)
        Me.grpaudio.Controls.Add(Me.CBACATEGORY)
        Me.grpaudio.Controls.Add(Me.Label8)
        Me.grpaudio.Controls.Add(Me.Label7)
        Me.grpaudio.Controls.Add(Me.BTNASEARCH)
        Me.grpaudio.Controls.Add(Me.Label4)
        Me.grpaudio.Controls.Add(Me.TXTAARTIST)
        Me.grpaudio.Controls.Add(Me.CBAYEAR)
        Me.grpaudio.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.grpaudio.Location = New System.Drawing.Point(0, 208)
        Me.grpaudio.Name = "grpaudio"
        Me.grpaudio.Size = New System.Drawing.Size(232, 272)
        Me.grpaudio.TabIndex = 4
        Me.grpaudio.TabStop = False
        Me.grpaudio.Text = "AUDIO"
        '
        'ComboBox1
        '
        Me.ComboBox1.DataSource = Me.DisP_ALBUM1
        Me.ComboBox1.DisplayMember = "A_MUSIC_PURCHASE.ALBUM_NAME"
        Me.ComboBox1.Location = New System.Drawing.Point(120, 32)
        Me.ComboBox1.Name = "ComboBox1"
        Me.ComboBox1.Size = New System.Drawing.Size(104, 21)
        Me.ComboBox1.TabIndex = 12
        '
        'DisP_ALBUM1
        '
        Me.DisP_ALBUM1.DataSetName = "DISP_ALBUM"
        Me.DisP_ALBUM1.Locale = New System.Globalization.CultureInfo("en-US")
        '
        'Label9
        '
        Me.Label9.Location = New System.Drawing.Point(16, 160)
        Me.Label9.Name = "Label9"
        Me.Label9.TabIndex = 10
        Me.Label9.Text = "CATEGORY"
        Me.Label9.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'CBACATEGORY
        '
        Me.CBACATEGORY.Items.AddRange(New Object() {"BENGALI", "BHOJPURI", "CLASSICAL", "DEVOTIONAL", "ENGLISH", "HINDI", "KANNADA", "KONKANI", "ORIYA", "TAMIL", "TELUGU", "WESTERN"})
        Me.CBACATEGORY.Location = New System.Drawing.Point(120, 160)
        Me.CBACATEGORY.Name = "CBACATEGORY"
        Me.CBACATEGORY.Size = New System.Drawing.Size(104, 21)
        Me.CBACATEGORY.TabIndex = 9
        '
        'Label8
        '
        Me.Label8.Location = New System.Drawing.Point(16, 120)
        Me.Label8.Name = "Label8"
        Me.Label8.TabIndex = 8
        Me.Label8.Text = "YEAR"
        Me.Label8.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label7
        '
        Me.Label7.Location = New System.Drawing.Point(16, 32)
        Me.Label7.Name = "Label7"
        Me.Label7.TabIndex = 6
        Me.Label7.Text = "ALBUM"
        Me.Label7.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'BTNASEARCH
        '
        Me.BTNASEARCH.BackColor = System.Drawing.Color.Silver
        Me.BTNASEARCH.Location = New System.Drawing.Point(72, 208)
        Me.BTNASEARCH.Name = "BTNASEARCH"
        Me.BTNASEARCH.Size = New System.Drawing.Size(88, 32)
        Me.BTNASEARCH.TabIndex = 4
        Me.BTNASEARCH.Text = "SEARCH"
        '
        'Label4
        '
        Me.Label4.ImageAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.Label4.Location = New System.Drawing.Point(16, 72)
        Me.Label4.Name = "Label4"
        Me.Label4.TabIndex = 3
        Me.Label4.Text = "ARTIST"
        Me.Label4.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'TXTAARTIST
        '
        Me.TXTAARTIST.Location = New System.Drawing.Point(120, 72)
        Me.TXTAARTIST.Name = "TXTAARTIST"
        Me.TXTAARTIST.TabIndex = 1
        Me.TXTAARTIST.Text = ""
        '
        'CBAYEAR
        '
        Me.CBAYEAR.Items.AddRange(New Object() {"1970", "1971", "1972", "1973", "1974", "1975", "1976", "1977", "1978", "1979", "1980", "1981", "1982", "1983", "1984", "1985", "1986", "1987", "1988", "1989"})
        Me.CBAYEAR.Location = New System.Drawing.Point(120, 120)
        Me.CBAYEAR.Name = "CBAYEAR"
        Me.CBAYEAR.Size = New System.Drawing.Size(64, 21)
        Me.CBAYEAR.TabIndex = 11
        '
        'grpvideo
        '
        Me.grpvideo.BackColor = System.Drawing.Color.DarkGray
        Me.grpvideo.Controls.Add(Me.Label12)
        Me.grpvideo.Controls.Add(Me.Label11)
        Me.grpvideo.Controls.Add(Me.Label10)
        Me.grpvideo.Controls.Add(Me.CBVCATEGORY)
        Me.grpvideo.Controls.Add(Me.CBVYEAR)
        Me.grpvideo.Controls.Add(Me.TXTVALBUM)
        Me.grpvideo.Controls.Add(Me.BTNVSEARCH)
        Me.grpvideo.Controls.Add(Me.Label6)
        Me.grpvideo.Controls.Add(Me.Label5)
        Me.grpvideo.Controls.Add(Me.TXTVARTIST)
        Me.grpvideo.Controls.Add(Me.TXTVTITLE)
        Me.grpvideo.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.grpvideo.Location = New System.Drawing.Point(0, 208)
        Me.grpvideo.Name = "grpvideo"
        Me.grpvideo.Size = New System.Drawing.Size(232, 296)
        Me.grpvideo.TabIndex = 1
        Me.grpvideo.TabStop = False
        Me.grpvideo.Text = "VIDEO"
        '
        'Label12
        '
        Me.Label12.Location = New System.Drawing.Point(8, 192)
        Me.Label12.Name = "Label12"
        Me.Label12.TabIndex = 16
        Me.Label12.Text = "CATEGORY"
        Me.Label12.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label11
        '
        Me.Label11.Location = New System.Drawing.Point(8, 152)
        Me.Label11.Name = "Label11"
        Me.Label11.TabIndex = 15
        Me.Label11.Text = "YEAR"
        Me.Label11.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label10
        '
        Me.Label10.Location = New System.Drawing.Point(8, 112)
        Me.Label10.Name = "Label10"
        Me.Label10.TabIndex = 14
        Me.Label10.Text = "ALBUM"
        Me.Label10.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'CBVCATEGORY
        '
        Me.CBVCATEGORY.Items.AddRange(New Object() {"BENGALI", "BHOJPURI", "CLASSICAL", "DEVOTIONAL", "ENGLISH", "HINDI", "KANNADA", "KONKANI", "ORIYA", "TAMIL", "TELUGU", "WESTERN"})
        Me.CBVCATEGORY.Location = New System.Drawing.Point(120, 192)
        Me.CBVCATEGORY.Name = "CBVCATEGORY"
        Me.CBVCATEGORY.Size = New System.Drawing.Size(104, 21)
        Me.CBVCATEGORY.TabIndex = 13
        '
        'CBVYEAR
        '
        Me.CBVYEAR.Items.AddRange(New Object() {"1970", "1971", "1972", "1973", "1974", "1975", "1976", "1977", "1978", "1979", "1980", "1981", "1982", "1983", "1984", "1985", "1986", "1987", "1988", "1989", "1990", "1991", "1992", "1993", "1994", "1995", "1996", "1997", "1998", "1999", "2000", "2001", "2002", "2003", "2004", "2005", "2006", "2007"})
        Me.CBVYEAR.Location = New System.Drawing.Point(120, 152)
        Me.CBVYEAR.Name = "CBVYEAR"
        Me.CBVYEAR.Size = New System.Drawing.Size(64, 21)
        Me.CBVYEAR.TabIndex = 12
        '
        'TXTVALBUM
        '
        Me.TXTVALBUM.Location = New System.Drawing.Point(120, 112)
        Me.TXTVALBUM.Name = "TXTVALBUM"
        Me.TXTVALBUM.TabIndex = 7
        Me.TXTVALBUM.Text = ""
        '
        'BTNVSEARCH
        '
        Me.BTNVSEARCH.BackColor = System.Drawing.Color.Silver
        Me.BTNVSEARCH.Location = New System.Drawing.Point(80, 232)
        Me.BTNVSEARCH.Name = "BTNVSEARCH"
        Me.BTNVSEARCH.Size = New System.Drawing.Size(88, 32)
        Me.BTNVSEARCH.TabIndex = 6
        Me.BTNVSEARCH.Text = "SEARCH"
        '
        'Label6
        '
        Me.Label6.ImageAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.Label6.Location = New System.Drawing.Point(8, 72)
        Me.Label6.Name = "Label6"
        Me.Label6.TabIndex = 5
        Me.Label6.Text = "ARTIST"
        Me.Label6.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label5
        '
        Me.Label5.ImageAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.Label5.Location = New System.Drawing.Point(8, 32)
        Me.Label5.Name = "Label5"
        Me.Label5.TabIndex = 4
        Me.Label5.Text = "TITLE"
        Me.Label5.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'TXTVARTIST
        '
        Me.TXTVARTIST.Location = New System.Drawing.Point(120, 72)
        Me.TXTVARTIST.Name = "TXTVARTIST"
        Me.TXTVARTIST.TabIndex = 3
        Me.TXTVARTIST.Text = ""
        '
        'TXTVTITLE
        '
        Me.TXTVTITLE.Location = New System.Drawing.Point(120, 32)
        Me.TXTVTITLE.Name = "TXTVTITLE"
        Me.TXTVTITLE.TabIndex = 2
        Me.TXTVTITLE.Text = ""
        '
        'OleDbConnection2
        '
        Me.OleDbConnection2.ConnectionString = "Provider=""MSDAORA.1"";User ID=scott;Data Source=ccfmitdb;Password=tiger"
        '
        'OleDbDataAdapter1
        '
        Me.OleDbDataAdapter1.DeleteCommand = Me.OleDbDeleteCommand1
        Me.OleDbDataAdapter1.InsertCommand = Me.OleDbInsertCommand1
        Me.OleDbDataAdapter1.SelectCommand = Me.OleDbSelectCommand1
        Me.OleDbDataAdapter1.TableMappings.AddRange(New System.Data.Common.DataTableMapping() {New System.Data.Common.DataTableMapping("Table", "A_MUSIC_PURCHASE", New System.Data.Common.DataColumnMapping() {New System.Data.Common.DataColumnMapping("ALBUM_NAME", "ALBUM_NAME"), New System.Data.Common.DataColumnMapping("ARTIST", "ARTIST"), New System.Data.Common.DataColumnMapping("UNITS", "UNITS"), New System.Data.Common.DataColumnMapping("PRICE", "PRICE"), New System.Data.Common.DataColumnMapping("LANGUAGE", "LANGUAGE"), New System.Data.Common.DataColumnMapping("P_ID", "P_ID")})})
        Me.OleDbDataAdapter1.UpdateCommand = Me.OleDbUpdateCommand1
        '
        'OleDbDeleteCommand1
        '
        Me.OleDbDeleteCommand1.CommandText = "DELETE FROM A_MUSIC_PURCHASE WHERE (P_ID = ?) AND (ALBUM_NAME = ? OR ? IS NULL AN" & _
        "D ALBUM_NAME IS NULL) AND (ARTIST = ? OR ? IS NULL AND ARTIST IS NULL) AND (LANG" & _
        "UAGE = ? OR ? IS NULL AND LANGUAGE IS NULL) AND (PRICE = ? OR ? IS NULL AND PRIC" & _
        "E IS NULL) AND (UNITS = ? OR ? IS NULL AND UNITS IS NULL)"
        Me.OleDbDeleteCommand1.Connection = Me.OleDbConnection1
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_P_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "P_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ARTIST", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ARTIST", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ARTIST1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ARTIST", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_LANGUAGE", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "LANGUAGE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_LANGUAGE1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "LANGUAGE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PRICE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PRICE1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbDeleteCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        '
        'OleDbConnection1
        '
        Me.OleDbConnection1.ConnectionString = "Provider=""MSDAORA.1"";User ID=scott;Password=tiger"
        '
        'OleDbInsertCommand1
        '
        Me.OleDbInsertCommand1.CommandText = "INSERT INTO A_MUSIC_PURCHASE(ALBUM_NAME, ARTIST, UNITS, PRICE, LANGUAGE, P_ID) VA" & _
        "LUES (?, ?, ?, ?, ?, ?)"
        Me.OleDbInsertCommand1.Connection = Me.OleDbConnection1
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, "ALBUM_NAME"))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("ARTIST", System.Data.OleDb.OleDbType.VarChar, 20, "ARTIST"))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("PRICE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("LANGUAGE", System.Data.OleDb.OleDbType.VarChar, 20, "LANGUAGE"))
        Me.OleDbInsertCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("P_ID", System.Data.OleDb.OleDbType.VarChar, 10, "P_ID"))
        '
        'OleDbSelectCommand1
        '
        Me.OleDbSelectCommand1.CommandText = "SELECT ALBUM_NAME, ARTIST, UNITS, PRICE, LANGUAGE, P_ID FROM A_MUSIC_PURCHASE WHE" & _
        "RE (ALBUM_NAME = ?)"
        Me.OleDbSelectCommand1.Connection = Me.OleDbConnection1
        Me.OleDbSelectCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, "ALBUM_NAME"))
        '
        'OleDbUpdateCommand1
        '
        Me.OleDbUpdateCommand1.CommandText = "UPDATE A_MUSIC_PURCHASE SET ALBUM_NAME = ?, ARTIST = ?, UNITS = ?, PRICE = ?, LAN" & _
        "GUAGE = ?, P_ID = ? WHERE (P_ID = ?) AND (ALBUM_NAME = ? OR ? IS NULL AND ALBUM_" & _
        "NAME IS NULL) AND (ARTIST = ? OR ? IS NULL AND ARTIST IS NULL) AND (LANGUAGE = ?" & _
        " OR ? IS NULL AND LANGUAGE IS NULL) AND (PRICE = ? OR ? IS NULL AND PRICE IS NUL" & _
        "L) AND (UNITS = ? OR ? IS NULL AND UNITS IS NULL)"
        Me.OleDbUpdateCommand1.Connection = Me.OleDbConnection1
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, "ALBUM_NAME"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("ARTIST", System.Data.OleDb.OleDbType.VarChar, 20, "ARTIST"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("PRICE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Current, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("LANGUAGE", System.Data.OleDb.OleDbType.VarChar, 20, "LANGUAGE"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("P_ID", System.Data.OleDb.OleDbType.VarChar, 10, "P_ID"))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_P_ID", System.Data.OleDb.OleDbType.VarChar, 10, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "P_ID", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ALBUM_NAME1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ALBUM_NAME", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ARTIST", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ARTIST", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_ARTIST1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "ARTIST", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_LANGUAGE", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "LANGUAGE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_LANGUAGE1", System.Data.OleDb.OleDbType.VarChar, 20, System.Data.ParameterDirection.Input, False, CType(0, Byte), CType(0, Byte), "LANGUAGE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PRICE", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_PRICE1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(5, Byte), CType(2, Byte), "PRICE", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        Me.OleDbUpdateCommand1.Parameters.Add(New System.Data.OleDb.OleDbParameter("Original_UNITS1", System.Data.OleDb.OleDbType.Decimal, 0, System.Data.ParameterDirection.Input, False, CType(3, Byte), CType(0, Byte), "UNITS", System.Data.DataRowVersion.Original, Nothing))
        '
        'Searc1
        '
        Me.Searc1.DataSetName = "searc"
        Me.Searc1.Locale = New System.Globalization.CultureInfo("en-US")
        '
        'DataGrid1
        '
        Me.DataGrid1.DataMember = "A_MUSIC_PURCHASE"
        Me.DataGrid1.DataSource = Me.Searc1
        Me.DataGrid1.HeaderForeColor = System.Drawing.SystemColors.ControlText
        Me.DataGrid1.Location = New System.Drawing.Point(304, 296)
        Me.DataGrid1.Name = "DataGrid1"
        Me.DataGrid1.Size = New System.Drawing.Size(488, 80)
        Me.DataGrid1.TabIndex = 5
        '
        'OleDbDataAdapter2
        '
        Me.OleDbDataAdapter2.DeleteCommand = Me.OleDbDeleteCommand2
        Me.OleDbDataAdapter2.InsertCommand = Me.OleDbInsertCommand2
        Me.OleDbDataAdapter2.SelectCommand = Me.OleDbSelectCommand2
        Me.OleDbDataAdapter2.TableMappings.AddRange(New System.Data.Common.DataTableMapping() {New System.Data.Common.DataTableMapping("Table", "A_MUSIC_PURCHASE", New System.Data.Common.DataColumnMapping() {New System.Data.Common.DataColumnMapping("P_ID", "P_ID"), New System.Data.Common.DataColumnMapping("ALBUM_NAME", "ALBUM_NAME"), New System.Data.Common.DataColumnMapping("ARTIST", "ARTIST"), New System.Data.Common.DataColumnMapping("UNITS", "UNITS"), New System.Data.Common.DataColumnMapping("PRICE", "PRICE"), New System.Data.Common.DataColumnMapping("SUPPLIER_ID", "SUPPLIER_ID"), New System.Data.Common.DataColumnMapping("CATEGORY_ID", "CATEGORY_ID"), New System.Data.Common.DataColumnMapping("LANGUAGE", "LANGUAGE"), New System.Data.Common.DataColumnMapping("PDATE", "PDATE"), New System.Data.Common.DataColumnMapping("PMON", "PMON"), New System.Data.Common.DataColumnMapping("PYEAR", "PYEAR")})})
        Me.OleDbDataAdapter2.UpdateCommand = Me.OleDbUpdateCommand2
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
        Me.OleDbDeleteCommand2.Connection = Me.OleDbConnection1
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
        'OleDbInsertCommand2
        '
        Me.OleDbInsertCommand2.CommandText = "INSERT INTO A_MUSIC_PURCHASE(P_ID, ALBUM_NAME, ARTIST, UNITS, PRICE, SUPPLIER_ID," & _
        " CATEGORY_ID, LANGUAGE, PDATE, PMON, PYEAR) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?" & _
        ", ?)"
        Me.OleDbInsertCommand2.Connection = Me.OleDbConnection1
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
        'OleDbSelectCommand2
        '
        Me.OleDbSelectCommand2.CommandText = "SELECT P_ID, ALBUM_NAME, ARTIST, UNITS, PRICE, SUPPLIER_ID, CATEGORY_ID, LANGUAGE" & _
        ", PDATE, PMON, PYEAR FROM A_MUSIC_PURCHASE"
        Me.OleDbSelectCommand2.Connection = Me.OleDbConnection1
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
        Me.OleDbUpdateCommand2.Connection = Me.OleDbConnection1
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
        'frm1
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
        Me.BackColor = System.Drawing.Color.DarkGray
        Me.ClientSize = New System.Drawing.Size(848, 585)
        Me.Controls.Add(Me.DataGrid1)
        Me.Controls.Add(Me.grpaudio)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.StatusBar1)
        Me.Controls.Add(Me.grptype)
        Me.Controls.Add(Me.grpsearch)
        Me.Controls.Add(Me.grpvideo)
        Me.Menu = Me.MainMenu1
        Me.Name = "frm1"
        Me.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Text = "Form1"
        Me.WindowState = System.Windows.Forms.FormWindowState.Maximized
        Me.grpsearch.ResumeLayout(False)
        Me.grptype.ResumeLayout(False)
        Me.grpaudio.ResumeLayout(False)
        CType(Me.DisP_ALBUM1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.grpvideo.ResumeLayout(False)
        CType(Me.Searc1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.DataGrid1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub

#End Region

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        DisP_ALBUM1.Clear()
        OleDbDataAdapter2.Fill(DisP_ALBUM1)
        Timer1.Start()
        DataGrid1.Hide()
        grpaudio.Visible = True
        grpvideo.Visible = False
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

    
    Private Sub btnaudio_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnaudio.Click
        grpaudio.Visible = True
        grpvideo.Visible = False
    End Sub

    Private Sub btnvideo_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles btnvideo.Click
        grpaudio.Visible = False
        grpvideo.Visible = True
    End Sub

    Private Sub MenuItem5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem5.Click
        End
    End Sub

    Private Sub btnmovie_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnmovie.Click
        
    End Sub

    Private Sub btnbilling_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles btnbilling.Click
        Dim F2 As New Form2
        F2.Show()
        Me.Hide()

    End Sub
    Dim F3 As New Form3

    Private Sub btnstock_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnstock.Click
        F3.Show()
        Me.Hide()

    End Sub

    Private Sub BTNASEARCH_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BTNASEARCH.Click
        DataGrid1.Show()
        OleDbDataAdapter1.SelectCommand.Parameters("album_name").Value = ComboBox1.Text
        Searc1.Clear()
        OleDbDataAdapter1.Fill(Searc1)
    End Sub

    Private Sub MenuItem2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem2.Click
        Dim F2 As New Form2
        F2.Show()
        Me.Hide()

    End Sub

    Private Sub MenuItem7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem7.Click
        Dim F3 As New Form3
        F3.Show()
        Me.Hide()

    End Sub

    Private Sub MenuItem3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem3.Click
        Dim F9 As New FORM9
        F9.SHOW()


    End Sub

    
    
End Class
