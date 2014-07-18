﻿'------------------------------------------------------------------------------
' <autogenerated>
'     This code was generated by a tool.
'     Runtime Version: 1.1.4322.573
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
Public Class DataSet1
    Inherits DataSet
    
    Private tableA_MUSIC_CATEGORY As A_MUSIC_CATEGORYDataTable
    
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
            If (Not (ds.Tables("A_MUSIC_CATEGORY")) Is Nothing) Then
                Me.Tables.Add(New A_MUSIC_CATEGORYDataTable(ds.Tables("A_MUSIC_CATEGORY")))
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
    Public ReadOnly Property A_MUSIC_CATEGORY As A_MUSIC_CATEGORYDataTable
        Get
            Return Me.tableA_MUSIC_CATEGORY
        End Get
    End Property
    
    Public Overrides Function Clone() As DataSet
        Dim cln As DataSet1 = CType(MyBase.Clone,DataSet1)
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
        If (Not (ds.Tables("A_MUSIC_CATEGORY")) Is Nothing) Then
            Me.Tables.Add(New A_MUSIC_CATEGORYDataTable(ds.Tables("A_MUSIC_CATEGORY")))
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
        Me.tableA_MUSIC_CATEGORY = CType(Me.Tables("A_MUSIC_CATEGORY"),A_MUSIC_CATEGORYDataTable)
        If (Not (Me.tableA_MUSIC_CATEGORY) Is Nothing) Then
            Me.tableA_MUSIC_CATEGORY.InitVars
        End If
    End Sub
    
    Private Sub InitClass()
        Me.DataSetName = "DataSet1"
        Me.Prefix = ""
        Me.Namespace = "http://www.tempuri.org/DataSet1.xsd"
        Me.Locale = New System.Globalization.CultureInfo("en-US")
        Me.CaseSensitive = false
        Me.EnforceConstraints = true
        Me.tableA_MUSIC_CATEGORY = New A_MUSIC_CATEGORYDataTable
        Me.Tables.Add(Me.tableA_MUSIC_CATEGORY)
    End Sub
    
    Private Function ShouldSerializeA_MUSIC_CATEGORY() As Boolean
        Return false
    End Function
    
    Private Sub SchemaChanged(ByVal sender As Object, ByVal e As System.ComponentModel.CollectionChangeEventArgs)
        If (e.Action = System.ComponentModel.CollectionChangeAction.Remove) Then
            Me.InitVars
        End If
    End Sub
    
    Public Delegate Sub A_MUSIC_CATEGORYRowChangeEventHandler(ByVal sender As Object, ByVal e As A_MUSIC_CATEGORYRowChangeEvent)
    
    <System.Diagnostics.DebuggerStepThrough()>  _
    Public Class A_MUSIC_CATEGORYDataTable
        Inherits DataTable
        Implements System.Collections.IEnumerable
        
        Private columnCATEGORY_ID As DataColumn
        
        Private columnCATEGORY As DataColumn
        
        Friend Sub New()
            MyBase.New("A_MUSIC_CATEGORY")
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
        
        Friend ReadOnly Property CATEGORY_IDColumn As DataColumn
            Get
                Return Me.columnCATEGORY_ID
            End Get
        End Property
        
        Friend ReadOnly Property CATEGORYColumn As DataColumn
            Get
                Return Me.columnCATEGORY
            End Get
        End Property
        
        Public Default ReadOnly Property Item(ByVal index As Integer) As A_MUSIC_CATEGORYRow
            Get
                Return CType(Me.Rows(index),A_MUSIC_CATEGORYRow)
            End Get
        End Property
        
        Public Event A_MUSIC_CATEGORYRowChanged As A_MUSIC_CATEGORYRowChangeEventHandler
        
        Public Event A_MUSIC_CATEGORYRowChanging As A_MUSIC_CATEGORYRowChangeEventHandler
        
        Public Event A_MUSIC_CATEGORYRowDeleted As A_MUSIC_CATEGORYRowChangeEventHandler
        
        Public Event A_MUSIC_CATEGORYRowDeleting As A_MUSIC_CATEGORYRowChangeEventHandler
        
        Public Overloads Sub AddA_MUSIC_CATEGORYRow(ByVal row As A_MUSIC_CATEGORYRow)
            Me.Rows.Add(row)
        End Sub
        
        Public Overloads Function AddA_MUSIC_CATEGORYRow(ByVal CATEGORY_ID As String, ByVal CATEGORY As String) As A_MUSIC_CATEGORYRow
            Dim rowA_MUSIC_CATEGORYRow As A_MUSIC_CATEGORYRow = CType(Me.NewRow,A_MUSIC_CATEGORYRow)
            rowA_MUSIC_CATEGORYRow.ItemArray = New Object() {CATEGORY_ID, CATEGORY}
            Me.Rows.Add(rowA_MUSIC_CATEGORYRow)
            Return rowA_MUSIC_CATEGORYRow
        End Function
        
        Public Function FindByCATEGORY_ID(ByVal CATEGORY_ID As String) As A_MUSIC_CATEGORYRow
            Return CType(Me.Rows.Find(New Object() {CATEGORY_ID}),A_MUSIC_CATEGORYRow)
        End Function
        
        Public Function GetEnumerator() As System.Collections.IEnumerator Implements System.Collections.IEnumerable.GetEnumerator
            Return Me.Rows.GetEnumerator
        End Function
        
        Public Overrides Function Clone() As DataTable
            Dim cln As A_MUSIC_CATEGORYDataTable = CType(MyBase.Clone,A_MUSIC_CATEGORYDataTable)
            cln.InitVars
            Return cln
        End Function
        
        Protected Overrides Function CreateInstance() As DataTable
            Return New A_MUSIC_CATEGORYDataTable
        End Function
        
        Friend Sub InitVars()
            Me.columnCATEGORY_ID = Me.Columns("CATEGORY_ID")
            Me.columnCATEGORY = Me.Columns("CATEGORY")
        End Sub
        
        Private Sub InitClass()
            Me.columnCATEGORY_ID = New DataColumn("CATEGORY_ID", GetType(System.String), Nothing, System.Data.MappingType.Element)
            Me.Columns.Add(Me.columnCATEGORY_ID)
            Me.columnCATEGORY = New DataColumn("CATEGORY", GetType(System.String), Nothing, System.Data.MappingType.Element)
            Me.Columns.Add(Me.columnCATEGORY)
            Me.Constraints.Add(New UniqueConstraint("Constraint1", New DataColumn() {Me.columnCATEGORY_ID}, true))
            Me.columnCATEGORY_ID.AllowDBNull = false
            Me.columnCATEGORY_ID.Unique = true
        End Sub
        
        Public Function NewA_MUSIC_CATEGORYRow() As A_MUSIC_CATEGORYRow
            Return CType(Me.NewRow,A_MUSIC_CATEGORYRow)
        End Function
        
        Protected Overrides Function NewRowFromBuilder(ByVal builder As DataRowBuilder) As DataRow
            Return New A_MUSIC_CATEGORYRow(builder)
        End Function
        
        Protected Overrides Function GetRowType() As System.Type
            Return GetType(A_MUSIC_CATEGORYRow)
        End Function
        
        Protected Overrides Sub OnRowChanged(ByVal e As DataRowChangeEventArgs)
            MyBase.OnRowChanged(e)
            If (Not (Me.A_MUSIC_CATEGORYRowChangedEvent) Is Nothing) Then
                RaiseEvent A_MUSIC_CATEGORYRowChanged(Me, New A_MUSIC_CATEGORYRowChangeEvent(CType(e.Row,A_MUSIC_CATEGORYRow), e.Action))
            End If
        End Sub
        
        Protected Overrides Sub OnRowChanging(ByVal e As DataRowChangeEventArgs)
            MyBase.OnRowChanging(e)
            If (Not (Me.A_MUSIC_CATEGORYRowChangingEvent) Is Nothing) Then
                RaiseEvent A_MUSIC_CATEGORYRowChanging(Me, New A_MUSIC_CATEGORYRowChangeEvent(CType(e.Row,A_MUSIC_CATEGORYRow), e.Action))
            End If
        End Sub
        
        Protected Overrides Sub OnRowDeleted(ByVal e As DataRowChangeEventArgs)
            MyBase.OnRowDeleted(e)
            If (Not (Me.A_MUSIC_CATEGORYRowDeletedEvent) Is Nothing) Then
                RaiseEvent A_MUSIC_CATEGORYRowDeleted(Me, New A_MUSIC_CATEGORYRowChangeEvent(CType(e.Row,A_MUSIC_CATEGORYRow), e.Action))
            End If
        End Sub
        
        Protected Overrides Sub OnRowDeleting(ByVal e As DataRowChangeEventArgs)
            MyBase.OnRowDeleting(e)
            If (Not (Me.A_MUSIC_CATEGORYRowDeletingEvent) Is Nothing) Then
                RaiseEvent A_MUSIC_CATEGORYRowDeleting(Me, New A_MUSIC_CATEGORYRowChangeEvent(CType(e.Row,A_MUSIC_CATEGORYRow), e.Action))
            End If
        End Sub
        
        Public Sub RemoveA_MUSIC_CATEGORYRow(ByVal row As A_MUSIC_CATEGORYRow)
            Me.Rows.Remove(row)
        End Sub
    End Class
    
    <System.Diagnostics.DebuggerStepThrough()>  _
    Public Class A_MUSIC_CATEGORYRow
        Inherits DataRow
        
        Private tableA_MUSIC_CATEGORY As A_MUSIC_CATEGORYDataTable
        
        Friend Sub New(ByVal rb As DataRowBuilder)
            MyBase.New(rb)
            Me.tableA_MUSIC_CATEGORY = CType(Me.Table,A_MUSIC_CATEGORYDataTable)
        End Sub
        
        Public Property CATEGORY_ID As String
            Get
                Return CType(Me(Me.tableA_MUSIC_CATEGORY.CATEGORY_IDColumn),String)
            End Get
            Set
                Me(Me.tableA_MUSIC_CATEGORY.CATEGORY_IDColumn) = value
            End Set
        End Property
        
        Public Property CATEGORY As String
            Get
                Try 
                    Return CType(Me(Me.tableA_MUSIC_CATEGORY.CATEGORYColumn),String)
                Catch e As InvalidCastException
                    Throw New StrongTypingException("Cannot get value because it is DBNull.", e)
                End Try
            End Get
            Set
                Me(Me.tableA_MUSIC_CATEGORY.CATEGORYColumn) = value
            End Set
        End Property
        
        Public Function IsCATEGORYNull() As Boolean
            Return Me.IsNull(Me.tableA_MUSIC_CATEGORY.CATEGORYColumn)
        End Function
        
        Public Sub SetCATEGORYNull()
            Me(Me.tableA_MUSIC_CATEGORY.CATEGORYColumn) = System.Convert.DBNull
        End Sub
    End Class
    
    <System.Diagnostics.DebuggerStepThrough()>  _
    Public Class A_MUSIC_CATEGORYRowChangeEvent
        Inherits EventArgs
        
        Private eventRow As A_MUSIC_CATEGORYRow
        
        Private eventAction As DataRowAction
        
        Public Sub New(ByVal row As A_MUSIC_CATEGORYRow, ByVal action As DataRowAction)
            MyBase.New
            Me.eventRow = row
            Me.eventAction = action
        End Sub
        
        Public ReadOnly Property Row As A_MUSIC_CATEGORYRow
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