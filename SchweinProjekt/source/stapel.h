class stapel
{
	bool empty{ true };
public :
	bool is_empty()
	{
			return empty;
	}

	void push(int i)
	{
		empty = false;
		
	}
};