/*12.Write program to implement a priority queue in C++ using an inorder list to store the items in the queue. 
Create a class that includes the data items (which should be template) and the priority (which should be int). 
The inorder list should contain these objects, with operator <= overloaded so that the items with highest priority
appear at the beginning of the list (which will make it relatively easy to retrieve the highest item.)
*/

#include <iostream>
using namespace std;
const int max_size = 10;
template <typename T>
class Item{
    public:
    T data;
    int priority;

    public:
    Item(T data, int priority){
        this->data = data;
        this->priority = priority;
    }
    bool operator>(Item<T>& other){
        return this->priority > other.priority;
    }
};
template <typename T>
class priorityQueue{
    Item<T>  *arr[max_size];
    int size;

    public:
    priorityQueue(){
        size = 0;
    }
    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == max_size;
    }
    
    void enqueue(T data, int priority){
        Item<T>* new_item = new Item<T>(data, priority);
        int i = 0;
        if(isFull()){
            cout<<"Queue is full"<<endl;
            delete new_item;
            return;
        }
        else{
            if(isEmpty()){
               
                arr[i] = new_item;
                size++;
            }
                for(int i = size-1; i>=0; i++){
                    if(new_item->priority > arr[i]->priority){
                        arr[i+1] = arr[i];
                    }
                    else{
                        break;
                    }
                }
                arr[i+1] = new_item;
                size++;
            }
        

    }

    void display(){
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
    
            for(int i = 0; i<size; i++){
                cout<<arr[i]->data<<" "<<arr[i]->priority<<endl;
            }
        
    }
    T dequeue(){
        Item<T>* item_to_dequeue = arr[0];
        T data = item_to_dequeue->data;
        if(isEmpty()){
            cout<<"The queue is empty..."<<endl;
            return T();    
        }
        else{
            size--;
            return arr[0]->data;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        delete item_to_dequeue; 
        return data;

    }

    ~priorityQueue() {
        for (int i = 0; i < size; i++) {
            delete arr[i]; // Delete each Item
        }
    }


};
int main()
{
    priorityQueue<string> pq;
    pq.enqueue("Task1", 2);
    pq.enqueue("Task2", 5);
    pq.enqueue("Task3", 1);
    pq.enqueue("Task4", 3);
    pq.display();

    return 0;
}