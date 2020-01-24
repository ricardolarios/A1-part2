#pragma once
//lang::Cpp
#include "queue.h"
#include "string.h"
#include <cassert>

// main entry point for program
int main()
{
	int max_size = 5;
	Queue test_queue = Queue(max_size);
	Queue test_queue_2 = Queue(max_size);
	Object elem_1 = Object();

	assert(test_queue.is_empty());
	assert(test_queue.max_size() == max_size);
	assert(test_queue.equals(test_queue_2));

	test_queue.enqueue(&elem_1);

	assert(test_queue.size() == 1);
	assert(!test_queue.equals(test_queue_2));

	Object* removed_elem = test_queue.dequeue();

	assert(elem_1.equals(removed_elem));
	assert(test_queue.is_empty());
	assert(test_queue.equals(test_queue_2));
	
	for (int i = 0; i < max_size; i++)
	{
		Object o = Object();
		test_queue.enqueue(&o);
	}

	assert(test_queue.is_full());

	test_queue.clear();
	
	assert(test_queue.is_empty());

	String s_1 = String();
	String s_2 = String();
	test_queue.enqueue(&s_1);

	assert(test_queue.size() == 1);

	test_queue.enqueue(&elem_1);

	assert(!test_queue.equals(test_queue_2));

	return 0;
}