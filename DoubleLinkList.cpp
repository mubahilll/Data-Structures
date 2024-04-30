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

class doublelist{
	int size; 
	node *head; 
	node *tail; 
	node *current;
	node *lastcurrent; 
public:
	
	doublelist(){
		size = 0;
		head = NULL; 
		tail = NULL; 
		current = NULL;
		lastcurrent = NULL; 
	} 
	
	void insertAtHead(int);
	void insertAtTail(int);
	void insertAtAnyPos(int, int);
	void removeAtHead();
	void removeAtTail();
	void remove_specificNode(int);
	void print();
	
	int get_size();
	friend void add_nodes(doublelist);
	friend void traverse(doublelist);  
	friend void remove_nodes(doublelist);
};

void doublelist::insertAtHead(int data){
	node *newnode = new node();
	newnode->set_data(data);
	if(head == NULL){
		head = newnode; 
		tail = newnode; 
	}
	else{
		newnode->set_next(head); 
		head->set_prev(newnode); 
		head = newnode; 			
	}
	size++;
}

void doublelist::insertAtTail(int data){
	node *newnode = new node();
	newnode->set_data(data); 
	if(head == NULL){
		head = newnode; 
		tail = newnode; 
	}
	else{
		tail->set_next(newnode); 
		newnode->set_prev(tail); 
		tail = newnode; 
	}
	size++;
}

void doublelist::insertAtAnyPos(int data, int pos){
	node *newnode = new node();
	newnode->set_data(data); 
	if(pos < 1 || pos > size+1){
		cout<<"Postion should be between 1 to "<<size+1<<endl;
	}
	else if(pos == 1){
		if(head == NULL){
			head = newnode; 
			tail = newnode; 
		}
		else{
			newnode->set_next(head); 
			head->set_prev(newnode); 
			head = newnode;
		}
		size++;
	}
	else{
   		current = head;
    	for(int i = 1; i < pos-1; i++) {	   	   	
    		current = current->get_next();
    	}
    	
		if(current != NULL) {
			newnode->set_next(current->get_next()); 
			newnode->set_prev(current); 
			if(current->get_next() != NULL){	
				current->get_next()->set_prev(newnode); 
			}
			current->set_next(newnode);
			
			current = newnode; 
			if(current->get_next() == NULL){
				tail = newnode; 
			}
	    	size++;
	    } 
		else{
	      	cout<<"\nThe previous node is null.";
	    } 
	}
}

void doublelist::removeAtHead(){
	if(head == NULL){
		cout<<"List is empty\n"; 
	}
	else{
		current = head; 
		head = head->get_next(); 
		head->set_prev(NULL);
		free (current); 
		size--;
	}
}

void doublelist::removeAtTail(){
	if (head == NULL){
		cout<<"List is empty\n"; 
	}
	else{
		current = tail; 
		tail->get_prev()->set_next(NULL);
		tail = tail->get_prev();
		free(current; 
		size--;
	}
}

void doublelist::remove_specificNode(int data){
	current = head; 
	if(head == NULL){
		cout<<"List is empty\n"; 
	}
	else if(head->get_data() == data){
		head = head->get_next(); 
		head->set_prev(NULL);
		free (current);
		size--;
	}
	else{
		while(current->get_next() != NULL && current->get_data() != data){
			current = current->get_next(); 
		}
		if (current->get_data() != data){
			cout<<"Given node does not exist\n"; 
		}
		else{u
			current->get_prev()->set_next(current->get_next());
			if (current->get_next() != NULL){
				current->get_next()->set_prev(current->get_prev());
			}
			 
			if (current->get_next() == NULL){
				tail = current->get_prev();
			}
			free(current); 
			size--;
		}
	}	
}

void doublelist::print(){
	if(head == NULL){
		cout<<"List is empty\n"; 
	}
	else{
		current = head; 
		while(current != NULL){
			cout<<current->get_data()<<"<->"; 
			current = current->get_next(); 
		}
		cout<<NULL<<endl; 
	}
}

int doublelist::get_size(){
	return size; 
}

void add_nodes(doublelist *dlist){
	cout<<"\nInserting node at head\n";
	dlist->insertAtHead(20);
	dlist->print(); 
	
	cout<<"\nInserting nodes (21,22,23,24,25) at specific positions (2,3,4,5,6)\n";
	dlist->insertAtAnyPos(21,2);
	dlist->insertAtAnyPos(22,3);
	dlist->insertAtAnyPos(23,4);
	dlist->insertAtAnyPos(24,5);
	dlist->insertAtAnyPos(25,6);
	dlist->print(); 
	
	cout<<"\nInserting node at tail\n";
	dlist->insertAtTail(26); 
	dlist->print(); 
}

void remove_nodes(doublelist *dlist){
	cout<<"\nRemoving node at head\n";
	dlist->removeAtHead(); 
	dlist->print(); 
	
	cout<<"\nRemoving specific node (23)\n";
	dlist->remove_specificNode(23); 
	dlist->print(); 
	
	cout<<"\nRemoving node at tail\n";
	dlist->removeAtTail();
	dlist->print(); 
}

void traverse(doublelist dlist){
	dlist.current = dlist.head; 
	
	if(dlist.head == NULL){
		cout<<"List is empty\n"; 
	}
	
	for(int i=1; dlist.current != NULL; i++){
		cout<<"Element "<<i<<"-> "<<dlist.current->get_data()<<"\n";
		dlist.current = dlist.current->get_next();  
	}
}

int main(){
	cout<<"\tDouble Link List\n";
	
	doublelist dlist; 
	
	add_nodes(&dlist); //adding nodes
	
	cout<<"\nTraversing list:\n"; 
	cout<<"List size= "<<dlist.get_size()<<"\n\n";
	traverse(dlist);
	
	remove_nodes(&dlist); //removing nodes
	
	cout<<"\nTraversing list:\n"; 
	cout<<"List size= "<<dlist.get_size()<<"\n\n";
	traverse(dlist);
	
	return 0;
}


