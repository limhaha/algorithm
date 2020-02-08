#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 30
//For original stack
int isEmpty_stack ();
int isFull_stack ();
void push (int);
int pop ();
//For temporary queue
int isEmpty_queue ();
int isFull_queue ();
void Insert (int);
int Delete ();

void flip ();
void findMax ();
void printResult (char[111]);

int stack[SIZE], queue[SIZE], flip_num[111];
int top, front, back;
int fixed = 0;
int count = 0;
int max, flip_idx = 0;

int main ()
{
	char line[111];
	char tmp_line[111];
	int tmp;
	char *token;
	char delimit[] = " \n";
	int i;
	int test_case = 3;

	for (i = 0; i < test_case; ++ i)
	{
		top = front = back = -1;

		gets(line);
		strcpy(tmp_line, line);

		token = strtok(tmp_line, delimit);
		while (token)
		{
			tmp = atoi(token);
			if (!(0 <= tmp && tmp <= 10))
			{
				printf("ERROR : Wrong Input\n");
				exit(1);
			}

			push(tmp);

			count ++;
			if (count >= 30)
			{
				printf("ERROR : Wrong Input\n");
				exit(1);
			}

			token = strtok(NULL, delimit);
		}
		while (isEmpty_stack() != -1)
			Insert(pop());
		while (isEmpty_queue() != -1)
			push(Delete());

		while (fixed < count)
		{
			findMax();
			if (stack[fixed] == max)
				fixed ++;
			else
				flip();
		}

		printResult(line);
	}

	return 0;
}

/*
Description : Check if stack is empty or not
Input : None
Output : If stack is empty, return -1
		 else return 1
*/
int isEmpty_stack ()
{
	if (top < fixed)
		return -1;
	else
		return 1;
}

/*
Description : Check if stack is full, or not
Input : None
Output : If stack is full, return -1
		 else, return 1
*/
int isFull_stack ()
{
	if (top >= count)
		return -1;
	else
		return 1;
}

/*
Description : Push a new key in the stack
Input : (int)key
Output : None
*/
void push (int key)
{
	stack[++ top] = key;
}

/*
Description : Pop top key from the stack
Input : None
Output : (int)Popped key
*/
int pop ()
{
	int tmp;

	tmp = stack[top --];

	return tmp;
}

/*
Description : Check if circular queue is empty, or not
Input : None
Output : If circular queue is empty, return -1
		 else, return 1
*/
int isEmpty_queue ()
{
	if (front == back)
		return -1;
	else
		return 1;
}

/*
Description : Check if circular queue is full, or not
Input : None
Output : If circular queue is full, return -1
		 else, return 1
*/
int isFull_queue ()
{
	if ((front + 1) % SIZE == back)
		return -1;
	else
		return 1;
}

/*
Description : Insert a new key in the queue
Input : (int)key
Output : None
*/
void Insert (int key)
{
	back = (back + 1) % SIZE;
	queue[back] = key;
}

/*
Description : Delete the key from the queue
Input : None
Output : (int)Deleted key
*/
int Delete ()
{
	int tmp;

	front = (front + 1) % SIZE;
	tmp = queue[front];

	return tmp;
}

/*
Description : Flip the stack by using the queue
Input : None
Output : None
*/
void flip ()
{
	if (stack[top] == max)
	{
		while (isEmpty_stack() != -1)
			Insert(pop());
		while (isEmpty_queue() != -1)
			push(Delete());

		fixed ++;
		flip_num[flip_idx ++] = fixed;
	}
	else
	{
		while (stack[top] != max)
			Insert(pop());
		Insert(pop());

		flip_num[flip_idx ++] = top + 2;
		while (isEmpty_queue() != -1)
			push(Delete());
	}

	for ()
}

/*
Description : Find the max value among remained values in the stack
Input : None
Output : None
*/
void findMax ()
{
	int i;

	for (i = fixed; i < count; ++ i)
	{
		if (i == fixed)
			max = stack[i];
		else if (max < stack[i])
			max = stack[i];
	}
}

/*
Description : Print the flip result
Input : String(char array)
Output : None
*/
void printResult (char line[])
{
	int i;

	fixed = 0;
	printf("%s(", line);
	while(isEmpty_stack() != -1)
		printf("%d ", pop());
	printf(")\n");
	for (i = 0; i < flip_idx; ++ i)
		printf("%d ", flip_num[i]);
	printf("0\n\n");

	flip_idx = 0;
}