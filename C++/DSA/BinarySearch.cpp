#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){

    int start = 0;
    int end = n-1;

    int mid = start + (end-start)/2 ;

    while(start<=end){

        if(arr[mid] == key){
            return mid;
        }
        else if( arr[mid] < key ){
            start =mid+1;
        }else{
            end = mid-1;
        }

        mid = start + (end-start)/2 ;
    }
    return -1;
}

int main(){

    int arr[5] = { 3, 4, 6, 7 ,9};
    int brr[6] = {8, 10, 12 ,14, 18, 22};

    int odd = binarySearch(arr,5,7);
    int even = binarySearch(brr,6,10);

    cout<<"For odd array : " <<odd<<endl;
    cout<<"For even array : " <<even<<endl;

    return 0;
}
