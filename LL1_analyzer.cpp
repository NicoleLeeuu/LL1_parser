#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int t,k;
/*
E'用A来代替 T'用B来代替 
*/
string ll[5][6]=
{{"err","err","TA","TA","err","err"},
{"+TA","err","err","err","e","e"},
{"err","err","FB","FB","err","err"},
{"e","*FB","err","err","e","e"},
{"err","err","a","(E)","err","err"}
};
string s;
stack<char>q;
bool IsVn(char c){
	if(c=='E'||c=='A'||c=='T'||c=='B'||c=='F') return true;
	else return false;
}
bool IsVt(char c){
	if(c=='+'||c=='*'||c=='a'||c=='('||c==')'||c=='#') return true;
	else return false;
}
bool IsVnempty(char c){
	if(c=='e') return true;
	else return false;
}
void numberc(char c){
	if(c=='E') t=0;
	else if(c=='A') t=1;
	else if(c=='T') t=2;
	else if(c=='B') t=3;
	else if(c=='F') t=4;
}
void numberr(char c){
	if(c=='+') k=0;
	else if(c=='*') k=1;
	else if(c=='a') k=2;
	else if(c=='(') k=3;
	else if(c==')') k=4;
	else if(c=='#') k=5;
}
void Analyse(){
	q.push('#');
	q.push('E');
	int i=0;
	while(i<=s.length()){
		if(q.empty()){
			cout<<"Syntax analysis is right"<<endl;
			break;
		}
		else{
			if(IsVt(q.top())){
				if(q.top()==s[i]){
					q.pop();
					i++;
					continue;
				}
				else{
					cout<<"Error on syntax analysis"<<endl;
					break;
				}
			}
			else if(IsVnempty(q.top())){
				q.pop();
			}
			else if(IsVn(q.top())){
				numberc(q.top());
	        	numberr(s[i]);
	        	if(ll[t][k]=="err"){
		    	cout<<"Error on syntax analysis"<<endl;
		    	break;
	         	}
	        	else{
		        	q.pop();
		        	string s0;
		        	s0=ll[t][k];
		        	for(int j=s0.length()-1;j>=0;j--){
		         		q.push(s0[j]);
	     	    	}
	         	}
			}
			else{
				cout<<"Error!"<<endl;
				break;
			}
		}
		
	}
}
int main()
{
	cin>>s;
	s=s+'#';
	Analyse();
 } 
