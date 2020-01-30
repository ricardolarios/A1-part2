#pragma once
//lang::Cpp
#include "queue.h"
#include "string.h"
#include <cassert>

// Testing peek functionality
void test_enqueue_dequeue()
{
	Queue* test_queue = new Queue();
	String* s1 = new String("a");
	String* s2 = new String("b");
	String* s3 = new String("c");

	assert(test_queue->size() == 0);
	assert(test_queue->dequeue() == NULL);

	bool enqueue_success = test_queue->enqueue(s1);
	
	assert(enqueue_success);
	assert(test_queue->size() == 1);
	assert(test_queue->dequeue()->equals(s1));
	assert(test_queue->size() == 0);

	test_queue->enqueue(s3);
	test_queue->enqueue(s2);
	test_queue->enqueue(s1);

	assert(test_queue->size() == 3);
	assert(test_queue->dequeue()->equals(s3));

	delete test_queue;
	delete s1;
	delete s2;
	delete s3;
}


// Testing peek functionality
void test_peek()
{
	Queue* test_queue = new Queue();
	String* s1 = new String("a");
	String* s2 = new String("b");
	String* s3 = new String("c");

	assert(test_queue->size() == 0);
	assert(test_queue->peek() == NULL); // Peeking an empty queue should return NULL.

	test_queue->enqueue(s1);

	assert(test_queue->size() == 1);
	assert(test_queue->peek()->equals(s1));
	assert(test_queue->size() == 1); // Size should stay the same after peeking.

	test_queue->enqueue(s2);
	test_queue->enqueue(s3);
	Object* peek_s1 = test_queue->peek();
	Object* dequeue_s1 = test_queue->dequeue();

	assert(peek_s1->equals(dequeue_s1));

	delete test_queue;
	delete s1;
	delete s2;
	delete s3;
}


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

// Testing peek functionality
void test_peek()
{
	Queue* test_queue = new Queue();
	String* s1 = new String("a");
	String* s2 = new String("b");
	String* s3 = new String("c");

	assert(test_queue->size() == 0);
	assert(test_queue->peek() == NULL); // Peeking an empty queue should return NULL.

	test_queue->enqueue(s1);

	assert(test_queue->size() == 1);
	assert(test_queue->peek()->equals(s1));
	assert(test_queue->size() == 1); // Size should stay the same after peeking.

	test_queue->enqueue(s2);
	test_queue->enqueue(s3);
	String* peek_s3 = test_queue->peek();
	String* dequeue_s3 = test_queue->dequeue();
	assert(peek_s3->equals(dequeue_s3));

	delete test_queue;
	delete s1;
	delete s2;
	delete s3;
}

// main entry point for program
int main()
{
	test_enqueue_dequeue();
	test_peek();
	test_clear();
	test_queue_add_pop_twice();
	test_equality();
	return 0;
}
