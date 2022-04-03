**PROCEDURE: main
**BEGIN: Three Address Code Statements
x_ = 0
temp0 = x_ == 0
temp2 = ! temp0
if(temp2) goto Label0
temp1 = x_ + 1
x_ = temp1
goto Label0
Label0:
temp3 = x_ == 0
temp5 = ! temp3
if(temp5) goto Label4
temp4 = x_ + 1
x_ = temp4
goto Label1
Label4:
temp6 = x_ == 5
temp8 = ! temp6
if(temp8) goto Label3
temp7 = x_ - 1
x_ = temp7
goto Label2
Label3:
Label2:
Label1:
**END: Three Address Code Statements
