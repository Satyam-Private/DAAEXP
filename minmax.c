#include<stdio.h>
#include<conio.h>
typedef struct minmax
{
    int min;
    int max;
}mm;

mm minmaxdac(int size , int arr[] , int low  , int high){
    mm leftresult , rightresult , result;
    if(low == high){
        result.min = arr[0];
        result.max = arr[0];
        return result;

    }
    else if(low + 1 == high){

        if(arr[low] <= arr[high]){
            result.min = arr[low];
        }
        else{
            result.min = arr[high];
        }
        if (arr[low] > arr[high])
        {
            result.max = arr[low];
        }
        else{
            result.max = arr[high];
        }
        return result;
        
    }
    else{
        int mid = (low + high) / 2;
        rightresult = minmaxdac(size , arr , low , mid );
        leftresult = minmaxdac(size , arr , mid + 1  , high);
    }
    result.min = (rightresult.min <= leftresult.min)?rightresult.min:leftresult.min;
    result.max = (rightresult.max) > leftresult.max?rightresult.max:leftresult.max;
    return result;
    

}

int main(){
    mm result;
   int arr[] = {23 , 43 , 44 , 32, 1};
   int size  = 5;
   int low = 0; 
   int high = size - 1;
   result = minmaxdac(size , arr , low , high);
   printf("the minimum element is : %d \n" , result.min);
   printf("the maximum element is : %d" , result.max);
   
   

}