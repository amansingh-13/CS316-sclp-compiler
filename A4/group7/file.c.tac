**PROCEDURE: main
**BEGIN: Three Address Code Statements
temp0 = x_ != 0
temp3 = ! temp0
if(temp3) goto Label2
temp1 = x_ == 0
temp2 = ! temp1
if(temp2) goto Label1
x_ = 5
goto Label0
Label1:
f_ = 2
Label0:
goto Label2
Label2:
Label3:
x_ = 5
temp4 = x_ != 5

if (temp4) goto Label3
Label9:
temp5 = x_ > 5
temp12 = !temp5
if(temp12) goto Label10
temp6 = x_ * x_
x_ = temp6
Label8:
temp7 = x_ < 12
temp8 = ! temp7
if(temp8) goto Label7
x_ = 9
goto Label4
Label7:
temp9 = x_ > 12
temp10 = ! temp9
if(temp10) goto Label6
x_ = 18
x_ = 78
goto Label5
Label6:
x_ = 90
write x_
Label5:
Label4:
temp11 = x_ != 0

if (temp11) goto Label8
write x_
goto Label9
Label10:
**END: Three Address Code Statements