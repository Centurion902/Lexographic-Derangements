#include <stdio.h>
#include <stdlib.h>

int cmp (const void * a, const void * b) {
   return (  *(int*)a-*(int*)b);
}

int findNext(int nums[], int n){

  int largest = n-1; 
  int smallest;
  int temp;
  for(int i = n-2; i>=0; i--){//Find the largest positionisuch that ai< ai+1(scan right to left)
    if(nums[i]<nums[i+1]){
      largest = i;
      i = -1;
      
    }
  }

  if(largest == n-1){
    return 0;
  }

  smallest = largest+1;
  for(int i = n-1; i> largest; i--){//Replaceaiwith the smallest value in ai+1 ... an that is bigger than the current value of ai
    if(nums[i]<nums[smallest]&&nums[i]>nums[largest]){
      smallest = i;
    }
  }

  
  temp = nums[smallest];//swaps
  nums[smallest] = nums[largest];
  nums[largest] = temp;
  qsort(nums+largest+1, n-largest-1,sizeof(int),cmp);//sorts remaining
  return 1;
}

int checkValid(int nums[], int n){
  for(int i = 0; i<n;i++){
    if(i == nums[i]){
      return 0;
    }
  }
  return 1;
}
int main(void) {
  int n, count = 1;
  printf("Enter a positive number\n");
  scanf("%d", &n);//input

  int nums[n];
  for(int i = 0; i<n; i++){//fills value
    nums[i] = i;
  }
  do{//not last one
    
    if(checkValid(nums,n)){//satisfies conditions
      printf("%d) ", count);
      
      for(int i = 0; i<n; i++){//prints value
        printf("%d, ", nums[i]+1);//been working with 0 so I just add one
        
      }
      
      printf("\n");
      count++;
    }

    
  }while(findNext(nums, n));//if cant find one returns 0 (percived as false)

  return 0;
}

