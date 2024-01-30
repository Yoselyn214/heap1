#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
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
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            std::cerr << "Heap vacío" << std::endl;
            return -1; // O manejar el error de alguna otra manera
        }

        int minValue = heap[0];
        std::swap(heap[0], heap.back());
        heap.pop_back();
        heapifyDown(0);

        return minValue;
    }

    bool isEmpty() const {
        return heap.empty();
    }
};

int main() {
    MinHeap minHeap;

    // Inserta elementos en el heap
    minHeap.insert(5);
    minHeap.insert(2);
    minHeap.insert(10);
    minHeap.insert(7);

    // Extrae e imprimi los elementos en orden ascendente
    while (!minHeap.isEmpty()) {
        std::cout << minHeap.extractMin() << " ";
    }

    return 0;
}

