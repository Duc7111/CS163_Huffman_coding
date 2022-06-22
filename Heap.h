#pragma once

template<class T>
class minHeap
{
    private:

    T* heap;
    int size, m_size;

    public:

    minHeap(T* arr, int n) : heap(arr), size(n), m_size(n)
    {
        for(int i = 1; i < size; ++i)
        {
            int t = i;
            while(t)
            {
                if(heap[t] > heap[(t - 1)/2]) break;
                else
                {
                    int k = t;
                    t = (t - 1)/2;
                    T temp = heap[t];
                    heap[t] = heap[k];
                    heap[k] = temp;
                }
            }
        }
    }

    ~minHeap()
    {
        delete[] heap;      
    }

    void insert(T x)
    {
        if(size == m_size) return;
        heap[size] = x;
        int i = size++;
        while(i >= 0)
        {
            int t = (i - 1)/2;
            if(heap[i] < heap[t])
            {
                heap[i] = heap[t];
                heap[t] = x;
                i = t;
            }
            else break;
        }
    }

    T getRoot()
    {
        if(size == 0) return nullptr;
        heap[0] = heap[--size];
        int i = 0;
        while(i*2 + 2 < size)
        {
            if(heap[i] < heap[2*i + 1] && heap[i] < heap[2*i + 2]) return heap[size];
            if(heap[2*i + 1] < heap[2*i + 2])
            {
                T temp = heap[2*i + 1];
                heap[2*i + 1] = heap[0];
                heap[0] = temp;
            }
            else
            {
                T temp = heap[2*i + 2];
                heap[2*i + 2] = heap[0];
                heap[0] = temp;
            }
        }
        if(i*2 + 1 < size && heap[i*2 + 1] < heap[i])
        {
            T temp = heap[2*i + 1];
            heap[2*i + 1] = heap[0];
            heap[0] = temp;
        } 
        return heap[size];
    }

    int Size()
    {
        return size;
    }
};