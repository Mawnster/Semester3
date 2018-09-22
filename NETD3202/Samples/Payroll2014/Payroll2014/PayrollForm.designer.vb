<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Public Class frmPayroll
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(frmPayroll))
        Me.btnCalculate = New System.Windows.Forms.Button()
        Me.btnClear = New System.Windows.Forms.Button()
        Me.lblName = New System.Windows.Forms.Label()
        Me.lblHours = New System.Windows.Forms.Label()
        Me.lblRate = New System.Windows.Forms.Label()
        Me.lblPay = New System.Windows.Forms.Label()
        Me.txtNameInput = New System.Windows.Forms.TextBox()
        Me.txtHoursInput = New System.Windows.Forms.TextBox()
        Me.txtRateInput = New System.Windows.Forms.TextBox()
        Me.btnExit = New System.Windows.Forms.Button()
        Me.lblPayDisplay = New System.Windows.Forms.Label()
        Me.btnSummary = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'btnCalculate
        '
        Me.btnCalculate.Location = New System.Drawing.Point(255, 24)
        Me.btnCalculate.Margin = New System.Windows.Forms.Padding(4)
        Me.btnCalculate.Name = "btnCalculate"
        Me.btnCalculate.Size = New System.Drawing.Size(100, 28)
        Me.btnCalculate.TabIndex = 8
        Me.btnCalculate.Text = "&Calculate"
        '
        'btnClear
        '
        Me.btnClear.CausesValidation = False
        Me.btnClear.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.btnClear.Location = New System.Drawing.Point(255, 53)
        Me.btnClear.Margin = New System.Windows.Forms.Padding(4)
        Me.btnClear.Name = "btnClear"
        Me.btnClear.Size = New System.Drawing.Size(100, 28)
        Me.btnClear.TabIndex = 9
        Me.btnClear.Text = "Cl&ear"
        '
        'lblName
        '
        Me.lblName.Location = New System.Drawing.Point(9, 26)
        Me.lblName.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblName.Name = "lblName"
        Me.lblName.Size = New System.Drawing.Size(79, 17)
        Me.lblName.TabIndex = 0
        Me.lblName.Text = "&Name:"
        Me.lblName.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblHours
        '
        Me.lblHours.Location = New System.Drawing.Point(9, 54)
        Me.lblHours.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblHours.Name = "lblHours"
        Me.lblHours.Size = New System.Drawing.Size(79, 17)
        Me.lblHours.TabIndex = 2
        Me.lblHours.Text = "&Hours:"
        Me.lblHours.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblRate
        '
        Me.lblRate.Location = New System.Drawing.Point(9, 83)
        Me.lblRate.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblRate.Name = "lblRate"
        Me.lblRate.Size = New System.Drawing.Size(79, 17)
        Me.lblRate.TabIndex = 4
        Me.lblRate.Text = "&Rate:"
        Me.lblRate.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'lblPay
        '
        Me.lblPay.Location = New System.Drawing.Point(9, 114)
        Me.lblPay.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblPay.Name = "lblPay"
        Me.lblPay.Size = New System.Drawing.Size(79, 17)
        Me.lblPay.TabIndex = 6
        Me.lblPay.Text = "Pay:"
        Me.lblPay.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'txtNameInput
        '
        Me.txtNameInput.Location = New System.Drawing.Point(93, 23)
        Me.txtNameInput.Margin = New System.Windows.Forms.Padding(4)
        Me.txtNameInput.Name = "txtNameInput"
        Me.txtNameInput.Size = New System.Drawing.Size(132, 22)
        Me.txtNameInput.TabIndex = 1
        '
        'txtHoursInput
        '
        Me.txtHoursInput.Location = New System.Drawing.Point(93, 52)
        Me.txtHoursInput.Margin = New System.Windows.Forms.Padding(4)
        Me.txtHoursInput.Name = "txtHoursInput"
        Me.txtHoursInput.Size = New System.Drawing.Size(132, 22)
        Me.txtHoursInput.TabIndex = 3
        '
        'txtRateInput
        '
        Me.txtRateInput.Location = New System.Drawing.Point(93, 81)
        Me.txtRateInput.Margin = New System.Windows.Forms.Padding(4)
        Me.txtRateInput.Name = "txtRateInput"
        Me.txtRateInput.Size = New System.Drawing.Size(132, 22)
        Me.txtRateInput.TabIndex = 5
        '
        'btnExit
        '
        Me.btnExit.Location = New System.Drawing.Point(255, 111)
        Me.btnExit.Margin = New System.Windows.Forms.Padding(4)
        Me.btnExit.Name = "btnExit"
        Me.btnExit.Size = New System.Drawing.Size(100, 28)
        Me.btnExit.TabIndex = 10
        Me.btnExit.Text = "E&xit"
        '
        'lblPayDisplay
        '
        Me.lblPayDisplay.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.lblPayDisplay.Location = New System.Drawing.Point(93, 114)
        Me.lblPayDisplay.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblPayDisplay.Name = "lblPayDisplay"
        Me.lblPayDisplay.Size = New System.Drawing.Size(133, 25)
        Me.lblPayDisplay.TabIndex = 11
        Me.lblPayDisplay.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'btnSummary
        '
        Me.btnSummary.Location = New System.Drawing.Point(255, 82)
        Me.btnSummary.Margin = New System.Windows.Forms.Padding(4)
        Me.btnSummary.Name = "btnSummary"
        Me.btnSummary.Size = New System.Drawing.Size(100, 28)
        Me.btnSummary.TabIndex = 12
        Me.btnSummary.Text = "&Summary"
        '
        'frmPayroll
        '
        Me.AcceptButton = Me.btnCalculate
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.CancelButton = Me.btnClear
        Me.ClientSize = New System.Drawing.Size(391, 184)
        Me.Controls.Add(Me.btnSummary)
        Me.Controls.Add(Me.lblPayDisplay)
        Me.Controls.Add(Me.btnExit)
        Me.Controls.Add(Me.txtRateInput)
        Me.Controls.Add(Me.txtHoursInput)
        Me.Controls.Add(Me.txtNameInput)
        Me.Controls.Add(Me.lblPay)
        Me.Controls.Add(Me.lblRate)
        Me.Controls.Add(Me.lblHours)
        Me.Controls.Add(Me.lblName)
        Me.Controls.Add(Me.btnClear)
        Me.Controls.Add(Me.btnCalculate)
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Margin = New System.Windows.Forms.Padding(4)
        Me.MaximizeBox = False
        Me.MinimizeBox = False
        Me.Name = "frmPayroll"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "Payroll"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents btnCalculate As System.Windows.Forms.Button
    Friend WithEvents btnClear As System.Windows.Forms.Button
    Friend WithEvents lblName As System.Windows.Forms.Label
    Friend WithEvents lblHours As System.Windows.Forms.Label
    Friend WithEvents lblRate As System.Windows.Forms.Label
    Friend WithEvents lblPay As System.Windows.Forms.Label
    Friend WithEvents txtNameInput As System.Windows.Forms.TextBox
    Friend WithEvents txtHoursInput As System.Windows.Forms.TextBox
    Friend WithEvents txtRateInput As System.Windows.Forms.TextBox
    Friend WithEvents btnExit As System.Windows.Forms.Button
    Friend WithEvents lblPayDisplay As System.Windows.Forms.Label
    Friend WithEvents btnSummary As System.Windows.Forms.Button

End Class
