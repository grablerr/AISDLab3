#include <Sorts.cpp>
#include <ctime>
using namespace std;
using namespace sorting;

void static do_Bubble(){
	srand(412);
	vector<int> test_vector1;
	size_t test_vector_size = 50;

	for (int i = 0; i < test_vector_size; ++i) {
		test_vector1.push_back(rand() % 100);
	}

	cout << "Случайные значения в векторе:" << endl;
	for (int i = 0; i < test_vector1.size(); ++i) {
		cout << test_vector1[i] << " ";
	}
	cout << endl << endl;

	stats sorting_stats1 = BubbleSort(test_vector1);
	cout << "Отсортированный массив (BubbleSort) :\n";
	for (int i = 0; i < test_vector1.size(); ++i) {
		cout << test_vector1[i] << " ";
	}
	cout << endl << endl;
	cout << sorting_stats1 << endl << endl << endl;
	}

int main() {
	setlocale(LC_ALL, "ru");
	do_Bubble();
}
