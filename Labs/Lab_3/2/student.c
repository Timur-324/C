#include "student.h"

int compareGroups(
	const char* first_group,
	const char* second_group)
{
	if(first_group == NULL || second_group == NULL){return -1;}

	return strcmp(first_group, second_group);
}

char* strDuplicate(
	const char* string)
{
	if (string == NULL)
	{
		return NULL;
	}

	char* copy = (char*)malloc(strlen(string) + 1);
	if (copy == NULL)
	{
		return NULL;
	}

	strcpy(copy, string);
	return copy;
}

int* copyGrades(
	const int* source,
	int count)
{
	if (source == NULL || count == 0){return (int *)NULL;}

	int* dest = (int*)malloc(count * sizeof(int));

	if (dest == NULL)
	{
		return (int*)NULL;
	}

	memcpy(dest, source, (count * sizeof(int)));
	return dest;
}

double avgStudent(
	const int* grades,
	int count)
{
	if (count == 0 || grades == NULL)
	{
		return (double)0;
	}

	double summary = 0.0;
	int i;

	for (i = 0; i < count; i++)
	{
		summary += grades[i];
	}

	return (summary / count);
}

Student createStudent(
	const char* name,
	const char* surname,
	const char* group,
	const int* grades,
	int grades_count)
{
	if
	( 
		name == NULL || 
		surname == NULL || 
		group == NULL || 
		grades == NULL || 
		grades_count == 0
	)
	{
		return (Student){0};
	}
	Student newStudent;
	if
	(
		(newStudent.name = strDuplicate(name)) == NULL
	)
	{
		return (Student){0};
	}
	if
	(
		(newStudent.surname = strDuplicate(surname)) == NULL
	)
	{
		return (Student){0};
	}
	if
	(
		(newStudent.group = strDuplicate(group)) == NULL
	)
	{
		return (Student){0};
	}
	if((newStudent.grades = copyGrades(grades, grades_count)) == (int*)NULL)
	{
		return (Student){0};
	}
	return newStudent;
}

Node* filter_sorting_students(
	Student* students,
	int students_count,
	int grades_count,
	double min_avg)
{
	if (students == NULL || grades_count == 0 || students_count == 0 || min_avg  < 0)
	{
		return (Node*)NULL;
	}

	Node* head = NULL;

	int i;
	double avg;

	for (i = 0; i < students_count; i++)
	{
		if((avg = avgStudent(students[i].grades, grades_count)) == (double)0)
		{
			return (Node*)NULL; 
		}
		if (avg >= min_avg)
		{
			Node* newNode = (Node*)malloc(sizeof(Node));
			if (newNode == NULL)
			{
				return (Node*)NULL;
			}

			if(
				(newNode->data.name = strDuplicate(students[i].name)) == (char*)-1 ||
				(newNode->data.name = strDuplicate(students[i].name)) == (char*)1
			)
			{
				return (Node*)NULL;
			}
			if(
				(newNode->data.surname = strDuplicate(students[i].surname)) == (char*)-1 ||
				(newNode->data.surname = strDuplicate(students[i].surname)) == (char*)1
			)
			{
				return (Node*)NULL;
			}
			if(
				(newNode->data.group = strDuplicate(students[i].group)) == (char*)-1 ||
				(newNode->data.group = strDuplicate(students[i].group)) == (char*)1
			)
			{
				return (Node*)NULL;
			}

			if((newNode->data.grades = copyGrades(students[i].grades, grades_count)) == (int*)NULL)
			{
				return (Node*)NULL;
			}

			newNode->next = NULL;

			if (!head || compareGroups(newNode->data.group, head->data.group) < 0)
			{
				newNode->next = head;
				head = newNode;
			}
			else
			{
				Node* current = head;
				while(current->next != NULL && 
					compareGroups(newNode->data.group, current->data.group) >= 0)
				{
					current = current->next;
				}
				newNode->next = current->next;
				current->next = newNode;
			}
		}
	}

	return head;
}

int freeList(
	Node* head)
{
	if (head == NULL)
	{
		return -1;
	}

	while (head != NULL)
	{
		Node* temp = head;
		head = head->next;

		free(temp->data.name);
		free(temp->data.surname);
		free(temp->data.group);
		free(temp->data.grades);
		free(temp);
	}

	return 0;
}