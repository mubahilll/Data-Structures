# include <iostream>
# include <conio.h>
# include "Stack.h"
# define MAXSTACKSIZE 50

using namespace std;

template <class T>
Stack<T>::Stack(){
	top = -1;
	nodes = new T[MAXSTACKSIZE];
}

template <class T>
Stack<T>::~Stack(){
	delete nodes;
}

template <class T>
int Stack<T>::isEmpty(){
	if (top < 0){
		return 1;
	}
	return 0;
}

template <class T>
int Stack<T>::push(T &x){
	if (top < MAXSTACKSIZE){
		nodes[++top] = x;
		return 1;
	}
	cout << "Stack overflow in push\n";
	return 0;
}

template <class T>
T Stack<T>::pop(){
	T x;
	if (!isEmpty()){
		x = nodes[top--];
		return x;
	}
	cout << "Stack underflow in pop\n";
	return x;
}

template <class T>
T Stack<T>::peek(){
	return nodes[top];
}

template <class T>
void Stack<T>::display(){
	if (top > 0){
		int i;
		for(i=top; i>=0; i--){
			cout << nodes[i];
			if (i > 0){
				cout << " -> ";
			}
		}
	}
	else{
		cout << "Stack is empty\n";
	}
}

template <class T>
int Stack<T>::sizeStack(){
	return top;
}
















