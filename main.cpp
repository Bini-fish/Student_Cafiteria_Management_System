#include <iostream>
#include <string.h>
#include <regex>
#include <cctype>  // to use the tolower function
#include <limits>  // to use numeric_limits in checking valid integer input
#include <cstdlib> // to clear the terminal everytime a function is used

using namespace std;

bool isValidID(string id)
{

    regex pattern("^T?\\NaScRR?/\\d{4}/\\d{2}$", regex_constants::icase);
    if (regex_match(id, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int getValidInteger(string prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number.\n";
        }
        else
        {
            return value;
        }
    }
}
bool isValidName(string name)
{
    regex pattern("^[A-Za-z ]+$");
    if (regex_match(name, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}

struct StdNode
{
    string studentName;
    string studentId;
    StdNode *next;
    StdNode *prev;
};

struct DLL
{
    StdNode *head = NULL;

    // Display scanned students -> displayStudents()

    void displayStudents()
    {
        if (!head)
        {
            cout << "List is empty!!!" << endl;
            return;
        }
        StdNode *temp = head;
        cout << "NULL|head->";
        while (temp)
        {
            cout << "<- (" << temp->studentId << "|" << temp->studentName << ") ->";
            temp = temp->next;
        }
        cout << "NULL";
    }

    // Insert a student (Scan) -> insertStudent(name, studentID) |  at end(default), beg, pos
    void insertStudentBeg(string name, string id)
    {
        StdNode *newNode = new StdNode();
        newNode->studentName = name;
        newNode->studentId = id;
        newNode->prev = NULL;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            StdNode *temp = head;
            while (temp->prev != NULL)
            {
                temp = temp->prev;
            }
            temp->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        displayStudents();
        cout << endl;
    }
    void insertStudentEnd(string name, string id)
    {
        StdNode *newNode = new StdNode();
        newNode->studentName = name;
        newNode->studentId = id;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            StdNode *temp;
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newNode->prev = temp;
            temp->next = newNode;
        }
        displayStudents();
        cout << endl;
    }
    void insertStudentPos(string name, string id, int pos)
    {

        StdNode *newNode = new StdNode();
        newNode->studentName = name;
        newNode->studentId = id;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else if (pos == 1)
        {
            insertStudentBeg(name, id);
        }
        else
        {
            // checking if the value of pos is greater than the length of the linked list
            int length = 0;
            StdNode *temp = head;
            while (temp != NULL)
            {
                length++;
                temp = temp->next;
            }
            if (pos >= length)
            {
                insertStudentEnd(name, id);
                return;
            }
            int count = 1;
            StdNode *curr = head;

            while (curr->next != NULL && count <= pos)
            {

                curr = curr->next;
                count++;
            }
            if (curr == NULL)
            {
                insertStudentEnd(name, id);
                return;
            }
            newNode->next = curr;
            curr->prev = newNode;
            newNode->prev = curr->prev;
            curr->prev->next = newNode;
        }
        displayStudents();
        cout << endl;
    }

    // check the lower case ids -> toLowerCase(string str)
    string toLowerCase(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]); // Convert each character to lowercase
        }
        return str;
    }
    // Search for duplicate student id (check if already scanned) -> searchStudent(studentID)
    bool searchStudent(string id)
    {
        StdNode *newNode;
        if (head == NULL)
        {
            return false;
        }
        else
        {
            StdNode *curr = head;
            StdNode *prev = NULL;
            string ids = {};
            while (curr != NULL)
            {
                if (toLowerCase(curr->studentId) == toLowerCase(id))
                {
                    return true;
                }
                curr = curr->next;
            }
        }
        return false;
    }
    // search for student by their id
    void searchStudentById(string id)
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        StdNode *curr = head;
        while (curr != NULL)
        {
            if (toLowerCase(curr->studentId) == toLowerCase(id))
            {
                cout << "Student Found: ID: " << curr->studentId << ", Name: " << curr->studentName << endl;
                return;
            }
            curr = curr->next;
        }

        cout << "Student with ID " << id << " not found!" << endl;
    }
    // Delete all students (reset list) -> resetList()
    void resetList()
    {
        if (head == NULL)
        {
            cout << "The list is empty!" << endl;
            return;
        }
        while (head != NULL)
        {
            StdNode *temp = head;
            head = head->next;
            delete temp;
        }
        cout << "All students have been deleted.The list is now empty." << endl;
    }

    // Sorting by name ->  sortStudents()
    void sortStudents()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == NULL)
        {
            cout << "List is already sorted!!!";
        }

        bool swapped;
        do
        {
            swapped = false;
            StdNode *curr = head;

            while (curr->next != NULL)
            {
                // Compare adjacent nodes by studentName
                if (curr->studentName > curr->next->studentName)
                {
                    // Swap the data (studentName and studentId)
                    swap(curr->studentName, curr->next->studentName);
                    swap(curr->studentId, curr->next->studentId);

                    swapped = true; // Mark that a swap was made
                }
                curr = curr->next; // Move to the next node
            }
        } while (swapped);

        cout << "Sorted Students!!!" << endl;
        displayStudents();
        cout << endl;
    }
};

int main()
{
    DLL list;
    string name, id;
    int size, option, position, choice;
    do
    {
        system("CLS");
        cout << "=============================================\n";
        cout << "         STUDENT CAFETERIA MANAGEMENT        \n";
        cout << "=============================================\n";
        cout << "1. Add Students\n";
        cout << "2. Display Students\n";
        cout << "3. Reset List\n";
        cout << "4. Display Sorted Students List\n";
        cout << "5. Search Student by ID\n";
        cout << "6. Exit\n";
        cout << "=============================================\n";

        choice = getValidInteger("Enter your choice: ");

        switch (choice)
        {
        case 1:
            size = getValidInteger("How many students do you want to add? ");
            for (int i = 0; i < size; i++)
            {
                cout << "Enter ID (NaScR): ";
                cin >> id;
                while (list.searchStudent(id) || !isValidID(id))
                {
                    if (list.searchStudent(id))
                    {
                        cout << "This ID already exists, Enter a new ID: ";
                    }
                    else
                    {
                        cout << "Invalid ID format: ";
                    }
                    cin >> id;
                }
                cin.ignore();
                cout << "Enter Student's Name: ";
                getline(cin, name);
                while (!isValidName(name))
                {
                    cout << "Invalid Name format! Enter a valid name: ";
                    getline(cin, name);
                }
                cout << "Where do you want to add the students?\n1. In the beginning\n2. At the end\n3. In a specific position\n";
                option = getValidInteger("Enter your option: ");
                while (option < 1 || option > 3)
                {
                    cout << "Invalid option! Please enter 1, 2, or 3: ";
                    option = getValidInteger("Enter your option: ");
                }
                switch (option)
                {
                case 1:
                    list.insertStudentBeg(name, id);
                    system("pause");
                    break;
                case 2:
                    list.insertStudentEnd(name, id);
                    system("pause");
                    break;
                case 3:
                    position = getValidInteger("What Position do you want to add the student? ");
                    list.insertStudentPos(name, id, position);
                    system("pause");
                    break;
                default:
                    list.insertStudentEnd(name, id);
                    system("pause");
                    break;
                }
            };

            break;
        case 2:
            list.displayStudents();
            cout << endl;
            system("pause");
            break;
        case 3:
            list.resetList();
            system("pause");
            break;
        case 4:
            list.sortStudents();
            system("pause");
            break;
        case 5:
            if (list.head == NULL)
            {
                cout << "The list is empty!" << endl;
                system("pause");
                break;
            }
            cout << "Enter the ID to search: ";
            cin >> id;
            list.searchStudentById(id);
            system("pause");
            break;
        case 6:
            cout << "Exit successful!!!\n";
            system("pause");
            break;
        default:
            cout << "Invalid input\n";
            break;
        }
    } while (choice != 6);

    return 0;
}