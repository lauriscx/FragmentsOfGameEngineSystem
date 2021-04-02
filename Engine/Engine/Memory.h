#pragma once

#ifdef DEBUG && MEMORY_LEAK
	#include <iostream>
	#include <map>
#endif // DEBUG

#include <memory>

namespace Memory {

	/*
	 * Deleting object then created Scope object
	 * goes out of scope or is assigned to other value.
	 * You can't copy Scope or have 2 pointers
	 * pointing to the same memory address.
	*/
	template<typename T>
	using Scope = std::unique_ptr<T>;

	/*
	 * Create a Scope.
	 * Uses constexpr to determent data type in
	 * compile time. This function return created
	 * Scope with prefered data.
	*/
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args) {
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	/*
	 * Counting reference. If reference
	 * count is zero the delete(release memory).
	*/
	template<typename T>
	using Reference = std::shared_ptr<T>;

	/*
	 * Create a reference.
	 * Uses constexpr to determent data type in
	 * compile time. This function return created
	 * Reference with prefered data.
	*/
	template<typename T, typename ... Args>
	constexpr Reference<T> CreateReference(Args&& ... args) {
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	/*
	 * This type is used to pas Reference pointer
	 * to other function without increasing
	 * reference count.
	*/
	template<typename T>
	using PassReference = std::weak_ptr<T>;

	/*
	 * Then is used define DEBUG and MEORY_LEAK
	 * together you can see in console printing
	 * meory alocation and releasion operations.
	*/
};
#if defined(DEBUG) && defined(MEMORY_LEAK)

	//std::map<void*, size_t> m_PointersMemoryMap;
	size_t m_MemoryAllocated = 0;

	void * operator new(size_t size) {
		std::cout << "Allocated memory " << size << std::endl;
		//void * p = ::operator new(size);
		void * p = malloc(size); //will also work fine
		//m_PointersMemoryMap[p] = size;//Add to map pointer and memory allocation.
		m_MemoryAllocated += size;

		return p;
	}

	void operator delete(void * p) {
		//m_PointersMemoryMap.erase(p);

		std::cout << "Releasing memory " << std::endl;
		free(p);
	}

#endif // DEBUG