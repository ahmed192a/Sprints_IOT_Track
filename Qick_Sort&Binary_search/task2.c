// include libraries
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// macros
#define DPRINTF(...) { fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

// types definitions
typedef unsigned char uint8_t;
typedef char int8_t;
typedef  int int32_t;
typedef unsigned int uint32_t;

// Fucntions prototypes
void swap(uint32_t *a, uint32_t *b);
uint8_t partition(uint32_t array[], uint8_t low, uint8_t high);
void quickSort(uint32_t arr[], uint8_t low, uint8_t high);
uint8_t binary_search_recursive(uint32_t arr[],uint8_t start, uint8_t end, uint32_t number);
uint8_t binary_search(uint32_t arr[], uint8_t size, uint32_t number);

// main program
int main(){
    
	uint32_t arr[]={9,1,8,2,7,3,6,4,5,0};
	
	int8_t temp[20];
	uint32_t q;
    
	quickSort(arr, 0, 4);
	// print sorted array
	for(uint8_t i = 0; i < 10;i++){
		printf("%d ", arr[i]);
	}

	DPRINTF("\n\rEnter the item you want to search for : " );
	gets(temp);
	q = atoi(temp);
	if(binary_search(arr,10,q) == -1){
		DPRINTF("\nDoesn't exist..\n");
	}
	else{
		DPRINTF("\nItem exist..\n");
	}
	return 0;

}


// Functions definitions

void swap(uint32_t *a, uint32_t *b){
	int tmp = *a;
	*a=*b;
	*b=tmp;
}
uint8_t partition(uint32_t array[], uint8_t low, uint8_t high) {
  uint32_t pivot = array[high];
  uint8_t i = (low - 1);
  for (uint8_t j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(uint32_t arr[], uint8_t low, uint8_t high) {
  if (low < high){
    uint8_t pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

uint8_t binary_search(uint32_t arr[], uint8_t size, uint32_t number){
		return binary_search_recursive(arr,0,size-1,number);
}

uint8_t binary_search_recursive(uint32_t arr[],uint8_t start, uint8_t end, uint32_t number){
	if(end<start)return -1;
	if(start == end )
	{
		if(arr[end] == number)
			return end;
		else
			return -1;
	}
	uint8_t mid = (start+end)/2;
	if(arr[mid] == number) return mid;
	if(number>arr[mid]) return binary_search_recursive(arr, mid+1, end, number);
	else return binary_search_recursive(arr, start, mid-1, number);
}