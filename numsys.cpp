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
int dot = 0;
float decimal = 0;
int integer = 0;

string upper(string str){
    transform(str.begin(), str.end(), str.begin(), ::toupper);  
    return str;
}
float convert_to_10(string num,int R1){
    float ans = 0;
    dot = 0;
    decimal = 0;
    integer = 0;
    bool isPos = true;
    bool isDes = false;
    int num_size = num.size();

    num = upper(num);
    char *old_pha = (char *)num.c_str();
    char *pha = old_pha;
    if(*pha == '-') {
        isPos = false;
        num_size--;
        pha++;
    }
    char *p = pha;

    for (p = pha + num_size - 1; p != pha - 1; --p){
        if(*p == '.') {
            dot = pha + num_size - 1 - p;
            isDes = true;
        }
    }

    int i = num_size - 1 - dot;
    if(isDes) i--;
    for (p = pha;*p != '.' && *p != '\0'; ++p)
    {
        for (int j = 0; j < 16; ++j)
        {
            if(*p == digit[j])
                integer += num_dig[j] * pow(R1 ,i);
        }
        
        i--;
    }
    
    if(isDes) p++;
    i = -1;
    for (;*p != '\0'; ++p)
    {
        for (int j = 0; j < 16; ++j)
        {
            if(*p == digit[j])
                decimal += ((float)num_dig[j] )* pow(R1 ,i);
        }
        i--;
    }

    ans = integer + decimal;
    if(!isPos) ans = -ans;
    return ans; 
}

string convert(string num,int R1,int R2)
{
    float flo_num;
    Stack <char> answer;

	flo_num =  convert_to_10(num,R1);
    cout << "Notes:" << flo_num << "(10)" << endl;

    while(integer != 0){
        answer.push(digit[integer % R2]);
        integer = integer / R2;
    }
    
    string str;
    for (int i = 0;!answer.empty(); ++i)
    {
        str.push_back(answer.pop());
    }
    
    if(dot > 0){
        str.push_back('.');
        while(decimal != 0){
            decimal = decimal * R2;
            str.push_back(digit[(int)decimal]);
            decimal -= (int)decimal;
        }
    }
    return str;
}

void Numsys()
{
    int r1,r2;
    string former;
    string later;
    do
    {
        cout << ">>>Input number and R1:" ;
 		cin >> former;
 		if(former == "q") break;
        cin >> r1;
        if (r1 == 0) {
        	cout << "Error:R1 shouldn't be 0." << endl;
        	continue;
        }
        cout << "To R2:";
        cin >> r2;
        if (r2 == 0) {
        	cout << "Error:R2 shouldn't be 0." << endl;
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
