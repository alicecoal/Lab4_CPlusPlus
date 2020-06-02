//---------------------------------------------------------------------------

#ifndef StackH
#define StackH

template <class T>
class Stack
{
	public:
	struct Vertex
	{
		T value;
		Vertex* prev;
	};
	Vertex* current;

public:

	Stack()
	{
		current = nullptr;
	}

	~Stack()
	{
		while(current != nullptr)
			pop_back();
	}

	//
	Stack(const Stack<T> &x)
	{
		current = nullptr;
		Vertex* q = x.current;
		while(q != nullptr)
		{
			this->push_back(q->value);
			q = q->prev;
		}
	}

    void push_back(T x)
	{
		Vertex* q = new Vertex;
		q->prev = current;
		q->value = x;
		current = q;
	}

	T pop_back()
	{
		if (current == nullptr) ShowMessage("ERROR");
		T y = current->value;
		Vertex* q = current;
		current = current->prev;
		delete q;
		return y;
	}

	void rev()
	{
		Vertex* e = nullptr;
		Vertex* q = current;
		while(q != nullptr){
			Vertex* y = q->prev;
			q->prev = e;
			e = q;
			q = y;
		}
		current = e;
	}

};

//---------------------------------------------------------------------------
#endif
