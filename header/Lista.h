#pragma once
#include<cstddef>
#include<iostream>

template <typename T>
class Lista
{
#include "Nodo.h"
public:
	Lista():head(NULL){}
	void push_front(const T& val);
	void push_back(const T& val);
	void pop_front();
	void pop_back();
	void print()const;
	size_t size()const;
	
	~Lista();

private:
	Nodo* head;
};

template<typename T>
void Lista<T>::push_front(const T& val)
{
	Nodo* pNuevo = new Nodo(val);
	if (head ==NULL)
	{
		head = pNuevo;
	}
	else {
		pNuevo->next = head;
		head = pNuevo;
	}
}

template<typename T>
void Lista<T>::push_back(const T & val)
{
	Nodo* pNuevo = new Nodo(val);
	Nodo* pTmp = head;
	if (head == NULL)
	{
		head = pNuevo;
	}
	else {
		while (pTmp->next != NULL)
		{
			pTmp = pTmp->next;
		}
		pTmp->next = pNuevo;
	}
}

template<typename T>
void Lista<T>::pop_front()
{
	Nodo* pTmp = head;

	if (pTmp)
	{		
		head = head->next;		
		delete pTmp;
	}
}

template<typename T>
void Lista<T>::pop_back()
{
	Nodo* pAnterior, *pActual;
	pAnterior = head;
	pActual = head;
	if (size() == 1)
	{
		delete pActual;
		head = NULL;
		return;
	}
	while (pActual->next)
	{
		pAnterior = pActual;
		pActual = pActual->next;
	}

	pAnterior->next = NULL;
	delete pActual;
}

template<typename T>
void Lista<T>::print() const
{
	Nodo* pNodo = head;
	while (pNodo)
	{
		std::cout << pNodo->data<<std::endl;
		pNodo = pNodo->next;
	}
}

template<typename T>
size_t Lista<T>::size() const
{
	size_t count = 0;

	Nodo* pTmp = head;

	while (pTmp)
	{
		count++;
		pTmp = pTmp->next;
	}
	
	return count;
}

template<typename T>
Lista<T>::~Lista()
{
	Nodo* pBorrar;
	while (head)
	{
		pBorrar = head;
		head = head->next;
		delete pBorrar;
	}
}