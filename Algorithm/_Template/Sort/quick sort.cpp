int partition(int arr[], int first, int last) 
{
	int p = first;	int l = first;
	int r = last;
	while (l < r) 
	{
		while (arr[p] >= arr[l] && l < last)
			l++;
		while (arr[p] < arr[r])
			r--;
		if (l < r)
			swap(arr[l], arr[r]);
	}
	swap(arr[p], arr[r]);
	return r;
}

void quickSort(int arr[], int first, int last) 
{
	if (first < last) 
	{
		int s = partition(arr, first, last);
		quickSort(arr, first, s - 1);
		quickSort(arr, s + 1, last);
	}
}