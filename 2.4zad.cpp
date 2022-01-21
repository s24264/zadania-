#include <iostream>
#include <vector>
using namespace std;
struct Student
{
	string name;
	string surname;
	vector<float> marks;
	Student(string a, string b, vector<float> c)
	{
		name=a;
		surname=b;
		copy(c.begin(), c.end(), back_inserter(marks));
	}
};
void average_of(Student stud1)
{
	float result = 0;
	for(int i=0; i<stud1.marks.size(); ++i) {result=result+stud1.marks[i];}
	cout << "Srednia ocena ucznia" << stud1.name << " " << stud1.surname << "=" << 
	result / stud1.marks.size() << endl;
}
auto main() -> int
{
	Student student1 = Student("Piotr","Prabucki",{5,3,3,4,4});
	average_of(student1);
	return 0;
}	
