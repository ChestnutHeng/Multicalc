#include <iostream>
#include <cstdio>

#include "Stack.h"

#define N_OPTR 9

using namespace std;


const char pri[N_OPTR][N_OPTR] = {
    '>','>','<','<','<','<','<','>','>',
    '>','>','<','<','<','<','<','>','>',
    '>','>','>','>','<','<','<','>','>',
    '>','>','>','>','<','<','<','>','>',
    '>','>','>','>','>','<','<','>','>',
    '>','>','>','>','>','>',' ','>','>',
    '<','<','<','<','<','<','<','=',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',
    '<','<','<','<','<','<','<',' ','=',
}; //    +,-,*,/,^,!,(,),\0

bool isdigit(char s){
    if((s <='9' && s >= '0') ||s == '.')
        return true;
    else return false;
}

int power(int a,int b){
    int sum = 1;
    while((b--) > 0)
        sum *= a;
    return sum;
}

char * readNumber(char *s,Stack <float> &num){
    float new_num = 0;
    new_num += (*s) - 48;
    while(isdigit(*(++s))){
        new_num = new_num * 10;
        new_num += (*s - 48);
    }
    num.push(new_num);
    return s;
}

float calcu(char op,float p){
    int new_p = (int) p;
    float sum = 1;
    switch(op){
        case '!':
            while(new_p != 0){
                sum *= new_p--;
            }
            break;
    }
    return sum;
}

float calcu(float p1,char op,float p2){
    switch(op){
        case '+':
        return p1 + p2;
        case '-':
        return p1 - p2;
        case '*':
        return p1 * p2;
        case '/':
        return p1 / p2;
        case '^':
        return power(p1,p2);
    }
    return 0;
}

char orderBetween(char s1,char s2){
    int raw,col;
    switch(s1){
        case '+':
            raw = 0;
            break;
        case '-':
            raw = 1;
            break;
        case '*':
            raw = 2;
            break;
        case '/':
            raw = 3;
            break;
        case '^':
            raw = 4;
            break;
        case '!':
            raw = 5;
            break;
        case '(':
            raw = 6;
            break;
        case ')':
            raw = 7;
            break;
        case '\0':
            raw = 8;
            break;
    }
    switch(s2){
        case '+':
            col = 0;
            break;
        case '-':
            col = 1;
            break;
        case '*':
            col = 2;
            break;
        case '/':
            col = 3;
            break;
        case '^':
            col = 4;
            break;
        case '!':
            col = 5;
            break;
        case '(':
            col = 6;
            break;
        case ')':
            col = 7;
            break;
        case '\0':
            col = 8;
            break;
    }
    return pri[raw][col];
}

float evaluate(char *S){
    Stack <float> opnd;
    Stack <char> optr;
    optr.push('\0');
    while(!optr.empty()){
        if(isdigit(*S)){
            S = readNumber(S,opnd);
        }else{
            switch(orderBetween(optr.top(),*S)){
                case '>':
                {
                    char op = optr.pop();
                    if('!' == op){
                        float pOpnd = opnd.pop();
                        opnd.push(calcu(op,pOpnd));
                    }else{
                        float pOpnd2 = opnd.pop();
                        float pOpnd1 = opnd.pop();
                        opnd.push(calcu(pOpnd1,op,pOpnd2));
                    }
                }
                break;
                case '<':
                    optr.push(*S);
                    S++;
                    break;
                case '=':
                    optr.pop();
                    S++;
                    break;
            }
        }

    }
    return opnd.pop();
}

void expression_calc(){
    while(true){
        char exp[100];
        char *pt = exp;
        cout << ">>>Input your expression:";
        scanf("%s",exp);
        if (exp[0] == 'q') return;
        cout << "Answer: " << evaluate(exp) << endl;
    }
}
