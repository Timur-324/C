#pragma once
#pragma warning(disable: 4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define studentsCount (5)
#define GRADESCOUNT (5)

typedef struct Student
{
	char* name;
	char* surname;
	char* group;
	int* grades;
} Student;

typedef struct Node
{
	Student data;
	int gradesCount;
	struct Node* next;
} Node;

int freeList(
	Node* head);

Student createStudent(
	const char* name,
	const char* surname,
	const char* group,
	const int* grades,
	int grades_count);

Node* filter_sorting_students(
	Student* students,
	int students_count,
	int grades_count,
	double min_avg);

double avgStudent(
	const int* grades,
	int count);

int compareGroups(
	const char* first_group,
	const char* second_group);

char* strDuplicate(
	const char* string);

int* copyGrades(
	const int* source,
	int count);