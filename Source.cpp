#include<iostream>
#include<time.h>
#include<thread>

using namespace std;

void fact(int lim)
{
	int nNum = 0, i = 0, j = 0 ;
	nNum = lim;
	//nNum = tar / 10;
	int nL = nNum;
	int reset_i = 0;

	clock_t start = clock();

	int* mptr = NULL;
	mptr = (int*)malloc(nNum * sizeof(int));
	int nLimit = 6;

	for (i = 0; i < nNum ; i++)
	{
		mptr[i] = nNum - i;
	}
	int* aptr = NULL;
	aptr = (int*)calloc((nNum * nLimit) , sizeof(int));
	int* bptr = NULL;
	bptr = (int*)calloc((nNum * nLimit) , sizeof(int));

	/*for (i = 0; i < nNum * nLimit; i++)
	{
		bptr[i] = NULL;
	}
	for (i = 0; i < nNum * nLimit; i++)
	{
		aptr[i] = NULL;
	}*/

	int nDig = 0;
	i = reset_i;

	while (((nNum % 10) != 0), i <= nDig)
	{
		bptr[i] = nNum % 10;
		nNum /= 10;
		nDig++;
		i++;
		if (nNum == 0)
		{
			break;
		}
	}

	int nrem = 0, nquo = 0;
	nNum = nL;
	int nround = 0;
	int ncount = 0;
	int nz = 0;
	int nxt = 0;
	int ny = 0;

	for (i = 0,j = 0; i < nNum - 1; i++)
	{
		ncount = 0;
		nround = 0;
		nxt = mptr[i + 1];
		while (true)
		{
			nxt = nxt / 10;
			ncount++;
			if (nxt == 0)
			{
				break;
			}
		}
		nz = nDig + ncount + ny;
		while (*bptr >= 0 && j < nz)
		{
			nDig = 0;
			aptr[j] = ((bptr[j] * mptr[i + 1]) + nquo) % 10;
			nrem = ((bptr[j] * mptr[i + 1]) + nquo) % 10;
			nquo = ((bptr[j] * mptr[i + 1]) + nquo) / 10;
			
			if (nrem == 0 && nquo == 0 && j == nz - 1)
			{
				break;
			}
			nround++;
			j++;
		}
		ny = nround;
		//nz = ncount + nround;
		int ni = i;
		for (i = 0; i < nround; i++)
		{
			bptr[i] = aptr[i];
		}
		i = ni, j = 0;
	}
	j = 0;
	
	int no_of_dig = 0;

	clock_t end = clock();
	double time = (end - start) / CLOCKS_PER_SEC;

	printf("The Factorial is : \n\n");

	for (i = nz - 2; i >= 0; i--)
	{
		printf("%d", bptr[i]);
		no_of_dig++;
	}

	printf("\nNo of digits : %d\n\n", no_of_dig);

	/*clock_t end = clock();
	double time = (end - start) / CLOCKS_PER_SEC;*/

	printf("Execution time : %0.1lf seconds\n", time);

	free(mptr);
	free(aptr);
	free(bptr);

}
int main()
{
	/*thread t1(fact,50, 50);
	thread t2(fact,50, 40);
	thread t3(fact,50, 30);
	thread t4(fact,50, 20);
	thread t5(fact,50, 10);

	t1.join();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	t2.join();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	t3.join();											  
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	t4.join();											  
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	t5.join();											  
	std::this_thread::sleep_for(std::chrono::milliseconds(100));*/

	fact(100000);

	return 0;
}

//int main()
//{
//	int nNum = 0, i = 0, j = 0;
//
//	printf("Enter the number to find factorial : ");
//	scanf_s("%d", &nNum);
//	int nL = nNum;
//	int reset_i = 0;
//
//	clock_t start = clock();
//
//	int* mptr = NULL;
//	mptr = (int*)malloc(nNum * sizeof(int));
//	int nLimit = 6;
//
//	for (i = 0; i < nNum; i++)
//	{
//		mptr[i] = nNum - i;
//	}
//	int* aptr = NULL;
//	aptr = (int*)malloc(nNum * nLimit * sizeof(int));
//	int* bptr = NULL;
//	bptr = (int*)malloc(nNum * nLimit * sizeof(int));
//
//	for (i = 0; i < nNum * nLimit; i++)
//	{
//		bptr[i] = NULL;
//	}
//	for (i = 0; i < nNum * nLimit; i++)
//	{
//		aptr[i] = NULL;
//	}
//
//	int nDig = 0;
//	i = reset_i;
//
//	while (((nNum % 10) != 0), i <= nDig)
//	{
//		bptr[i] = nNum % 10;
//		nNum /= 10;
//		nDig++;
//		i++;
//		if (nNum == 0)
//		{
//			break;
//		}
//	}
//
//	int nrem = 0, nquo = 0;
//	nNum = nL;
//	int nround = 0;
//	int ncount = 0;
//	int nz = 0;
//	int nxt = 0;
//	int ny = 0;
//
//	for (i = 0, j = 0; i < nNum - 1; i++)
//	{
//		ncount = 0;
//		nround = 0;
//		nxt = mptr[i + 1];
//		while (true)
//		{
//			nxt = nxt / 10;
//			ncount++;
//			if (nxt == 0)
//			{
//				break;
//			}
//		}
//		nz = nDig + ncount + ny;
//		while (*bptr >= 0 && j < nz)
//		{
//			nDig = 0;
//			aptr[j] = ((bptr[j] * mptr[i + 1]) + nquo) % 10;
//			nrem = ((bptr[j] * mptr[i + 1]) + nquo) % 10;
//			nquo = ((bptr[j] * mptr[i + 1]) + nquo) / 10;
//
//			if (nrem == 0 && nquo == 0 && j == nz - 1)
//			{
//				break;
//			}
//			nround++;
//			j++;
//		}
//		ny = nround;
//		//nz = ncount + nround;
//		int ni = i;
//		for (i = 0; i < nround; i++)
//		{
//			bptr[i] = aptr[i];
//		}
//		i = ni, j = 0;
//	}
//	j = 0;
//
//	int no_of_dig = 0;
//
//	clock_t end = clock();
//	double time = (end - start) / CLOCKS_PER_SEC;
//
//	/*printf("The Factorial is : \n\n");
//
//	for (i = nz - 2; i >= 0; i--)
//	{
//		printf("%d", bptr[i]);
//		no_of_dig++;
//	}
//
//	printf("\n\nNo of digits : %d\n", no_of_dig);
//
//	clock_t end = clock();
//	double time = (end - start) / CLOCKS_PER_SEC;*/
//
//	printf("Execution time : %0.1lf seconds\n", time);
//
//	free(mptr);
//	free(aptr);
//	free(bptr);
//
//	return 0;
//}