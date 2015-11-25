#include <iostream>
#include <cstdio>

#include "Stack.h"

#define N_OPTR 9
#define VERIFY(_STACK_) {\
    if (_STACK_.empty()) {\
        return false;\
    }\
}

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
    if((s <='9' && s >= '0'))
        return true;
    else return false;
}

float power(int a,int b){
    float sum = 1;
    if(b < 0){
       while((b++) < 0)
        sum /= a; 
        return sum;
    }
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
    if(*s == '.') {
        int i = -1;
        while(isdigit(*(++s))){
            cout << "ff";
            new_num += (*s - 48) * power(10,i);
            i--;
        }
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

bool evaluate(char *S, float *result){
    Stack <float> opnd;
    Stack <char> optr;
    char *origin = S;
    optr.push('\0');
    while(!optr.empty()){
        if(isdigit(*S)){
            S = readNumber(S,opnd);
        }else{
            if (*S == '-') {
                if (S == origin) {
                    opnd.push(0);
                } else if (S[-1] == '(') {
                    opnd.push(0);
                }
            }
            switch(orderBetween(optr.top(),*S)){
                case '>':
                    {
                        VERIFY(optr);
                        char op = optr.pop();
                        if('!' == op){
                            float pOpnd = opnd.pop();
                            VERIFY(opnd);
                            opnd.push(calcu(op,pOpnd));
                        }else{
                            VERIFY(opnd);
                            float pOpnd2 = opnd.pop();
                            VERIFY(opnd);
                            float pOpnd1 = opnd.pop();
                            opnd.push(calcu(pOpnd1,op,pOpnd2));
                        }
                        break;
                    }
                case '<':
                    optr.push(*S);
                    S++;
                    break;
                case '=':
                    VERIFY(optr);
                    optr.pop();
                    S++;
                    break;
            }
        }

    }
    *result = opnd.pop();
    return true;
}

void expression_calc(){
    while(true){
        char exp[100];
        char *pt = exp;
        cout << ">>>Input your expression:";
        scanf("%s",exp);
        if (exp[0] == 'q') return;
        float output;
        if (evaluate(exp, &output)) {
            cout << "Answer: " << output << endl;
        } else {
            cout << "Syntax error." << endl;
        }
    }
}
