#include<stdio.h>

int binary_search(int* a, int k,int sz)
{
	
	int left = 0;
	int right = sz - 1;


	
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] < k)
		{
			left = mid + 1;
		}
		else if (a[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(a) / sizeof(a[0]);
	int k;
	scanf_s("%d", &k);

	int ret = binary_search(a, k,sz);

	if (ret != -1)
		printf("找到了，是第%d个元素。", ret + 1);
	else
		printf("数组中没有与之相同的元素。");


	return 0;
}