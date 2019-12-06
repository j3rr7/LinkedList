#include <iostream>

struct Node
{
	int data;
	Node* next;
};

class LinkedList {
private:
	Node* head;
	Node* tail;
public:
	LinkedList()
	{
		this->head = NULL;
		this->tail = NULL;
	}
	void insert(int value)
	{
		Node* tempNode = new Node;
		tempNode->data = value;
		tempNode->next = NULL;
		if (this->head == NULL)
		{
			this->head = tempNode;
			this->tail = tempNode;
		}
		else
		{
			this->tail->next = tempNode;
			this->tail = this->tail->next;
		}
	}
	void view() {
		Node* temp;
		temp = this->head;
		while (temp != NULL)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
	}
	void del(int value)
	{
		Node* temp;
		temp = this->head;
		while (temp != NULL)
		{
			Node* simpan = temp->next;
			if (simpan->data == value)
			{
				temp->next = simpan->next;
				delete simpan;
				break;
			}
			temp = temp->next;
		}
	}
};

int main()
{
	LinkedList l;

	l.insert(3);
	l.insert(9);
	l.insert(12);
	l.insert(17);
	l.insert(18);

	l.del(17);
	l.del(18);

	l.view();

	return 0;