#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct treeNode
{
	struct treeNode *linkL;
	int count;
	char data;
	struct treeNode *linkR;
};

class countTree
{
	friend void showTree(struct treeNode *);
private :
	struct treeNode *root;
public :
	countTree(void);
	void insertNode(char);
	void show(void);
};


void showTree(struct treeNode *a)
{
	if (a!=NULL)
	{
		showTree(a->linkL);
		cout<<(int)a->data<<" "<<a->count<<endl;
		showTree(a->linkR);
	}
}

void countTree::show(void)
{
	showTree(root);
}

countTree::countTree(void)
{
	root=NULL;
}

void countTree::insertNode(char key)
{
	struct treeNode *t,*p,*q;
	t=new struct treeNode;
	t->count=1;
	t->linkL=t->linkR=NULL;
	t->data=key;
	if (root==NULL)
		root=t;
	else
	{
		p=root;
		while (p!=NULL)
		{
			q=p;
			if (key<p->data)
				p=p->linkL;
			else if (key>p->data)
				p=p->linkR;
			else if (key==p->data)
			{
				p->count++;
				return ;
			}
		}
		if (key<q->data)
			q->linkL=t;
		else q->linkR=t;
	}
}

main()
{
	char key;
	countTree text;
	while (1)
	{
		while (1)
		{
			cin>>key;
			if (key=='.') break;
			text.insertNode(key);
		}
		text.show();
		cout<<endl;
	}
	return 0;
}

