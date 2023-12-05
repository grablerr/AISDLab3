#include <Sorts.cpp>
#include <ctime>
using namespace std;
using namespace sorting;

void static do_Bubble(){
	srand(412);
	vector<int> vector;
	size_t vector_size = 50;

	for (int i = 0; i < vector_size; ++i) {
		vector.push_back(rand() % 100);
	}

	cout << "Случайные значения в векторе:" << endl;
	for (int i = 0; i < vector.size(); ++i) {
		cout << vector[i] << " ";
	}
	cout << endl << endl;

	stats sorting_stats = BubbleSort(vector);
	cout << "Отсортированный массив (BubbleSort) :\n";
	for (int i = 0; i < vector.size(); ++i) {
		cout << vector[i] << " ";
	}
	cout << endl << endl;
	cout << sorting_stats << endl << endl << endl;
	}

void static do_Quick() {
	srand(412);
	vector<int> vector;
	size_t vector_size = 50;

	for (int i = 0; i < vector_size; ++i) {
		vector.push_back(rand() % 100);
	}

	cout << "Случайные значения в векторе:" << endl;
	for (int i = 0; i < vector.size(); ++i) {
		cout << vector[i] << " ";
	}
	cout << endl << endl;

	stats sorting_stats = QuickSort(vector);
	cout << "Отсортированный массив (QuickSort) :\n";
	for (int i = 0; i < vector.size(); ++i) {
		cout << vector[i] << " ";
	}
	cout << endl << endl;
	cout << sorting_stats << endl << endl << endl;
}

int main() {
	setlocale(LC_ALL, "ru");
	do_Bubble();
	do_Quick();
}
