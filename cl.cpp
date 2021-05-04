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
		int getData (){
			return this->data;
		}
		node * getNext (){
			return this->next;
		}
		node * getPrev (){
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
		void push( int data){
			node * now;
			now = new node();
			now->setData(data);
			if( current == nullptr){
				current = now;
			}
			else{
				now->setNext(current);
                now->setPrev(current->getPrev());
                current = now;
			}
			size++;
		}
		void pop();
		void pop(int data);

		//PushBefore function added by Mahdi Shirazi (GitHub ID: mhdshrz)
		void PushAfter (int newdata, int PushAfterdata) {

            node* ptr=nullptr;
            node* tempo=nullptr;
            ptr=this->current;

            if(this->size==0) {

                cout << "Can't be done!\n";

                return;

            }

            while(ptr->getData()!=PushAfterdata) {

                ptr=ptr->getNext();

                if(ptr==this->current) break;

            }

            if(ptr==this->current) {

                if(ptr->getData()!=PushAfterdata) {

                    cout << "Not found!\n";

                    return;

                }

            }

            tempo=this->current;
            this->current=ptr->getNext();

            this->push(newdata);

            //this->current=tempo;

            return;

        }

		//PushAfter function added by Mahdi Shirazi (GitHub ID: mhdshrz)
		void PushBefore (int newdata, int PushBeforedata) {

            node* ptr=nullptr;
            node* tempo=nullptr;
            ptr=this->current;

            if(this->size==0) {

                cout << "Can't be done!\n";

                return;

            }

            while(ptr->getData()!=PushBeforedata) {

                ptr=ptr->getNext();

                if(ptr==this->current) break;

            }

            if(ptr==this->current) {

                if(ptr->getData()!=PushBeforedata) {

                    cout << "Not found!\n";

                    return;

                }

            }

            tempo=this->current;
            this->current=ptr;

            this->push(newdata);

            //this->current=tempo;

            return;

        }

		void print();

		//One parametric print added by Mahdi Shirazi (GitHub ID: mhdshrz)
		//An extra feature which works as a function and takes an integer number and finds it in our list ...
		//... as a data, then prints the  whole list beginning from the node having that integer as its data part.
		void print (int data) {

            node* ptr=nullptr;
            node* tempo=nullptr;
            ptr=this->current;

            if(this->size==0) {

                cout << "Can't be done!\n";

                return;

            }

            while(ptr->getData()!=data) {

                ptr=ptr->getNext();

                if(ptr==this->current) break;

            }

            if(ptr==this->current) {

                if(ptr->getData()!=data) {

                    cout << "Not found!\n";

                    return;

                }

            }

            tempo=this->current;
            this->current=ptr;

            this->print();

            this->current=tempo;

            return;

        }

};



int main(){



}
