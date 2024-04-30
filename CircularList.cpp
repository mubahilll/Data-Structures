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
	
	void insertAtHead(int data){
		node *newnode = new node();
		newnode->set_data(data); 
		
		if(head == NULL){
			head = newnode;
			newnode->set_next(head); 
			tail = newnode;
		}
		else{
			newnode->set_next(head); 
			head = newnode; 
			tail->set_next(head);
		}
		size++;
	}
	
	void insertAtTail(int data){
		node *newnode = new node(); 
		newnode->set_data(data); 
		
		if(head == NULL){
			head = newnode;
			newnode->set_next(head); 
			tail = newnode;
		}
		else{
			tail->set_next(newnode); 
			newnode->set_next(head); 
			tail = newnode;
		}
		size++;
	}
	
	void insertAtAnyPosition(int data, int pos){
		node *newnode = new node();
		newnode->set_data(data);
		
		if(pos<1 || pos>size+1){
			cout<<"Position should be between 1 to "<<++size<<"\n"; 
		}	
		else if(pos == 1){
			if(head == NULL){
				head = newnode;
				newnode->set_next(head); 
				tail = newnode;
			}
			else{
				newnode->set_next(head); 
				head = newnode; 
				tail->set_next(head);
			}
			size++;
		}
		else{
			current = head; 
			for (int i=1; i<pos-1; i++){ 
				current = current->get_next();
			}
			if (current != NULL){
				newnode->set_next(current->get_next());
				current->set_next(newnode); 
				if(newnode->get_next() == head){
					tail = newnode;
				} 
				size++;
			}
		}
	}
	
	void removeHead(){
		if(head == NULL){
			cout<<"List is empty\n";
		}
		else{
			current = head;
			head = head->get_next(); 
			tail->set_next(head); 
			free(current); 
			size--;
		}
	}
	
	void removeTail(){
		if(head == NULL){
			cout<<"List is empty\n"; 
		}
		else{
			current = head;
			while(current->get_next() != head){
				lastcurrent = current;
				current = current->get_next();
			}
			lastcurrent->set_next(head); 
			tail = lastcurrent; 
			free(current); 
			size--; 
		}
	}
	
	void remove_specific_node(int data){
		current = head;
		if(head == NULL){
			cout<<"List is empty\n";
		}
		else if(head->get_data() == data){
			head = head->get_next(); 
			tail->set_next(head); 
			free(current); 
			size--;
		}
		else{
			while(current->get_next() != head && current->get_data() != data){
				lastcurrent = current; 
				current = current->get_next();
			}
			if(current->get_data() != data){
				cout<<"Given node does not exist\n";
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
			cout<<current->get_data()<<endl; //to confirm last node is pointing at head
		}
	}
	
	int get_length(){
		return size;
	}
	
	friend void add_nodes(circularlist);
	friend void remove_nodes(circularlist);
	friend void traverse(circularlist); 
};

void add_nodes(circularlist *clist){
	cout<<"\nInserting node (10) at head\n";
	clist->insertAtHead(10); 
	clist->print();
	
	cout<<"\nInserting nodes (11,12,13,14,9) at positions (2,3,4,5,1)\n";
	clist->insertAtAnyPosition(11,2);
	clist->insertAtAnyPosition(12,3);
	clist->insertAtAnyPosition(13,4);
	clist->insertAtAnyPosition(14,5);
	clist->insertAtAnyPosition(9,1);
	clist->print();
	
	cout<<"\nInserting node (15) at tail\n";
	clist->insertAtTail(15); 
	clist->print();
	
	cout<<"\nList size = "<<clist->get_length()<<"\n";
}

void remove_nodes(circularlist *clist){
	cout<<"\nRemoving head\n";
	clist->removeHead();
	clist->print();
	
	cout<<"\nRemoving specific node(11)\n";
	clist->remove_specific_node(11);
	clist->print();
	
	cout<<"\nRemoving tail\n";
	clist->removeTail();
	clist->print();
	cout<<"\nList size = "<<clist->get_length()<<"\n";
}

void traverse(circularlist clist){
	clist.current = clist.head; 
	
	if(clist.head == NULL){
		cout<<"List is empty\n";
	}
	else{
		int i=1; 
		do{
			cout<<"Element "<<i<<": "<<clist.current->get_data()<<"\n";
			clist.current = clist.current->get_next();
			++i; 
		}while(clist.current != clist.head);	

	}
}

int main(){
	cout<<"\tCircular Link List\n\n";
	circularlist clist; 
	

	add_nodes(&clist); 
	traverse(clist); 
	
	remove_nodes(&clist);
	traverse(clist);

	return 0;
}


