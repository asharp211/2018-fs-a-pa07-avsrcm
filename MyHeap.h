#ifndef MYHEAP_H
#define MYHEAP_H

#include <iostream>
using namespace std;

void get_identity(string my_id[])
{
	my_id[0] = "avsrcm";
	my_id[1] = "12449123";
}

template<typename T>
class HeapNode
{
public:
	T value;
	HeapNode *h_next;
	HeapNode *h_prev;

	HeapNode(T val, HeapNode *next, HeapNode *prev)
	{
		value(val);
		h_next(next);
		h_prev(prev);
	}
};


template <typename T>
class MyHeap
{
private:
	HeapNode<T> *heap = nullptr;

	T *h_array

	int h_size;

public:
	//default constructor
	MyHeap();

	//parameterized constructor
    MyHeap(T h[], int h_value);

	//destructor
	~MyHeap();

	//copy contructor
	MyHeap(const MyHeap<T> &source);

	//operator=
	MyHeap<T> & operator=(const MyHeap<T> &source);

	//top
	T & top() const;

	//pop
	void pop();

	//push
	void push(T const&);

	//empty
	bool empty();

	//size
	int size();

	//void resverse();

	/*
	default constructor - starts with an empty array
	parameterized constructor - takes two parameters, one templated array, and an
	integer size of the array.
	The constructor should build the internal heap using the heapify operation we learned.
	Note the syntax of this constructor differs from the std:: constructor.
	*/
};

//default constructor
template <typename T>
MyHeap<T>::MyHeap()
{
	heap = new HeapNode<T>(NULL, nullptr, nullptr);
	heap->h_next = heap;
	heap->h_prev = heap;

	h_size = 0;

	h_array = NULL;
}

//parameterized constructor
template<typename T>
MyHeap<T>::MyHeap(T h[], int h_value)
{

}

//destructor
template <typename T>
MyHeap<T>::~MyHeap()
{
	HeapNode<T> *temp = heap;
	HeapNode<T> *deleteHeap = temp;
	temp = temp->h_next;

	delete deleteHeap;
}

//copy contructor
template <typename T>
MyHeap<T>::MyHeap(const MyHeap<T> &source)
{
    HeapNode<T> *temp;
	heap = Temp(source.heap);

	delete Temp;
}

//operator=
template <typename T>
MyHeap<T> & MyHeap<T>::operator=(const MyHeap &source)
{
	if (heap)
	{
		MyHeap<T> temp = heap->next;
		delete temp;
	}
}

//top
template <typename T>
T & MyHeap<T>::top() const
{
	return heap->next;
}

//pop
template <typename T>
void MyHeap<T>::pop()
{
	if (!empty())
	{
		heap->h_prev->h_prev->h_next = heap;
		heap->h_prev = heap->h_prev->h_prev;
	}
	h_size--;
}

//push
template <typename T>
void MyHeap<T>::push(const T &x)
{
	MyHeap<T> *p_Temp = heap->h_prev;

	HeapNode<T> pPtr = new HeapNode<T>(x, heap->h_prev, heap);

    p_Temp->h_next = pPtr;

    heap->h_prev = pPtr;

    h_size++;
}

//empty
template <typename T>
bool MyHeap<T>::empty()
{
	if (!heap)
		return true;
	else
		return false;
}

//size
template <typename T>
int MyHeap<T>::size()
{
	return h_size;
}
/*
//reserver
template<typename T>
void MyHeap<T>::resverse()
{
    HeapNode<T> *temp;

	heap = heap->h_next;

    temp = heap->m_prev;

    heap->m_prev = heap->m_next;

    heap->m_next = temp;

    heap = heap->m_prev;
}*/
#endif
