#include<bits/stdc++.h>
using namespace std;

struct node
{
	bool endmark;
	node *next[26+1];
	node()
	{
		endmark=false;
		for(int i=0;i<26;i++) next[i]=NULL;
	}
}*root;

void insert(string str)
{
	node *curr=root;
	for(int i=0;str[i];i++)
	{
		int id=str[i]-'a';
		if(curr->next[id]==NULL)
			curr->next[id]=new node();
		curr=curr->next[id];
	}
	curr->endmark=true;

}
bool search(string str)
{
	node *curr=root;
	for(int i=0;str[i];i++)
	{
		int id=str[i]-'a';
		if(curr->next[id]==NULL) return false;
		curr=curr->next[id];
	}
	return curr->endmark;
}
void del(node *cur)
{
      for(int i=0;i<26;i++)
             if(cur->next[i])
                  del(cur->next[i]) ;

         delete(cur) ;
}
int main()
{
    int num_word, query;
    string str;

	root=new node();

	cout<<"ENTER NUMBER OF WORDS: ";
	cin>>num_word;

	cout<<"NOW ENTER THE WORDS:\n";
	for(int i=1;i<=num_word;i++)
	{
		cin>>str;
		insert(str);
	}

	cout<<"ENTER NUMBER OF QUERY: ";
	cin>>query;

	cout<<"NOW ENTER THE WORDS:\n";
	for(int i=1;i<=query;i++)
	{
		cin>>str;
		if(search(str))
            cout<<"FOUND\n";
		else
            cout<<"NOT FOUND\n";
	}
	del(root);

	return 0;
}
