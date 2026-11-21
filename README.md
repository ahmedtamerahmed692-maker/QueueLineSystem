# Custom Data Structures & Service Queue Simulator

A robust C++ template library implementing custom computer science data structures (Doubly Linked List, Safe Dynamic Array, Queue, Stack) and a real-world Ticketing and Service Queue Simulator.

---

## 🏛️ Project Architecture & OOP Layout

The codebase is organized into clean, physical namespaces to separate core data structures from utilities and simulation layers.

### Key Components

#### 1. Data Structures (Core Entities)
*   **[clsDblLinkedList.h](Core/clsDblLinkedList.h):** A custom doubly linked list template supporting dynamic insertions, deletions, and in-place reversing.
*   **[clsDynamicArray.h](Core/clsDynamicArray.h):** A memory-safe dynamic array template featuring bounds checking, safety constructors/destructors, and memory resizing routines.
*   **[clsMyQueue.h](Core/clsMyQueue.h) & [clsMyQueueArr.h](Core/clsMyQueueArr.h):** Queue adapters (FIFO) implemented using both Doubly Linked List and Dynamic Array backends.
*   **[clsMyStack.h](Core/clsMyStack.h) & [clsMyStackArr.h](Core/clsMyStackArr.h):** Stack adapters (LIFO) derived from Queue backends.

#### 2. Service Queue Simulator
*   **[clsQueueLine.h](Core/clsQueueLine.h):** A simulation manager for bank/bill queues. It encapsulates ticket issuance (`clsTicket`), client serving logic, queue state reporting (`PrintInfo`), and queue layouts (RTL/LTR printing using standard queues and stacks).

#### 3. Utilities
*   **[clsMyString.h](Utils/clsMyString.h):** A custom string utility implementing **Undo/Redo** transaction logic using LIFO stack operations.

---

## 📂 Project Directory Structure

```text
├── Core/                            # Core Data Structures & Simulator
│   ├── clsDblLinkedList.h           # Doubly Linked List template
│   ├── clsDynamicArray.h            # Safe Dynamic Array template
│   ├── clsMyQueue.h                 # List-based Queue
│   ├── clsMyQueueArr.h              # Array-based Queue
│   ├── clsMyStack.h                 # List-based Stack
│   ├── clsMyStackArr.h              # Array-based Stack
│   └── clsQueueLine.h               # Ticketing/Queue Simulator
│
├── Utils/                           # Helper Utilities
│   └── clsMyString.h                # String utility with Undo/Redo
│
├── main.cpp                         # Application entry point (driver program)
├── QueueLineSystem.sln              # MSVC Solution configuration file
├── QueueLineSystem.vcxproj          # MSVC Project file containing references
├── README.md                        # Documentation
└── .gitignore                       # Clean Git tracking exclusions
```

---

## ⚙️ Getting Started

### Prerequisites
*   Windows OS.
*   Visual Studio 2022 (with the **Desktop Development with C++** workload installed).
*   A C++17 or C++20 compliant compiler.

### Build and Run
1.  Clone this repository to your local system:
    ```bash
    git clone https://github.com/yourusername/queue-line-system.git
    cd queue-line-system
    ```
2.  Open the solution file `QueueLineSystem.sln` in Visual Studio.
3.  Press **Ctrl + Shift + B** to build the project.
4.  Press **Ctrl + F5** to compile and run the application.

---

## 👨‍💻 Developer
**Ahmed Tamer** - Computer Science Student at New Mansoura University (NMU).

## 📄 License
This project is licensed under the MIT License.
