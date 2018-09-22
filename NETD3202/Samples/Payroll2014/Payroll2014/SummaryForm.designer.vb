<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Public Class frmSummary
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing AndAlso components IsNot Nothing Then
            components.Dispose()
        End If
        MyBase.Dispose(disposing)
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.btnClose = New System.Windows.Forms.Button()
        Me.lblObjectCount = New System.Windows.Forms.Label()
        Me.lblOvertime = New System.Windows.Forms.Label()
        Me.lblObjectCountDisplay = New System.Windows.Forms.Label()
        Me.lblOvertimeDisplay = New System.Windows.Forms.Label()
        Me.lblPayroll = New System.Windows.Forms.Label()
        Me.lblPayrollDisplay = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'btnClose
        '
        Me.btnClose.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.btnClose.Location = New System.Drawing.Point(215, 143)
        Me.btnClose.Margin = New System.Windows.Forms.Padding(4)
        Me.btnClose.Name = "btnClose"
        Me.btnClose.Size = New System.Drawing.Size(100, 28)
        Me.btnClose.TabIndex = 0
        Me.btnClose.Text = "&Close"
        '
        'lblObjectCount
        '
        Me.lblObjectCount.Location = New System.Drawing.Point(19, 32)
        Me.lblObjectCount.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblObjectCount.Name = "lblObjectCount"
        Me.lblObjectCount.Size = New System.Drawing.Size(166, 21)
        Me.lblObjectCount.TabIndex = 1
        Me.lblObjectCount.Text = "Employees Processed:"
        Me.lblObjectCount.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblOvertime
        '
        Me.lblOvertime.Location = New System.Drawing.Point(66, 64)
        Me.lblOvertime.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblOvertime.Name = "lblOvertime"
        Me.lblOvertime.Size = New System.Drawing.Size(119, 21)
        Me.lblOvertime.TabIndex = 2
        Me.lblOvertime.Text = "Overtime Hours:"
        Me.lblOvertime.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblObjectCountDisplay
        '
        Me.lblObjectCountDisplay.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.lblObjectCountDisplay.Location = New System.Drawing.Point(182, 29)
        Me.lblObjectCountDisplay.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblObjectCountDisplay.Name = "lblObjectCountDisplay"
        Me.lblObjectCountDisplay.Size = New System.Drawing.Size(133, 25)
        Me.lblObjectCountDisplay.TabIndex = 7
        Me.lblObjectCountDisplay.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblOvertimeDisplay
        '
        Me.lblOvertimeDisplay.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.lblOvertimeDisplay.Location = New System.Drawing.Point(182, 62)
        Me.lblOvertimeDisplay.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblOvertimeDisplay.Name = "lblOvertimeDisplay"
        Me.lblOvertimeDisplay.Size = New System.Drawing.Size(133, 25)
        Me.lblOvertimeDisplay.TabIndex = 8
        Me.lblOvertimeDisplay.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblPayroll
        '
        Me.lblPayroll.Location = New System.Drawing.Point(90, 99)
        Me.lblPayroll.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblPayroll.Name = "lblPayroll"
        Me.lblPayroll.Size = New System.Drawing.Size(95, 21)
        Me.lblPayroll.TabIndex = 11
        Me.lblPayroll.Text = "Total Payroll:"
        Me.lblPayroll.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblPayrollDisplay
        '
        Me.lblPayrollDisplay.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.lblPayrollDisplay.Location = New System.Drawing.Point(182, 95)
        Me.lblPayrollDisplay.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblPayrollDisplay.Name = "lblPayrollDisplay"
        Me.lblPayrollDisplay.Size = New System.Drawing.Size(133, 25)
        Me.lblPayrollDisplay.TabIndex = 16
        Me.lblPayrollDisplay.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'frmSummary
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.CancelButton = Me.btnClose
        Me.ClientSize = New System.Drawing.Size(391, 184)
        Me.ControlBox = False
        Me.Controls.Add(Me.lblPayrollDisplay)
        Me.Controls.Add(Me.lblPayroll)
        Me.Controls.Add(Me.lblOvertimeDisplay)
        Me.Controls.Add(Me.lblObjectCountDisplay)
        Me.Controls.Add(Me.lblOvertime)
        Me.Controls.Add(Me.lblObjectCount)
        Me.Controls.Add(Me.btnClose)
        Me.Margin = New System.Windows.Forms.Padding(4)
        Me.MaximizeBox = False
        Me.MinimizeBox = False
        Me.Name = "frmSummary"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "Payroll Summary"
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents btnClose As System.Windows.Forms.Button
    Friend WithEvents lblObjectCount As System.Windows.Forms.Label
    Friend WithEvents lblOvertime As System.Windows.Forms.Label
    Friend WithEvents lblObjectCountDisplay As System.Windows.Forms.Label
    Friend WithEvents lblOvertimeDisplay As System.Windows.Forms.Label
    Friend WithEvents lblPayroll As System.Windows.Forms.Label
    Friend WithEvents lblPayrollDisplay As System.Windows.Forms.Label

End Class
