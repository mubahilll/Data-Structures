#include <iostream>
#include <stdlib.h>
using namespace std;

class node{
	int data; 
	node *next; 
public:
	node(){
		data = 0; 
		next = NULL;
	}
	
	void set_data(int data){
		this->data = data; 
	}
	void set_next(node *next){
		this->next = next; 
	}
	int get_data(){
		return data;
	}
	node *get_next(){
		return next; 
	}
};

class stacks{
	int size; 
	node *head; 
public:
	stacks(){
		size = 0;
		head = NULL;
	}
	
	void push(int data){
		node *newnode = new node(); 
		newnode->set_data(data);
		
		if (head == NULL){
			head = newnode;
		}
		else{
			newnode->set_next(head);
			head = newnode; 
		}
		size++;
	}
	
	int pop(){
		if (head == NULL){
			cout<<"Stack is empty\n"; 
		}
		else{
			int x = head->get_data();
			node *toDelete = head; 
			head = head->get_next(); 
			free(toDelete);
			size--;
			
			return x; 
		}
	}
	
	int top(){
		if(head != NULL){
			return head->get_data();
		}
		else{
			cout<<"Stack is empty\n";
		}
	}
	
	bool isEmpty(){
		return (head == NULL);
	}
};

int main(){
	cout<<"\tStacks\n\n";
	stacks st; 
	
	cout<<"Is stack empty? ";
	if(st.isEmpty()){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}
	
	cout<<"\nPushing elements\n";
	for(int i=1; i<=10; i++){
		st.push(i+10); 
		cout<<"Element "<<i<<": "<<st.top()<<endl;
	}
	
	cout<<"\nIs stack empty? ";
	if(st.isEmpty()){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}
	
	cout<<"\nPopping elements\n";
	for(int i=1; i<=9; i++){
		cout<<"Element "<<i<<": "<<st.pop()<<endl; 
	}
	
	cout<<"\nTop element: "<<st.top()<<endl;
	
	return 0;
}


