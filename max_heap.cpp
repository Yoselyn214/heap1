#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            std::cerr << "Heap vacío" << std::endl;
            return -1; // O manejar el error de alguna otra manera
        }

        int maxValue = heap[0];
        std::swap(heap[0], heap.back());
        heap.pop_back();
        heapifyDown(0);

        return maxValue;
    }

    bool isEmpty() const {
        return heap.empty();
    }
};

int main() {
    MaxHeap maxHeap;

    // Inserta elementos en el heap
    maxHeap.insert(5);
    maxHeap.insert(2);
    maxHeap.insert(10);
    maxHeap.insert(7);

    // Extrae e imprimi los elementos en orden descendente
    while (!maxHeap.isEmpty()) {
        std::cout << maxHeap.extractMax() << " ";
    }

    return 0;
}

