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
	int get_data(){
		return data; 
	}
	
	void set_data(int data){
		this->data = data; 
	}
	
	node *get_next(){
		return next; 
	}
	
	void set_next(node *next){
		this->next = next; 
	}
};

class linklist{
	int size;
	node *head; 
	node *tail; 
	node *current; 
	node *lastcurrent; 
public:
	
	linklist(){
		size = 0; 
		head = NULL;
		current = NULL; 
		lastcurrent = NULL; 
		tail = NULL;
	}
	void insertAtHead(int);
	void insertAtTail(int);
	void insertAtAnyPos(int, int);
	void removeAtHead();
	void removeAtTail();
	void remove_specificNode(int);
	void print();
	int get_size();
	
	friend void add_nodes(linklist);
	friend void traverse(linklist);  
	friend void remove_nodes(linklist); 
};

void linklist::insertAtHead(int data){
	node *newnode = new node();
	newnode->set_data(data); 
	if (head == NULL){
		head = newnode;
		tail = newnode; 
	}
	else{
		newnode->set_next(head); 
		head = newnode;
	}
	size++; 
}

void linklist::insertAtTail(int data){
	node *newnode = new node();
	newnode->set_data(data); 
	if(head == NULL){
		head = newnode; 
		tail = newnode; 
	}
	else{
		tail->set_next(newnode); 
		tail = newnode; 
	}
	size++;
}

void linklist::insertAtAnyPos(int data, int pos){
	node *newnode = new node(); 
	newnode->set_data(data); 
	if (pos < 1 || pos >size+1){
		cout<<"postion shouhd be between 1 to "<<size+1<<endl; 
	}
	else if (pos == 1){
		if(head == NULL){
			head = newnode; 
			tail = newnode; 
		}
		else{
			newnode->set_next(head); 
			head = newnode; 
		}
		size++;
	}
	else{
		current = head; 
		for (int i=1; i<pos-1; i++){
				current = current->get_next();
		}
		if(current != NULL){
			newnode->set_next(current->get_next());
			current->set_next(newnode); 
			current = newnode;
			if(current->get_next() == NULL){
				tail = newnode;
			}
			size++;
		}
		else{
			cout<<"Previous node is null\n";
		}
	}	 
}

void linklist::removeAtHead(){
	if(head == NULL){
		cout<<"List is empty\n";
	}
	else{
		current = head; 
		head = head->get_next(); 
		free(current); 
		size--;
	}
}

void linklist::removeAtTail(){
	if(head == NULL){
		cout<<"List is empty\n";
	}
	else{
		current = head; 
		while(current->get_next() != NULL){
			lastcurrent = current; 
			current = current->get_next();
		}
		free(current); 
		lastcurrent->set_next(NULL); 
		tail = lastcurrent;
		size--; 
	}
}

void linklist::remove_specificNode(int data){
	current = head;
	if (head == NULL){
		cout<<"List is empty\n"; 
	}
	else if(head->get_data() == data){
		head = head->get_next();
		free(current);
		size--; 
	}
	else{
		while(current->get_next() != NULL && current->get_data() != data){
			lastcurrent = current; 
			current = current->get_next();
		}
		if (current->get_data() != data){
			cout<<"Given node does not exist\n"; 
		}
		else{
			lastcurrent->set_next(current->get_next());
			if(current->get_next() == NULL){
				tail = lastcurrent; 
			}
			free(current); 
			size--;
		}
	}
}

void linklist::print(){
	if (head == NULL){
		cout<<"List is empty\n"; 
	}
	else{
		current = head;
		
		while(current != NULL){
			cout<<current->get_data()<<"->";
			current = current->get_next();
		} 
		cout<<NULL<<endl;
	}
}

int linklist::get_size(){
	return size; 
}

void add_nodes(linklist *list){
	
	cout<<"\nInserting node at head\n";
	list->insertAtHead(10);
	list->print();
	
	cout<<"\nInserting nodes (11,12,13,14,15) at specific positions(2,3,4,5,6)\n";
	list->insertAtAnyPos(11,2);
	list->insertAtAnyPos(12,3);
	list->insertAtAnyPos(13,4);
	list->insertAtAnyPos(14,5);
	list->insertAtAnyPos(15,6);
	list->print();
	
	cout<<"\nInserting node at tail\n";
	list->insertAtTail(16); 
	list->print();
}

void traverse(linklist list){
	list.current = list.head; 
	int sum = 0;
	if (list.head == NULL){
		cout<<"List is empty\n"; 
	}
	for (int i=1; list.current != NULL; i++){
		cout<<"Element "<<i<<"-> "<<list.current->get_data()<<"\n"; 
		sum += list.current->get_data();
		list.current = list.current->get_next();
	}
	cout<<"\n\nSum = "<<sum<<endl;
}

void remove_nodes(linklist *list){
	
	cout<<"\nRemoving head node\n";
	list->removeAtHead();
	list->print();
	
	cout<<"\nRemoving specific node (13)\n";
	list->remove_specificNode(13); 
	list->print();
	
	cout<<"\nRemoving tail node\n";
	list->removeAtTail(); 
	list->print();
}

int main(){
	cout<<"\tSingle Link List\n";
	
	linklist list; 
	
	add_nodes(&list);  //adding nodes;
	
	cout<<"\nTraversing list:\n"; 
	cout<<"List size= "<<list.get_size()<<"\n\n";
	traverse(list); 
	
	remove_nodes(&list); //removing nodes;
	
	cout<<"\nTraversing list:\n"; 
	cout<<"List size= "<<list.get_size()<<"\n\n";
	traverse (list); 
	
	return 0;
}


