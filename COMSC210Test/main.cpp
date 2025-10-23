#include <iostream>
using namespace std;

struct Node
{
	int number;
	Node* next;
};

void add(Node*& head, int value)
{
	Node* newNode;
	Node* nodePtr;
	
	newNode = new Node;
	newNode->number = value;
	newNode->next = nullptr;

	if (!head)
	{
		head = newNode;
	}
	else
	{
		nodePtr = head;

		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
	}
}

void print(Node* head)
{
	Node* p = head;

	while (p != nullptr)
	{
		cout << p->number << " ";
		p = p->next;
	}
}
int total(Node* head)
{
	Node* p = head;
	int total = 0;

	while (p != nullptr)
	{
		total += p->number;
		p = p->next;
	}

	return total;
}

void clear(Node* head)
{
	Node* nodePtr;
	Node* nextNode;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;

		delete nodePtr;

		nodePtr = nextNode;
	}

	head = nullptr;
}

int main()
{
	
	Node* head = nullptr;
	Node* node = new Node;
	
	for (int i = 1; i < 6; i++)
	{
		int valueEntered;
		cout << "Enter number " << i << ": ";
		cin >> valueEntered;
		add(head, valueEntered);
	}
	
	cout << "You entered: ";
	print(head);
	cout << endl;
	cout << "Total entered: " << total(head) << endl;
	clear(head);
}

