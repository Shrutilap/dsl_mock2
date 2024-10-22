/*
Write C++ program for storing appointment schedule for day. Appointments are 
booked randomly using linked list. Set start and end time and min and max 
duration for visit slot. Write functions for-  
a) Display free slots  
b) Book appointment  
c) Cancel appointment (check validity, time bounds, availability)  
d) Sort list based on time  
e) Sort list based on time using pointer manipulation */
#include <iostream>
using namespace std;
class Node{
    public:
    bool isBooked;
    string start;
    string end;
    Node *next;
    int min_dur;
    int max_dur;

    public:
    Node(string s, string e){
        start = s;
        end = e;
        next = nullptr;
        isBooked = false;;
        min_dur = 30;
        max_dur = 60;
    }

};

Node* add_slot(Node *head, string s, string e){
    Node *new_node = new Node(s, e);
    Node *temp = nullptr;
    if(head == nullptr){
        head = new_node;
    }
    else{
        temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

void display(Node *head){
    Node *temp = head;
    if(head == nullptr){
        cout<<"Nothing to display"<<endl;
    }
    else{
        while(temp != nullptr){
            cout<<temp->isBooked<<"->";
            temp = temp->next;
        }
    }
}
void *book(Node *head, int seatno){
    Node *temp = head;
    int cnt = 0;
    if(head == nullptr){
        cout<<"Cannot book"<<endl;
    }
    else{
        do{
            if(cnt == seatno){
                temp->isBooked = true;
                cout<<"Seat booked successfully"<<endl;
                break;
            }
            temp = temp->next;
            cnt++;
        }while(temp != nullptr);
    }
}

void displayFree(Node *head){
    Node *temp = head;
    if(head == nullptr){
        cout<<"Nothing to display"<<endl;
    }
    else{
        while(temp != nullptr){
            if(!temp->isBooked){
                cout<<"Free slot "<<temp->start<<" to "<<temp->end<<endl;
            }
            temp = temp->next;
        }
    }
}

void cancel_app(Node *head, string s){
    Node *temp = head;
    if(head == nullptr){
        cout<<"Nothing to cancel"<<endl;
    }
    else{
        while(temp != nullptr){
            if(temp->start == s){
                temp->isBooked = 0;
                cout<<"Appointment cancelled successfully"<<endl;
                break;
            }
            temp = temp->next;
        }
    }
}

void sortByTime(Node *head){
    if(head == nullptr || head->next == nullptr){
        return;
    }
    Node *current = head;
    Node *min = current;
    Node *temp = current->next;
    while(current != nullptr){
         while(temp != nullptr){
        if(temp->start < min->end){
            min  = temp;
        }
        temp = temp->next;
    }
    if(min != current){
        swap(current->start, min->start);
        swap(current->end, min->end);
        swap(current->isBooked, min->isBooked);
    }
        current = current->next;
    }
   
    
}
int main()
{
    Node *head = nullptr;
    head = add_slot(head, "09:00", "09:30");
    head = add_slot(head, "10:00", "10:30");
    head = add_slot(head, "09:30", "10:00");

    cout << "Initial appointment slots:" << endl;
    display(head);
    cout<<endl;
    
    displayFree(head);
    cout<<endl;
    
    book(head, 2);
    cout<<endl;
    book(head, 1);
    cout<<endl;
    
    cout << "\nAfter booking appointments:" << endl;
    cout<<endl;
    display(head);
    cout<<endl;
    
    cancel_app(head, "09:00");
    cout<<endl;
    
    cout << "\nAfter cancelling an appointment:" << endl;
    cout<<endl;
    displayFree(head);
    cout<<endl;
    cout << "\nSorted appointment slots:" << endl;
    sortByTime(head);
    display(head);
    cout<<endl;

    return 0;
}