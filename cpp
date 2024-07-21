#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	int age;
	double cgpa;
}stu_t;

int main(void)
{
	FILE* inp = fopen("stu.bin", "rb");
	if (inp == NULL)
		printf("This file does not exist!");
	else
	{
		int choice;
		stu_t students;
		int x;
		int i = 0;

		printf("1) Go to record X from top\n");
		printf("2) Move X records ahead\n");
		printf("3) Go X records back from bottom\n");
		printf("4) Exit\n");

		printf("Enter your choice: ");
		scanf("%d", &choice);

		while (choice != 4 && choice <= 4 && choice >=1 )
		{
			switch (choice)
			{
			case 1:
				printf("Enter x: ");
				scanf("%d", &x);
				fseek(inp, (x-1) * sizeof(stu_t), SEEK_SET);
				break;
			case 2:
				printf("Enter x: ");
				scanf("%d", &x);
				fseek(inp,  (x-1) * sizeof(stu_t), SEEK_CUR);
				break;
			case 3:
				printf("Enter x: ");
				scanf("%d", &x);
				fseek(inp, -x * sizeof(stu_t), SEEK_END);
				break;
			}

			fread(&students, sizeof(stu_t), 1, inp);
			printf("%s %d %f\n", students.name, students.age, students.cgpa);

			printf("Enter your choice: ");
			scanf("%d", &choice);
		}
	}
}
