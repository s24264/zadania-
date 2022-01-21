#include<iostream>
#include<vector>
using namespace std;

struct Student
{
	string name;
	string surname;
	vector<float> marks;
	Student(string a, string b, vector<float> c)
	{
		name = a;
		surname = b;
		copy(c.begin(), c.end(), back_inserter(marks));
	}
};
struct Group
{
	string nameOfGroup;
	vector<Student> vectorOfStudents1;
	Group(string a, vector<Student> b)
	{
		nameOfGroup = a;
		copy(b.begin(), b.end(), back_inserter(vectorOfStudents1));
	}
};

void addStudent(Group someGroup, Student someStudent)
{
	someGroup.vectorOfStudents1.push_back(someStudent);
}
auto main() -> int
{
	Student student1 = Student("Piotr","Prabucki",{3,4,5});
	Student student2 = Student("Sebastian","Otto",{3,4,4,1});
	Student student3 = Student("Maciej","Gruszko",{5,4,5});
	Student student4 = Student("Marek","Jarowski",{3,5,5,3});

	vector<Student> vectorOfStudents = {student1, student2, student3, student4};
	Group myGroup = Group("My_Group", vectorOfStudents);
	return 0;
}


