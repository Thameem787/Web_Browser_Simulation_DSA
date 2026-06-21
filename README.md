# 🌐 Web Browser Simulation System

> Ever wondered what's actually happening when you hit the Back button? This is that — minus the GUI, plus all the data structures that make it work.

A C++ engine that simulates how a real browser manages **history, bookmarks, and downloads** under the hood — no graphics, no frameworks, just pure DSA doing the heavy lifting.

No Chromium. No V8. Just pointers, nodes, and a queue doing exactly what Chrome does internally — minus 20 million lines of code.

## ⚡ Why this exists

Browsers feel like magic until you realize **Back/Forward is just a doubly linked list with a cursor.** Bookmarks? Singly linked list. Downloads finishing in order? A queue. That's it. That's the whole trick.

This project strips a browser down to that skeleton and makes it runnable in a terminal.

## 🧠 The Core Idea

| Browser Feature | Data Structure | Why |
|---|---|---|
| Back / Forward history | Doubly Linked List | Need to move both directions in O(1) |
| Bookmarks | Singly Linked List | Just need to scan, never go backward |
| Download Manager | Queue (FIFO) | Fairness — first requested, first done |

## 🚀 Features

| Feature | Data Structure | Operation |
|---|---|---|
| Visit Page | Doubly Linked List | Insert + truncate forward history |
| Back / Forward | Doubly Linked List | O(1) pointer movement |
| View History | Doubly Linked List | O(N) traversal |
| Search History by Title | Doubly Linked List | O(N) linear search |
| Delete Page | Doubly Linked List | Node removal + relink |
| Clear History | Doubly Linked List | Full traversal + free memory |
| Add / Delete Bookmark | Singly Linked List | Head insertion / linear removal |
| View Bookmarks | Singly Linked List | O(N) traversal |
| Add Download | Queue (STL) | Enqueue |
| Process Download | Queue (STL) | Dequeue (FIFO) |
| View Downloads | Queue (STL) | Non-destructive traversal |

## 🛠️ Tech Stack

- **Language:** C++ (C++17)
- **STL:** `queue`
- **Custom structures:** `Page`, `Bookmark`, `Download`
- **Memory:** raw pointers — manual `new` / `delete`, no smart pointer crutches

## 📁 Project Structure

```
web-browser-simulation-dsa/
│
├── src/
│   └── main.cpp           # Entire engine — history, bookmarks, downloads, menu
│
├── docs/
│   └── Presentation.pdf   # Slide deck — architecture, diagrams, complexity breakdown
│
├── .gitignore              # Keeps binaries/build junk out of the repo
└── README.md                # You are here
```

## ▶️ Build & Run

```bash
g++ -std=c++17 -o browser src/main.cpp
./browser
```

## 📊 Complexity Cheat Sheet

| Operation | Big-O | Why |
|---|---|---|
| Visit Page | O(1) | Direct pointer insertion |
| Back / Forward | O(1) | Just move `prev`/`next` |
| Search History | O(N) | Linear scan, no shortcuts |
| Clear History | O(N) | Visit every node to free it |

## 🎓 Built For

Data Structures & Algorithms coursework — proof that the "boring" structures (linked lists, queues) are exactly what real software runs on.

---

⭐ If this helped you understand linked lists better than your textbook did, star the repo.
