#pragma once
#include <iostream>

using namespace std;

struct Node
{
	float value;
	Node* priv;
	Node* next;
};

class LinkedList
{
public:
	LinkedList() 
	{

	}

	int len()
	{
		return size;
	}



	bool add(float item) 
	{
		try 
		{
			Node* node = new Node;
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


	bool insert(int index, float item) 
	{
		try
		{
			Node* node = new Node;
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
			Node* last_node = first;
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

	void toString()
	{
		Node* node = first;
		while (node != NULL)
		{
			cout << node->value << endl;
			node = node->next;
		}
	}

private:
	Node* first = NULL;
	Node* last = NULL;
	int size = 0;

};

