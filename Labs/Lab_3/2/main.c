#include "student.h"

int main()
{
	int grades1[] = { 4, 5, 5, 4, 3 };
	int grades2[] = { 5, 5, 5, 5, 5 };
	int grades3[] = { 2, 4, 2, 2, 3 };
	int grades4[] = { 5, 4, 5, 5, 5 };
	int gardes5[] = { 5, 5, 5, 5, 5 };

	double avg;

	Student students[studentsCount];

	students[0] = createStudent("A", "B", "ITIT-125", grades1, GRADESCOUNT);
	students[1] = createStudent("C", "D", "ITPM-125", grades2, GRADESCOUNT);
	students[2] = createStudent("E", "F", "ITIT-525", grades3, GRADESCOUNT);
	students[3] = createStudent("G", "H", "ITIT-12", grades4, GRADESCOUNT);
	students[4] = createStudent("I", "J", "IIT-31", gardes5, GRADESCOUNT);			

	Node* forwardList = filter_sorting_students(students, studentsCount, GRADESCOUNT, 4.0);

	if (forwardList == (Node*)NULL)
	{
		return -1;
	}
	printf("Students with a grade point average greater than 4.0: \n");

	Node* forWhilePrint = forwardList;

	while (forWhilePrint != NULL)
	{
		avg = avgStudent(forWhilePrint->data.grades, GRADESCOUNT);
		printf("%s %s | group: %s | avg score: %.2f\n", forWhilePrint->data.name, forWhilePrint->data.surname, forWhilePrint->data.group, avg);
		forWhilePrint = forWhilePrint->next;
	}

	freeList(forwardList);

	int i;
	for (i = 0; i < studentsCount; i++)
	{
		free(students[i].name);
		free(students[i].surname);
		free(students[i].group);
		free(students[i].grades);
	}
	return 0;
}