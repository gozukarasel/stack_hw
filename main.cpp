/* @Author
Student Name: Ahmet Selim Gözükara
Student ID : 060190228
*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <string>
#include <iomanip>
#include <ctype.h> // for isdigit


using namespace std;

void infix_to_postfix(string,string&);
bool higher_priority(char,char);
double eval_postfix(string);
double evaluate(double,double,char);



int main(){
    string infix;
    string postfix;
    bool is_exit = false;


    while(!is_exit)
    {
        cout<<"Input the expression in infix: ";
        // cin>>infix;

        infix = "1+2+3+4";

        if (infix == "E" || infix == "e") 
            is_exit = true;

        else
        {
            infix_to_postfix(infix, postfix);
            cout<<postfix<<endl;
            cout<<setprecision(2)<<fixed<<eval_postfix(postfix)<<endl;
        }
        
        //cin.clear();
        //cin.ignore();
        infix.clear();
        postfix.clear();

    }
    return EXIT_SUCCESS;
}

void infix_to_postfix(string infix,string& postfix)
{
    stack<char> myStack;


    for(int i=0; i<infix.length(); i++)
    {
        if(isdigit(infix[i]) == true)
        {
            postfix = postfix + infix[i];
            cout<<postfix<<endl;
        }
        else if (isdigit(infix[i]) == false &&  !myStack.empty())
        {
            if(higher_priority(myStack.top(),infix[i]))
            {
                postfix = postfix + myStack.top();
                cout<<postfix<<endl;
                myStack.pop();
                myStack.push(infix[i]);
                cout<<postfix<<endl;
            }
            else
            {
                myStack.push(infix[i]);
            }
            
        }
        else if (isdigit(infix[i]) == false && myStack.empty())
        {
            myStack.push(infix[i]);
        }
    }

    while(!myStack.empty())
    {
        postfix = postfix + myStack.top();
        myStack.pop();
    }
    
}

bool higher_priority(char first,char second)
{
    if(first=='*' || first=='/')
        return true;
    else if(second=='+' || second=='-')
        return true;
    else return false;
}



double eval_postfix(string expr)
{
    
    stack<double> myStack;

    for(int i = 0; i<expr.length(); i++)
    {
        if (isdigit(expr[i]) == true)
        {
            double number = static_cast<double>(expr[i] - '0');
            myStack.push(number);
        }
        else
        {
            double first = myStack.top() ; myStack.pop();
            double second = myStack.top(); myStack.pop();

            double result  = evaluate(first,second,expr[i]);

            myStack.push(result);
        }
        
    }
    double final_result = myStack.top(); 
    
    return final_result;
}



double evaluate(double first,double second,char c)
{
    switch(c)
    {
        case '*':
            return first*second;
        case '+':
            return first+second;
        case '-':
            return first-second;
        case '/':
            return first/second;
        default:
            return 0;
    }
}

