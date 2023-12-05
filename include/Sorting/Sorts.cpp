#pragma once
#include <iostream>
#include <algorithm>
#include <cstdlib> 
#include <stdexcept>
#include <vector>
using namespace std;
namespace sorting {

	struct stats {
		size_t comparison_count = 0;
		size_t copy_count = 0;
	};

};