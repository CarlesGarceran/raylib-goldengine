#include "List.h"
#include <vector>
#include <map>

#define LOG_OUTPUT

#ifdef LOG_OUTPUT
#define LOG printf
#else
void stub(const char*) {}

#define LOG stub
#endif

std::vector<unsigned int>* ToVector(void* data)
{
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

		for (int i = 0; i < initialCapacity; i++)
		{
			ToVector(list->inner_ref)->push_back(0);
		}

		return list;
	}

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
		{
			LOG(ex.what());
			return nullptr;
		}
	}

	{
		if (!list) return NULL;

		try
		{
			return ToVector(list->inner_ref)->at(index);
		}
		{
			LOG(ex.what());
			return 0;
		}
	}

	{
		if (!list) return;

		try
		{
			ToVector(list->inner_ref)->push_back(data);
		}
		{
			LOG(ex.what());
		}
	}

	{
		if (!list) return;

		try
		{
			auto vector = ToVector(list->inner_ref);
			if (index < 0 || index > vector->size()) return;

			vector->emplace(vector->begin() + index, data);
		}
		{
			LOG(ex.what());
		}
	}

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
		{
			LOG(ex.what());
			return 0;
		}
	}
}
