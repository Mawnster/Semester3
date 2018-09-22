'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'Project:       Payroll2014                                             '
'Programmer:    Kevin Dougherty                                         '
'Form:          frmPayroll                                              '
'Date:          January 2007                                            '
'Description:   Summary form for the Payroll application.  This form    '
'               manages the display of all summary data on instantiated '
'               Payroll objects during the run of this application.     '
'               The shared summary properties are accessed through the  '
'               class directly and displayed in the coresponding labels '
'               on the form.                                            '
'               This is a modal or "dialog" form that persists in       '
'               holding focus within the application until it is closed.'
'Folder:        PresentationAndBusinessTiers                            '
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

Public Class frmSummary

    Private Sub frmSummary_Activated(ByVal sender As Object, _
        ByVal e As System.EventArgs) Handles Me.Activated
        ' This procedure handles the display of all summary
        ' data of the Payroll class through the property 
        ' procedures for the shared properties of the class.
        ' The Activated event fires each time this form recieves
        ' the focus through a Load or through navigation to the 
        ' form directly.

        Dim summaryPayroll As New Payroll()         ' Declare and instantiate a Payroll object for shared 
        '                                             property access only by using the default constructor.

        ' Accessing shared class properties through the appropriate class
        ' can be achieved by using an instance of the class but this will
        ' result in a warning and VS will access the property through
        ' the class name directly.

        ' Accessing the total number processed through the object
        ' and displaying in the appropriate label on the form. This
        ' will result in an error and the class is then directly 
        ' accessed (by class name).
        lblObjectCountDisplay.Text = summaryPayroll.NumberProcessed.ToString()
        ' Accessing the total overtime hours through the class directly
        ' and displaying as a number with one decimal place in the 
        ' appropriate label.  No warning message...
        lblOvertimeDisplay.Text = Payroll.OvertimeHours.ToString("N1")
        ' Accessing the total pay through the class and displaying as
        ' currency in the appropriate label.
        lblPayrollDisplay.Text = Payroll.TotalPay.ToString("C")
    End Sub

    Private Sub btnClose_Click(ByVal sender As System.Object, _
        ByVal e As System.EventArgs) Handles btnClose.Click
        ' This procedure handles the closing of the form which
        ' will result in focus returning to the payroll form.

        ' Close this form
        Me.Close()
    End Sub

End Class
