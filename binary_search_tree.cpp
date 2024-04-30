#include <iostream>
#include <stdlib.h>
using namespace std; 

class node{
	int data; 
	node *rightchild; 
	node *leftchild;
public: 
	node(){
		data = 0; 
		rightchild = NULL;
		leftchild = NULL;
	}
	int get_data(){
		return data; 
	}
	void set_data(int data){
		this->data = data;
	}
	node *get_rightchild(){
		return rightchild;
	}
	node *get_leftchild(){
		return leftchild;
	}
	void *set_rightchild(node *rightchild){
		this->rightchild = rightchild;
	}
	void *set_leftchild(node *leftchild){
		this->leftchild = leftchild;
	}
};

class stknode{
	node *add; 
	stknode *next; 
public: 
	stknode(){
		add = NULL;
		next = NULL;
	}
	
	void set_add(node *add){
		this->add = add;
	}
	void set_next(stknode *next){
		this->next = next;
	}
	
	node *get_add(){
		return add; 
	}
	
	stknode *get_next(){
		return next; 
	}
	
};

class stack{
	stknode *top; 
public: 
	stack(){
		top = NULL;
	}
	bool isEmpty(){
		return (top == NULL); 
	}
	void push(node *add){
		stknode *newnode = new stknode(); 
		newnode->set_add(add); 
		if (top == NULL){
			top = newnode;
		}
		else{
			newnode->set_next(top); 
			top = newnode; 
		}
	}
	
	stknode *pop(){
		if(top == NULL){
			cout<<"Stack is empty\n"; 
		}
		else{
			node *x = top->get_add(); 
			stknode *nodetodel = top; 
			top = top->get_next(); 
			free(nodetodel); 
		}
	}
	node *peek(){
		return top->get_add(); 
	}
};

class bst{
	node *root; 
	node *insert(int data, node *r){
		if(r == NULL){
			r = new node(); 
			r->set_data(data); 
		}
		else if(data < r->get_data()){
			r->set_leftchild(insert(data, r->get_leftchild())); 
		}
		else if(data > r->get_data()){
			r->set_rightchild(insert(data, r->get_rightchild())); 
		}
		return r; 
	}
	
	node *min(node *r){
		if (r == NULL){
			cout<<"\nTree does not exist\n";
			return r; 
		}
		else if(r->get_leftchild() == NULL){
			cout<<"\nMinimum = "<<r->get_data()<<endl;
		}
		else{
			min(r->get_leftchild());
		}
	}
	
	node *find(int x, node *r){
		if (r == NULL){
			cout<<"\nElement does not exist!\n";
			return r; 
		}
		else if(x < r->get_data()){
			return find(x, r->get_leftchild());
		}
		else if(x > r->get_data()){
			return find(x, r->get_rightchild());
		}
		else{
			cout<<"Element founded = "<<r->get_data()<<endl; 
			return r; 
		}
	}
	
	node *remove(int x, node *r){
		node *tmp; 
		
		if (r == NULL){
			cout<<"\nElement does not exist!\n";
			return NULL;
		}
		else if(x < r->get_data()){
			r->set_leftchild(remove(x, r->get_leftchild()));
		}
		else if(x > r->get_data()){
			r->set_rightchild(remove(x, r->get_rightchild()));
		}
		else if(r->get_leftchild() && r->get_rightchild()){
			tmp = min(r->get_rightchild());
			r->set_data(tmp->get_data());
			r->set_rightchild(remove(r->get_data(), r->get_rightchild()));
		}
		else{
			tmp = r; 
			if(r->get_leftchild() == NULL){
				r = r->get_rightchild();
			}
			else if(r->get_rightchild() == NULL){
				r = r->get_leftchild();
			}
			free(tmp);
			cout<<"Element removed!"; 
		}
		return r; 
	}
public:
	bst(){
		root = NULL; 
	}
	
	void insert(int data){
		root = insert(data, root); 
	}
	
	void inorder(){
		stack st; 
		node *current = root;
		
		while(!st.isEmpty() || current != NULL){
			if(current != NULL){
				st.push(current); 
				current = current->get_leftchild(); 
			}
			else{
				current = st.peek(); 
				st.pop(); 
				cout<<current->get_data()<<" "; 
				current = current->get_rightchild(); 
			}
		}
	}
	
	void min(){
		min(root); 
	}
	
	void find(int x){
		find(x, root); 
	}
	
	void remove(int x){
		root = remove(x, root); 
	}
};

int main(){
	bst b; 
	int x; 
	int arr[9] = {40,30,10,35,20,75,70,90,55}; 
	
	cout<<"Inserting elements!\n"; 
	for (int i=0; i<9; i++){
		cout<<"Inserting "<<arr[i];
		b.insert(arr[i]); 
		cout<<"\n";
	};
	
	cout<<"\nInorder traversal\n"; 
	b.inorder();
	
	cout<<"\n\nFinding minimum";
	b.min();
	
	cout<<"\nEnter any number to find: "; 
	cin>>x; 
	cout<<"Finding "<<x<<"..."<<endl; 
	b.find(x);  
	
	cout<<"\nEnter any number to remove: ";
	cin>>x; 
	cout<<"Removing "<<x<<endl; 
	b.remove(x); 
	
	cout<<"\n\nInorder traversal\n"; 
	b.inorder();
}
