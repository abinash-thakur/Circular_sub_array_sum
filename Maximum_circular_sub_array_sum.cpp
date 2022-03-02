//To find the circular subarray sum

//The toatal time complexcity of the solution is O(n)
#include <iostream>
using namespace std;
int maximum_Sum(int[], int);
int main()
{ 
    //n is length of the array
    //mass=maximum subarray sum
    //css=circular subarray sum
    //arraySum=total array sum
    int n,mass,css,arraySum; 
    cout << "Enter the length of the array: ";
    cin >> n;
    int arr[n];
    cout << "\n"
         << "Enter the element in the array: ";

    //This loop is used to enetr the array elemnt
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mass=maximum_Sum(arr, n);

    //if all the number are negative in the array then no need to find the circular subarray sum beacause maximum sub array sum is give the circular sub array sum.so I use this if condition below.
    if(mass<0)
    cout<<"\n"<<"The maximum sum circular sub array is: "<<mass;
    else
    {
        //In this block we find the circular sub array sum
        //first we find the total sum of an array
        //them we Inverted the array element
        //I inverted the array element so when i call the maximu_sum(arr,n) method i get the minimum sum sub array
        //I invert the array so insted of subtracting from totalArraySum to minimu sum sub array, i will do adition and then get the value of circular sub array sum.
        //then we compair the maximum sub array sum and circular sub array sum,those value are grater that is the result of maximum circular sub array sum.
        arraySum=0;
        for(int i=0;i<n;i++)
        {
            arraySum+=arr[i];
            arr[i]=-arr[i];
        }
        css=arraySum+maximum_Sum(arr,n);

        (mass>css)?cout<<"\n"<<"The circular subarray sum is: "<<mass:cout<<"\n"<<"The circular subarray sum is: "<<css;
    }
    return 0;
}
int maximum_Sum(int arr[], int n)
{
    int res = arr[0];
    int maximum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] +res) > arr[i])
            res = arr[i] + res;
        else
            res = arr[i];
        if (res > maximum)
            maximum = res;
    }
    return maximum;
}