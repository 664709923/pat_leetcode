#include <iostream>
#include <string>

using namespace std;

int n, cnt=0;
bool first = true;

struct Node
{
	Node(int _val): val(_val), left(NULL), right(NULL) {}
	int val;
	Node* left;
	Node* right;
};

Node* build_tree()
{
	Node* node = NULL;

	if (cnt < 2 * n)
	{
		string s;
		cin >> s;
		++ cnt;
		if (s == "Push")
		{
			int num;
			cin >> num;
			node = new Node(num);
			node->left = build_tree();
			node->right = build_tree();
		}
	}

	return node;
}

void postorder(Node* node)
{
	if (node == NULL)
	{
		return ;
	} else
	{
		postorder(node->left);
		postorder(node->right);
		if (first == true)
		{
			cout << node->val;
			first = false;
		} else
		{
			cout << " " << node->val;
		}
	}
}

int main()
{
	cin >> n;

	auto root = build_tree();
	postorder(root);

	return 0;
}
