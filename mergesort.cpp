#include <vector>

#include "vectorutils.h"
#include "mergesort.h"

using std::vector;

void mergesort(vector<int> &vec){
	if(vec.size() == 1) return;

	vector<int>::size_type midpoint = vec.size() / 2;
	vector<int>::iterator midpoint_iter = vec.begin() + midpoint;

	vector<int> vector_a, vector_b;

	for(auto i=vec.begin();i<midpoint_iter;++i){
		vector_a.push_back(*i);
	}
	for(auto i=midpoint_iter;i<vec.end();++i){
		vector_b.push_back(*i);
	}

	mergesort(vector_a);
	mergesort(vector_b);

	vec.clear();

	vector<int>::iterator vec_a_pos = vector_a.begin();
	vector<int>::iterator vec_b_pos = vector_b.begin();

	while(vec_a_pos != vector_a.end() || vec_b_pos != vector_b.end()){
		if(vec_a_pos == vector_a.end()){
			vec.push_back(*(vec_b_pos++));
		}else if(vec_b_pos == vector_b.end()){
			vec.push_back(*(vec_a_pos++));
		}else if(*vec_a_pos < *vec_b_pos){
			vec.push_back(*(vec_a_pos++));
		}else{
			vec.push_back(*(vec_b_pos++));
		}
	}

}
