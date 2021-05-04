#include <bits/stdc++.h>
using namespace std;

class node{
	private:
		int data;
		node* next;
		node* prev;
	public:
		void setData( int data){
			this->data = data;
		}
		void setNext( node * next){
			this->next = next;
		}
		void setPrev( node * prev){
			this->prev = prev;
		}
		void getData (){
			return this->data
		}
		void getNext (){
			return this->next;
		}
		void getPrev (){
			return this->prev;
		}
		
};
class Circular_linked_list{
	private:
		int size;
		node* current;
	public:
		Circular_linked_list();
		~Circular_linked_list();
		//add getter and setter functions here
		/*
		
			here

		*/
		void push();
		void pop();
		void pop(int data);
		void push_after(int new_data,int pa_data);
		void push_befor(int new_data,int pb_data);
		void print();


}



int main(){



}
