
#include <iostream>
#include <vector>

namespace MyAlgorithm_lib
{
	
	struct Sort
	{
        template <typename T>
		void insertion(std::vector<T>&);
        template <typename T>
        void bubble(std::vector<T>&);
		template <typename T>
        void quickSort(std::vector<T>&, int, int);
        template <typename T>
        void heapSort(std::vector<T>& a);
	};

    struct Search
    {

    };

	template <typename T>
	void swap(T* xp, T* yp)
	{
		T temp = *xp;
		*xp = *yp;
		*yp = temp;
	}

	template<typename T>
	inline void Sort::insertion(std::vector<T>& a)
	{
        int i, key, j;
        for (i = 1; i < a.size(); i++){
            key = a[i];
            j = i - 1;

            /* Move elements of arr[0..i-1], that are
            greater than key, to one position ahead
            of their current position */
            while (j >= 0 && a[j] > key){
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = key;
        }
	}

    template<typename T>
    inline void Sort::bubble(std::vector<T>& a)
    {
		int i, j;
		for (i = 0; i < a.size() - 1; i++){
			for (j = 0; j < a.size() - i - 1; j++){
				if (a[j] > a[j + 1]){
					swap(&a[j], &a[j + 1]);
				}
			}
		}
    }

    template<typename T>
    int partition(std::vector<T>& values, int left, int right) {
        int pivotIndex = left + (right - left) / 2;
        int pivotValue = values[pivotIndex];
        int i = left, j = right;
        int temp;
        while (i <= j) {
            while (values[i] < pivotValue) {
                i++;
            }
            while (values[j] > pivotValue) {
                j--;
            }
            if (i <= j) {
                temp = values[i];
                values[i] = values[j];
                values[j] = temp;
                i++;
                j--;
            }
        }
        return i;
    }

    // left pivot usually first element, right pivot usually last element
	template<typename T>
	inline void Sort::quickSort(std::vector<T>& values, int left_pivot, int right_pivot)
	{
		if (left_pivot < right_pivot) {
			int pivotIndex = partition(values, left_pivot, right_pivot);
			quickSort(values, left_pivot, pivotIndex - 1);
			quickSort(values, pivotIndex, right_pivot);
		}
	}

    template<typename T>
    void heapify(std::vector<T>& arr, int size, int i)
    {
        int max = i; // initialize max as root
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // if left child is larger than root
        if (left < size && arr[left] > arr[max]){
            max = left;
        }

        // if right child is larger than max
        if (right < size && arr[right] > arr[max]){
            max = right;
        }

        // if max is not root
        if (max != i) {
            // swap
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
           
            // recursively heapify the affected sub-tree
            heapify(arr, size, max);
        }

    }
    template<typename T>
    inline void Sort::heapSort(std::vector<T>& a)
    {
        int size = a.size();
        // build heapSort (rearrange array)
        for (int i = size / 2 - 1; i >= 0; i--){
            heapify(a, size, i);
        }

        // one by one extract an element from heapSort
        for (int i = size - 1; i >= 0; i--){
            // move current root to end
            int temp = a[0];
            a[0] = a[i];
            a[i] = temp;
           
            // call max heapify on the reduced heapSort
            heapify(a, i, 0);
        }
    }

}