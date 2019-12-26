#pragma once
#include<iostream>
template <class T>
struct TNode
{
	T val;
	TNode<T> *pNext;
};

template <class T>
class TStack
{
private:
	TNode<T> *pFirst;
public:
	TStack();
	TStack(int s);
	~TStack();
	TStack(const TStack<T>& st);
	TStack<T>& operator=(const TStack<T>& st);
	bool IsEmpty()const;
	bool IsFull()const;
	void push(const T& a);
	T pop();
	T top();
	void clear();
};

template <class T>
TStack<T>::TStack()
{
	pFirst = NULL;
}

template <class T>
TStack<T>::~TStack()
{
	TNode<T> *tmp = pFirst;
	while (pFirst != NULL)
	{
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}
}

template <class T>
TStack<T>::TStack(const TStack<T>& st)
{
	TNode<T> *tmp = st.pFirst;
	if (tmp == NULL)
	{
		pFirst = tmp;
	}
	while (tmp != NULL)
	{
		push(tmp->val);
		tmp = tmp->pNext;
	}
	delete tmp;
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& st)
{
	if (this != &st)
	{
		if (!IsEmpty())
		{
			clear();
		}
		else
		{
			TNode<T> *tmp = st.pFirst;
			if (tmp == NULL)
			{
				pFirst = tmp;
			}
			while (tmp != NULL)
			{
				push(tmp->val);
				tmp = tmp->pNext;
			}
			delete tmp;
		}
	}
	return *this;
}

template <class T>
bool TStack<T>::IsEmpty()const {
	return pFirst == NULL;
}

template <class T>
bool TStack<T>::IsFull()const {
	TNode<T> *tmp;
	tmp = new TNode<T>;
	if (tmp == NULL)
	{
		return 1;
	}
	else
	{
		delete tmp;
		return 0;
	}
}

template <class T>
void TStack<T>::push(const T& a) {
	if (IsFull())
	{
		throw - 1;
	}
	else
	{
		TNode<T> *tmp;
		tmp = new TNode<T>;
		tmp->pNext = pFirst;
		tmp->val = a;
		pFirst = tmp;
	}
}

template <class T>
T TStack<T>::pop() {
	if (IsEmpty())
	{
		throw - 1;
	}
	else
	{
		T res = pFirst->val;
		TNode<T> *tmp;
		tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		return res;
	}
}

template <class T>
T TStack<T>::top() {
	if (IsEmpty())
	{
		throw - 1;
	}
	else
	{
		return pFirst->val;
	}
}

template <class T>
void TStack<T>::clear() {
	TNode<T> *tmp = pFirst;
	while (pFirst != NULL)
	{
		pFirst = pFirst->pNext;
		delete tmp;
		tmp = pFirst;
	}

}