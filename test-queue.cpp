#pragma once
//lang::Cpp
#include "queue.h"
#include "string.h"
#include <cassert>

// main entry point for program
int main()
{
	Queue test_queue = Queue();
	Queue test_queue_2 = Queue();
	Object elem_1 = Object();

	assert(test_queue.is_empty());
	assert(test_queue.equals(&test_queue_2));

	test_queue.enqueue(&elem_1);

	assert(test_queue.size() == 1);
	assert(!test_queue.equals(&test_queue_2));

	Object* removed_elem = test_queue.dequeue();

	assert(elem_1.equals(removed_elem));
	assert(test_queue.is_empty());
	assert(test_queue.equals(&test_queue_2));
	
	for (int i = 0; i < max_size; i++)
	{
		Object o = Object();
		test_queue.enqueue(&o);
	}

	test_queue.clear();
	
	assert(test_queue.is_empty());

	String s_1 = String();
	String s_2 = String();
	test_queue.enqueue(&s_1);

	assert(test_queue.size() == 1);

	test_queue.enqueue(&elem_1);

	assert(!test_queue.equals(&test_queue_2));

    String s_3 = String("hello");
    String s_4 = String("world");
    Queue test_queue_3 = Queue();
    test_queue_3.enqueue(&s_3);
    test_queue_3.enqueue(&s_4);
    Object* peeked_elem = test_queue_3.peek();
    assert(s_3.equals(peeked_elem));
    test_queue_3.dequeue();
    peeked_elem = test_queue_3.peek();
    assert(s_4.equals(peeked_elem));

	return 0;
}