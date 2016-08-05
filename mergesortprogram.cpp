#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "vectorutils.h"
#include "mergesort.h"

using std::cin;
using std::cout;
using std::endl;

using std::vector;

using std::srand;
using std::time;
using std::rand;

constexpr vector<int>::size_type NUMBER_COUNT = 256;
constexpr unsigned int NUMBER_RANGE = 65536;

int main(){
	vector<int> numbers_to_sort;

	srand(time(nullptr));

	for(vector<int>::size_type i=0;i<NUMBER_COUNT;i++){
		numbers_to_sort.push_back(rand() % NUMBER_RANGE);
	}

	cout << "Unsorted list: " << endl;
	print_vector(cout, numbers_to_sort) << endl << endl;

	cout << "Sorting" << endl << endl;
	mergesort(numbers_to_sort);

	cout << "Sorted List" << endl;
	print_vector(cout, numbers_to_sort) << endl;

	return 0;
}
