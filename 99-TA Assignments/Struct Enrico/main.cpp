#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student{
	string student_name;
	int student_id;
	int student_number;
};

int main(){
	int option, count = 0;
	vector<Student> students;

	cout << "Options: " << endl << "[1] Insert student" << endl << "[2] Remove student" << endl << "[3] Show students" << endl << "[99] End program" << endl << "Insert option: ";
	cin >> option;
	while(option != 99){
		if(option == 1){
			string name;
			int id, number;
			students.push_back(Student());
			cout << "Insert name: ";
			cin >> name;
			cout << "Insert id: ";
			cin >> id;
			cout << "Insert number: ";
			cin >> number;
			students[count].student_name = name;
			students[count].student_id = id;
			students[count].student_number = number;
			count++;
		}
		else if(option == 2){
			int index_rmv;
			cout << "Insert student index to remove: ";
			cin >> index_rmv;
			students.erase(students.begin() + index_rmv-1);
			count--;
		}
		else if(option == 3){
			cout << "(index) name, id, number" << endl;
			for(int i=0; i<students.size(); i++){
				cout << "(" << i+1 << ") " << students[i].student_name << ", " << students[i].student_id << ", " << students[i].student_number << endl;
			}
		}
		cout << "Options: " << endl << "[1] Insert student" << endl << "[2] Remove student" << endl << "[3] Show students" << endl << "[99] End program" << endl << "Insert option: ";
		cin >> option;
	}
	return 0;
}