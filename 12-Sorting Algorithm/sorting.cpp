#include <iostream>

const int N = 5;

void print(int (arr)[N]){
	for(int i = 0; i<N; i++){
		if(i != N-1){
			std::cout << arr[i] << ", ";
		} else {
			std::cout << arr[i];
		}
	}
	std::cout << std::endl;
}

void selection_sort(int (arr)[N]){
	int min;
	for(int i = 0; i < N-1; i++){
		min = i;
		for(int j = i+1; j < N; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		std::swap(arr[i], arr[min]);
	}
	print(arr);
}
void bubble_sort(int (arr)[N]){
	for(int i = 0; i < N-1; i++){
		for(int j = i+1; j < N-i-1; j++){
			if(arr[j+1] < arr[j]){
				std::swap(arr[j], arr[j+1]);
			}
		}
	}
	print(arr);
}
void insertion_sort(int (arr)[N]){
	int key, j;
	for(int i = 1; i < N; i++){
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	print(arr);
}

int main(){

	int arr[N] = {13, 17, 10, 16, 3};

	std::cout << "Original List: " << "\t";
	print(arr);

	std::cout << "Selection Sort: ";
	selection_sort(arr);

	std::cout << "Insertion Sort: ";
	insertion_sort(arr);

	std::cout << "Bubble Sort: " << "\t";
	bubble_sort(arr);

	return 0;
}