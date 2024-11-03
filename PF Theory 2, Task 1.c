#include <stdio.h>

    int main()
    {
    	int number,elements,min,secondMin,intMax;
    	int arr[5]={};
    	
    	printf("Enter the Number of Elements bwt(1-5) :");
    	scanf("%d" ,&number);
    	
    	if(number<1 || number>5) {
    		printf("Invalid Input");
		}
		
    	for(int i=0; i<number; i++) {
    		printf("Enter Elements :");
    		scanf("%d" ,&elements);
    		arr[i] = elements;
        }
    	min=intMax;
    	secondMin=intMax;
    	for(int i=0; i<number; i++) {
    		if(arr[i] < min) {
    			secondMin = min;
    			min=arr[i];
			}
			else if(arr[i] < secondMin && arr[i]!=min) {
				secondMin=arr[i];
			}
		}
	
		    if (secondMin == intMax) {
             printf("There is no second minimum number (all elements may be the same).\n");
            }
			else {
			 printf("The Second Smallest Element in the Array is :%d" ,secondMin);
		    }
	return 0;
	}