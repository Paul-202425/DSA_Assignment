Q1: Airport Baggage Priority Queue

The task is to construct a Max-Heap out of the given sequence of numbers. We need to insert a given element and delete it right away. The resulting structure needs to be presented as an array and a tree. All operations need to have a trace of their execution steps.

Algorithm:

Build: We are going to use a bottom-up approach to build a max-heap out of the given numbers. This will require us to call sift_down operation for every element starting from the middle to the beginning of the array.

Insert: We will add a new element to the end of the array and sift it up to its appropriate position.

Delete: We are going to delete the specified element by displacing it with the last element in the array and sift it down.

The trace of operations will include all the swapping steps that we perform during sift_up and sift_down operations.

The final structure is going to be a max-heap represented as an array and a tree. We will be doing a validation step after every major heap operation to check if the resulting structure satisfies all the heap properties.
