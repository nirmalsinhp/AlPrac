#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	Node * next;
	Node(int v, Node * nptr =  nullptr):val(v), next(nptr){};
};

Node * reverse(Node * head)
{
	auto start = head;
	Node * prev = nullptr;
	while(!start)
	{
		auto next = start->next;
		start->next =  prev;
		prev = start;
		start =  next;
	}
	
	return prev;
}

int main()
{
	Node * head;
	auto h = reverse(head);

	return 0;
}