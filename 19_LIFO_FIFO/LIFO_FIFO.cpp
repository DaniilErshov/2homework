// ConsoleApplication20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <ctime>

struct Stack
{
	int value;
	struct Stack *prev;
}; 

struct Queue
{
	int value;
	struct Queue *next;
}; 

class LIFO
{
    private:
	  struct Stack *stck_ptr;

    public:

		LIFO()
		{
			stck_ptr = nullptr;
		}

		void push(int n)
		{
				Stack* stck_ptrNext = new Stack;
			    stck_ptrNext -> prev = stck_ptr;
				stck_ptrNext -> value = n;
				stck_ptr = stck_ptrNext;
		} 
	   
		int pop()
		{
			if (stck_ptr == nullptr)
			{
				std::cout << "empty\n";
				return 0;
			} else {
			  struct Stack *tmp_ptr;
			  int tmp;
		      tmp_ptr = stck_ptr -> prev; 
			  tmp = stck_ptr -> value;
			  delete stck_ptr;
			  stck_ptr = tmp_ptr;
			  return tmp;
			}
		}
	    
	   ~LIFO()
		{
			struct Stack *tmp_ptr;
			while (stck_ptr != nullptr)
			{
			  tmp_ptr = stck_ptr -> prev; 
			  delete stck_ptr;
			  stck_ptr = tmp_ptr;
			}
			delete stck_ptr;
			std::cout << "LIFO"  << stck_ptr << "\n";
		}

};


class FIFO
{
    private:
	  struct Queue *qu_ptrStart;
	  struct Queue *qu_ptr;
    public:

		FIFO()
		{
			Queue* qu_ptrNext = new Queue;
		    qu_ptr = qu_ptrNext;
			qu_ptrStart = nullptr;
			qu_ptr -> next = nullptr;
		}

		void push(int n)
		{

			if (qu_ptrStart == nullptr)
			{
				std::cout << "new\n";
			   Queue* qu_ptrNext = new Queue;
			   qu_ptrStart = qu_ptrNext;
			   qu_ptrStart -> next = nullptr;
			   qu_ptrStart -> value = n;
			   qu_ptr = qu_ptrStart;
			   std::cout << n << "\n";
			} else {
				Queue* qu_ptrNext = new Queue;
			    qu_ptr -> next = qu_ptrNext;
				qu_ptrNext -> value = n;
				qu_ptr = qu_ptrNext;
				qu_ptr -> next = nullptr;
				std::cout << n << "\n";
			}
		} 

	    int pop()
		{
			if (qu_ptrStart  == nullptr)
			{
				std::cout << "empty\n";
				return 0;
			} else {
			  struct Queue *tmp_ptr;
			  int tmp;
			  if (qu_ptrStart == qu_ptr)
			  {
				  std::cout << "gg" << qu_ptrStart -> value << ' ' << qu_ptr -> value << "\n";
				  tmp = qu_ptrStart -> value;
				  qu_ptr = nullptr;
				  delete qu_ptrStart;
				  qu_ptrStart = nullptr;
				  std::cout << "gg" << qu_ptrStart << ' ' << qu_ptr << "\n";
				  return tmp;
			  } else {
				tmp_ptr = qu_ptrStart -> next; 
			    tmp = qu_ptrStart -> value;
			    delete qu_ptrStart;
			    qu_ptrStart = tmp_ptr;
			    std::cout << tmp << ' ' << qu_ptr -> value << "\n";
			    return tmp;
			  }
			}
		}

		 ~FIFO()
		 {
			 struct Queue *tmp_ptr;

			 while(qu_ptrStart  != qu_ptr)
			 {
				std::cout << qu_ptrStart-> value << ' ' << qu_ptr -> value << "\n";
				tmp_ptr = qu_ptrStart -> next; 
			    delete qu_ptrStart;
			    qu_ptrStart = tmp_ptr;
			 }
			 qu_ptr = qu_ptrStart;
			 delete qu_ptr;
			 std::cout << qu_ptrStart << ' ' << qu_ptr << "\n";
		 }
};


int _tmain(int argc, _TCHAR* argv[])
{
	int a;
	int b;
	LIFO stack;
	FIFO qu;
	stack.push(5);
	stack.push(4);
	stack.push(3);

	a = stack.pop();
	std::cout <<  a << "\n";
	a = stack.pop();
	std::cout <<  a << "\n";
	a = stack.pop();
	std::cout <<  a << "\n";
	a = stack.pop();
	a = stack.pop();
	stack.push(15);
	a = stack.pop();
    std::cout <<  a << "\n";
	a = stack.pop(); 

	std::cout << "\nqueue\n";

	qu.push(1);
	qu.push(2);
	qu.push(3);
	
	b = qu.pop();
	std::cout <<  b << "\n";
	b = qu.pop();
	std::cout <<  b << "\n";
	b = qu.pop();
	std::cout <<  b << "\n";
	b = qu.pop();
	b = qu.pop();

	qu.push(15);
	b = qu.pop();
	std::cout <<  b << "\n";
	b = qu.pop();
	b = qu.pop();
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	return 0;
}
