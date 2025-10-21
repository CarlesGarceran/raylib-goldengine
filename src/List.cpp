#include "List.h"
#include <vector>
#include <map>

#define LOG_OUTPUT

#ifdef LOG_OUTPUT
#define LOG printf
#else
#define LOG stub
#endif

void stub(const char*) {}

std::vector<void*>* ToVector(void* data)
{
	return static_cast<std::vector<void*>*>(data);
}

extern "C"
{
	List* CreateEmptyList(size_t elementSize)
	{
		return CreateList(elementSize, 0);
	}

	List* CreateList(size_t elementSize, size_t initialCapacity)
	{
		List* list = new List();
		list->element_size = elementSize;
		list->inner_ref = (void*)new std::vector<void*>();
		list->defaultValue = nullptr;

		for (int i = 0; i < initialCapacity; i++)
		{
			ToVector(list->inner_ref)->push_back(0);
		}

		return list;
	}

	void SetFallbackValue(List* list, void* defaultValue)
	{
		if (!list) return;

		list->defaultValue = defaultValue;
	}

	void* GetData(List* list)
	{
		if (!list) return NULL;

		try
		{
			return ToVector(list->inner_ref)->data();
		}
		catch (std::exception ex)
		{
			LOG(ex.what());
		}
	}

	void* GetAt(List* list, int index)
	{
		if (!list) return NULL;

		try
		{
			return ToVector(list->inner_ref)->at(index);
		}
		catch (std::exception ex)
		{
			LOG(ex.what());
		}
	}

	void PushBack(List* list, void* data)
	{
		if (!list) return;

		try
		{
			ToVector(list->inner_ref)->push_back(data);
		}
		catch (std::exception ex)
		{
			LOG(ex.what());
		}
	}

	void Emplace(List* list, int index, void* data)
	{
		if (!list) return;

		try
		{
			auto vector = ToVector(list->inner_ref);
			vector->emplace(vector->begin() + index, data);
		}
		catch (std::exception ex)
		{
			LOG(ex.what());
		}
	}

	void SetAt(List* list, int index, void* data)
	{
		if (!list) return;

		try
		{
			auto vector = ToVector(list->inner_ref);
			if (index < 0) return;

			if (index >= (int)vector->size())
				vector->resize(index + 1, list->defaultValue); // resize and fill new slots with nullptr

			(*vector)[index] = data;
		}
		catch (std::exception ex)
		{
			LOG(ex.what());
		}
	}

	void DestroyList(List* list)
	{
		if (!list) return;

		delete ToVector(list->inner_ref);

		delete list;
	}

	size_t SizeOf(List* list)
	{
		if (!list) return 0;

		try
		{
			return ToVector(list->inner_ref)->size();
		}
		catch (std::exception ex)
		{
			LOG(ex.what());
		}
	}
}