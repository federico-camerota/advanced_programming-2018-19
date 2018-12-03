/* IMPLEMENT A LINKED LIST WITH NODES THAT STORE AN ELEMENT AND A POINTER TO THE 
 * NEXT NODE.
 * THE CLASS SHOULD IMPLEMENT MOVE AND COPY SEMANTICS AND PUSH_BACK/PUSH_FRONT METHODS
 * AS WELL AS BEGIN() END() AND HAVE AN ITERATOR THAT INHERITS FROM SOMEWHERE
 * CHECKOUT: http://www.cplusplus.com/reference/iterator/iterator/
 */
#ifndef LISTS_H

#define LISTS_H

#include <iterator>
#include <iostream>
#include "list_node.h"

namespace mylib
{

    /**
     * LinkedList type definition
     */
    template <typename T>
    class LinkedList 
    {

	private:
	    //pointer to the first node in the list
	    Node<T>* head;
	    //pointer to the last node in the list
	    Node<T>* tail;
	    //Helper function to delete all nodes starting from a given node
	    void delete_node (Node<T> *node){
	    
		if (node)
		{
		    delete_node (&(*node).get_next());
		    delete node;
		}
	    }
	
	public:

	    /**
	     * ListIterator type definition
	     */
	    template <class V>
	    class ListIterator : std::iterator<std::forward_iterator_tag, V>
	    {
		private:
		    Node<V>* node;
		public:
		    ListIterator ()noexcept : 
			node{nullptr}
		    {}
		    ListIterator (Node<V> * n) noexcept :
			node{n}
		    {}
		    ListIterator ( const ListIterator<V>& other):
			node{other.node}
		    {}
		    ListIterator ( ListIterator<V>&& other):
			ListIterator()
		    {
			std::swap(node, other.node); 
		    }

		    auto& operator++ ()
		    {
			node =  &(*node).get_next();
			return *this;
		    }
		    auto& operator* ()
		    {
			std::cout << "operator*" << std::endl; //DEBUG
			return (*node).get_elem();
		    }
		    const auto& operator* () const
		    {
			std::cout << "operator* const" << std::endl; //DEBUG
			return (*node).get_elem();
		    }
		    bool operator== (const ListIterator<V>& other) const
		    {
			return node == other.node;
		    }
		    bool operator!= (const ListIterator<V>& other) const
		    {
			return !(*this == other);
		    }
	    };
	    template <class V>
	    using iterator = ListIterator<V>;

	    LinkedList ():
		head{nullptr}, tail{nullptr}
	    {}
	    LinkedList ( T& elem):
		LinkedList()
	    {
		tail = head = new Node<T>{elem};
	    }

	    LinkedList ( T&& elem):
		LinkedList()
	    {
		tail = head = new Node<T>{elem};
	    }
	    LinkedList ( const LinkedList<T>& other);
	    //another idea may be to  first call LinkedList() and then use std::swap
	    LinkedList ( LinkedList<T>&& other):
		head{other.head}, tail{other.tail}
	    {
		other.head = nullptr;
		other.tail = nullptr;
	    }
	    ~LinkedList ()
	    {
		delete_node(head);
	    }


	    auto& operator= ( LinkedList<T>& other);
	    auto& operator= ( LinkedList<T>&& other);

	    iterator<T> const begin() const 
	    { 
		std::cout << "begin() const" << std::endl; //DEBUG
		return ListIterator<T>(head);
	    }
	    iterator<T> const end() const
	    {
		std::cout << "end() const" << std::endl; //DEBUG
		return iterator<T>(nullptr);
	    }
	    /**
	     * Not needed, const ones can be used both with const and non const instances
	     * but needed to have the behavior I desire (have iterators that don't allow
	     * the underlying data to be modified for const instances).
	     */
//	    auto begin()  
//	    { 
//		return iterator<T>(head);
//	    }
//	    auto end() 
//	    {
//		return ListIterator<T>(nullptr);
//	    }
	    bool is_empty()
	    {
		return head == nullptr;
	    }
	    void push_back ( const T& elem);
	    void push_back ( T&& elem);
	    void push_front (const T& elem);
	    void push_front ( T&& elem);
    };

    template<class T>
    std::ostream& operator<< (std::ostream& os, const LinkedList<T>& list);


    /**
     * LinkdList constructors and destructors implementations
     */
    //Copy constructor
    template <class T>
    LinkedList<T>::LinkedList ( const LinkedList<T>& other):
	LinkedList()
    {
	Node<T>* previous{nullptr};
	Node<T>* new_node{nullptr};
	for (const auto& x : other){
	
	    new_node = new Node<T>{x};
	    if (previous)
		(*previous).set_next(new_node);
	    else
		head = new_node;
	    previous = new_node;
	}
	tail = new_node;
    }

    /**
     * LinkedList function members implementations
     */
    //Overloading operator= for LinkedList type use copy and move semantics
    template <class T>
    auto& LinkedList<T>::operator= ( LinkedList<T>& other)
    {
	LinkedList<T> tmp{other};
	*this = std::move(tmp);
	return *this;
    }
    template <class T>
    auto& LinkedList<T>::operator= ( LinkedList<T>&& other)
    {
	//better replace it with std::swap
//	delete_node(head);
//	head = other.head;
//	tail = other.tail;
//	other.head = nullptr;
//	other.head = nullptr;
	std::swap(head, other.head);
	std::swap(tail, other.tail);
	return *this;
    }
    //push_back function member, adds element at the end of the list using copy and move semantics
    template <class T>
    void LinkedList<T>::push_back ( const T& elem)
    {

	Node<T>* new_node = new Node<T>{elem};
	if (!is_empty())
	    (*tail).set_next(new_node);
	else
	    head = new_node;
	tail = new_node;
    }
    template <class T>
    void LinkedList<T>::push_back ( T&& elem)
    {
	Node<T>* new_node = new Node<T>{elem};
	if (!is_empty())
	    (*tail).set_next(new_node);
	else
	    head = new_node;
	tail = new_node;
    }
    //push_front function member, adds element at the begining of the list using copy and move semantics
    template <class T>
    void LinkedList<T>::push_front (const T& elem)
    {
	Node<T>* new_node = new Node<T>{elem, head};
	if (is_empty())
	    tail = new_node;
	head = new_node;
	
    }
    template <class T>
    void LinkedList<T>::push_front ( T&& elem)
    {
	Node<T>* new_node = new Node<T>{elem, head};
	if (is_empty())
	    tail = new_node;
	head = new_node;
    }

    /**
     * Helper functions implementations
     */
    //Overload of operator<< for LinkedList type, prints each element in one line
    template <class T>
    std::ostream& operator<< (std::ostream& os, const LinkedList<T>& list)
    {
	for (const auto& x : list)
	    os << x << std::endl;
	return os;
    }
}

#endif
