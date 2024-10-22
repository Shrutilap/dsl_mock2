/*Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++ program for simulating job queue. Write functions to add job and delete job from queue. */
#include <iostream>
using namespace std;
const int max_size = 10;
class Queue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    Queue(){
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
        cout<<"Job "<<ele<<" added to the queue "<<endl;
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
        cout<<"Job "<<job<<" deleted from the queue"<<endl;
        return job;
    }
    ~Queue(){
        delete[] arr;
    }
};
int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.dequeue();
  

    return 0;
}