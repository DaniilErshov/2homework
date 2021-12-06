
class Example // это абстрактный родительский класс
{

protected:
    virtual void push(int n) = 0;
	virtual int pop() = 0;
};






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

class LIFO : public Example
{
    private:
	  struct Stack *stck_ptr;

    public:

		LIFO()
		{
			stck_ptr = nullptr;
		}

		virtual void push(int n)
		{
				Stack* stck_ptrNext = new Stack;
			    stck_ptrNext -> prev = stck_ptr;
				stck_ptrNext -> value = n;
				stck_ptr = stck_ptrNext;
				std::cout << "push " << stck_ptr -> value << "\n" ;
		} 
	   
		virtual int pop()
		{
			if (stck_ptr == nullptr)
			{
				std::cout << "empty\n";
				return 0;
			} else {
			  struct Stack *tmp_ptr;
			  int tmp;
			  std::cout << "pop " << stck_ptr -> value << "\n" ;
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
		}

};


class FIFO: public Example
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

		virtual void push(int n)
		{

			if (qu_ptrStart == nullptr)
			{
			   Queue* qu_ptrNext = new Queue;
			   qu_ptrStart = qu_ptrNext;
			   qu_ptrStart -> next = nullptr;
			   qu_ptrStart -> value = n;
			   qu_ptr = qu_ptrStart;
			   std::cout << "push "<< qu_ptr -> value << "\n";
			} else {
				Queue* qu_ptrNext = new Queue;
			    qu_ptr -> next = qu_ptrNext;
				qu_ptrNext -> value = n;
				qu_ptr = qu_ptrNext;
				qu_ptr -> next = nullptr;
				std::cout << "push "<< qu_ptr -> value << "\n";
			}
		} 

	    virtual int pop()
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
				  std::cout << "pop "<< qu_ptrStart -> value << "\n";
				  tmp = qu_ptrStart -> value;
				  qu_ptr = nullptr;
				  delete qu_ptrStart;
				  qu_ptrStart = nullptr;
				  return tmp;
			  } else {
				tmp_ptr = qu_ptrStart -> next; 
			    tmp = qu_ptrStart -> value;
				std::cout << "pop "<< qu_ptrStart -> value << "\n";
			    delete qu_ptrStart;
			    qu_ptrStart = tmp_ptr;
			    return tmp;
			  }
			}
		}

		 ~FIFO()
		 {
			 struct Queue *tmp_ptr;

			 while(qu_ptrStart  != qu_ptr)
			 {
				std::cout  << "ed " << qu_ptrStart-> value << ' ' << qu_ptrStart -> value << "\n";
				tmp_ptr = qu_ptrStart -> next; 
			    delete qu_ptrStart;
			    qu_ptrStart = tmp_ptr;
			 }
			 std::cout  << "ed " << qu_ptrStart-> value << ' ' << qu_ptrStart -> value << "\n";
			 qu_ptr = qu_ptrStart;
			 delete qu_ptr;
		 }
};