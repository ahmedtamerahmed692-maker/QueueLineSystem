# Queue Line System (C++ · Custom Data Structures)

A service-desk ticketing and queue simulator built entirely on **hand-written C++ template data structures** - no STL containers.

**Timeline:** Jul 2026 · **Stack:** C++ · Templates · OOP

---

## 🏛️ Custom Data Structures (Core/)

- **clsDblLinkedList** - doubly linked list template supporting dynamic insertions, deletions and in-place reversing
- **clsDynamicArray** - memory-safe dynamic array template with bounds checking and resizing
- **clsMyQueue / clsMyQueueArr** - FIFO queue adapters over both the linked-list and the dynamic-array backends
- **clsMyStack / clsMyStackArr** - LIFO stack adapters derived from the queue backends

## 🎫 Queue Line Simulator

`clsQueueLine` issues numbered tickets and serves clients in order, simulating a real service desk: issue ticket → wait in line → serve → call next.

## 🛠️ Technologies

C++ · Templates · Custom data structures · Console UI
