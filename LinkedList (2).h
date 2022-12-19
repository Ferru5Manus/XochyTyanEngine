#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T value;
	Node<T>* priv;
	Node<T>* next;
};

template <typename T>
/*
* Связанный список
*/
class LinkedList
{
public:
	/*
	* Связанный список
	*/
	LinkedList() 
	{

	}

	/*
	* Возвращает длину массива
	*/
	int len()
	{
		return size;
	}


	/*
	* Добавляет item в конец
	* @return возвращает flase, если произошла ошибка
	*/
	bool add(T item) 
	{
		try 
		{
			Node<T>* node = new Node<T>;
			node->value = item;
			node->next = NULL;
			if (first == NULL)
			{
				first = node;
				last = node;
			}
			else
			{
				node->priv = last;
				last->next = node;
				last = last->next;
			}
			size++;
			return true;
		}
		catch (exception e) {
			return false;
		}
	}

	/*
	* @param index - элемент, перед которым будет вставлен элемент
	* @param item  - элемент
	* @return возвращает flase, если произошла ошибка
	*/
	bool insert(int index, T item) 
	{
		try
		{
			Node<T>* node = new Node<T>;
			node->value = item;
			if (index == size || first == NULL)
			{
				return add(item);
			}
			if (index > size)
			{
				return false;
			}
			if (index == 0)
			{
				node->next = first;
				first->priv = node;
				first = node;
				size++;
				return true;
			}
			Node<T>* last_node = first;
			for (int i = 1; i <= index; i++)
			{
				last_node = last_node->next;
			}
			last_node->priv->next = node;
			last_node->priv = node;
			node->priv = last_node->priv;
			node->next = last_node;
			size++;
			return true;
		}
		catch (exception e)
		{
			return false;
		}
	}

	/*
	* Удаляет элемент по индексу
	* @throw std::invalid_argument
	*/
	void remove(int index)
	{
		try
		{
			if (index >= size || index < 0)
			{
				throw std::invalid_argument("index out of range!");
			}
			if (index == 0)
			{
				first = first->next;
				delete first->priv;
				first->priv = NULL;
				size--;
				return;
			}
			if (index == size - 1)
			{
				last = last->priv;
				delete last->next;
				last->next = NULL;
				size--;
				return;
			}
			Node<T>* node = NULL;
			if (size / 2 > index)
			{
				node = first;
				for (int i = 0; i < index; i++)
				{
					node = node->next;
				}
			}
			else
			{
				node = last;
				for (int i = size - 1; i > index; i--)
				{
					node = node->priv;
				}
			}
			node->priv->next = node->next;
			node->next->priv = node->priv;
			delete node;
			size--;
		}
		catch (exception e) 
		{
			throw std::invalid_argument("index out of range!");
		}
	}

	/*
	* Выводит массив на экран в виде строки
	* @param _endl \n flase - нужно вывести подряд \n true - каждый элемент с новой строки
	*/
	void toString(bool _endl)
	{
		Node<T>* node = first;
		while (node != NULL)
		{
			if (_endl)
			{
				cout << node->value << endl;
			}
			else
			{
				cout << node->value << "; ";
			}
			node = node->next;
		}
		cout << endl;
	}
	
	/**
	 Метод очищет массив и освобождает всю выделенню под него память
	*/
	void clear()
	{
		if (first == NULL)
		{
			return;
		}
		Node<T>* node = first;
		while (node != NULL)
		{
			Node<T>* del = node;
			node = node->next;
			delete del;
		}
		delete node;
		size = 0;
		first = NULL;
		last = NULL;
	}

private:
	Node<T>* first = NULL;
	Node<T>* last = NULL;
	int size = 0;

};

