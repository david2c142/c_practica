#pragma once
#include<cstddef>
#include<iostream>

template <typename T>
class Lista
{
#include "Nodo.h"
public:
	Lista():head(NULL){}

	void push_front(const T& val){
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

	void push_back(const T& val){
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

	void pop_front(){
        Nodo* pTmp = head;

        if (pTmp)
        {		
            head = head->next;		
            delete pTmp;
        }
    }

	void pop_back(){
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

	void print()const{
        Nodo* pNodo = head;
        while (pNodo)
        {
            std::cout << pNodo->data<<std::endl;
            pNodo = pNodo->next;
        }
    }

	size_t size()const{
        size_t count = 0;

        Nodo* pTmp = head;

        while (pTmp)
        {
            count++;
            pTmp = pTmp->next;
        }
        
        return count;
    }
	
	~Lista(){
        Nodo* pBorrar;
        while (head)
        {
            pBorrar = head;
            head = head->next;
            delete pBorrar;
        }
    }

private:
	Nodo* head;
};

