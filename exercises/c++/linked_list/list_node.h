#ifndef LIST_NODE_H

#define LIST_NODE_H
namespace mylib
{
    /**
     * ListNode class
     */
    template <class T>
    class ListNode
    {

	private:
	    T NodeElement;
	    ListNode<T> *NextNode;
	public:


	    ListNode ( const  T& elem, ListNode<T>* next = nullptr):
		NodeElement{elem}, NextNode{next}
	    {}
	    ListNode ( T&& elem, ListNode<T>* next = nullptr):
		NodeElement{elem}, NextNode{next}
	    {}
	    ListNode ( const ListNode<T>& other):
		NodeElement{other.NodeElement}, NextNode{other.NextNode}
	    {}
	    ListNode ( ListNode<T>&& other):
		NodeElement{std::move(other.NodeElement)}, NextNode{other.NextNode}
	    {}


	    auto& operator= (const ListNode<T>& other)
	    {
		NodeElement = other.NodeElement;
		NextNode = other.NextNode;
		return *this;
	    }
	    auto& operator= ( ListNode<T> && other)
	    {
		NodeElement = std::move (other.NodeElement);
		NextNode = other.NextNode;
		return *this;
	    }
	    
	    auto& get_next() const noexcept
	    {
		return *NextNode;
	    }
	    const T& get_elem() const noexcept 
	    {
		return NodeElement;
	    }
	    T& get_elem() noexcept 
	    {
		return NodeElement;
	    }
	    void set_next( ListNode<T>* new_next) noexcept 
	    {
		NextNode = new_next;
	    }
	    void set_elem( const T& new_elem)
	    {
		NodeElement = new_elem;
	    }
	    void set_elem( const T&& new_elem)
	    {
		NodeElement = new_elem;
	    }
    };
    template <class T>
    using Node = ListNode<T>;
}
#endif
