void main(){
    // float x;
    // bool y;
    // x = x * x;
    // x = x + x;
    // x = x / x;
    // y = x > x;
    // y = y || y;


    int x, y;
    float z;
    x = x + y + x + y;
    x = x * (y + 123455555555555588000000000000000000000000000);
    z = 123.444444444444444444444444444444444444444;
    
    if(!x>y){
        y = x;
    }
    else{
        x = y;
    }

    while(x > 2){
        x = y;
    }

    do{
        y = x;
    }
    while(y > 2 && x > 2);

    x = x>2 ? x : y;

    read x;
    print y*y;

    //x = ((x + y)+(x+y)) + ((x + y)+(x+y));


}