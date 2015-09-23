#include <iostream>
#include <string>

#include "main.h"


using namespace std;

// double fourans(double a, double b,string str);
// int stringconvert(string str);

int main()
{
    string str;
    while(true)
    {
        cout << ">>>Input a command:(Linar,Numsys,q):";
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
        else {cout << "Error input." << endl;}
    }
    return 0;
}


