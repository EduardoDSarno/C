
#include <cstdio>
#include <utility>
#include <vector>



void insert_min(std::vector<int>& heap, int value);
void insert_max(std::vector<int>& heap, int value);
int main(void)
{
    std::vector<int> heap;
   

    for (int i : heap)
    {
        printf("%d ", i);
    }

    return 0;
}

void insert(std::vector<int> &max_heap,
            std::vector<int> &min_heap,
            int value)

{
    if (max_heap.empty() || value <= max_heap[max_heap.size() - 1])
    {
        insert_max(max_heap, value);
    }
    else 
    {
        insert_min(min_heap, value);
    }

    // rebalance
    if(max_heap.size() > min_heap.size() + 1)
    {

    }

}

void insert_min(std::vector<int>& heap, int value)
{
    heap.push_back(value);

    if(heap.size() > 1)
    {
        int i = heap.size() - 1; // the index of value we just inserted
        int parent_index = (i - 1) / 2;
        while(i > 0 && heap[parent_index] > heap[i])
        {
            std::swap(heap[parent_index], heap[i]);
            i = parent_index; // moving up
            parent_index = (i - 1) / 2; // recalcualting index
        }
    }
}

void insert_max(std::vector<int>& heap, int value)
{
    heap.push_back(value);

    if(heap.size() > 1)
    {
        int i = heap.size() - 1; // the index of value we just inserted
        int parent_index = (i - 1) / 2;
        while(i > 0 && heap[parent_index] < heap[i])
        {
            std::swap(heap[parent_index], heap[i]);
            i = parent_index; // moving up
            parent_index = (i - 1) / 2; // recalcualting index
        }
    }
}

