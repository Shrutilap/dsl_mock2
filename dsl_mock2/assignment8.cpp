/*Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B of students like butterscotch ice-cream. Write C++ program to store two sets using linked list. compute and display- 
	a) Set of students who like both vanilla and butterscotch 
	b) Set of students who like either vanilla or butterscotch or not both 
	c) Number of students who like neither vanilla nor butterscotch */
#include <iostream>
using namespace std;
class Node{
    public:
    string name;
    Node *next;
    public:
    Node(string name){
        this->name = name;
        next = nullptr;
    }
};
Node* createSetVanilla(Node *head, string name){
    Node *newNode = new Node(name);
    if(head == nullptr){
        head = newNode;
    }
    else{
         Node *temp = head;
        while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;

    }
    return head;
}

Node* createSet(Node *head, string name){
    Node *newNode = new Node(name);
    if(head == nullptr){
        head = newNode;
    }
    else{
         Node *temp = head;
        while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;

    }
    return head;
}

Node* createSetButter(Node *head, string name){
    Node *newNode = new Node(name);
    if(head == nullptr){
        head = newNode;
    }
    else{
        Node *temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

Node* likeBoth(Node* head1, Node* head2){
    Node *commonHead = nullptr;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while(temp1 != nullptr){
        while(temp2 != nullptr){
             if(temp1->name == temp2->name){
                commonHead = createSet(commonHead, temp1->name);
                break;
        }
        temp2 = temp2->next;

        }
        temp1 = temp1->next;
        return commonHead;
    }  
}

    Node* Union(Node *head1, Node* head2){
        Node *commonHead = nullptr;
        Node *temp1 = head1;
        Node *temp2 = head2;
        while(temp1 != nullptr){
            while(temp2 != nullptr){
                if(temp1->name != temp2->name){
                    commonHead = createSet(commonHead, temp1->name);
                    break;
            }
            temp2 = temp2->next;

            }
            temp1 = temp1->next;
            return commonHead;
        }  

    }
int main()
{
return 0;
}
