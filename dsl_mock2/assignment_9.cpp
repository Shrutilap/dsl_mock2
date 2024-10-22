/*In any language program mostly syntax error occurs due to unbalancing delimiter such as (), {}, []. Write C++ program using stack to check whether given expression is well parenthesized or not.*/
#include <iostream>
using namespace std;
const int max_size = 10;
class Stack{
    char *arr;
    int size;

    public:
    Stack(){
        this->size = 0;
        arr = new char[max_size];
    }

    ~Stack() {
        delete[] arr;
    }

    bool matched(char opening, char closing){
        return (opening == '(' && closing == ')') || (opening == '[' && closing == ']') || (opening == '{' && closing == '}');
    }

    void input(string &brackets){
        cout<<"Enter string for checking balanced parenthesis : "<<endl;
        cin>>brackets;
    }

    void add_element(char ele){
        if(size<max_size){
            arr[size++] = ele;
        }
        else{
            cout<<"Array is full"<<endl;
        }    
    }

    char top(){
        if(size>0){
            return arr[size-1];
        }
        else{
            cout<<"Array is empty"<<endl;
        }
    }

    char pop(){
        if(size>0){
            return arr[--size];
        }
        else{
            cout<<"Array is empty"<<endl;
            return '0';
        }
    }

    bool isEmpty(){
        return size == 0;
        
    }

    void balancedparent(string &brackets){
        for(int i = 0; i<brackets.size(); i++){
            if(brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{'){
                add_element(brackets[i]);
            }
            else{
               
                if(isEmpty()){
                    cout<<"Unbalanced parenthesis"<<endl;
                    return;
                }
                else{
                     char Top = pop();
                    if(!matched(Top, brackets[i])){
                        cout<<"Unbalanced parenthesis"<<endl;
                        return;
                    }
                }
               
            }
        }
        if(isEmpty()){
            cout<<"Its a balanced parenthesis"<<endl;
        }
        else{
            cout<<"Its not a balanced parenthesis"<<endl;
        }
    }


};
int main()
{
    Stack s;
    string brackets;
    s.input(brackets);
    s.balancedparent(brackets);
    return 0;
}