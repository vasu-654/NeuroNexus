#include <iostream>
#include <vector>
#include <string>

using namespace std;

class work {
public:
    bool completed;
    string description;

    work(const string& desc) : description(desc), completed(false) {}
};

class to_do_list {
private:
    vector<work> tasks;

public:
    void add_task(const string& description) {
        work newTask(description);
        tasks.push_back(newTask);
        cout << "work added succressfully : " << description << endl<<endl;
    }

    void view_tasks() {
        if (tasks.empty()) {
            cout << "No tasks available." << endl<<endl;
        } else {
            cout << "Tasks in your to do list includes : " << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". ";
                display_task(tasks[i]);
            }
        }
    }

    void mark_if_completed(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "successfully task marked as completed: " << tasks[index - 1].description << endl<<endl;
        } else {
            cout << "Please enter the appropriate index from list   !! Invalid task index  " << endl<<endl;
        }
    }

    void remove_task(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            cout << "Successfully removed the work " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Please enter the appropriate index from list   !! Invalid task index  " << endl;
        }
    }

private:
    void display_task(const work& task) {
        cout << task.description;
        if (task.completed) {
            cout << " - Completed";
        } else {
            cout << " - Pending";
        }
        cout << endl;
    }
};

int main() {
    to_do_list toDoList;
    int wrong_choice_count = 0;

    while (true) {
        cout << endl<<endl<<"Welcome to your To do list \n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: "<<endl;

        int choice;
        cin >> choice;
try
{
        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore(); 
                getline(cin, description);
                toDoList.add_task(description);
                break;
            }
            case 2:
                toDoList.view_tasks();
                break;
            case 3: {
                size_t index;
                toDoList.view_tasks();
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                toDoList.mark_if_completed(index);
                bool do_remove = false;
                cout<<"Do you wish to remove this index"<<endl<<endl;
                cout<<"Press (1) to remove \n Press(2) to continue : ";
                cin>>do_remove;
                if(do_remove==1)
                {
                toDoList.remove_task(index);
                }
                
                break;
            }
            case 4: {
                size_t index;
                cout << "Enter task index to remove: ";
                cin >> index;
                toDoList.remove_task(index);
                break;
            }
            case 5:
                cout << "Thanks for using I hope it was useful in your you time management \n";
                return 0;
            default:
            {
                wrong_choice_count++;
                if(wrong_choice_count>=3)
                {
                    throw 1;
                }
                cout << "Invalid choice. Please try again.\n";
            }

                
        }
}
        catch(int a)
        {
             cout<<"!!  Wrong Entry limit exceeded Please try again later!! \n Thanks for using us "<<endl;
             break;
        }
}

    return 0;
}
