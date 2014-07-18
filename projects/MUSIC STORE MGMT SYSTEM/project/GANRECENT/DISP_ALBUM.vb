﻿'------------------------------------------------------------------------------
' <autogenerated>
'     This code was generated by a tool.
'     Runtime Version: 1.1.4322.2032
'
'     Changes to this file may cause incorrect behavior and will be lost if 
'     the code is regenerated.
' </autogenerated>
'------------------------------------------------------------------------------

Option Strict Off
Option Explicit On

Imports System
Imports System.Data
Imports System.Runtime.Serialization
Imports System.Xml


<Serializable(),  _
 System.ComponentModel.DesignerCategoryAttribute("code"),  _
 System.Diagnostics.DebuggerStepThrough(),  _
 System.ComponentModel.ToolboxItem(true)>  _
Public Class DISP_ALBUM
    Inherits DataSet
    
    Private tableA_MUSIC_PURCHASE As A_MUSIC_PURCHASEDataTable
    
    Public Sub New()
        MyBase.New
        Me.InitClass
        Dim schemaChangedHandler As System.ComponentModel.CollectionChangeEventHandler = AddressOf Me.SchemaChanged
        AddHandler Me.Tables.CollectionChanged, schemaChangedHandler
        AddHandler Me.Relations.CollectionChanged, schemaChangedHandler
    End Sub
    
    Protected Sub New(ByVal info As SerializationInfo, ByVal context As StreamingContext)
        MyBase.New
        Dim strSchema As String = CType(info.GetValue("XmlSchema", GetType(System.String)),String)
        If (Not (strSchema) Is Nothing) Then
            Dim ds As DataSet = New DataSet
            ds.ReadXmlSchema(New XmlTextReader(New System.IO.StringReader(strSchema)))
            If (Not (ds.Tables("A_MUSIC_PURCHASE")) Is Nothing) Then
                Me.Tables.Add(New A_MUSIC_PURCHASEDataTable(ds.Tables("A_MUSIC_PURCHASE")))
            End If
            Me.DataSetName = ds.DataSetName
            Me.Prefix = ds.Prefix
            Me.Namespace = ds.Namespace
            Me.Locale = ds.Locale
            Me.CaseSensitive = ds.CaseSensitive
            Me.EnforceConstraints = ds.EnforceConstraints
            Me.Merge(ds, false, System.Data.MissingSchemaAction.Add)
            Me.InitVars
        Else
            Me.InitClass
        End If
        Me.GetSerializationData(info, context)
        Dim schemaChangedHandler As System.ComponentModel.CollectionChangeEventHandler = AddressOf Me.SchemaChanged
        AddHandler Me.Tables.CollectionChanged, schemaChangedHandler
        AddHandler Me.Relations.CollectionChanged, schemaChangedHandler
    End Sub
    
    <System.ComponentModel.Browsable(false),  _
     System.ComponentModel.DesignerSerializationVisibilityAttribute(System.ComponentModel.DesignerSerializationVisibility.Content)>  _
    Public ReadOnly Property A_MUSIC_PURCHASE As A_MUSIC_PURCHASEDataTable
        Get
            Return Me.tableA_MUSIC_PURCHASE
        End Get
    End Property
    
    Public Overrides Function Clone() As DataSet
        Dim cln As DISP_ALBUM = CType(MyBase.Clone,DISP_ALBUM)
        cln.InitVars
        Return cln
    End Function
    
    Protected Overrides Function ShouldSerializeTables() As Boolean
        Return false
    End Function
    
    Protected Overrides Function ShouldSerializeRelations() As Boolean
        Return false
    End Function
    
    Protected Overrides Sub ReadXmlSerializable(ByVal reader As XmlReader)
        Me.Reset
        Dim ds As DataSet = New DataSet
        ds.ReadXml(reader)
        If (Not (ds.Tables("A_MUSIC_PURCHASE")) Is Nothing) Then
            Me.Tables.Add(New A_MUSIC_PURCHASEDataTable(ds.Tables("A_MUSIC_PURCHASE")))
        End If
        Me.DataSetName = ds.DataSetName
        Me.Prefix = ds.Prefix
        Me.Namespace = ds.Namespace
        Me.Locale = ds.Locale
        Me.CaseSensitive = ds.CaseSensitive
        Me.EnforceConstraints = ds.EnforceConstraints
        Me.Merge(ds, false, System.Data.MissingSchemaAction.Add)
        Me.InitVars
    End Sub
    
    Protected Overrides Function GetSchemaSerializable() As System.Xml.Schema.XmlSchema
        Dim stream As System.IO.MemoryStream = New System.IO.MemoryStream
        Me.WriteXmlSchema(New XmlTextWriter(stream, Nothing))
        stream.Position = 0
        Return System.Xml.Schema.XmlSchema.Read(New XmlTextReader(stream), Nothing)
    End Function
    
    Friend Sub InitVars()
        Me.tableA_MUSIC_PURCHASE = CType(Me.Tables("A_MUSIC_PURCHASE"),A_MUSIC_PURCHASEDataTable)
        If (Not (Me.tableA_MUSIC_PURCHASE) Is Nothing) Then
            Me.tableA_MUSIC_PURCHASE.InitVars
        End If
    End Sub
    
    Private Sub InitClass()
        Me.DataSetName = "DISP_ALBUM"
        Me.Prefix = ""
        Me.Namespace = "http://www.tempuri.org/DISP_ALBUM.xsd"
        Me.Locale = New System.Globalization.CultureInfo("en-US")
        Me.CaseSensitive = false
        Me.EnforceConstraints = true
        Me.tableA_MUSIC_PURCHASE = New A_MUSIC_PURCHASEDataTable
        Me.Tables.Add(Me.tableA_MUSIC_PURCHASE)
    End Sub
    
    Private Function ShouldSerializeA_MUSIC_PURCHASE() As Boolean
        Return false
    End Function
    
    Private Sub SchemaChanged(ByVal sender As Object, ByVal e As System.ComponentModel.CollectionChangeEventArgs)
        If (e.Action = System.ComponentModel.CollectionChangeAction.Remove) Then
            Me.InitVars
        End If
    End Sub
    
    Public Delegate Sub A_MUSIC_PURCHASERowChangeEventHandler(ByVal sender As Object, ByVal e As A_MUSIC_PURCHASERowChangeEvent)
    
    <System.Diagnostics.DebuggerStepThrough()>  _
    Public Class A_MUSIC_PURCHASEDataTable
        Inherits DataTable
        Implements System.Collections.IEnumerable
        
        Private columnP_ID As DataColumn
        
        Private columnALBUM_NAME As DataColumn
        
        Private columnARTIST As DataColumn
        
        Private columnUNITS As DataColumn
        
        Private columnPRICE As DataColumn
        
        Private columnSUPPLIER_ID As DataColumn
        
        Private columnCATEGORY_ID As DataColumn
        
        Private columnLANGUAGE As DataColumn
        
        Private columnPDATE As DataColumn
        
        Private columnPMON As DataColumn
        
        Private columnPYEAR As DataColumn
        
        Friend Sub New()
            MyBase.New("A_MUSIC_PURCHASE")
            Me.InitClass
        End Sub
        
        Friend Sub New(ByVal table As DataTable)
            MyBase.New(table.TableName)
            If (table.CaseSensitive <> table.DataSet.CaseSensitive) Then
                Me.CaseSensitive = table.CaseSensitive
            End If
            If (table.Locale.ToString <> table.DataSet.Locale.ToString) Then
                Me.Locale = table.Locale
            End If
            If (table.Namespace <> table.DataSet.Namespace) Then
                Me.Namespace = table.Namespace
            End If
            Me.Prefix = table.Prefix
            Me.MinimumCapacity = table.MinimumCapacity
            Me.DisplayExpression = table.DisplayExpression
        End Sub
        
        <System.ComponentModel.Browsable(false)>  _
        Public ReadOnly Property Count As Integer
            Get
                Return Me.Rows.Count
            End Get
        End Property
        
        Friend ReadOnly Property P_IDColumn As DataColumn
            Get
                Return Me.columnP_ID
            End Get
        End Property
        
        Friend ReadOnly Property ALBUM_NAMEColumn As DataColumn
            Get
                Return Me.columnALBUM_NAME
            End Get
        End Property
        
        Friend ReadOnly Property ARTISTColumn As DataColumn
            Get
                Return Me.columnARTIST
            End Get
        End Property
        
        Friend ReadOnly Property UNITSColumn As DataColumn
            Get
                Return Me.columnUNITS
            End Get
        End Property
        
        Friend ReadOnly Property PRICEColumn As DataColumn
            Get
                Return Me.columnPRICE
            End Get
        End Property
        
        Friend ReadOnly Property SUPPLIER_IDColumn As DataColumn
            Get
                Return Me.columnSUPPLIER_ID
            End Get
        End Property
        
        Friend ReadOnly Property CATEGORY_IDColumn As DataColumn
            Get
                Return Me.columnCATEGORY_ID
            End Get
        End Property
        
        Friend ReadOnly Property LANGUAGEColumn As DataColumn
            Get
                Return Me.columnLANGUAGE
            End Get
        End Property
        
        Friend ReadOnly Property PDATEColumn As DataColumn
            Get
                Return Me.columnPDATE
            End Get
        End Property
        
        Friend ReadOnly Property PMONColumn As DataColumn
            Get
                Return Me.columnPMON
            End Get
        End Property
        
        Friend ReadOnly Property PYEARColumn As DataColumn
            Get
                Return Me.columnPYEAR
            End Get
        End Property
        
        Public Default ReadOnly Property Item(ByVal index As Integer) As A_MUSIC_PURCHASERow
            Get
                Return CType(Me.Rows(index),A_MUSIC_PURCHASERow)
            End Get
        End Property
        
        Public Event A_MUSIC_PURCHASERowChanged As A_MUSIC_PURCHASERowChangeEventHandler
        
        Public Event A_MUSIC_PURCHASERowChanging As A_MUSIC_PURCHASERowChangeEventHandler
        
        Public Event A_MUSIC_PURCHASERowDeleted As A_MUSIC_PURCHASERowChangeEventHandler
        
        Public Event A_MUSIC_PURCHASERowDeleting As A_MUSIC_PURCHASERowChangeEventHandler
        
        Public Overloads Sub AddA_MUSIC_PURCHASERow(ByVal row As A_MUSIC_PURCHASERow)
            Me.Rows.Add(row)
        End Sub
        
        Public Overloads Function AddA_MUSIC_PURCHASERow(ByVal P_ID As String, ByVal ALBUM_NAME As String, ByVal ARTIST As String, ByVal UNITS As Decimal, ByVal PRICE As Decimal, ByVal SUPPLIER_ID As String, ByVal CATEGORY_ID As String, ByVal LANGUAGE As String, ByVal PDATE As Decimal, ByVal PMON As Decimal, ByVal PYEAR As Decimal) As A_MUSIC_PURCHASERow
            Dim rowA_MUSIC_PURCHASERow As A_MUSIC_PURCHASERow = CType(Me.NewRow,A_MUSIC_PURCHASERow)
            rowA_MUSIC_PURCHASERow.ItemArray = New Object() {P_ID, ALBUM_NAME, ARTIST, UNITS, PRICE, SUPPLIER_ID, CATEGORY_ID, LANGUAGE, PDATE, PMON, PYEAR}
            Me.Rows.Add(rowA_MUSIC_PURCHASERow)
            Return rowA_MUSIC_PURCHASERow
        End Function
        
        Public Function FindByP_ID(ByVal P_ID As String) As A_MUSIC_PURCHASERow
            Return CType(Me.Rows.Find(New Object() {P_ID}),A_MUSIC_PURCHASERow)
        End Function
        
        Public Function GetEnumerator() As System.Collections.IEnumerator Implements System.Collections.IEnumerable.GetEnumerator
            Return Me.Rows.GetEnumerator
        End Function
        
        Public Overrides Function Clone() As DataTable
            Dim cln As A_MUSIC_PURCHASEDataTable = CType(MyBase.Clone,A_MUSIC_PURCHASEDataTable)
            cln.InitVars
            Return cln
        End Function
        
        Protected Overrides Function CreateInstance() As DataTable
            Return New A_MUSIC_PURCHASEDataTable
        End Function
        
        Friend Sub InitVars()
            Me.columnP_ID = Me.Columns("P_ID")
            Me.columnALBUM_NAME = Me.Columns("ALBUM_NAME")
            Me.columnARTIST = Me.Columns("ARTIST")
            Me.columnUNITS = Me.Columns("UNITS")
            Me.columnPRICE = Me.Columns("PRICE")
            Me.columnSUPPLIER_ID = Me.Columns("SUPPLIER_ID")
            Me.columnCATEGORY_ID = Me.Columns("CATEGORY_ID")
            Me.columnLANGUAGE = Me.Columns("LANGUAGE")
            Me.columnPDATE = Me.Columns("PDATE")
            Me.columnPMON = Me.Columns("PMON")
            Me.columnPYEAR = Me.Columns("PYEAR")
        End Sub
        
        Private Sub InitClass()
            Me.columnP_ID = New DataColumn("P_ID", GetType(System.String), Nothing, System.Data.MappingType.Element)
            Me.Columns.Add(Me.columnP_ID)
            Me.columnALBUM_NAME = New DataColumn("ALBUM_NAME", GetType(System.String), Nothing, System.Data.MappingType.Element)
            Me.Columns.Add(Me.columnALBUM_NAME)
            Me.columnARTIST = New DataColumn("ARTIST", GetType(System.String), Nothing, System.Data.MappingType.Element)
            Me.Columns.Add(Me.columnARTIST)
            Me.columnUNITS = New DataColumn("UNITS", GetType(System.Decimal), Nothing, System.Data.MappingType.Element)
            Me.Columns.Add(Me.columnUNITS)
            Me.columnPRICE = New DataColumn("PRICE", GetType(System.Decimal), Nothing, System.Data.MappingType.Element)
            Me.Columns.Add(Me.columnPRICE)
            Me.columnSUPPLIER_ID = New DataColumn("SUPPLIER_ID", GetType(System.String), Nothing, System.Data.MappingType.Element)
            Me.Columns.Add(Me.columnSUPPLIER_ID)
            Me.columnCATEGORY_ID = New DataColumn("CATEGORY_ID", GetType(System.String), Nothing, System.Data.MappingType.Element)
            Me.Columns.Add(Me.columnCATEGORY_ID)
            Me.columnLANGUAGE = New DataColumn("LANGUAGE", GetType(System.String), Nothing, System.Data.MappingType.Element)
            Me.Columns.Add(Me.columnLANGUAGE)
            Me.columnPDATE = New DataColumn("PDATE", GetType(System.Decimal), Nothing, System.Data.MappingType.Element)
            Me.Columns.Add(Me.columnPDATE)
            Me.columnPMON = New DataColumn("PMON", GetType(System.Decimal), Nothing, System.Data.MappingType.Element)
            Me.Columns.Add(Me.columnPMON)
            Me.columnPYEAR = New DataColumn("PYEAR", GetType(System.Decimal), Nothing, System.Data.MappingType.Element)
            Me.Columns.Add(Me.columnPYEAR)
            Me.Constraints.Add(New UniqueConstraint("Constraint1", New DataColumn() {Me.columnP_ID}, true))
            Me.columnP_ID.AllowDBNull = false
            Me.columnP_ID.Unique = true
        End Sub
        
        Public Function NewA_MUSIC_PURCHASERow() As A_MUSIC_PURCHASERow
            Return CType(Me.NewRow,A_MUSIC_PURCHASERow)
        End Function
        
        Protected Overrides Function NewRowFromBuilder(ByVal builder As DataRowBuilder) As DataRow
            Return New A_MUSIC_PURCHASERow(builder)
        End Function
        
        Protected Overrides Function GetRowType() As System.Type
            Return GetType(A_MUSIC_PURCHASERow)
        End Function
        
        Protected Overrides Sub OnRowChanged(ByVal e As DataRowChangeEventArgs)
            MyBase.OnRowChanged(e)
            If (Not (Me.A_MUSIC_PURCHASERowChangedEvent) Is Nothing) Then
                RaiseEvent A_MUSIC_PURCHASERowChanged(Me, New A_MUSIC_PURCHASERowChangeEvent(CType(e.Row,A_MUSIC_PURCHASERow), e.Action))
            End If
        End Sub
        
        Protected Overrides Sub OnRowChanging(ByVal e As DataRowChangeEventArgs)
            MyBase.OnRowChanging(e)
            If (Not (Me.A_MUSIC_PURCHASERowChangingEvent) Is Nothing) Then
                RaiseEvent A_MUSIC_PURCHASERowChanging(Me, New A_MUSIC_PURCHASERowChangeEvent(CType(e.Row,A_MUSIC_PURCHASERow), e.Action))
            End If
        End Sub
        
        Protected Overrides Sub OnRowDeleted(ByVal e As DataRowChangeEventArgs)
            MyBase.OnRowDeleted(e)
            If (Not (Me.A_MUSIC_PURCHASERowDeletedEvent) Is Nothing) Then
                RaiseEvent A_MUSIC_PURCHASERowDeleted(Me, New A_MUSIC_PURCHASERowChangeEvent(CType(e.Row,A_MUSIC_PURCHASERow), e.Action))
            End If
        End Sub
        
        Protected Overrides Sub OnRowDeleting(ByVal e As DataRowChangeEventArgs)
            MyBase.OnRowDeleting(e)
            If (Not (Me.A_MUSIC_PURCHASERowDeletingEvent) Is Nothing) Then
                RaiseEvent A_MUSIC_PURCHASERowDeleting(Me, New A_MUSIC_PURCHASERowChangeEvent(CType(e.Row,A_MUSIC_PURCHASERow), e.Action))
            End If
        End Sub
        
        Public Sub RemoveA_MUSIC_PURCHASERow(ByVal row As A_MUSIC_PURCHASERow)
            Me.Rows.Remove(row)
        End Sub
    End Class
    
    <System.Diagnostics.DebuggerStepThrough()>  _
    Public Class A_MUSIC_PURCHASERow
        Inherits DataRow
        
        Private tableA_MUSIC_PURCHASE As A_MUSIC_PURCHASEDataTable
        
        Friend Sub New(ByVal rb As DataRowBuilder)
            MyBase.New(rb)
            Me.tableA_MUSIC_PURCHASE = CType(Me.Table,A_MUSIC_PURCHASEDataTable)
        End Sub
        
        Public Property P_ID As String
            Get
                Return CType(Me(Me.tableA_MUSIC_PURCHASE.P_IDColumn),String)
            End Get
            Set
                Me(Me.tableA_MUSIC_PURCHASE.P_IDColumn) = value
            End Set
        End Property
        
        Public Property ALBUM_NAME As String
            Get
                Try 
                    Return CType(Me(Me.tableA_MUSIC_PURCHASE.ALBUM_NAMEColumn),String)
                Catch e As InvalidCastException
                    Throw New StrongTypingException("Cannot get value because it is DBNull.", e)
                End Try
            End Get
            Set
                Me(Me.tableA_MUSIC_PURCHASE.ALBUM_NAMEColumn) = value
            End Set
        End Property
        
        Public Property ARTIST As String
            Get
                Try 
                    Return CType(Me(Me.tableA_MUSIC_PURCHASE.ARTISTColumn),String)
                Catch e As InvalidCastException
                    Throw New StrongTypingException("Cannot get value because it is DBNull.", e)
                End Try
            End Get
            Set
                Me(Me.tableA_MUSIC_PURCHASE.ARTISTColumn) = value
            End Set
        End Property
        
        Public Property UNITS As Decimal
            Get
                Try 
                    Return CType(Me(Me.tableA_MUSIC_PURCHASE.UNITSColumn),Decimal)
                Catch e As InvalidCastException
                    Throw New StrongTypingException("Cannot get value because it is DBNull.", e)
                End Try
            End Get
            Set
                Me(Me.tableA_MUSIC_PURCHASE.UNITSColumn) = value
            End Set
        End Property
        
        Public Property PRICE As Decimal
            Get
                Try 
                    Return CType(Me(Me.tableA_MUSIC_PURCHASE.PRICEColumn),Decimal)
                Catch e As InvalidCastException
                    Throw New StrongTypingException("Cannot get value because it is DBNull.", e)
                End Try
            End Get
            Set
                Me(Me.tableA_MUSIC_PURCHASE.PRICEColumn) = value
            End Set
        End Property
        
        Public Property SUPPLIER_ID As String
            Get
                Try 
                    Return CType(Me(Me.tableA_MUSIC_PURCHASE.SUPPLIER_IDColumn),String)
                Catch e As InvalidCastException
                    Throw New StrongTypingException("Cannot get value because it is DBNull.", e)
                End Try
            End Get
            Set
                Me(Me.tableA_MUSIC_PURCHASE.SUPPLIER_IDColumn) = value
            End Set
        End Property
        
        Public Property CATEGORY_ID As String
            Get
                Try 
                    Return CType(Me(Me.tableA_MUSIC_PURCHASE.CATEGORY_IDColumn),String)
                Catch e As InvalidCastException
                    Throw New StrongTypingException("Cannot get value because it is DBNull.", e)
                End Try
            End Get
            Set
                Me(Me.tableA_MUSIC_PURCHASE.CATEGORY_IDColumn) = value
            End Set
        End Property
        
        Public Property LANGUAGE As String
            Get
                Try 
                    Return CType(Me(Me.tableA_MUSIC_PURCHASE.LANGUAGEColumn),String)
                Catch e As InvalidCastException
                    Throw New StrongTypingException("Cannot get value because it is DBNull.", e)
                End Try
            End Get
            Set
                Me(Me.tableA_MUSIC_PURCHASE.LANGUAGEColumn) = value
            End Set
        End Property
        
        Public Property PDATE As Decimal
            Get
                Try 
                    Return CType(Me(Me.tableA_MUSIC_PURCHASE.PDATEColumn),Decimal)
                Catch e As InvalidCastException
                    Throw New StrongTypingException("Cannot get value because it is DBNull.", e)
                End Try
            End Get
            Set
                Me(Me.tableA_MUSIC_PURCHASE.PDATEColumn) = value
            End Set
        End Property
        
        Public Property PMON As Decimal
            Get
                Try 
                    Return CType(Me(Me.tableA_MUSIC_PURCHASE.PMONColumn),Decimal)
                Catch e As InvalidCastException
                    Throw New StrongTypingException("Cannot get value because it is DBNull.", e)
                End Try
            End Get
            Set
                Me(Me.tableA_MUSIC_PURCHASE.PMONColumn) = value
            End Set
        End Property
        
        Public Property PYEAR As Decimal
            Get
                Try 
                    Return CType(Me(Me.tableA_MUSIC_PURCHASE.PYEARColumn),Decimal)
                Catch e As InvalidCastException
                    Throw New StrongTypingException("Cannot get value because it is DBNull.", e)
                End Try
            End Get
            Set
                Me(Me.tableA_MUSIC_PURCHASE.PYEARColumn) = value
            End Set
        End Property
        
        Public Function IsALBUM_NAMENull() As Boolean
            Return Me.IsNull(Me.tableA_MUSIC_PURCHASE.ALBUM_NAMEColumn)
        End Function
        
        Public Sub SetALBUM_NAMENull()
            Me(Me.tableA_MUSIC_PURCHASE.ALBUM_NAMEColumn) = System.Convert.DBNull
        End Sub
        
        Public Function IsARTISTNull() As Boolean
            Return Me.IsNull(Me.tableA_MUSIC_PURCHASE.ARTISTColumn)
        End Function
        
        Public Sub SetARTISTNull()
            Me(Me.tableA_MUSIC_PURCHASE.ARTISTColumn) = System.Convert.DBNull
        End Sub
        
        Public Function IsUNITSNull() As Boolean
            Return Me.IsNull(Me.tableA_MUSIC_PURCHASE.UNITSColumn)
        End Function
        
        Public Sub SetUNITSNull()
            Me(Me.tableA_MUSIC_PURCHASE.UNITSColumn) = System.Convert.DBNull
        End Sub
        
        Public Function IsPRICENull() As Boolean
            Return Me.IsNull(Me.tableA_MUSIC_PURCHASE.PRICEColumn)
        End Function
        
        Public Sub SetPRICENull()
            Me(Me.tableA_MUSIC_PURCHASE.PRICEColumn) = System.Convert.DBNull
        End Sub
        
        Public Function IsSUPPLIER_IDNull() As Boolean
            Return Me.IsNull(Me.tableA_MUSIC_PURCHASE.SUPPLIER_IDColumn)
        End Function
        
        Public Sub SetSUPPLIER_IDNull()
            Me(Me.tableA_MUSIC_PURCHASE.SUPPLIER_IDColumn) = System.Convert.DBNull
        End Sub
        
        Public Function IsCATEGORY_IDNull() As Boolean
            Return Me.IsNull(Me.tableA_MUSIC_PURCHASE.CATEGORY_IDColumn)
        End Function
        
        Public Sub SetCATEGORY_IDNull()
            Me(Me.tableA_MUSIC_PURCHASE.CATEGORY_IDColumn) = System.Convert.DBNull
        End Sub
        
        Public Function IsLANGUAGENull() As Boolean
            Return Me.IsNull(Me.tableA_MUSIC_PURCHASE.LANGUAGEColumn)
        End Function
        
        Public Sub SetLANGUAGENull()
            Me(Me.tableA_MUSIC_PURCHASE.LANGUAGEColumn) = System.Convert.DBNull
        End Sub
        
        Public Function IsPDATENull() As Boolean
            Return Me.IsNull(Me.tableA_MUSIC_PURCHASE.PDATEColumn)
        End Function
        
        Public Sub SetPDATENull()
            Me(Me.tableA_MUSIC_PURCHASE.PDATEColumn) = System.Convert.DBNull
        End Sub
        
        Public Function IsPMONNull() As Boolean
            Return Me.IsNull(Me.tableA_MUSIC_PURCHASE.PMONColumn)
        End Function
        
        Public Sub SetPMONNull()
            Me(Me.tableA_MUSIC_PURCHASE.PMONColumn) = System.Convert.DBNull
        End Sub
        
        Public Function IsPYEARNull() As Boolean
            Return Me.IsNull(Me.tableA_MUSIC_PURCHASE.PYEARColumn)
        End Function
        
        Public Sub SetPYEARNull()
            Me(Me.tableA_MUSIC_PURCHASE.PYEARColumn) = System.Convert.DBNull
        End Sub
    End Class
    
    <System.Diagnostics.DebuggerStepThrough()>  _
    Public Class A_MUSIC_PURCHASERowChangeEvent
        Inherits EventArgs
        
        Private eventRow As A_MUSIC_PURCHASERow
        
        Private eventAction As DataRowAction
        
        Public Sub New(ByVal row As A_MUSIC_PURCHASERow, ByVal action As DataRowAction)
            MyBase.New
            Me.eventRow = row
            Me.eventAction = action
        End Sub
        
        Public ReadOnly Property Row As A_MUSIC_PURCHASERow
            Get
                Return Me.eventRow
            End Get
        End Property
        
        Public ReadOnly Property Action As DataRowAction
            Get
                Return Me.eventAction
            End Get
        End Property
    End Class
End Class
