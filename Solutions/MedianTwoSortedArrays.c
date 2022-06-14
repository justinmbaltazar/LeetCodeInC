#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i = 0;
    int j = 0;
    int k = 0;
    int m = nums1Size + nums2Size;
    int *arr = malloc(sizeof(int) * m);
    while(i < nums1Size && j < nums2Size){
        if(nums1[i] < nums2[j]){
            arr[k] = nums1[i];
            i++;
        }
        else{
            arr[k] = nums2[j];
            j++;
        }
        k++;
    }
    while(i < nums1Size){
        arr[k] = nums1[i];
        i++;
        k++;
    }
    while(j < nums2Size){
        arr[k] = nums2[j];
        j++;
        k++;
    }
    if(m % 2 == 0){
        return (arr[m / 2 - 1] + arr[m / 2]) / 2.0;
    }
    else{
        return arr[m / 2];
    }
}

    
