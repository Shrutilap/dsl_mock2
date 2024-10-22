/*The ticket booking system of Cinemax theatre has to be implemented using C++ program. There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained to keep track of free seats at rows. Assume some random booking to start with. Use array to store pointers (Head pointer) to each row. On demand 
	a) The list of available seats is to be displayed 
	b) The seats are to be booked 
	c) The booking can be cancelled. 
*/
#include <iostream>
using namespace std;
class Node{
    bool isBooked;
    Node *next;
    Node *prev;
    public:
    Node(){
        isBooked = false;
        next = nullptr;
        prev = nullptr;
    }

    Node* createRow(Node *head){
        Node *temp = nullptr;
        for(int i = 0; i<7; i++){
            Node *seat = new Node();
            if(head == nullptr){
                head = seat;
                temp = head;
            }
            else{
                temp->next = seat;
                seat->prev = temp;
                temp = seat;
            }
        }
        temp->next = head;
        head->prev = temp;

        return head;
    }
    void createHeadArray(Node* headArray[10]){
        for(int i = 0; i<10; i++){
            headArray[i] = createRow(nullptr);
        }
    }
    void displayUnbooked(Node* headArray[10]){
        for(int i = 0; i<10; i++){
            Node *temp = headArray[i];
            do{
                cout<<temp->isBooked<<" ";
                temp = temp->next;
            }
            while(temp != headArray[i]);
            cout<<endl;
        }

    }

    void bookSeat(Node* headArray[10], int rowno, int seatno){
        Node *temp = headArray[rowno];
        int cnt = 1;
        do{
            if(seatno == cnt){
                if(!temp->isBooked){
                    temp->isBooked = true;
                    cout<<"Seat no : "<<seatno<<" in row no "<<rowno<<" successfully booked."<<endl;
                }
                else{
                cout<<"Seat no : "<<seatno<<" in row no "<<rowno<<" is already booked."<<endl;
            }
            }
            
            cnt++;
            temp = temp->next;
        }
         while(temp != headArray[rowno]);
    }

    void cancelSeat(Node *headArray[10], int rowno, int seatno){
        Node* temp = headArray[rowno];
        int cnt = 1;
        do{
            if(seatno == cnt){
                if(temp->isBooked){
                    temp->isBooked = false;
                    cout<<"Seat no : "<<seatno<<" in row no "<<rowno<<" successfully cancelled"<<endl;
                }
                else{
                    cout<<"Seat no : "<<seatno<<" in row no "<<rowno<<" was not booked to cancel"<<endl;
                }
            }
            cnt++;
            temp = temp->next;
        }
        while(temp != headArray[rowno]);
    }
  
};
int main()
{
    Node obj;
    Node* headArray[10];
    obj.createHeadArray(headArray);
    obj.displayUnbooked(headArray);
    obj.bookSeat(headArray, 3,4);
    obj.bookSeat(headArray, 2,2);
    obj.bookSeat(headArray, 3,2);
    obj.bookSeat(headArray, 4,1);
    obj.bookSeat(headArray, 5,1);
    obj.bookSeat(headArray, 6,4);
    obj.displayUnbooked(headArray);
    obj.cancelSeat(headArray, 3, 4);
    obj.displayUnbooked(headArray);
 
    return 0;
}
