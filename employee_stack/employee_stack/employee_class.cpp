#include <iostream>
#define MAX 100
#include <string>
using namespace std;

class Employee {
private:
	int id;
	string name;
public:
	void setId(int eid) {
		id = eid;
	}
	int getId() {
		return id;
	}
	void setName(const string& eName) {
		name = eName;
	}
	string getName() const {
		return name;
	}
	void display() const {
		cout << "ID: " << id << ", Name: " << name << endl;
	}
};
class StackEmployee {
private:
	int top;
	Employee arr[MAX];

public:
	StackEmployee() {
		top = -1;
	}
	void push(const Employee& emp) {
		if (top >= MAX - 1) {
			cout << "Stack Overflow" <<endl;;
			return;
		}
		arr[++top] = emp;
		cout << "Employee added"<<endl;
	}
	void pop() {
		if (top < 0) {
			cout << "Stack Underflow" << endl;
			return;
		}
		cout << "Removing Employee: ";
		arr[top--].display();
	}
	void display() {
		if (top < 0) {
			cout << "No employees to display"<<endl;
			return;
		}
		cout << "----- Employee List-----"<<endl;
		for (int i = top; i >= 0; --i) {
			arr[i].display();
		}
	}

};
int main() {
	StackEmployee st;
	Employee emp1, emp2;
	emp1.setId(101);
	emp1.setName("Lavanya");
	st.push(emp1);

	emp2.setId(102);
	emp2.setName("dora");
	st.push(emp2);

	st.display();

	st.pop();
	st.display();
	return 0;
}
