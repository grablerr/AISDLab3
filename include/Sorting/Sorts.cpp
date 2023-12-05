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

	template <typename T>
	void custom_swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	};

	ostream& operator<<(ostream& os, stats& stat)
	{
		os << "comparison_count = " << stat.comparison_count << " copy_count = " << stat.copy_count;
		return os;
	}

	class ReturnClass {
	private:
		int value;
	public:
		ReturnClass() :value(0) {};
		ReturnClass(const int value) :value(value) {};
		int get_value() const {
			return this->value;
		}
		bool operator>(const ReturnClass& rhs) {
			return this->value > rhs.value;
		}
		bool operator<(const ReturnClass& rhs) {
			return !(*this > rhs);
		}
	};

	template<typename T>
	stats& BubbleSort(vector<T>& vec) {
		stats statistics;
		for (int i(0); i < (vec.size() - 1); ++i) {
			for (int j(0); j < (vec.size() - i - 1); ++j) {
				statistics.comparison_count += 1;
				if (vec[j] > vec[j + 1]) {
					custom_swap(vec[j], vec[j + 1]);
					//statistics.copy_count += 3;???
					statistics.copy_count += 2;//???
				}
			}
		}
		return statistics;
	}

};