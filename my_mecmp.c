#include<stdio.h>
#include<assert.h>
#include<string.h>

int my_memcmp(const void* dest, const void* src, size_t num)
{
	assert(dest);//检测是否未空地址
	assert(src);
	int i = 0;
	for (i = 0; i < num; i++)//逐字节对比
	{
		if (*((char*)dest + i) > * ((char*)src + i))//dest比src大时，返回1
			return 1;
		else if (*((char*)dest + i) < *((char*)src + i))//dest比src小时，返回-1
			return -1;
	}

	if (num == i)//确认是否完成比较
		return 0;

}


int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 1,2,43,545,61};

	int ret = 2;
	ret = my_memcmp(arr1, arr2, 4);

	printf("%d\n", ret);

	return 0;
}