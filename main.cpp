/* @Author
Student Name: Umut TÖLEK
Student ID : 150190724
Date: 08.11.2021 */


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
        cin>>infix;

        if (infix == "E" || infix == "e") 
            is_exit = true;

        else
        {
            infix_to_postfix(infix, postfix);
            cout<<postfix<<endl;
            cout<<setprecision(2)<<fixed<<eval_postfix(postfix)<<endl;
        }
        
        cin.clear();
        cin.ignore();
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

bool higher_priority(char first,char second){
    if(first=='*' || first=='/')
        return true;
    else if(second=='+' || second=='-')
        return true;
    else return false;
}




double eval_postfix(string expr){
    
}

double evaluate(double first,double second,char c){
    switch(c){
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

