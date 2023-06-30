#pragma once
namespace kiko
{
	struct MemoyAllocation
	{
		void* address;
		size_t size;
		MemoyAllocation* next;
	};
	class MemoryTracker
	{
	public:
		void Add(void* address, size_t size);
		void Remove(void* address, size_t size);
		void displayInfo();
		//MemoryTracker();
		//~MemoryTracker();

	private:
		size_t m_bytesAllocated = 0;
		size_t m_numAllocations = 0;
		
	};

	/*MemoryTracker::MemoryTracker()
	{
	}

	MemoryTracker::~MemoryTracker()
	{
	}*/
	extern MemoryTracker g_memoryTracker;
}