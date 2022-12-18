#ifndef TAB_H
#define TAB_H

#include <ostream>

#define DEF_TAB_SIZE 10 
class Tab
{
public:
	Tab() { 
		tab = new int[DEF_TAB_SIZE]; 
		size = DEF_TAB_SIZE; 
	}
	Tab(const Tab& other);
	Tab(Tab&& other);

	//shouldnt operator= return Tab& instead of Tab ?
	Tab& operator=(const Tab& other);
	Tab& operator=(Tab&& other);
	~Tab();
	bool setSize(int newSize);
	int getSize() {
		return size; 
	}
	void fill();
	friend std::ostream& operator<<(std::ostream& out, const Tab& table);
	
private:
	void copy(const Tab& other);
	int* tab;
	int size;
};
#endif

