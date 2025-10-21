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

		void* defaultValue;
	} List;

	List* CreateEmptyList(size_t elementSize);
	List* CreateList(size_t elementSize, size_t initialCapacity);
	void SetFallbackValue(List* list, void* defaultValue);
	void* GetData(List* list);
	void* GetAt(List* list, int index);
	void PushBack(List* list, void* data);
	void Emplace(List* list, int index, void* data);
	void SetAt(List* list, int index, void* data);

	size_t SizeOf(List* list);

	void DestroyList(List* list);

#ifdef __cplusplus
}
#endif

#endif