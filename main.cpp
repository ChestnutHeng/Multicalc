#include <iostream>
#include <string>

#include "main.h"
#include "Stack.h"

using namespace std;


int main()
{
    string str;

    while(true)
    {
        cout << ">>>Input a command:(Calc,Linar,Numsys,q):";
        cin >> str ;
        if(str == "q") {
            break;
        }
        else if((str == "Linar") || (str == "linar")) {
            Linar();
        }
        else if((str == "numsys") || (str == "Numsys")) {
            Numsys();
        }
        else if(str == "Calc" || str == "calc"){
            expression_calc();
        }
        else {cout << "Error input." << endl;}
    }
    return 0;
}

