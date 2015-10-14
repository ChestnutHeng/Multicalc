#include <cmath>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include "Stack.h"


#ifndef EPS
	#define EPS 0.000001
#endif

using namespace std;

static char digit[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
static char num_dig[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

string upper(string str){
    transform(str.begin(), str.end(), str.begin(), ::toupper);  
    return str;
}
int convert_to_10(string num,int R1){
    int ans = 0;
    num = upper(num);
    char *pha = (char *)num.c_str();
    char *p = pha;
    int i = 0;
    for (p = pha + num.size() - 1; p != pha - 1; --p)
    {
        for (int j = 0; j < 16; ++j)
        {
            if(*p == digit[j])
                ans += num_dig[j] * pow(R1 , i);
        }
        i++;
    }
    return ans; 
}

string convert(string num,int R1,int R2)
{

	int number;
    Stack <char> answer;
	number =  convert_to_10(num,R1);
    cout << "Notes:" << number << "(10)" << endl;
    while(number != 0){
        answer.push(digit[number % R2]);
        number = number / R2;
	}
    char *str = new char[answer.size()];
    for (int i = 0;!answer.empty(); ++i)
    {
        str[i] = answer.pop();
    }
    string op = str;
    return op;
}

void Numsys()
{
    int r1,r2;
    string former;
    string later;

    do
    {
        cout << "Input number and R1:" ;
 		cin >> former;
 		if(former == "q") break;
        cin >> r1;
        if (r1 == 0) {
        	cout << "R1 shouldn't be 0." << endl;
        	continue;
        }
        cout << "To R2:";
        cin >> r2;
        if (r2 == 0) {
        	cout << "R2 shouldn't be 0." << endl;
        	continue;
        }
        else if(r2 ==  10){
            cout << "The answer is:" << convert_to_10(former,r1) << "(" << r2 << ")" << endl;
        }
        else {
            later = convert(former,r1,r2);
            cout << "The answer is:" << later << "(" << r2 << ")" << endl;
        }
        cout << "q to quit." << endl;
    }while (former != "q");
}
