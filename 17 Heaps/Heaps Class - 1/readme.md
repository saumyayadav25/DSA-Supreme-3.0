# Heaps 
#### (Priority queue)
It is a data structure which is **complete binary tree and follows heap property**

#### Complete Binary Tree:
A complete binary tree is a special type of binary tree where all the levels of the tree are filled completely except the lowest level nodes which are filled from left.

![image](https://github.com/user-attachments/assets/e1d2e8c6-ba8b-43e8-bbdd-f1805d61a482)

#### Heap Property:
- Max-Heap: root/parent node value > left and right child
- Min-Heap: root/parent node value < left and right child
<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20221220165711/MinHeapAndMaxHeap1.png">

-> **Heap**: can find maximum and minimum in O(1) time.

**Heaps: visualise as Tree and implemented as array(easy to access elements)**

(1 based indexing)

![image](https://github.com/user-attachments/assets/1aeb1b45-fb05-450a-8c99-9e3d6a2f0e53)


## Insertion
- STEP 1: insert the element normally into the first empty position inside the array/ insert new element at size + 1 index
- STEP 2: then compare the element with the parent and put the element at the right place(by comparing with parent node)
<img src="https://www.codingeek.com/wp-content/uploads/2016/11/HeapInsertion.png">

## Deletion
- STEP 1: replace root(or element to be deleted) with last node
- STEP 2: size--
- STEP 3: heapify root node
<img width="280" alt="Screenshot 2024-09-15 at 4 16 15 PM" src="https://github.com/user-attachments/assets/e676bb4a-ebea-4015-9893-286ac8a730bb">

**TC of insertion/deletion: O(logn)**

## Heapify
- Let largestKaIndex = i (assuming i par hi sbse badi value hai)
- but it is possible ki sabse badi value left ya right child me ho, check for that
- if larger value is found in left or right then update largestKaIndex
- Now, if largestKaIndex = i even after checking, then no need to do anything
- but if largestKaIndex != i then swap the value, Baaki RECURSION sambhal lega

## Heap Sort
- Swap root element with last element
- delete last(now root) element
- heapify

**TC: O(NlogN)**
<img src="https://miro.medium.com/v2/resize:fit:1400/format:webp/1*FNfDwQYa3wN-zcma1c1bfQ.png">


