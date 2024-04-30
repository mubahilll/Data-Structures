#include <iostream>
#include <stdlib.h>
#define maxsize 50
using namespace std; 

class queue{
	int front, back, size;
	int node[maxsize];  
public:
	queue(){
		front = 0; 
		back = 0; 
		size = 0; 
	}
	
	void enque(int data){
		if (!isFull()){
			node[back] = data; 
			back++;
			size++; 
		}
		else{
			cout<<"queue is full\n"; 
		}
	}
	
	int dequeue(){
		if (!isEmpty()){
			int x = node[front];
			front++; 
			size--;
			return x; 
		}
		else{
			cout<<"queue is empty\n"; 
		}
	}
	
	bool isEmpty(){
		return (size == 0); 
	}
	
	bool isFull(){
		return (size == maxsize); 
	}
	
	int top(){
		return node[front]; 
	}
	
	int returnsize(){
		return size;
	}
	
	void display(){
		int i;
		for(i = front; i<back ; i++){
			cout<<node[i]<<"<-";
		}
	}	
};

int main(){
	
	cout<<"\tQueues using array\n\n";
	
	queue q; 
	
	for(int i=1; i<=10; i++){
		q.enque(i); 
	}
	
	cout<<"Entered queue\n"; 
	q.display();
	cout<<"\nSize of queue: "<<q.returnsize()<<"\n";
	
	cout<<"\n\ndequeueing top 5 elements\n";
	for(int i=1; i<=5; i++){
		cout<<"\ndequeueing "<<q.dequeue(); 
	}
	cout<<endl;
	
	
	cout<<"\nRemaining queue\n";
	q.display();
	cout<<"\nSize of queue: "<<q.returnsize()<<"\n"; 

	cout<<"\nTop elemet: "<<q.top()<<"\n";
	
}
