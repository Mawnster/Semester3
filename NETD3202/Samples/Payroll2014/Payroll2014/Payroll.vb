'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'Project:       Payroll2014                                             '
'Programmer:    Kevin Dougherty                                         '
'Module:        Payroll.vb Class                                        '
'Date:          January 2007                                            '
'                                                                       '
'Description:   Business tier for payroll calculation: validates input  '
'               data and throws exception as requried.  On validation   '
'               calculation of the employee pay is carried out.         '
'               Overtime pay is calculated as required on hours over 40 '
'               on top of regular pay.                                  '
'               Summary data is also calculated as part of this class   '
'               based on each payroll object created including number   '
'               employees (objects) processed, total payroll for all    '
'               employee objects and the total overtime hours worked    '
'               by all employees.                                       '
'Folder:        PresentationAndBusinessTiers                            '
'Modified:      January 17, 2013                                        '
'               Updated names to match current Program Style Guide      '
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

Friend Class Payroll

#Region "Instance and Shared Property Variables"

    ' Instance variables.
    Private employeeHours As Decimal                ' Hold the hours worked value for object.
    Private payRate As Decimal                      ' Hold the pay rate value for object.
    Private employeePay As Decimal                  ' Hold the calucalted employee pay for object.

    ' Shared class variables.
    Private Shared numberOfEmployees As Integer   ' Hold the total number of employees processed for all objects.
    ' Number of employees is Protected for access by any derived class
    Private Shared totalPayroll As Decimal          ' Hold the total payroll for all objects.
    Private Shared totalOvertimeHours As Decimal    ' Hold the total overtime hours worked for all objects.

#End Region

#Region "Constructors"

    ' Constructor.
    Friend Sub New(ByVal hoursValue As Decimal, ByVal rateValue As Decimal)
        ' Assign object property values and calculate the employee pay.

        ' Set the hours using the Hours property procedure
        Me.Hours = hoursValue
        ' Set the rate using the Rate property procedure
        Me.Rate = rateValue
        ' Call to the method to calculate and set employee pay
        findPay()
    End Sub

    Friend Sub New()
        ' Empty constructor for inheritance and instantiation.

    End Sub

#End Region

#Region "Class Methods"

    Protected Overridable Sub findPay()
        ' local constant declarations.
        Const REGULAR_HOURS As Decimal = 40D    ' Threshold for regular pay hours.
        Const OVERTIME_RATE As Decimal = 1.5D   ' All overtime pay is calulated as 1.5 X regular pay (time and one half)

        ' Calculate the employee pay.

        ' Local variable for overtime hours
        Dim overtimeHours As Decimal

        ' Are the employee hours greater then the maximum regular hours?
        If employeeHours <= REGULAR_HOURS Then            ' No overtime.
            ' set employee pay = hours worked X rate
            employeePay = employeeHours * payRate
            ' set overtime hours to 0
            overtimeHours = 0D
        Else                                                ' Overtime.
            ' calculate overtime hours as total hours worked minus maximum regular hours.
            overtimeHours = employeeHours - REGULAR_HOURS
            ' set employee pay = maximum regular hours X rate plus overtime hours X rate X 1.5
            employeePay = (REGULAR_HOURS * payRate) + _
              (overtimeHours * OVERTIME_RATE * payRate)
        End If

        ' Add overtime hours to shared summary variable
        totalOvertimeHours += overtimeHours
        ' Add employee pay to shared summary variable
        totalPayroll += employeePay
        ' Increment the number of employees processed
        numberOfEmployees += 1
    End Sub

    ' Procedure in the Payroll class to override 
    ' the ToString() function.
    Public Overrides Function ToString() As String
        ' Return the Name property for this object’s
        ' ToString method.
        Return employeeHours & ": " & employeePay
    End Function

#End Region

#Region "Property Procedures"

    Friend Property Hours() As Decimal
        ' Read and Write the hours worked
        ' Includes validation of hours within minimum and maximum

        ' Read and return the employee hours for an object
        Get
            Return employeeHours
        End Get

        ' Write the employee hours for an object, after passing validation
        Set(ByVal setHoursValue As Decimal)
            ' Is the value passed to this procedure within the acceptable
            ' range for hours worked for an employee?

            ' local constant declarations
            Const MINIMUM_HOURS As Decimal = 1D     ' Minimum hours that can worked and paid for any employee object.
            Const MAXIMUM_HOURS As Decimal = 60D    ' Maximum hours that can worked and paid for any employee object.

            If setHoursValue >= MINIMUM_HOURS And _
              setHoursValue <= MAXIMUM_HOURS Then
                ' Write to the employee hours field
                employeeHours = setHoursValue
            Else
                ' If outside of range, throw a new Application Exception
                ' to the calling class, including a message and the
                ' source of the exception
                Dim payrollException As New ApplicationException( _
                  "Hours are outside of the acceptable range: " & _
                    MINIMUM_HOURS & " - " & MAXIMUM_HOURS)
                payrollException.Source = "Hours"

                ' Throw the exception
                Throw payrollException
            End If
        End Set
    End Property

    Friend Property Rate() As Decimal
        ' Read and Write the rate of pay
        ' Includes validation of rate within minimum and maximum

        ' Read and return the rate of pay for an object
        Get
            Return payRate
        End Get

        ' Write the pay rate for an object, after passing validation
        Set(ByVal setPayRateValue As Decimal)
            ' local constant declarations
            Const MINIMUM_WAGE As Decimal = 10.25D   ' Minimum pay rate for any employee object.
            Const MAXIMUM_WAGE As Decimal = 42D     ' Maximum pay rate for any employee object.

            ' Is the value passed to this procedure within the acceptable
            ' range for pay rate for an employee?
            If setPayRateValue >= MINIMUM_WAGE And _
              setPayRateValue <= MAXIMUM_WAGE Then
                ' Write to the pay rate field
                payRate = setPayRateValue
            Else
                ' If outside of range, throw a new Application Exception
                ' to the calling class, including a message and the
                ' source of the exception
                Dim payrollException As New ApplicationException( _
                  "Pay rate is outside of the acceptable range: " & _
                    FormatCurrency(MINIMUM_WAGE) & " - " & FormatCurrency(MAXIMUM_WAGE))
                payrollException.Source = "Rate"

                ' Throw the exception
                Throw payrollException
            End If
        End Set
    End Property

    Friend ReadOnly Property Pay() As Decimal
        ' Read and return the employee pay, this field cannot be
        ' written to outside of the findPay() method
        Get
            Return employeePay
        End Get
    End Property


    Friend Shared ReadOnly Property TotalPay() As Decimal
        ' Read and return the total pay summary value, this value cannot be
        ' written to outside of the findPay() method
        Get
            Return totalPayroll
        End Get
    End Property

    Friend Shared ReadOnly Property OvertimeHours() As Decimal
        ' Read and return the overtime hours summary value, this value cannot be
        ' written to outside of the findPay() method
        Get
            Return totalOvertimeHours
        End Get
    End Property

    Friend Shared ReadOnly Property NumberProcessed() As Decimal
        ' Read and return the number of employees processed summary value
        ' this field cannot be written to outside of the addEmployee() method
        Get
            Return numberOfEmployees
        End Get
    End Property

#End Region

End Class



