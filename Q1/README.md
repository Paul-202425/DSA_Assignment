Q1: Airport Baggage Priority Queue

The objective is to construct a Max-Heap out of the given sequence of numbers, insert a particular element, and delete it right away. The resulting structure has to be presented as an array and a tree. Every operation needs to have a trace of its execution steps.

Algorithm:

Build: Use the bottom-up approach to create a max-heap out of the given numbers. This will involve calling sift_down on every element starting from the middle to the beginning of the array.

Insert: Add a new element at the end of the array and sift it up to its appropriate position.

Delete: Delete the specified element by displacing it with the last element in the array and sift it down.

The trace of operations will include all the swapping steps performed during sift_up and sift_down operations.

The final result will be a max-heap represented as an array and a tree. There will be a validation step after every major heap operation to check if the resulting structure satisfies all the heap properties.
