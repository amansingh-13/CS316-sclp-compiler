**PROCEDURE: main
**BEGIN: Three Address Code Statements
x_ = 0
temp0 = x_ == 0
temp1 = ! temp0
if(temp1) goto Label1
x_ = 5
goto Label0
Label1:
x_ = 6
temp2 = x_ == 6
temp3 = ! temp2
if(temp3) goto Label2
goto Label2
Label2:
Label0:
**END: Three Address Code Statements
