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

	template <typename T>
	stats& QuickSort(vector<T>& vec, int start, int end) {
		stats statistics;

		int i = start;
		int j = end;
		T middle = vec[(start + end) / 2];

		do {
			while (vec[i] < middle) {
				i++;
				statistics.comparison_count++;
			}
			while (vec[j] > middle) {
				j--;
				statistics.comparison_count++;
			}

			if (i <= j) {
				custom_swap(vec[i], vec[j]);
				i++;
				j--;
				//statistics.copy_count += 3;???
				statistics.copy_count += 2;//???
			}
		} while (i <= j);

		if (j > start) {
			stats left_statistics = QuickSort(vec, start, j);
			statistics.comparison_count += left_statistics.comparison_count;
			statistics.copy_count += left_statistics.copy_count;
		}
		if (i < end) {
			stats right_statistics = QuickSort(vec, i, end);
			statistics.comparison_count += right_statistics.comparison_count;
			statistics.copy_count += right_statistics.copy_count;
		}

		return statistics;
	}

	template <typename T>
	stats& QuickSort(vector<T>& vec) {
		return QuickSort(vec, 0, vec.size() - 1);
	}

};