/*
  Problem description : 
  
  
  Code is not properly working...
*/
#include <iostream>
#include<vector>
#include<malloc.h>
#include<string>
#include<stack>
using namespace std;
struct puzzle{
	bool isVisited;
	char val;
	struct puzzle * left;
	struct puzzle * right;
	struct puzzle * up;
	struct puzzle * down;
};
struct puzzle * newNode(char ch){
	struct puzzle * p = (struct puzzle*)malloc(sizeof(struct puzzle));
	p->isVisited=false;
	p->val = ch;
	p->left=NULL;
	p->right=NULL;
	p->up=NULL;
	p->down=NULL;
	return p;
}

string wordH(struct puzzle * itr){
	string ret="";
	while(itr){
		ret+=itr->val;
		itr=itr->right;
	}
	return ret;
}

string wordV(struct puzzle * itr){
	string ret="";
	while(itr){
		ret+=itr->val;
		itr=itr->down;
	}
	return ret;
}

vector<string> wordsFromPuzzle(struct puzzle * head){
	vector<string> ans;
	struct puzzle * itr;
	stack<struct puzzle*> s;
	s.push(head);
	while(!s.empty()){
		itr=s.top();
		s.pop();
		itr->isVisited=true;
		if(itr->right&&itr->right->isVisited==false){
			s.push(itr->right);
		}
		if(itr->left&&itr->left->isVisited==false){
			s.push(itr->left);
		}
		if(itr->up&&itr->up->isVisited==false){
			s.push(itr->up);
		}
		if(itr->down&&itr->down->isVisited==false){
			s.push(itr->down);
		}
		if(itr->left==NULL){
			string ret = wordH(itr);
			if(ret.size()>1){
				ans.push_back(ret);
			}
		}
		if(itr->up==NULL){
			string ret = wordV(itr);
			if(ret.size()>1){
				ans.push_back(ret);
			}
		}
	}
    return ans;
}

int main() {
	char ch = 'h';
	struct puzzle * head=newNode(ch);
    head->left=newNode('x');
	head->right=newNode('i');
	head->down=newNode('p');
	vector<string> ans=wordsFromPuzzle(head);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}

