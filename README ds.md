# Browser History Manager

A C++ console application that simulates the **Back** and **Forward** buttons of a web browser using the **Stack** data structure. The stack is built from scratch using a singly linked list (no STL containers).

## Objectives
- Understand how the Stack (LIFO: Last In, First Out) data structure works
- Implement a stack from scratch using a linked list and dynamic memory
- Apply stacks to a real-life problem: browser navigation

## Features
- Visit a new page
- Go back to the previous page
- Go forward after going back
- View the current page and both history stacks
- Forward history is cleared when a new page is visited, exactly like a real browser
- Handles empty-stack cases (no pages to go back/forward) without crashing
- Memory is freed properly using a destructor, and copying is disabled to avoid shallow-copy bugs

## Data Structures Used
| Structure | Where it is used |
|-----------|------------------|
| **Stack** (custom class) | One stack for Back history, one for Forward history |
| **Singly linked list** | Underlying storage of the stack; the head acts as the top, so push and pop are O(1) |

## How It Works
1. **Visit a page:** push the current page onto the Back stack, set the new page as current, clear the Forward stack.
2. **Back:** pop the Back stack, push the current page onto the Forward stack, and make the popped page current.
3. **Forward:** pop the Forward stack, push the current page onto the Back stack, and make the popped page current.

Example: visit `A`, `B`, `C`, then Back, Back, Forward.

| Action  | Back stack (top first) | Current     | Forward stack (top first) |
|---------|------------------------|-------------|---------------------------|
| Start   | -                      | about:blank | -                         |
| Visit A | blank                  | A           | -                         |
| Visit B | A, blank               | B           | -                         |
| Visit C | B, A, blank            | C           | -                         |
| Back    | A, blank               | B           | C                         |
| Back    | blank                  | A           | B, C                      |
| Forward | A, blank               | B           | C                         |

## Time Complexity
| Operation | Complexity |
|-----------|------------|
| push / pop | O(1) |
| visit / back / forward | O(1) (clearing the Forward stack is O(n)) |

## Project Structure
```
browser-history-ds/
├── main.cpp
└── README.md
```

## How to Run
Requires a C++ compiler such as g++ (C++11 or later).

```bash
g++ main.cpp -o browser
./browser
```

On Windows (MinGW): `g++ main.cpp -o browser.exe` then `browser.exe`

## Sample Output
```
===== Browser History Manager =====
1. Visit new page
2. Back
3. Forward
4. Show history
0. Exit
Choice: 4

Current page: B.com
Back stack (top first):
   A.com
   about:blank
Forward stack (top first):
   C.com
```

## Real-Life Applications of Stacks
- Browser Back/Forward navigation
- Undo/Redo in text editors
- Function call stack in programming languages
- Expression evaluation and bracket matching

## Author
**Jatin Anand**
B.Tech IT, Maharaja Agrasen Institute of Technology, Delhi
