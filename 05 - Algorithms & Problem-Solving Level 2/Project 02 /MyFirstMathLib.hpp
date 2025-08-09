#pragma once
#include <iostream>

namespace MyMathLibrary 
{
    double SimpleCalculator (double num1 , double num2 , char sign)
    {
            switch (sign)
            {
                case '+':
                    return num1 + num2 ;
                    break;
                
                case '-':
                    return num1 - num2;
                    break;

                case '*':
                    return num1 * num2;
                    break;

                case '/':
                    return num1 / num2;
                    break;

                default:
                    return num1 + num2 ;

            }
    }


int MyPower(int base  , int power)
{
   
    if (power > 1)
    {
        base = base * MyPower(base , power - 1);
       
    }
   
    return base;
   
}

}  
