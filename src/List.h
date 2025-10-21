#ifndef LIST_H
#define LIST_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct
	{
		size_t element_size;
		void* inner_ref;

		unsigned int defaultValue;
	} List;

	List* CreateEmptyList(size_t elementSize);
	List* CreateList(size_t elementSize, size_t initialCapacity);
	void SetFallbackValue(List* list, unsigned int defaultValue);
	void* GetData(List* list);
	unsigned int GetAt(List* list, int index);
	void PushBack(List* list, unsigned int data);
	void Emplace(List* list, int index, unsigned int data);
	void SetAt(List* list, int index, unsigned int data);

	size_t SizeOf(List* list);

	void DestroyList(List* list);

#ifdef __cplusplus
}
#endif

#endif