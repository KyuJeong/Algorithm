template <typename T>
struct priority_queue 
{
	T arr[MAXN] = { 0 };
	int idx = 1;

	bool empty() { return idx == 1; };
	
	int size() { return idx - 1; };
	
	void push(T data) 
	{
		arr[idx++] = data;
		int cur = idx - 1;
		while (cur > 1)
		{
			if (arr[cur >> 1] > arr[cur])
				swap(arr[cur >> 1], arr[cur]);
			else break;
			cur >>= 1;
		}
	}

	void pop()
	{
		if (idx == 1) return;
		arr[1] = arr[--idx];
		int cur = 1;
		int tmp;
		while (cur << 1 < idx) 
		{
			tmp = cur;
			if (arr[cur << 1] < arr[tmp])
				tmp = cur << 1;
			if (cur << 1 | 1 < idx && arr[cur << 1 | 1] < arr[tmp])
				tmp = cur << 1 | 1;
			if (tmp == cur) break;
			swap(arr[tmp], arr[cur]);
			cur = tmp;
		}
	}

	T top()
	{
		if (idx == 1)
			arr[1] = 0;
		return arr[1];
	}
};