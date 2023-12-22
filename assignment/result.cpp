#include <iostream>
#include <vector>
using namespace std;

class node{
private:
  string name; // state node name

  bool transited; // for syncronization
  bool state; // 0: deactivated, 1: activated
  bool isTerminal; // 0: terminal, 1: non-terminal
  int cnt;

  char match; // target character for matching

  vector<node*> next; // next link 

public:
  void init(const string &_name, bool _isTerminal, char _match) {
    name = _name;

    isTerminal = _isTerminal;
    match = _match;
    cnt = -1;
    state = transited = 0;
  }
  
  void setcnt(int n){
    cnt = n;
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
    if(state && (match == ch)){
      if(isTerminal){
        cout << "  >>>> accepted by " << name << endl;
      }

      for(int i = 0 ; i < next.size(); i++){
        next[i]->transition();
      }
    }
    state = 0; // deactivate this node after matching
  }
};

void test(vector<node> &s, const string &str){
  cout << "test for ' " << str << "'" << endl;

  for(int i = 0 ; i < str.length() ; i++){
    cout<< "  >> input " << str[i] << endl;
    
    // epsilon activation for s0
    s[0].transition().activation();
   
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
  for(int i = 0; i < regex.length()){
    alpha = regex[i];
    if(check(alpha) == -1){
      cout << "invalid_syntax" << endl;
      return 0;
    }
  }
  vector<node> s(regex.length());
  for(int i = 0; i < regex.length()){
    if(regex[i] == '*'){
      if(i > 0){
        
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
 
  // set test cases
  string test1 = "abc";
  string test2 = "ade";
  string test3 = "aaaaabbbbabcaaaaaadeaaaaabc";

  test(s, test1);
  test(s, test2);
  test(s, test3);
}

