#include <iostream>
using namespace std;


void printing(int arr[],int n)
{
    int *pointer=arr;
    int i=0;
    int minimum=*pointer;
    while(i<n)
    {
        minimum=min(minimum,(*pointer));
        pointer+=1;
        i++;
    }
    cout<<"The minimum integer in the array is: ";
    cout<<minimum<<'\n';
}


int main()
{
    int n;
    cout<<"enter number of elements in the array: ";
    cin>>n;

    int arr[n];
    int *ptr=arr;
    cout<<"\nenter the elements separated by spaces: ";
    for(int i=0;i<n;i++)
    {
        cin>>(*ptr);
        ptr++;
    }
    printing(arr,n);
    return 0;
}
