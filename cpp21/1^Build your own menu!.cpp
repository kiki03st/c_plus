#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

//#define clrscr() system("cls")
//#define getkey() getch()

class AbstractMenu{
	string title;
	public:
		AbstractMenu(string s) : title(s) {}
		virtual ~AbstractMenu() {}
		string getTitle() { return title; }
		virtual void command() = 0;
};

class MenuItem : public AbstractMenu{
	int id;
	public:
		MenuItem(string s, int n) : AbstractMenu(s), id(n) {}

		virtual void command() {
			cout << getTitle() << " is selected. " << endl;
			getkey();
		}
};

class PopupMenu : public AbstractMenu{
	vector<AbstractMenu*> v;
	public:
		PopupMenu(string s) : AbstractMenu(s) {}
		~PopupMenu(){
			for(int i = 0; i < v.size(); i++) delete v[i];
		}
		void addMenu( AbstractMenu* p) { v.push_back(p); }
		virtual void commant(){
			while(true){
				clrscr();
				int size = v.size();
				for(int i = 0; i <  size; i++) cout << i + 1 << ". " << v[i] -> getTitle() << endl;
				cout << "Select an item >> ";
				int cmd;
				cin >> cmd;
				if(cmd == size + 1) break;
				if(cmd < 1 || cmd > size + 1) continue;
				v[cmd - 1] -> command();
			}
		}
};

int main(){
	PopupMenu* menubar = new PopupMenu("The Venti");

	PopupMenu* p1 = new PopupMenu("매장");
	PopupMenu* p2 = new PopupMenu("포장");

	menubar -> addMenu(p1);
	menubar -> addMenu(p2);

	p1 -> addMenu( new MenuItem("아이스티", 11) );
	p1 -> addMenu( new MenuItem("아이스 아메리카노", 12) );
	p1 -> addMenu( new MenuItem("딸기라떼", 13) );

	p2 -> addMenu( new MenuItem("아이스티", 21) );
	p2 -> addMenu( new MenuItem("아이스 아메리카노", 22) );
	p2 -> addMenu( new MenuItem("딸기라떼", 23) );

	PopupMenu* p3 = new PopupMenu("결제");
	p2 -> addMenu(p3);

	p3 -> addMenu( new MenuItem("카드", 31) );
	p3 -> addMenu( new MenuItem("카카오페이", 32) );
	p3 -> addMenu( new MenuItem("삼성페이", 33) );

	menubar -> command();
	
	delete menubar;

	return 0;
}
