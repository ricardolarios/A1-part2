#pragma once
//lang::Cpp
#include "queue.h"
#include "string.h"
#include <cassert>

// test equality of queues.
void test_equality() {
	Queue* test_queue = new Queue();
	Queue* comp_queue = new Queue();
	String* s1 = new String("1");
	String* s2 = new String("2");
	String* s3 = new String("3");
	String* s4 = new String("4");
	String* s5 = new String("5");

	assert(test_queue->equals(comp_queue));
	assert(comp_queue->equals(test_queue));
	assert(test_queue->hash() == comp_queue->hash());

	test_queue->enqueue(s2);
	test_queue->enqueue(s1);
	test_queue->enqueue(s3);
	test_queue->enqueue(s4);
	test_queue->enqueue(s5);

	comp_queue->enqueue(s1);
	comp_queue->enqueue(s2);
	comp_queue->enqueue(s3);
	comp_queue->enqueue(s4);
	comp_queue->enqueue(s5);

	// order matters
	assert(!test_queue->equals(comp_queue));
	assert(!comp_queue->equals(test_queue));

	test_queue->clear();
	test_queue->enqueue(s1);
	test_queue->enqueue(s2);
	test_queue->enqueue(s3);
	test_queue->enqueue(s4);

	// need same number of elements
	assert(!test_queue->equals(comp_queue));
	assert(!comp_queue->equals(test_queue));

	// they are the same again
	test_queue->enqueue(s5);
	assert(test_queue->equals(comp_queue));
	assert(comp_queue->equals(test_queue));
	assert(test_queue->hash() == comp_queue->hash());

	delete test_queue;
	delete comp_queue;
	delete s1;
	delete s2;
	delete s3;
	delete s4;
	delete s5;
}

// test add / delete half way through.
void test_queue_add_pop_twice() {
	Queue* test_queue = new Queue();
	String* s1 = new String("1");
	String* s2 = new String("2");
	String* s3 = new String("3");
	String* s4 = new String("4");
	String* s5 = new String("5");

	test_queue->enqueue(s1);
	test_queue->enqueue(s2);
	test_queue->enqueue(s3);
	test_queue->enqueue(s4);
	test_queue->enqueue(s5);

	assert(test_queue->dequeue()->equals(s1));
	assert(test_queue->dequeue()->equals(s2));
	assert(test_queue->dequeue()->equals(s3));

	test_queue->enqueue(s1);
	test_queue->enqueue(s2);
	test_queue->enqueue(s3);

	assert(test_queue->dequeue()->equals(s4));
	assert(test_queue->dequeue()->equals(s5));
	assert(test_queue->dequeue()->equals(s1));
	assert(test_queue->dequeue()->equals(s2));
	assert(test_queue->dequeue()->equals(s3));

	delete test_queue;
	delete s1;
	delete s2;
	delete s3;
	delete s4;
	delete s5;
}

// test clearing empty
void test_clear() {
	Queue* test_queue = new Queue();
	assert(test_queue->size() == 0);
	String* s1 = new String("1");
	String* s2 = new String("2");
	String* s3 = new String("3");
	String* s4 = new String("4");
	String* s5 = new String("5");

	test_queue->enqueue(s1);
	test_queue->enqueue(s2);
	test_queue->enqueue(s3);
	test_queue->enqueue(s4);
	test_queue->enqueue(s5);

	assert(test_queue->size() == 5);
	test_queue->clear();
	assert(test_queue->size() == 0);
	test_queue->clear();
	assert(test_queue->size() == 0);

	delete test_queue;
	delete s1;
	delete s2;
	delete s3;
	delete s4;
	delete s5;
}

// main entry point for program
int main()
{
	Queue test_queue = Queue();
	Queue test_queue_2 = Queue();
	Object* elem_1 = new Object();

	assert(test_queue.is_empty());
	assert(test_queue.equals(&test_queue_2));

	test_queue.enqueue(elem_1);

	assert(test_queue.size() == 1);
	assert(!test_queue.equals(&test_queue_2));

	Object* removed_elem = test_queue.dequeue();

	assert(elem_1->equals(removed_elem));
	assert(test_queue.is_empty());
	assert(test_queue.equals(&test_queue_2));

	for (int i = 0; i < 10; i++)
	{
		Object* o = new Object();
		test_queue.enqueue(o);
	}

	assert(test_queue.size() == 10);

	test_queue.clear();

	assert(test_queue.is_empty());

	String* s_1 = new String("");
	String* s_2 = new String("");

	test_queue.enqueue(s_1);
	test_queue.enqueue(s_2);
	test_queue.enqueue(elem_1);

	assert(test_queue.size() == 3);
	assert(!test_queue.equals(&test_queue_2));

	String* s_3 = new String("hello");
	String* s_4 = new String("world");
	Queue test_queue_3 = Queue();
	test_queue_3.enqueue(s_3);
	test_queue_3.enqueue(s_4);
	Object* peeked_elem = test_queue_3.peek();
	assert(s_3->equals(peeked_elem));
	Object* removed_elem_2 = test_queue_3.dequeue();

	// delete this since the queue no longer handles this
	delete removed_elem_2;

	peeked_elem = test_queue_3.peek();
	assert(s_4->equals(peeked_elem));

	// add specific tests
	test_clear();
	test_queue_add_pop_twice();
	test_equality();
	return 0;
}
