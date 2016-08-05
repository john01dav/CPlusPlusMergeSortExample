#include <iostream>
#include <vector>

#include "vectorutils.h"

using std::ostream;

using std::vector;

ostream& print_vector(ostream &out, vector<int> &vec){
	for(int n : vec){
		out << n << " ";
	}

	return out;
}
