#include <iostream>
#include <string>
#include <queue>
using namespace std;

// ===================== PAGE NODE (DOUBLY LINKED LIST) =====================
struct Page {
    string url;
    string title;
    Page* prev;
    Page* next;

    Page(string u, string t) {
        url = u;
        title = t;
        prev = nullptr;
        next = nullptr;
    }
};

// ===================== BOOKMARK NODE (SINGLY LINKED LIST) =====================
struct Bookmark {
    string url;
    string title;
    Bookmark* next;

    Bookmark(string u, string t) {
        url = u;
        title = t;
        next = nullptr;
    }
};

// ===================== DOWNLOAD QUEUE ITEM =====================
struct Download {
    string filename;
    Download(string f) {
        filename = f;
    }
};

// ===================== MAIN BROWSER CLASS =====================
class Browser {
private:
    Page* head;
    Page* tail;
    Page* current;

    Bookmark* bookmarksHead;

    queue<Download> downloadQueue;

public:
    Browser() {
        head = tail = current = nullptr;
        bookmarksHead = nullptr;
        visitPage("www.google.com", "Google Home");
    }

    // ===================== VISIT PAGE =====================
    void visitPage(const string& url, const string& title) {
        Page* newPage = new Page(url, title);

        if (!head) {
            head = tail = current = newPage;
            cout << "Visited: " << title << endl;
            system("pause");
            return;
        }

        // Remove forward chain
        if (current->next != nullptr) {
            Page* temp = current->next;
            while (temp) {
                Page* d = temp;
                temp = temp->next;
                delete d;
            }
            current->next = nullptr;
            tail = current;
        }

        current->next = newPage;
        newPage->prev = current;
        current = newPage;
        tail = newPage;

        cout << "Visited: " << title << endl;
        system("pause");
    }

    // ===================== GO BACK =====================
    void goBack() {
        if (current->prev == nullptr) {
            cout << "No previous page.\n";
            system("pause");
            return;
        }
        current = current->prev;
        cout << "Current: " << current->title << endl;
        system("pause");
    }

    // ===================== GO FORWARD =====================
    void goForward() {
        if (current->next == nullptr) {
            cout << "No forward page.\n";
            system("pause");
            return;
        }
        current = current->next;
        cout << "Current: " << current->title << endl;
        system("pause");
    }

    // ===================== VIEW FULL HISTORY =====================
    void viewHistory() {
        system("cls");
        cout << "=========== BROWSING HISTORY ===========\n";
        Page* temp = head;

        while (temp) {
            if (temp == current)
                cout << " > " << temp->title << " (" << temp->url << ") < [CURRENT]\n";
            else
                cout << "   " << temp->title << " (" << temp->url << ")\n";
            temp = temp->next;
        }
        cout << "========================================\n";
        system("pause");
    }

    // ===================== DELETE PAGE =====================
    void deletePage(const string& title) {
        Page* temp = head;

        while (temp && temp->title != title)
            temp = temp->next;

        if (!temp) {
            cout << "Page not found.\n";
            system("pause");
            return;
        }

        if (temp == current) {
            if (current->prev)
                current = current->prev;
            else
                current = current->next;
        }

        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;

        if (temp == head) head = temp->next;
        if (temp == tail) tail = temp->prev;

        delete temp;
        cout << "Page deleted.\n";
        system("pause");
    }

    // ===================== CLEAR HISTORY =====================
    void clearHistory() {
        Page* temp = head;
        while (temp) {
            Page* d = temp;
            temp = temp->next;
            delete d;
        }

        head = tail = current = nullptr;

        visitPage("www.google.com", "Google Home");
        cout << "History cleared.\n";
        system("pause");
    }

    // ===================== SEARCH HISTORY BY TITLE (LINEAR SEARCH) =====================
    void searchHistory(const string& title) {
        Page* temp = head;

        while (temp && temp->title != title)
            temp = temp->next;

        if (!temp) {
            cout << "Page NOT found.\n";
            system("pause");
            return;
        }

        cout << "Page FOUND: " << temp->title << " (" << temp->url << ")\n";
        system("pause");
    }

    // ===================== BOOKMARKS =====================
    void addBookmark(const string& url, const string& title) {
        Bookmark* bm = new Bookmark(url, title);
        bm->next = bookmarksHead;
        bookmarksHead = bm;
        cout << "Bookmark added.\n";
        system("pause");
    }

    void deleteBookmark(const string& title) {
        Bookmark* temp = bookmarksHead;
        Bookmark* prev = nullptr;

        while (temp && temp->title != title) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) {
            cout << "Bookmark not found.\n";
            system("pause");
            return;
        }

        if (!prev) bookmarksHead = temp->next;
        else prev->next = temp->next;

        delete temp;
        cout << "Bookmark deleted.\n";
        system("pause");
    }

    void viewBookmarks() {
        system("cls");
        cout << "============ BOOKMARKS ============\n";
        Bookmark* temp = bookmarksHead;

        if (!temp) {
            cout << "(Empty)\n";
            system("pause");
            return;
        }

        while (temp) {
            cout << " - " << temp->title << " (" << temp->url << ")\n";
            temp = temp->next;
        }

        cout << "===================================\n";
        system("pause");
    }

    // ===================== DOWNLOADS =====================
    void addDownload(const string& file) {
        downloadQueue.push(Download(file));
        cout << "Download added.\n";
        system("pause");
    }

    void processDownload() {
        if (downloadQueue.empty()) {
            cout << "No downloads.\n";
            system("pause");
            return;
        }

        Download d = downloadQueue.front();
        downloadQueue.pop();
        cout << "Downloaded: " << d.filename << endl;
        system("pause");
    }

    void viewDownloads() {
        system("cls");
        cout << "=========== DOWNLOAD QUEUE ===========\n";

        if (downloadQueue.empty()) {
            cout << "(No pending downloads)\n";
            system("pause");
            return;
        }

        queue<Download> temp = downloadQueue;

        while (!temp.empty()) {
            cout << " - " << temp.front().filename << endl;
            temp.pop();
        }

        cout << "======================================\n";
        system("pause");
    }

    // ===================== CURRENT PAGE =====================
    void displayCurrent() {
        system("cls");
        cout << "====================================\n";
        cout << "Current Page: ";
        if (current)
            cout << current->title << " (" << current->url << ")";
        else
            cout << "(Empty)";
        cout << "\n====================================\n";
    }
};

// ===================== MAIN MENU =====================
int main() {
    Browser browser;
    int choice;
    string url, title, file;

    while (true) {
        browser.displayCurrent();
        cout << "1. Visit Page\n";
        cout << "2. Back\n";
        cout << "3. Forward\n";
        cout << "4. View History\n";
        cout << "5. Delete Page\n";
        cout << "6. Clear History\n";
        cout << "7. Add Bookmark\n";
        cout << "8. Delete Bookmark\n";
        cout << "9. View Bookmarks\n";
        cout << "10. Add Download\n";
        cout << "11. Process Download\n";
        cout << "12. View Downloads\n";
        cout << "13. Search Page by Title\n";
        cout << "14. Exit\n";
        cout << "Select: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "URL: "; getline(cin, url);
            cout << "Title: "; getline(cin, title);
            browser.visitPage(url, title);
            break;

        case 2: browser.goBack(); break;
        case 3: browser.goForward(); break;
        case 4: browser.viewHistory(); break;

        case 5:
            cout << "Enter Title: "; getline(cin, title);
            browser.deletePage(title);
            break;

        case 6: browser.clearHistory(); break;

        case 7:
            cout << "URL: "; getline(cin, url);
            cout << "Title: "; getline(cin, title);
            browser.addBookmark(url, title);
            break;

        case 8:
            cout << "Enter Title: "; getline(cin, title);
            browser.deleteBookmark(title);
            break;

        case 9: browser.viewBookmarks(); break;

        case 10:
            cout << "Filename: "; getline(cin, file);
            browser.addDownload(file);
            break;

        case 11: browser.processDownload(); break;
        case 12: browser.viewDownloads(); break;

        case 13:
            cout << "Enter Title: "; getline(cin, title);
            browser.searchHistory(title);
            break;

        case 14:
            exit(0);

        default:
            cout << "Invalid option.\n";
            system("pause");
        }
    }
}
