#include <iostream>
using namespace std;

struct node {
    node* left;
    node* right;
    string name;
    string number;
    string email;
    node(string name, string no, string email) {
        left = nullptr;
        right = nullptr;
        this->name = name;
        number = no;
        this->email = email;
    }
};

class BinaryTree {
public:
    node* root;
    string name;
    string no;
    string email;
    int flag;
    BinaryTree() {
        root = nullptr;
    }
    string checknumber(string number) {
        while (number.length() != 10) {
            cout << "\nThe Contact Number Must be 10 Digits!...\n";
            cout << "PLEASE ENTER A VALID NUMBER!...\n";
            cin >> number;
        }
        return number;
    }
    void create() {
        int ch, flag = 0, flag1 = 0;
        node* ptr;
        node* any;
        do {
            cout << "\nEnter the Name: ";
            cin >> name;
            cout << "\nEnter the phone no: ";
            cin >> no;
            no = checknumber(no);
            any = root;
            while (any != nullptr) {
                if (any->number.compare(no) == 0) {
                    flag = 1;
                    break;
                }
                if (any->number.compare(no) > 0) {
                    any = any->left;
                } else {
                    any = any->right;
                }
            }
            if (flag == 1) {
                cout << "This Number is Already Present in Phonebook!...\n";
                cout << "Enter a Different Number!...\n";
                cin >> no;
                no = checknumber(no);
            }
            cout << "\nEnter the Email id: ";
            cin >> email;
            int m = email.length() - 1;
            while (m != -1) {
                if (email[m] == '@') {
                    flag1 = 1;
                }
                if (email[m] == '.') {
                    flag1 = 2;
                    break;
                }
                m--;
            }
            if (flag1 != 2) {
                cout << "Enter a Valid Email address:\n";
                cin >> email;
            }
            node* temp = new node(name, no, email);
            if (root == nullptr) {
                root = temp;
            } else {
                ptr = root;
                while (flag == 0) {
                    if (temp->name.compare(ptr->name) > 0) {
                        if (ptr->right != nullptr) {
                            ptr = ptr->right;
                        } else {
                            ptr->right = temp;
                            flag = 1;
                        }
                    }
                    if (temp->name.compare(ptr->name) < 0) {
                        if (ptr->left != nullptr) {
                            ptr = ptr->left;
                        } else {
                            ptr->left = temp;
                            flag = 1;
                        }
                    }
                }
            }
            flag = 0;
            cout << "\nDo you want to add any Phone Record (0/1): ";
            cin >> ch;
        } while (ch != 0);
    }
    void insert() {
        create();
    }
    void update() {
        int flag = 0;
        node* ptr;
        cout << "Enter a Contact Name you want to update: ";
        string key;
        cin >> key;
        ptr = root;
        while (ptr != nullptr) {
            if (ptr->name.compare(key) == 0) {
                flag = 1;
                break;
            }
            if (ptr->name.compare(key) > 0) {
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }
        if (flag == 1) {
            cout << "Enter New Number: ";
            string new1;
            cin >> new1;
            ptr->number = new1;
        }
    }
    void search() {
        int flag = 0;
        node* ptr;
        cout << "Enter a Name to be searched: ";
        string key;
        cin >> key;
        ptr = root;
        while (ptr != nullptr) {
            if (ptr->name.compare(key) == 0) {
                flag = 1;
                cout << "\n\t-----RECORD FOUND-----\n";
                cout << "-----------------------------------------------\n";
                cout << "NAME\t|  CONTACT NUMBER  |\tEMAIL\n";
                cout << "-----------------------------------------------\n";
                cout << ptr->name << "\t    " << ptr->number << "\t      " << ptr->email << endl;
                break;
            }
            if (ptr->name.compare(key) > 0) {
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }
        if (flag == 0) {
            cout << "-----RECORD NOT FOUND-----\n";
        }
    }
    void deleteNode(node* root, string key) {
        if (root == nullptr)
            return;
        if (root->name.compare(key) > 0) {
            deleteNode(root->left, key);
        } else if (root->name.compare(key) < 0) {
            deleteNode(root->right, key);
        } else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
            } else if (root->left == nullptr) {
                node* temp = root;
                root = root->right;
                delete temp;
            } else if (root->right == nullptr) {
                node* temp = root;
                root = root->left;
                delete temp;
            } else {
                node* temp = findMin(root->right);
                root->name = temp->name;
                root->number = temp->number;
                root->email = temp->email;
                deleteNode(root->right, temp->name);
            }
        }
    }
    node* findMin(node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }
    void deleteContact() {
        cout << "Enter the Contact name you want to delete: ";
        string key;
        cin >> key;
        deleteNode(root, key);
    }
    void inorder(node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->name << "\t    " << root->number << "\t      " << root->email << endl;
            inorder(root->right);
        }
    }
    void display() {
        inorder(root);
    }
};

int main() {
    BinaryTree b;
    int ch, ch1;
    cout << "\n********WELCOME TO OUR PHONEBOOK********\n";
    do {
        cout << "\n 1. Search\n 2. Insertion/Creation\n 3. All Contacts Information\n 4. Removal\n 5. Change a Phone number\n 6. Exit\n";
        cout << "ENTER YOUR CHOICE: ";
        cin >> ch;
        switch (ch) {
            case 1:
                b.search();
                break;
            case 2:
                b.create();
                break;
            case 3:
                cout << "-----------------------------------------------\n";
                cout << "NAME\t|  CONTACT NUMBER  |\tEMAIL\n";
                cout << "-----------------------------------------------\n";
                b.display();
                cout << "-----------------------------------------------\n";
                break;
            case 4:
                b.deleteContact();
                break;
            case 5:
                b.update();
                break;
            case 6:
                cout << "EXITING FROM THE PHONEBOOK!...\n";
                break;
        }
        cout << "\nDo you want to continue? (0/1) -- OPERATIONS -- ";
        cin >> ch1;
    } while (ch1 == 1);

    return 0;
}