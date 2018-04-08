#include <iostream>
using namespace std;

struct Student{
	int id;
	string name;
	double gpa;
	Student* link;
};
int main(){
	// Declaring Variables
	int sId;
	string sName;
	double sGpa;
	string cont = "y";

	// Declareing Nodes
	Student* head;
	Student* current;
	Student* newnode;

	// First node
	cout << "Enter ID: ";
	cin >> sId;
	cout << "Enter Name: ";
	cin >> sName;
	cout << "Enter GPA: ";
	cin >> sGpa;

	newnode = new Student;
	head = newnode;
	current = head;

	current->link = NULL;
	current->id = sId;
	current->name = sName;
	current->gpa = sGpa;
	
	cout << "Add more? (y/n)";
	cin >> cont;
	while(cont != "n"){
		cout << "Enter ID: ";
		cin >> sId;
		cout << "Enter Name: ";
		cin >> sName;
		cout << "Enter GPA: ";
		cin >> sGpa;

		// Create new student
		newnode = new Student;
		// Link previous node to this new node
		current->link = newnode;
		// Set current node to new node
		current = newnode;

		current->link = NULL;
		current->id = sId;
		current->name = sName;
		current->gpa = sGpa;

		cout << "Add more? (y/n)";
		cin >> cont;
	}
	
	current = head;
	while(current != NULL){
		cout << current->id << " " << current->name << " " << current->gpa << "->";
		current = current->link;
	}

	return 0;
}