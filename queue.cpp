#include <iostream>
#include <stdlib.h>
using namespace std;

class node{
	int data; 
	node *next; 
	node *prev; 
public: 
	node(){
		data = 0; 
		next = NULL;
		prev = NULL;
	}
	
	void set_data(int data){
		this->data = data; 
	}
	
	int get_data(){
		return data; 
	}
	
	void set_next(node *next){
		this->next = next; 
	}
	
	node *get_next(){
		return next; 
	}
	
	void set_prev(node *prev){
		this->prev = prev; 
	}
	
	node *get_prev(){
		return prev; 
	}
};

class queue{
	int size; 
	node *front; 
	node *back; 
public:
	
	queue(){
		size = 0;
		front = NULL; 
		back = NULL; 
	} 
	
	void enqueue(int data){
		node *newnode = new node(); 
		newnode->set_data(data); 
		
		if (front == NULL){
			front = newnode;
			back = newnode; 
		} 
		else{
			front->set_prev(newnode); 
			newnode->set_next(front); 
			front  = newnode; 
		}
		size++;
	}
	
	int dequeue(){
	
		if (front == NULL){
			cout<<"Queue is empty\n";
		}
		else{
			int x = back->get_data();
			node *nodetodel = back;  
			back->get_prev()->set_next(NULL);
			back = back->get_prev();
			free(nodetodel); 
			size--;
			return x; 
		}
	}
	
	bool isEmpty(){
		return (front == NULL); 
	}
	
	int top(){
		return back->get_data();
	}
	
	void display(){
		node *current = front; 
		
		while(current != NULL){
			cout<<current->get_data()<<"->"; 
			current = current->get_next();
		}
	}
	
	int return_size(){
		return size;
	}
};


int main(){
	
	cout<<"\tQueues using linklist\n\n";
	
	queue q; 
	
	for(int i=1; i<=10; i++){
		q.enqueue(i); 
	}
	cout<<"Entered queue\n"; 
	q.display();
	cout<<"\nSize of queue: "<<q.return_size()<<"\n"; 
	
	cout<<"\n\ndequeueing top 5 elements\n";
	for(int i=1; i<=5; i++){
		cout<<"\ndequeueing "<<q.dequeue(); 
	}
	cout<<endl; 
	
	cout<<"\nRemaining queue\n";
	q.display();
	cout<<"\nSize of queue: "<<q.return_size()<<"\n"; 
	
	cout<<"\nTop elemet: "<<q.top()<<"\n"; 
	
	
	return 0;
}


