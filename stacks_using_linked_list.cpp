# include <iostream>
# include <conio.h>

using namespace std;

class Node{
	private:
		int object;
		Node *nextNode;
		
	public:
		int get(){
			return object;
		}
		void set(int object){
			this->object = object;
		}
		Node *getNext(){
			return nextNode;
		}
		void setNext(Node *nextNode){
			this->nextNode = nextNode;
		}
};

class Stack{
	private:
		Node *top;
		int size = 0;
	
	public:
		Stack();
		void push(int);
		int pop();
		int peek();
		int isEmpty();
		int sizeStack();
		void display();
};

Stack::Stack(){
	top = NULL;
	size = 0;		
}

void Stack::push(int object){
	Node *newNode = new Node();
	newNode->set(object);
	newNode->setNext(top);
	top = newNode;
	size++;
}

int Stack::pop(){
	int data;
	Node *tempPtr;
	data = top->get();
	tempPtr = top;
	top = top->getNext();
	delete tempPtr;
	size--;
	return data;
}

int Stack::peek(){
	return top->get();
}

int Stack::isEmpty(){
	return top==NULL;
}

int Stack::sizeStack(){
	return size;
}

void Stack::display(){
	Node *tempPtr;
	
	if(top==NULL){
		cout << "\nNothing in Stack";
	}
	else{
		tempPtr = top;
		while(tempPtr != NULL){
			cout << tempPtr->get();
			tempPtr = tempPtr->getNext();
			if(tempPtr != NULL){
				cout << " -> ";
			}
		}
	}
}



int main(){
	
	Stack s;
	
	s.push(11);
	s.push(22);
	s.push(33);
	s.push(44);
	
	cout << "Stack is: "; 
	s.display();
	cout << endl;
	
	cout << "Size of Stack: " << s.sizeStack();
	
	cout << "\nTop element is: " << s.peek() << endl;
	
	cout << "\nPopped element: " << s.pop() << endl;	
	cout << "\nPopped element: " << s.pop() << endl;
	
	cout << "\nTop element is: " << s.peek() << endl;
	cout << "Size of Stack: " << s.sizeStack();
	
	getche();
	return 0;
}