#include <bits/stdc++.h>
using namespace std;

class node
{
private:
    int data;
    node *next;
    node *prev;

public:
    void setData(int data)
    {
        this->data = data;
    }
    void setNext(node *next)
    {
        this->next = next;
    }
    void setPrev(node *prev)
    {
        this->prev = prev;
    }
    int getData()
    {
        return this->data;
    }
    node *getNext()
    {
        return this->next;
    }
    node *getPrev()
    {
        return this->prev;
    }
};
class Circular_linked_list
{
private:
    int size;
    node *current;

public:
    Circular_linked_list()
    {
        this->size = 0;
        this->current = nullptr;
    }
    ~Circular_linked_list()
    {
        node *tmp = new node;
        tmp = this->current;

        for (int i = 0; i < size; i++)
        {
            node *tmp2 = new node;
            tmp2 = tmp;
            tmp = tmp->getNext();
            delete tmp2;
        }

        this->size = 0;
        this->current = nullptr;
        delete tmp;
    }
    // getter and setter functions
    int get_size()
    {
        return this->size;
    }
    void set_size(int size)
    {
        this->size = size;
        return;
    }
    node * get_current()
    {
        return this->current;
    }
    void set_current(node * current)
    {
        this->current = current;
        return;
    }

    void push(int data)
    {
        node *now;
        now = new node();
        now->setData(data);
        if (current == nullptr)
        {
            current = now;
        }
        else
        {
            now->setNext(current);
            now->setPrev(current->getPrev());
            current = now;
        }
        size++;
    }
    void pop();
    void pop(int data);

    //PushAfter function added by Mahdi Shirazi (GitHub ID: mhdshrz)
    void PushAfter(int newdata, int PushAfterdata)
    {

        node *ptr = nullptr;
        node *tempo = nullptr;
        ptr = this->current;

        if (this->size == 0)
        {

            cout << "Can't be done!\n";

            return;
        }

        while (ptr->getData() != PushAfterdata)
        {

            ptr = ptr->getNext();

            if (ptr == this->current)
                break;
        }

        if (ptr == this->current)
        {

            if (ptr->getData() != PushAfterdata)
            {

                cout << "Not found!\n";

                return;
            }
        }

        tempo = this->current;
        this->current = ptr->getNext();

        this->push(newdata);

        //this->current=tempo;

        return;
    }

    //PushBefore function added by Mahdi Shirazi (GitHub ID: mhdshrz)
    void PushBefore(int newdata, int PushBeforedata)
    {

        node *ptr = nullptr;
        node *tempo = nullptr;
        ptr = this->current;

        if (this->size == 0)
        {

            cout << "Can't be done!\n";

            return;
        }

        while (ptr->getData() != PushBeforedata)
        {

            ptr = ptr->getNext();

            if (ptr == this->current)
                break;
        }

        if (ptr == this->current)
        {

            if (ptr->getData() != PushBeforedata)
            {

                cout << "Not found!\n";

                return;
            }
        }

        tempo = this->current;
        this->current = ptr;

        this->push(newdata);

        //this->current=tempo;

        return;
    }

    void print();

    //One parametric print added by Mahdi Shirazi (GitHub ID: mhdshrz)
    //An extra feature which works as a function and takes an integer number and finds it in our list ...
    //... as a data, then prints the  whole list beginning from the node having that integer as its data part.
    void print(int data)
    {

        node *ptr = nullptr;
        node *tempo = nullptr;
        ptr = this->current;

        if (this->size == 0)
        {

            cout << "Can't be done!\n";

            return;
        }

        while (ptr->getData() != data)
        {

            ptr = ptr->getNext();

            if (ptr == this->current)
                break;
        }

        if (ptr == this->current)
        {

            if (ptr->getData() != data)
            {

                cout << "Not found!\n";

                return;
            }
        }

        tempo = this->current;
        this->current = ptr;

        this->print();

        this->current = tempo;

        return;
    }
};

int main()
{
    // commands:
    // finish -> end the loop and print data, push -> push the data after current, pushA and pushB -> push the data after and before target data
    // spop -> pop node which has data, pop -> pop current node
    Circular_linked_list list;
    int data, target;

    string command;
    cin >> command;

    while(command != "finish")
    {
        if(command == "push")
        {
            cin >> data;
            list.push(data);
        }
        else if (command == "pushA")
        {
            cin >> data;
            cin >> target;
            list.PushAfter(data, target);
        }
        else if(command == "fushB")
        {
            cin >> data;
            cin >> target;
            list.PushBefore(data, target);
        }
        else if(command == "spop") // SPop stands for Specific Pop
        {
            cin >> target;
            list.pop(target);
        }
        else if(command == "pop")
        {
            list.pop();
        }
        else if(command == "print")
        {
            cin >> target;
            list.print(target);
        }
        else
        {
            cout << "Wrong input! Try again..." << endl;
        }
        cin >> command;
    }

    list.print();

    return 0;
}
