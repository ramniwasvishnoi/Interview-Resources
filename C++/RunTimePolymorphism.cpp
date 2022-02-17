#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Base{
	public:
	virtual void fun(){
		cout<<"Inside base fun"<<endl;
	}
	void fun1(){
		cout<<"Inside base fun1"<<endl;
	}
	Base(){
		cout<<"inside base constructor"<<endl;
	}
	~Base(){
		cout<<"inside base destructor"<<endl;
	}
};

class Child1:public Base{
	public:
	void fun(){
		cout<<"Inside Child1 fun"<<endl;
	}
	void fun1(){
		cout<<"Inside Child1 fun1"<<endl;
	}
	void fun2(){
		cout<<"Inside Child1 fun2"<<endl;
	}
	Child1(){
		cout<<"Inside Child1 constructor"<<endl;
	}
	~Child1(){
		cout<<"Inside Child1 destructor"<<endl;
	}
};

class Child2: public Base{
	public:
	void fun(){
		cout<<"Inside Child2 fun"<<endl;
	}
};

int fact(int input){
	if(input==1||input==0){
		return 1;
	}
	return input*fact(input-1);
}

// //64/4

// 1000000
// 100=>2^2
// 100=>4
// 10000=>16
// 1000000=>64

// 10000=>16

// 64/2
// 10=>2
// 1000000=>64
// diff = 100000=>32



struct ll{
	int val;
	struct ll * next;
};

struct ll * newNode(int input){
	struct ll * node = (struct ll*)malloc(sizeof(struct ll));
	node->val=input;
	node->next=NULL;
	return node;
}

void insertLL(struct ll * &head, int val){
	if(head==NULL){
		head=newNode(val);
		return ;
	}
	struct ll * temp=head;
	while(temp->next){
		temp=temp->next;
	}
	temp->next=newNode(val);
	return ;
}

void printLL(struct ll * head){
	while(head){
		cout<<head->val<< " ";
		head=head->next;
	}
	cout<<endl;
}

int main() {
	// int val=5;
	// int ans=fact(val);
	// cout<<ans<<endl;

	// struct ll * head = newNode(5);
	// insertLL(head, 1);
	// insertLL(head, 2);
	// insertLL(head, 3);
	// printLL(head);
	Base * b=new Child1();
	b->fun();
	delete b;
	// Child1 ch1;
	// Child2 ch2;
	// b=&ch1;
	// b->fun();//It wil print "Inside Child1 fun"
	// b=&ch2;
	// b->fun();////It wil print "Inside Child2 fun"
	return 0;
}
