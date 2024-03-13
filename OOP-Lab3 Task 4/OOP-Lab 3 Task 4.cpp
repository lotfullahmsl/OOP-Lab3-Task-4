#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // we use this for adding spaces 
using namespace std;

class Task {
public:
    string description;
    bool completed;
    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
    vector<Task*> tasks;
public:
    void addTask(const string& desc) { tasks.push_back(new Task(desc)); }

    void removeTask(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task." << endl;
            return;
        }
        delete tasks[index - 1];
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully!" << endl;
    }

    void markCompleted(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task ." << endl;
            return;
        }
        tasks[index - 1]->completed = true;
        cout << "Task marked as completed!" << endl;
    }

    void listTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }
        cout << "Tasks:" << endl;
        cout << setw(6) << left << "Index" << setw(40) << left << "Description" << "Status" << endl;
        cout << string(55, '-') << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << setw(6) << left << i + 1 << setw(40) << left << tasks[i]->description;
            if (tasks[i]->completed)
                cout << "Completed";
            else
                cout << "Pending";
            cout << endl;
        }
    }

    ~ToDoList() {
        for (auto& task : tasks)
            delete task;
    }
};

int main() {
    ToDoList myList;
    cout << "Welcome to ToDo List Application!" << endl;
    char choice;
    do {
        cout << "\nSelect an option:\n"
            << "1. Add a new task\n"
            << "2. Remove a task\n"
            << "3. Mark a task as completed\n"
            << "4. List all tasks\n"
            << "5. Exit\n"
            << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case '1': {
            string taskDescription;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, taskDescription);
            myList.addTask(taskDescription);
            cout << "Task added successfully!" << endl;
            break;
        }
        case '2': {
            int index;
            cout << "Enter the index of the task to remove: ";
            cin >> index;
            myList.removeTask(index);
            break;
        }
        case '3': {
            int index;
            cout << "Enter the index of the task to mark as completed: ";
            cin >> index;
            myList.markCompleted(index);
            break;
        }
        case '4':
            myList.listTasks();
            break;
        case '5':
            cout << "Exiting application..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}