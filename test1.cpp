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
	//Node * head;
	//auto h = reverse(head);
	vector<int> v = {6,2,1,3,7,5};
	auto sum = 0;
	for(int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
		int avg = sum / (i+1);
		cout << sum << " " << avg << endl;;
	}
	cout << endl;
	return 0;
}