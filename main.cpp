#include <iostream>
#include <stdio.h>
#include <string>
#include "linar.h"
#include "numsys.h"
using namespace std;


string str1,str2,str3;

double fourans(double a, double b,string str);
int stringconvert(string str);


int main()
{
    string str;
    while(str != "q")
    {
         cout << ">>>Input a command:(Linar,Numsys,q):";

         cin >> str ;
         if((str == "Linar") || (str == "linar"))  Linar();
         if((str == "numsys") || (str == "Numsys")) Numsys();
    }
    return 0;
}


