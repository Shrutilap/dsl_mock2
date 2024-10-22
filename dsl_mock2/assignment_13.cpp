/*A double-ended queue (deque) is a linear list in which additions and deletions may be made at either end. 
Obtain a data representation mapping a deque into a one-dimensional array.
Write C++ program to simulate deque with functions to add and delete elements from either end of the deque.*/

#include <iostream>
using namespace std;
const int max_size = 10;
class deque{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    deque(){
        front = -1;
        rear = -1;
        arr = new int[max_size];
        size = 0;
    }

    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == max_size;
    }

    void enqueue(int ele){
        if(isEmpty()){
            front = rear = 0;
        }
        else if(isFull()){
            cout<<"Elements cannot be added : "<<endl;
            return;
        }
        else{
            rear++;
        }
        arr[rear] = ele;
        size++;
        cout<<"Job "<<ele<<" added to the position "<<rear<<" queue"<<endl;
    }

    void insertFront(int ele){
        if(isEmpty()){
            front = rear = 0;
        }
        else if(isFull()){
            cout<<"Elements cannot be added : "<<endl;
            return;
        }
        else{
            front = front - 1;
        }
        arr[front] = ele;
        cout<<"Job "<<ele<<" added to the position "<<front<<" queue"<<endl;
    }

    int dequeue(){
        int job = 0;
        if(isEmpty()){
            cout<<"Queue is empty.."<<endl;
            return -1;
        }
        else{
            job = arr[front];
            if(front == rear){
                front = rear = -1;
            }
            else{
                front++;
            }
        }
        size--;
        cout<<"Job "<<job<<" deleted from the position"<<front<<"queue"<<endl;
        return job;
    }

    int deleteEnd(){
        int ini_rear = rear;
        int job = 0;
        if(isEmpty()){
            cout<<"Queue is empty.."<<endl;
            return -1;
        }
        else{
            job = arr[rear];
            if(front == rear){
                front = rear = -1;
            }
            else{
                rear--;
            }
        }
        size--;
        cout<<"Job "<<job<<" deleted from the position "<<ini_rear<<" queue"<<endl;
        
        return job;

    }
    ~deque(){
        delete[] arr;
    }
};
int main()
{
    deque q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.insertFront(11);
    q.deleteEnd();
  
  

    return 0;
}