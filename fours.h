#include <iostream>
#include <stdio.h>
#include <string>
void fourr()
{
    /

}
double fourans(double a, double b,string str)
{
    char ch = str.at(0);
    switch(ch)
    {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;

    }
    return 1;
}

int stringconvert(string str)
{

    bool str1over = false;
    for(unsigned int i = 0;i < str.length(); ++i)
    {
        if(str1over == false || 0 <= str[i] || str[i] <= 9 || str[i] == '.' || str[i] == 'E')
            str1 += str[i];
        else if (0 > str[i] ||  str[i] > 9 || str[i] != '.' || str[i] != 'E')
        {
            str2 += str[i];
            str1over = true;
        }
        else str3 += str[i];

    }
    return 0;
}