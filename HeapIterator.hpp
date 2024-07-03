#ifndef HEAPITERATOR_HPP
#define HEAPITERATOR_HPP

#include "Node.hpp"
#include <queue>
#include <iostream> // For debugging output

template <typename T>
class HeapIterator {
private:
    std::vector<T> heap;
    std::size_t index;

public:
    explicit HeapIterator(const std::vector<T>& heap, std::size_t i = 0) : heap(heap), index(i) {}

    T operator*() const {
        return heap[index];
    }

    bool operator!=(const HeapIterator& other) const {
        return index != other.index;
    }

    HeapIterator& operator++() {
        ++index;
        return *this;
    }

    static HeapIterator end(const std::vector<T>& heap) {
        return HeapIterator(heap, heap.size());
    }
};

#endif // HEAPITERATOR_HPP
