#include <iostream>
#include <vector>
using namespace std;

vector<int> linearSearch(int arr[], int size, int key) {
    vector<int> indices;  // To store positions of found elements
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    int size, key;

    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> key;

    vector<int> result = linearSearch(arr, size, key);

    if (!result.empty()) {
        cout << "Element found at indices: ";
        for (int index : result) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "Element not found in the array.\n";
    }

    return 0;
}
