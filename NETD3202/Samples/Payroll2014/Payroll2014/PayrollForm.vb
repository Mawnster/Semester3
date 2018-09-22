'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'Project:       Payroll2014                                             '
'Programmer:    Kevin Dougherty                                         '
'Form:          frmPayroll                                              '
'Date:          January 2007                                            '
'Description:   User interface for payroll application.                 '
'               Accepts data entry of user name, hours worked and       '
'               hourly rate for the worker.  This version validates     '
'               both hours and rate to ensure entry of numeric data,    '
'               greater than zero in both cases.                        '
'               Once the endtered data is validated, the worker's pay   '
'               is calculated through the creation of a Payroll object  '
'               that provides access to a find pay method as well as    '
'               properties to maintain summary data on all Payroll      '
'               objects created.                                        '
'               The form contains buttons for pay calculation, clearing '
'               the form data for a new entry, displaying summary data  '
'               on all Payroll objects created through the display of a '
'               modal summary form and exiting the application.         '
'Folder:        PresentationAndBusinessTiers                            '
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

Public Class frmPayroll


    Private Sub btnCalculate_Click(ByVal sender As System.Object, _
        ByVal e As System.EventArgs) Handles btnCalculate.Click
        ' This procedure performs data validation on hours and 
        ' rate and then creates a Payroll object (on valid data)
        ' for pay calculation and summary data tabulation.

        Dim payObject As Payroll            ' Create a Payroll object for access to the business tier.

        Dim formInputHours As Decimal       ' Hold the valid hours input for passing to the business class constructor
        Dim formInputRate As Decimal        ' Hold the valid rate input for passing to the business class constructor

        ' Go ahead and parse the entered value for hours.
        ' If non-numeric data is entered formInputHours will
        ' hold 0 as a value.
        Decimal.TryParse(txtHoursInput.Text, formInputHours)
        ' If the user entered valid numeric data greater than 0...
        If formInputHours > 0 Then
            ' Parse the entered value for rate only if the 
            ' entered hours is valid
            Decimal.TryParse(txtRateInput.Text, formInputRate)
            ' If the user entered valid numeric data greater than 0...
            If formInputRate > 0 Then

                ' Both values parsed successfully, instantiate the declared
                ' Payroll object using the parameterized constructor.
                ' Pass the input hours and input rate to the contstructor
                ' for object creation, pay calculation and summary tabulation.
                payObject = New Payroll(formInputHours, formInputRate)

                ' Set the pay label text to the value calculated for pay
                ' for this worker by calling the "Pay" property procedure of
                ' the business class on the Payroll object.  Format the 
                ' output as Currency.
                lblPayDisplay.Text = payObject.Pay.ToString("C")


            Else
                ' Rate did not pass validation, send a message to the user, select 
                ' any entry in the "rate" text box and set the focus for a new entry.
                MessageBox.Show("The rate must be numeric, greater than zero.", _
                                "Payroll Input Error")
                txtRateInput.SelectAll()
                txtRateInput.Focus()

            End If
        Else
            ' Hours did not pass validation, send a message to the user, select 
            ' any entry in the "hours" text box and set the focus for a new entry.
            MessageBox.Show("The hours must be numeric, greater than zero.", "Payroll Input Error")
            txtHoursInput.SelectAll()
            txtHoursInput.Focus()

        End If

    End Sub

    Private Sub btnClear_Click(ByVal sender As System.Object, _
        ByVal e As System.EventArgs) Handles btnClear.Click
        ' This procedure resets the form for a new entry
        ' of rate and hours for another Payroll object.

        ' Clear the output label text
        lblPayDisplay.Text = ""
        ' Clear the input hours text field
        txtHoursInput.Clear()
        ' Clear the input rate text field
        txtRateInput.Clear()
        ' Clear the input name text field
        txtNameInput.Clear()
        ' Set the focus in the name text field to allow
        ' for entry of values for a new Payroll object.
        txtNameInput.Focus()
    End Sub

    Private Sub btnExit_Click(ByVal sender As System.Object, _
        ByVal e As System.EventArgs) Handles btnExit.Click
        ' This procedure handles the closing of the form and
        ' ending the program.

        ' Close this form and exit the program.
        Me.Close()
    End Sub

    Private Sub btnSummary_Click(sender As Object, _
        e As EventArgs) Handles btnSummary.Click
        ' This procedure handles the display of the 
        ' summary form as a modal form.  Control can
        ' not be regained by this form until the 
        ' summary form is closed.

        ' Display the summary form modal
        ' so form has to be explicitly closed
        ' prior to returning to this form
        frmSummary.ShowDialog()

    End Sub
End Class