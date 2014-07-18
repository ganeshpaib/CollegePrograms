Public Class Form3
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
    Friend WithEvents StatusBar1 As System.Windows.Forms.StatusBar
    Friend WithEvents TreeView1 As System.Windows.Forms.TreeView
    Friend WithEvents Button1 As System.Windows.Forms.Button
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
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
        Dim resources As System.Resources.ResourceManager = New System.Resources.ResourceManager(GetType(Form3))
        Me.StatusBar1 = New System.Windows.Forms.StatusBar
        Me.TreeView1 = New System.Windows.Forms.TreeView
        Me.Button1 = New System.Windows.Forms.Button
        Me.grptype = New System.Windows.Forms.GroupBox
        Me.btnbilling = New System.Windows.Forms.Button
        Me.btnsearch = New System.Windows.Forms.Button
        Me.btnstock = New System.Windows.Forms.Button
        Me.MainMenu1 = New System.Windows.Forms.MainMenu
        Me.MenuItem1 = New System.Windows.Forms.MenuItem
        Me.MenuItem5 = New System.Windows.Forms.MenuItem
        Me.MenuItem6 = New System.Windows.Forms.MenuItem
        Me.MenuItem2 = New System.Windows.Forms.MenuItem
        Me.MenuItem3 = New System.Windows.Forms.MenuItem
        Me.MenuItem4 = New System.Windows.Forms.MenuItem
        Me.Label1 = New System.Windows.Forms.Label
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.grptype.SuspendLayout()
        Me.SuspendLayout()
        '
        'StatusBar1
        '
        Me.StatusBar1.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!, CType((System.Drawing.FontStyle.Bold Or System.Drawing.FontStyle.Italic), System.Drawing.FontStyle), System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.StatusBar1.Location = New System.Drawing.Point(0, 512)
        Me.StatusBar1.Name = "StatusBar1"
        Me.StatusBar1.Size = New System.Drawing.Size(800, 22)
        Me.StatusBar1.TabIndex = 6
        Me.StatusBar1.Text = "STOCK"
        '
        'TreeView1
        '
        Me.TreeView1.BackColor = System.Drawing.Color.Silver
        Me.TreeView1.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TreeView1.ImageIndex = -1
        Me.TreeView1.Location = New System.Drawing.Point(8, 88)
        Me.TreeView1.Name = "TreeView1"
        Me.TreeView1.Nodes.AddRange(New System.Windows.Forms.TreeNode() {New System.Windows.Forms.TreeNode("ENTRY", New System.Windows.Forms.TreeNode() {New System.Windows.Forms.TreeNode("PURCHASE ENTRY"), New System.Windows.Forms.TreeNode("SUPPLIER ENTRY"), New System.Windows.Forms.TreeNode("CATEGORY ENTRY")}), New System.Windows.Forms.TreeNode("DISPLAY", New System.Windows.Forms.TreeNode() {New System.Windows.Forms.TreeNode("STOCK DISPLAY"), New System.Windows.Forms.TreeNode("PURCHASE DISPLAY")})})
        Me.TreeView1.SelectedImageIndex = -1
        Me.TreeView1.Size = New System.Drawing.Size(256, 360)
        Me.TreeView1.TabIndex = 8
        '
        'Button1
        '
        Me.Button1.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Button1.Location = New System.Drawing.Point(104, 320)
        Me.Button1.Name = "Button1"
        Me.Button1.TabIndex = 9
        Me.Button1.Text = "OPEN"
        '
        'grptype
        '
        Me.grptype.BackColor = System.Drawing.Color.DarkGray
        Me.grptype.Controls.Add(Me.btnbilling)
        Me.grptype.Controls.Add(Me.btnsearch)
        Me.grptype.Controls.Add(Me.btnstock)
        Me.grptype.Location = New System.Drawing.Point(0, 8)
        Me.grptype.Name = "grptype"
        Me.grptype.Size = New System.Drawing.Size(296, 56)
        Me.grptype.TabIndex = 10
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
        Me.MenuItem6.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem2})
        Me.MenuItem6.Text = "VIEW"
        '
        'MenuItem2
        '
        Me.MenuItem2.Index = 0
        Me.MenuItem2.Text = ""
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
        Me.Label1.Location = New System.Drawing.Point(448, 24)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(296, 48)
        Me.Label1.TabIndex = 11
        Me.Label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        Me.Timer1.Interval = 300
        '
        'Form3
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
        Me.BackColor = System.Drawing.Color.DarkGray
        Me.ClientSize = New System.Drawing.Size(800, 534)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.grptype)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.TreeView1)
        Me.Controls.Add(Me.StatusBar1)
        Me.Name = "Form3"
        Me.Text = "Form3"
        Me.grptype.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub

#End Region
    Dim str As String

    Private Sub TreeView1_AfterSelect(ByVal sender As System.Object, ByVal e As System.Windows.Forms.TreeViewEventArgs) Handles TreeView1.AfterSelect
        str = e.Node.Text

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Select Case str
            Case "ENTRY"
                MsgBox("SELECT THE CHILD NODES")
            Case "DISPLAY"
                MsgBox("SELLECT THE CHILD NODES")
            Case "PURCHASE ENTRY"
                Dim F4 As New Form4
                F4.Show()

            Case "CATEGORY ENTRY"
                Dim F5 As New Form5
                F5.Show()
            Case "SUPPLIER ENTRY"
                Dim F7 As New Form7
                F7.Show()

            Case "STOCK DISPLAY"
                Dim F6 As New Form6
                F6.Show()

            Case "PURCHASE DISPLAY"
                Dim F8 As New Form8
                F8.Show()



        End Select
    End Sub

    Private Sub btnsearch_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnsearch.Click
        Dim F1 As New frm1
        F1.Show()
        Me.Hide()

    End Sub

    Private Sub btnbilling_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnbilling.Click
        Dim F2 As New Form2
        F2.Show()
        Me.Hide()

    End Sub

    Private Sub Form3_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        Timer1.Start()
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

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)

    End Sub
End Class
