#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;

struct listNode
{
	int count;
	int data;
	struct listNode *link;
};

class list
{
	friend ostream &operator<<(ostream &,const list &);
private :
	struct listNode *head;
	struct listNode *tail;
	int check(int);
public :
	list(void);
	void operator+(const int &);
};

ostream &operator<<(ostream &output,const list &right)
{
	struct listNode *p;
	for (p=right.head;p!=NULL;p=p->link)
		output<<p->data<<" "<<p->count<<endl;
	return output;
}

list::list(void)
{
	head=NULL;
}

int list::check(int key)
{
	struct listNode *p;
	for (p=head;p!=NULL;p=p->link)
		if (p->data==key)
		{
			p->count++;
			return 1;
		}
	return 0;
}

void list::operator+(const int &key)
{
	struct listNode *t;
	if (check(key)) return;
	t=new struct listNode;
	t->data=key;
	t->count=1;
	t->link=NULL;
	if (head==NULL)
		head=tail=t;
	else tail->link=t,tail=t;
}

main()
{
	list c;
	int key;
	while (cin>>key)
		c+key;
	cout<<c;
	return 0;
}




