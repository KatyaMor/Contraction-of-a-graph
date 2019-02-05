//////////////////////////////
//Created by Katya Morgunova//
//////////////////////////////

#pragma once

#include <string>
#include "stack.h"

template <class T>
class Stack
{
protected:
	struct Node { T data; Node *next; Node *prev };
	Node *head;
	int size = 0;
public:
	Stack();
	Stack(const Stack&) = delete;
	Stack(Stack&&) = delete;
	Stack& operator=(const Stack&) = delete;
	Stack& operator=(Stack&&) = delete;
	~Stack();//clear()
	int size()const;// return size
	void push(const T&);//додає елемент до контейнеру
	bool pop();//delete head.next(head=nullptr)
	T& top()const;//return head.next
	bool empty()const;//size==0
	void clear();//очистка стеку
	bool remove(const T&);//видалення конкретного елементу
	void extractData(const char*); //to file
	class Iterator
	{
	public:
		Iterator(Node *current = nullptr);
		~Iterator() = default;
		T& operator*()const;//показує поточний елемент
		typename Iterator& operator++();
		operator bool()const;//current!=nullptr
	protected:
		Node *head;
		Node *current;
	};
	Iterator begin()const;//початок стеку
	Iterator end()const;//кінець
	Iterator& find(const T&)const;//пошук конкретного елементу
};

template <class T>
T& Stack<T>::Iterator::operator*()const
{
	if (current) return current->data;	else throw std::out_of_range("\nError!Wrong iterator position!\n");
}

template <class T>
void Stack<T>::push(const T& num)
{
	Node *tmp = new Node{ num };
	tmp.next = head.next;
	tmp.prev = head;
	head.next = tmp;
	tmp->next->prev = tmp;
	++size;
}

template <class T>
bool Stack<T>::remove(const T& num)
{
	Node *tmp = new Node{ num };
	if (tmp->next!=nullptr && tmp->prev!=nullptr)
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		delete tmp;
		--size;
		return 1;
	}
	if (tmp == head.next)
	{
		tmp->next->prev = nullptr;
		head.next = tmp->next;
		delete tmp;
		--size;
		return 1;
	}
	if (tmp->next==nullptr)
	{
		tmp->prev->next = nullptr;
		delete tmp;
		--size;
		return 1;
	}
	return 0;
}

template <class T>
int Stack<T>::size()const
{
	return size;
}

template <class T>
Stack<T>::Stack()
{
	head = new Node;
	head.next = head;
	head.prev = head;
}

template <class T>
Stack<T>::~Stack()
{
	clear();
	delete head;
}

template <class T>
bool Stack<T>::empty()const
{
	return size == 0;
}

template <class T>
void Stack<T>::clear()
{
	Node *tmp;
	while (head)
	{
		tmp = head.next->next;
		delete head.next;
		head.next = tmp;
	}
	size = 0;
}

template <class T>
T& Stack<T>::top()const
{
	if (!head) throw std::out_of_range("\nError! No data.\n");
	return head->data;
}

template <class T>
bool Stack<T>::pop()
{
	if (!head) return false;
	Node *tmp = head.next->next;
	head = nullptr;
	delete head.next;
	head.next = tmp; 
	--size;
	return true;
}

/*template <class T>
void Stack<T>::extractData(std::string& s)
{
	for (Iterator i; i; ++i) s += to_string(*i);
}*/

template <class T>
void Stack<T>::extractData(const char *fname)
{
	std::fstream f(fname);
	for (Iterator i; i; ++i) f << (*i) << endl;
}

template <class T>
Stack<T>::Iterator::Iterator(Node *c) :current(c) {}

template <class T>
typename Stack<T>::Iterator& Stack<T>::Iterator::operator++()
{
	if (current) current = current->next;
	return *this;
}

template <class T>
Stack<T>::Iterator::operator bool()const
{
	return current != nullptr;
}

template <class T>
typename Stack<T>::Iterator& Stack<T>::find(const T& t)const
{
	typename Stack<T>::Node *tmp;
	for (tmp = head; tmp && tmp->t != t; tmp = tmp->next);
	return typename Stack<T>::Iterator(tmp);
}

template <class T>
typename Stack<T>::Iterator Stack<T>::begin()const
{
	return Iterator(head);
}

template <class T>
typename Stack<T>::Iterator Stack<T>::end()const
{
	return Iterator();
}
