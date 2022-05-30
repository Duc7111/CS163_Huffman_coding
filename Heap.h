#pragma once

template<class T>
class minHeap
{
    private:

    T* heap;
    int size;

    public:

    minHeap(T* arr, int n) : T(arr), size(n)
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
};