# Priority Queue with Stack-Based Space Management

## Introduction

This project implements a priority queue using a combination of a stack and an array. The design focuses on efficient space management and order preservation by leveraging a stack to track empty spaces within the queue. This approach contrasts with multi-dimensional queue implementations, offering specific advantages in simplicity, space efficiency, and operation predictability.


## Features

- **Priority-Based Insertion and Deletion**: Items are inserted with a priority, and items with the highest priority (lowest numerical value) are deleted first.
- **Order Preservation**: Items with the same priority are deleted in the order they were inserted, preserving the insertion sequence.
- **Stack-Based Space Management**: A stack tracks available spaces in the queue, preventing fragmentation and ensuring efficient space utilization.
- **Overflow and Underflow Handling**: Proper checks are in place to handle queue overflow and underflow conditions.
- **Efficient Use of Space**: In a multi-dimensional queue, memory might be allocated for multiple dimensions even if they are not fully utilized. In contrast, this implementation only requires an array and a stack, minimizing wasted space.
