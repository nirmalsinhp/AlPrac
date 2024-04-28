#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	Node *next;
	Node(int v, Node *nptr = nullptr) : val(v), next(nptr){};
};

Node *reverse(Node *head)
{
	auto start = head;
	Node *prev = nullptr;
	while (!start)
	{
		auto next = start->next;
		start->next = prev;
		prev = start;
		start = next;
	}

	return prev;
}

int main()
{
	// Node * head;
	// auto h = reverse(head);
	string s = "Hello World";
	auto itr = find_if(s.rbegin(), s.rend(), [](auto c)
					   { return isalpha(c); });
	auto sitr = find_if(itr + 1, s.rend(), [](auto c)
						{ return isspace(c); });
	int d = distance(itr, sitr);

	vector<int> v = {6, 2, 1, 3, 7, 5};
	replace(v.begin(), v.end(), v[3], v[2]);
	for(auto n : v)
		cout << n << " ";
	cout << endl;
	auto sum = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		sum += v[i];
		int avg = sum / (i + 1);
		cout << sum << " " << avg << endl;
		;
	}
	cout << endl;
	return 0;
}