#include<iostream>
#include<algorithm>
#include<vector>
#include <fstream>
using namespace std;

int COUNT =0;

void maxheap (int arr[],int i,int n){
int largest = i;
int left = i*2 +1;
int right = i*2 + 2 ;

if ((left<n)&&(arr[left]>arr[largest]) )
{
largest = left ;
}
if ((right<n)&&(arr[right]>arr[largest]))
	largest=right;
if (largest != i)
{
	COUNT ++;
	swap(arr[i],arr[largest]);
	maxheap(arr,largest,n);
}
}
void heapSort(int arr[] , int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        maxheap(arr, i, n);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
		if (i!=0)
		COUNT++;
        // call max heap on the reduced heap
		maxheap(arr, 0, i);
    }
}
int main(void){
	
	int y;
	int num=0;
	ifstream file;
	ifstream numfile;
	ofstream outfile;
  
	outfile.open("output.txt",ios:: app);
	file.open("unsorted.txt",ios::in);
	numfile.open("unsorted.txt",ios::in);
	while (numfile >> y) {
		
		num++;
}
int * arr = new int [num];
int i=0;
	while (file >> y) {
		arr[i]=y;
		i++;
}
	int hh;

 heapSort(arr, num);
  
	
	for(int i=0;i<num;i++)
		outfile<<arr[i]<<endl;
	outfile<<COUNT<<endl;
system("pause");
return 0;
}
