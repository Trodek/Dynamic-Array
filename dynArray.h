#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

#include <string.h>

#define DYNARRAY_BLOCK_SIZE 16

typedef unsigned int uint;


template <class T>
class dynArray{
private:
	T* buffer;
	uint capacity;
	uint num_elements;
	
public:
	dynArray():
		capacity(DYNARRAY_BLOCK_SIZE),
		num_elements(0)
	{
		buffer = new T[DYNARRAY_BLOCK_SIZE];
	};
	dynArray(uint inum_elements):
			capacity((DYNARRAY_BLOCK_SIZE)*((inum_elements / DYNARRAY_BLOCK_SIZE) + 1)),
			num_elements(0)

			{
			buffer = new T[capacity];
			}

	dynArray(const dynArray& idynarray){
		uint iarraysize = idynarray.capacity;
		buffer = new T[iarraysize];
		capacity = idynarray.capacity;
		num_elements = idynarray.num_elements;
	}


	void PushBack(T element){
		num_elements++;
		if (num_elements > capacity){
			dynArray<T> temp(*this);
			delete[] buffer;
			capacity=((DYNARRAY_BLOCK_SIZE)*((num_elements / DYNARRAY_BLOCK_SIZE) + 1));
			buffer = new T[capacity];
			memcpy(buffer, temp.buffer,capacity);
		}
		buffer[num_elements - 1] = element;
	}

	T& operator[](uint index){
		return buffer[index];
	}

	dynArray<T>& operator=(const dynArray& src){
		if (src.capacity > capacity){
			delete[] buffer;
			buffer = new T[src.capacity];
			capacity = src.capacity;
		}
		memcpy(buffer, src.buffer, src.capacity);
		num_elements = src.num_elements;
		
		return *this;
	}

	~dynArray(){
		delete[] buffer;
	}
};






#endif //__DYNARRAY_H__