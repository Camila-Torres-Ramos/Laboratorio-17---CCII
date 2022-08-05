#include "Calculadora.h"    

int main()      
{
    int date1{1},date2{2};
    float date_1{1.5},date_2{2.9};
    Calculadora<int,float> C(date1,date_2);     
    Calculadora<float,int> D(date_1,date2);    

    return 0;
}

