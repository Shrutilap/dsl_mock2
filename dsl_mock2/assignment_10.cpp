/*Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions: 
1. Operands and operator, both must be single character. 
2. Input Postfix expression must be in a desired format. 
3. Only '+', '-', '*' and '/ ' operators are expected. 
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int max_size = 10;
class Stack{
    char *arr;
    string exp;
    int size;
    string postfix;
    public:
    Stack(){
        arr = new char[max_size];
        size = 0;
        postfix = "";
    }

    int precedence(char op) {
    if(op == '*' || op == '/') return 2; // Multiplication and Division
    if(op == '+' || op == '-') return 1; // Addition and Subtraction
    return 0; // Parentheses or any other symbol
}

    string inputExp(){
        cout<<"Enter expression for converting from infix to postfix : "<<endl;
        cin>>exp;
        return exp;
    }


    void add_element(char ele){
        if(size<max_size){
            arr[size++] = ele;

        }
        
    }

    char top(){
        if(size>0){
            return arr[size-1];
        }
    }
    char pop(){
        if(size>0){
            return arr[--size];
        }
    }

    bool isEmpty(){
        return size == 0;
    }

    void convert(){
        for(int i = 0; i<exp.size(); i++){
            if(isEmpty()){
                if(exp[i] != '+' && exp[i] != '-' && exp[i] != '/' && exp[i] != '*'){
                    postfix += exp[i];
                
                }else{
                    add_element(exp[i]);
                }
            }
            else{
                if(exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*'){
                    char Top = top();
                    if(precedence(Top) < precedence(exp[i])){
                        add_element(exp[i]);
                    }
                    else{
                        postfix += pop();
                        add_element(exp[i]);
                    }

                }
                else{
                    postfix += exp[i];
                }
                
                
            }
            
        }
        while(!isEmpty()){
                postfix += pop();
            }
        
        cout<<postfix<<endl;
    }

    int eval(string exp, string foreval){

        Stack s1;
        for(int i = 0; i < foreval.size(); i++){
            if(isdigit(foreval[i])){
                s1.add_element(foreval[i]-'0');
            }
            else{
                int result;
                int operator1, operator2;
                operator2 = s1.pop();
                operator1 = s1.pop();
                switch(foreval[i]){
                    case '+' : result = operator1 + operator2;
                                break;
                    case '-' : result = operator1 - operator2;
                                break;
                    case '/' : result = operator1 / operator2;
                                break;
                    case '*' : result = operator1 * operator2;
                                break;
                }
                s1.add_element(result);
            }
        }
        return s1.pop();
    }
};
int main()
{
    Stack s;
    string exp = s.inputExp();
            
    s.convert();
    string foreval;
    cout<<"Input numbers to evaluate the expression "<<exp<<endl;
    cin>>foreval;
    int final = s.eval(exp, foreval);
    cout<<final;
    
    return 0;
}