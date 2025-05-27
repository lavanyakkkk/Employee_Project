#include <iostream>
#include <string>
using namespace std;

const int max_emp = 1000;

class Employee {
private:
	int id;
	string name;
	float salary;
public:
	Employee(int i, const string& n, float s) {
		id = i;
		name = n;
		salary = s;
	}
	void setId(int i) {
		id = i;
	}
	int getId() const{
		return id;
	}
	void setName(const string& n) {
		name=n;
	}
	string getName() const {
		return name;
	}
	void setSalary(float s) {
		salary = s;
	}
	float getSalary() const {
		return salary;
	}
	void display() const {
		cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
	}
};

struct node{
	Employee emp;
	node* next;
};

node* head =nullptr;

int total_employee = 0;

void addEmployee(int id, string& name, float salary) {
	if (total_employee >= max_emp) {
		cout << "we reach the maximum of employee" << max_emp << endl;
		return;
	}
	Employee e(id, name, salary);
    node* newNode = new node{ e, nullptr };

	if (head == nullptr) {
		head = newNode;
	}
	else {
		node* temp = head;
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = newNode;
	}

	total_employee++;
	cout << "Employee add: " << name << endl;
}


void displayAll() {
	if (head == nullptr) {
		cout << "No employees to display.\n";
		return;
	}

	cout << "\n--- All Employees ---\n";
	node* temp = head;
	while (temp != nullptr) {
		temp->emp.display();
		temp = temp->next;
	}
}

void deleteEmployeeById(int id) {
	if (head == nullptr) {
		cout << "List is empty.\n";
		return;
	}

	node* temp = head;
	node* prev = nullptr;

	while (temp != nullptr && temp->emp.getId() != id) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == nullptr) {
		cout << "Employee with ID is not found " << id<<endl;
		return;
	}

	if (prev == nullptr)
		head = temp->next;
	else
		prev->next = temp->next;

	delete temp;
	total_employee--;
	cout << "Employee with ID " << id << " deleted." << endl;
}

void searchByName(const string& name) {
	node* temp = head;
	bool found = false;

	cout << "\n--- Search Result ---\n";
	while (temp != nullptr) {
		if (temp->emp.getName() == name) {
			temp->emp.display();
			found = true;
		}
		temp = temp->next;
	}

	if (!found) {
		cout << "No employee with name \"" << name << "\" found" << endl;
	}

}

void updateSalaryById(int id, float newSalary) {
	node* temp = head;

	while (temp != nullptr) {
		if (temp->emp.getId() == id) {
			temp->emp.setSalary(newSalary);
			cout << "Salary updated for ID " << id << endl;
			return;
		}
		temp = temp->next;
	}

	cout << "Employee with ID " << id << " not found.\n";
}


	void countEmployees() {
		cout << "Total Employees: " << total_employee << endl;
	}

	int main() {
		int choice;

		while (true) {
			cout << "---- Employee Record Menu ----"<<endl;
			cout << "1. Add Employee"<<endl;
			cout << "2. Display All Employees"<<endl;
			cout << "3. Delete Employee by ID"<<endl;
			cout << "4. Search Employee by Name"<<endl;
			cout << "5. Update Salary by ID"<<endl;
			cout << "6. Count Employees"<<endl;
			cout << "0. Exit"<<endl;
			cout << "Enter your choice: " << endl;;
			cin >> choice;

			if (choice == 0) {
				cout << "Exiting..."<<endl;
				break;
			}

			switch (choice) {
			case 1: {
				int id;
				string name;
				float salary;
				cout << "Enter ID Name Salary: ";
				cin >> id >> name >> salary;
				addEmployee(id, name, salary);
				break;
			}
			case 2:
				displayAll();
				break;
			case 3: {
				int id;
				cout << "Enter ID to delete: ";
				cin >> id;
				deleteEmployeeById(id);
				break;
			}
			case 4: {
				string name;
				cout << "Enter name to search: ";
				cin >> name;
				searchByName(name);
				break;
			}
			case 5: {
				int id;
				float salary;
				cout << "Enter ID and new salary: ";
				cin >> id >> salary;
				updateSalaryById(id, salary);
				break;
			}
			case 6:
				countEmployees();
				break;
			default:
				cout << "Invalid choice.\n";
			}
		}

		return 0;
	}







	

