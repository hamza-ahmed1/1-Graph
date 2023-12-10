
#include <iostream>
using namespace std;
#define INF 999




struct dataset
{
	int weight;
	int vertex;
};

class Min_Heap
{
	dataset* arr;
	int size;
	int cur_size = 0;
public:
	Min_Heap(int size)
	{
		this->size = size;
		arr = new dataset[size]{ 0 };
		arr[0].weight = -1;
	}

	//insertion :
	void insert(int weight,int vertex)
	{
		cur_size = cur_size + 1;
		int index = cur_size;
		arr[cur_size].weight = weight;
		arr[cur_size].vertex = vertex;

		//Heapification:
		while (index>1)//until i found you means parent index!
		{
			int parent = index / 2;
			if (arr[parent].weight > arr[index].weight)//cheak if parent's weight < child's weight if not then swap
			{
				swap(arr[parent], arr[index]);
				index = parent;//jump upward
			}
			else
			{
				return; //if parent's weight < child's weight if not then return 
			}
		}

	}
	//get top element:
	dataset get_top()
	{
		if (cur_size == 0)
		{
			return { -1, -1 };
		}
		if (cur_size > 1)
		{
			
			
			dataset top_element = arr[1];//save top element as min
			arr[1] = arr[cur_size];//change that element with last one
			--cur_size;// dec original size
			int index = 1;
			while (index < cur_size)
			{
				int l = 2 * index;
				int r = 2 * index + 1;

				if (l<cur_size && arr[l].weight < arr[index].weight)
				{
					swap(arr[l], arr[index]);
					index = l;
				}
				else if (r < cur_size && arr[r].weight < arr[index].weight)
				{
					swap(arr[r], arr[index]);
					index = r;
				}
				else
				{
					return top_element;
				}


			}
			return top_element;
		}
	}
	void Heapify(int i)
	{
		int size1 = size;
		int smallest = i;
		int l = 2 * i +1;
		int r = 2 * i;
		if (l < size1 && arr[l].weight < arr[smallest].weight)
			smallest = l;
		if (r < size1 && arr[r].weight < arr[smallest].weight)
			smallest = r;

		if (smallest != i)
		{
			swap(arr[i].weight, arr[smallest].weight);
			swap(arr[i].vertex, arr[smallest].vertex);
			Heapify(smallest);
		}
	}
	
	void Print()
	{
		for (int i = 0; i <= cur_size; i++)
		{
			cout << arr[i].weight << "      ";
		}
		cout << endl;
	}
};
int main()
{
	Min_Heap m(5);
	m.insert(2, 1);
	m.insert(5, 2);
	m.insert(3, 1);
	m.insert(1, 1);

	m.Print();

	dataset a = m.get_top();
	cout << "weight :" << a.weight << endl;

	m.Print();

	dataset a1 = m.get_top();
	cout << "weight :" << a1.weight << endl;

	m.Print();

	return 0;
}
