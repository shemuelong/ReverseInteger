#include <iostream>
 
/* Code here is taken from Clifford A Shaffer's Data Structures and Algorithm Analysis Book.
*/
 
void Assert(bool val, string s) {
    if (!val) { // Assertion failed -- close the program
        cout << "Assertion Failed: " << s << endl;
        exit(-1);
    }
}

// Singly linked list node
template <typename E> class Link {
	public:
	E element; // Value for this node
	Link *next; // Pointer to next node in list
	// Constructors
	Link(const E& elemval, Link* nextval = NULL)
		{ element = elemval; next = nextval; }
	explicit Link(Link* nextval =NULL) { next = nextval; }
};


// Stack abstarct class
template <typename E> class Stack {
	private:
	void operator =(const Stack&) {} // Protect assignment
	Stack(const Stack&) {} // Protect copy constructor
	public:
	Stack() {} // Default constructor
	virtual ~Stack() {} // Base destructor
	// Reinitialize the stack. The user is responsible for
	// reclaiming the storage used by the stack elements.
	virtual void clear() = 0;
	// Push an element onto the top of the stack.
	// it: The element being pushed onto the stack.
	virtual void push(const E& it) = 0;
	// Remove the element at the top of the stack.
	// Return: The element at the top of the stack.
	virtual E pop() = 0;
	// Return: A copy of the top element.
	virtual const E& topValue() const = 0;
	// Return: The number of elements in the stack.
	virtual int length() const = 0;
};

// Linked stack implementation
template <typename E> class LStack: public Stack<E> {
	private:
	Link<E>* top; // Pointer to first element
	int size; // Number of elements
	public:
	LStack(int sz = 20) // Constructor
	{ top = NULL;
	size = 0;
		}
	~LStack() { clear(); } // Destructor
	void clear() { // Reinitialize
		while (top != NULL) { // Delete link nodes
            Link<E>* temp = top;
            top = top->next;
            delete temp;
	    }
	    size = 0;
	}
	void push(const E& it) { // Put "it" on stack
		top = new Link<E>(it, top);
		size++;
	}
	E pop() { // Remove "it" from stack
		Assert(top != NULL, "Stack is empty");
		E it = top->element;
		Link<E>* ltemp = top->next;
		delete top;
		top = ltemp;
		size--;
		return it;
	}
	const E& topValue() const { // Return top value
	Assert(top != 0, "Stack is empty");
	return top->element;
	}
	int length() const { return size; } // Return length
};
