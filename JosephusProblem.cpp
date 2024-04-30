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

class circularlist{
	int size;
	node *head;
	node *tail; 
	node *current; 
	node *lastcurrent; 
public:
	circularlist(){
		size = 0; 
		head = NULL; 
		tail = NULL; 
		current = NULL; 
		lastcurrent = NULL;
	}
	
	void insert_nodes(int data){
		node *newnode = new node();
		newnode->set_data(data);
		
		if (head == NULL){
			head = newnode; 
			newnode->set_next(head); 
			tail = newnode;
		}
		else{
			newnode->set_next(head); 
			tail->set_next(newnode); 
			tail = newnode;
		}
		size++;
	}
	
	void remove(){
		if(current == head){
			head = head->get_next();
			tail->set_next(head); 
			free(current); 
			size--;
		}
		else if(current == tail){
			lastcurrent->set_next(head); 
			tail = lastcurrent;
			free(current); 
			size--;
		}
		else{
			lastcurrent->set_next(current->get_next());
			if(current->get_next() == head){
				tail = lastcurrent;
			}
			free(current);
			size--;
		}
	}

	
	int get_length(){
		return size;
	}
	
	int leader(int m){	
		lastcurrent = head;
		current = head;
		
		while(get_length() > 1){
			for(int i=1; i <= m; i++){
				lastcurrent = current; 
				current = current->get_next();
			}
			cout<<"\nRemove: "<<current->get_data();
			remove(); 
			current = lastcurrent->get_next();
		}
		
		return current->get_data();
	}
	 
	void print(){
		if(head == NULL){
			cout<<"List is empty\n"; 
		}
		else{
			current = head; 
			do{
				cout<<current->get_data()<<"->";
				current = current->get_next();
			}while(current != head);
			cout<<head->get_data()<<endl;
		}
	}
};



int main(){
	cout<<"\tJosephus Problem\n\n";
	
	circularlist clist; 
	
	int n, m; 
	cout<<"Enter total elements: ";
	cin>>n; 
	cout<<"Enter number of hops: ";
	cin>>m;
	
	for(int i=1; i<=n; i++){
		clist.insert_nodes(i); 
	}
	cout<<"\nCircular list\n";
	clist.print();
	
	cout<<"\n\nLeader is: "<<clist.leader(m)<<"\n";

	return 0;
}


