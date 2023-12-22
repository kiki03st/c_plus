#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;

class node{
private:
  string name; // state node name

  bool transited; // for syncronization
  bool state; // 0: deactivated, 1: activated
  bool isTerminal; // 0: terminal, 1: non-terminal
  bool loop;
  int start;
  int end;
  int parent;
  int cnt;

  char match; // target character for matching

  vector<node*> next; // next link 

public:
  void init(const string &_name, bool _isTerminal, char _match) {
    name = _name;

    isTerminal = _isTerminal;
    match = _match;
	loop = 0;
	start = 0;
	end = 0;
	cnt = 0;
    state = transited = 0;
  }
  char getmatch(){
	  return match;
  }

  void setpt(int num){
	  parent = num;
  }
  int getpt(){
	  return parent;
  }
  void setterminal(bool n){
	  isTerminal = n;
  }
  void setcnt(int n){
    start = n;
	end = numeric_limits<int>::max();
  }
  void setcnt(int a, int b){
	  start = a;
	  end = b;
  }
  void setloop(){
	  loop = 1;
  }

  void addNode(node *_next){
    next.push_back(_next);
  }
 
  // for syncronization
  node& transition() { 
    transited = 1; 
    return *this;
  }
  void activation(){
    state = transited;
    transited = 0;
  }

  void input(const char &ch){
    if(state && (match == ch || match == '.')){
      if(isTerminal){
        cout << "  >>>> accepted by " << name << endl;
      }

      for(int i = 0 ; i < next.size(); i++){
		  if(start == 0 && end == 0 || cnt > end){
			next[i]->transition();
		  }
      }
    }
    state = 0; // deactivate this node after matching
  }
  vector<node*> next_node(){
	  /*
	  cout << "next node : " << endl;
	  for(int i = 0; i < next.size(); i++){
		cout << next[i] -> match << endl;
	  }
*/
	  return next;
  }
};

void test(vector<node> &s, const string &str){
  cout << "test for ' " << str << "'" << endl;

  for(int i = 0 ; i < str.length() ; i++){
    cout<< "  >> input " << str[i] << endl;
    // epsilon activation for s0
	vector<node*> b = s[0].next_node();
	int cnt = 0;
	for(int i = 1; i < s.size(); i++){
		if(s[i].getpt() == 0){
			s[i].transition().activation();
		}
	}
	/*
	for(auto i : s[0].next_node()){
	  i -> transition().activation();
	}
	*/

    // give ch all nodes
    for(int j = 0 ; j < s.size(); j++)
      s[j].input( str[i] );
    
    // determine transited state
    for(int j = 0 ; j < s.size(); j++)
      s[j].activation();
  }
  cout << endl;
}

int check(char alpha){
  if(alpha >= 'a' && alpha <= 'z' || alpha >= 'A' && alpha <= 'Z') return 0;
  else if(alpha == '.' || alpha == '*' || alpha == '{' || alpha == ',' || alpha == '}' || alpha == '|' || alpha == '+') return 1;
  return -1;
}

int main(){
  cout << "regex:";
  string regex;
  cin >> regex;
  char alpha;
  for(int i = 0; i < regex.length(); i++){
    alpha = regex[i];
    if(check(alpha) == -1){
      cout << "invalid_syntax" << endl;
      return 0;
    }
  }
  vector<node> s(regex.length());
  s[0].init("s0", 0, '@');
  stringstream ss(regex);
  string tmp;
  int cnt = 1, num = 1;
  while(getline(ss, tmp, '|')){
	  for(int i = 0; i < tmp.length(); i++){
		  if(check(tmp[i]) == 0){
			  if(i == 0){
				  bool loop = 1;
				  for(int j = 0; j < s.size(); j++){
					  if(s[j].getmatch() == tmp[i]){
						  loop = 0;
						  num = j;
						  break;
					  }
				  }
				  if(loop){
					  s[cnt].init("s" + to_string(cnt), 0, tmp[i]);
					  s[cnt].setpt(0);
					  s[0].addNode(&s[cnt]);
					  num = cnt;
					  cnt++;
				  }
			  }
			  else{
				  s[cnt].init("s" + to_string(cnt), 0, tmp[i]);
				  s[num].addNode(&s[cnt]);
				  s[cnt].setpt(num);
				  num = cnt;
				  cnt++;
			  }
		  }
		  else if(tmp[i] == '.'){
			  s[cnt].init("s" + to_string(cnt), 0, tmp[i]);
			  if(i == 0){
				  s[0].addNode(&s[cnt]);
				  s[cnt].setpt(0);
			  }
			  else{
				s[num].addNode(&s[cnt]);
				  s[cnt].setpt(num);
			  }
			  num = cnt;
			  cnt++;
		  }
		  else if(tmp[i] == '*'){
			  s[cnt - 1].setloop();
			  s[cnt - 1].setcnt(0);
		  }
		  else if(tmp[i] == '+'){
			  s[cnt - 1].setloop();
			  s[cnt - 1].setcnt(1);
		  }
		  else if(tmp[i] == '{'){
			  int a = tmp[i + 1] - '0';
			  int b = tmp[i + 3] - '0';
			  s[cnt - 1].setloop();
			  s[cnt - 1].setcnt(a, b);
		  }
	  }
	  s[cnt - 1].setterminal(1);
  }


/*				
        
  // set nodes (name, terminal, match)
  s[0].init("s0", 0, 'a'); 
  s[1].init("s1", 0, 'b');
  s[2].init("s2", 1, 'c');
  s[3].init("s3", 0, 'd');
  s[4].init("s4", 1, 'e');
 
  // set links
  s[0].addNode(&s[1]);
  s[0].addNode(&s[3]);
  s[1].addNode(&s[2]);
  s[3].addNode(&s[4]);
 
  */
  // set test cases
  string test1 = "abc";
  string test2 = "ade";
  string test3 = "aaaaabbbbabcaaaaaadeaaaaabc";
  string test4 = "abcdef";


  test(s, test1);
  test(s, test2);
  test(s, test3);
  test(s, test4);

}

