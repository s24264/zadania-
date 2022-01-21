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
		name = a;
		surname = b;
		copy(c.begin(), c.end(), back_inserter(marks));
	}
};

float getBeS(Student a)
{
	int result=0;
	for(int i=0; i<a.marks.size(); ++i)
	{
		result=result+a.marks[i];
	}
	return result / a.marks.size();
}

Student get_best_student(vector<Student> vec)
{
	int max = getBeS(vec[0]);
	int index = 0;
	for(int i=1; i<vec.size(); ++i)
	{
		if(max<getBeS(vec[i]))
		{
			max<getBeS(vec[i]);
			index = i;
		}
	}
	return vec[index];
}

auto main() -> int
{
	Student student1 = Student("Piotr", "Prabucki", {3,4,4});
	Student student2 = Student("Marek", "Jarowski", {3,4,4,5});
	Student student3 = Student("Maciek", "Gruszko", {3,4,4,3});
	Student student4 = Student("Sebastian ", "Otto ", {3,3,3,10});

	vector<Student> vectorOfStudents={student1,student2,student3,student4};
	cout << get_best_student(vectorOfStudents).name << 		   	        get_best_student(vectorOfStudents).surname << 			   getBeS(get_best_student(vectorOfStudents)) << endl;
	return 0;
}




