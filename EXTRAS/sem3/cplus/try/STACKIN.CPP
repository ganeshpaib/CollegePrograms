#include "header.cpp"
#define MAX 10

enum boolean{TRUE,FALSE};

class Stack
{
	protected:
		int top,item;
	public:
		Stack()
		{
			top=-1;
		}

		boolean isfull()
		{
			return (top==MAX)? TRUE: FALSE;
		}

		boolean isempty()
		{
			return (top==-1)?TRUE: FALSE;
		}

		void add_item(

};