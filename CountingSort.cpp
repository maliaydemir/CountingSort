#include<iostream>
#include <stdlib.h>   
#include <time.h>  
using namespace std;
void display(int *array, int size) {
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
}
int getMax(int array[], int size) {
	int max = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] > max)
			max = array[i];
	}
	return max; 
}
int getMin(int array[], int size) {
	int min = array[0];
	for (int i = 1; i < size; i++) {
		if (array[i] < min)
			min = array[i];
	}
	return min; 
}
int* countingSort(int *arr,int size) {
	int fark = getMin(arr,size);
	if (fark<0)
	{
		fark = fark*-1;
	}
	else {
		fark = 0;
	}
	//eğer negatif sayı yoksa fark değerimiz 0 yapılır
	//negatif değer varsa dizieki en küçük değer fark değeri yapılır
	//min değerimiz -2 düşünürsek, fark 2 olacaktır

	const int max = getMax(arr, size)+fark;
	int *count = new int[max + 1];
	for (int i = 0; i < max+1; i++)
	{
		count[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		count[arr[i]+fark]++;
		/*örn
			-2 sayısının adedini tutabilmek için -2+2 = 0 ile dizinin en küçük elemanını 0. indiste tutarız			
		*/
	}
	display(count,max+1);

	int *sorted = new int[size];
	for (int i = 0; i < size;)
	{
		for (int j = 0; j < max+1; j++)
		{
			for (int k = 0; k < count[j]; k++)
			{
				sorted[i] = j-fark;
				i++;
				/*örn->> j=0 düşünülürse
					-2 değerini tekrar elde edebilmek için 0-fark = 0-2 = -2 sonucunu elde ederiz 
				*/
			}
		}
	}
	return sorted;
}

int main() {
	srand(time(NULL));
	const int boyut= 10;
	int* dizi = new int[boyut];
	for (int i = 0; i < boyut; i++)
	{
		dizi[i] = (rand() % 20)-10;
	}
	display(dizi, boyut);
	dizi = countingSort(dizi,boyut);
	display(dizi,boyut);
	system("pause");
}