#include <vector>

#include "vectorutils.h"
#include "mergesort.h"

using std::vector;

void mergesort(vector<int> &vec){
	//find midpoints in array
	vector<int>::size_type midpoint = vec.size() / 2;
	vector<int>::iterator midpoint_iter = vec.begin() + midpoint;

	//split main array into two subarrays
	vector<int> vector_a, vector_b;

	for(auto i=vec.begin();i!=midpoint_iter;++i){
		vector_a.push_back(*i);
	}
	for(auto i=midpoint_iter;i!=vec.end();++i){
		vector_b.push_back(*i);
	}

	//if needed, sort subarrays
	if(vector_a.size() > 1) mergesort(vector_a);
	if(vector_b.size() > 1) mergesort(vector_b);

	//merge now sorted subarrays
	vec.clear();

	vector<int>::iterator vec_a_pos = vector_a.begin();
	vector<int>::iterator vec_b_pos = vector_b.begin();

	while(vec_a_pos != vector_a.end() || vec_b_pos != vector_b.end()){ //I am especially interested in ways to improve this loop
		if(vec_a_pos == vector_a.end()){
			vec.push_back(*(vec_b_pos++));
		}else if(vec_b_pos == vector_b.end()){
			vec.push_back(*(vec_a_pos++));
		}else{
			vec.push_back(*vec_a_pos < *vec_b_pos ? *(vec_a_pos++) : *(vec_b_pos++));
		}
	}
}
