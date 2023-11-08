# Contact-Management-System

# DATA STRUCTURE USED : Binary Search Tree.

We have chosen a Binary Search Tree (BST) is the most appropriate data structure for simulating a file explorer in C++ due to its inherent properties that closely resemble the hierarchical organization of files and directories in a file system. A BST allows for efficient storage and retrieval of data, making it ideal for managing file structures.

Each node in the tree can represent a file or a directory, with left child nodes representing subdirectories and right child nodes representing files or subdirectories at the same level. The key advantage of a BST lies in its logarithmic time complexity for searching, insertion, and deletion operations, which closely mirrors the way users navigate and manipulate files in a real file system.

This efficient search capability means that we are enabling the users can quickly access and manipulate files and directories, making the simulation highly responsive and user-friendly. Furthermore, the ordered nature of a BST enables easy sorting and listing of files and directories, mirroring the intuitive organization of a file explorer.

In summary, we have chosen the BST as it is the most appropriate data structure for a file explorer simulation due to its efficiency, organization, and close alignment with the real-world file system's hierarchical structure.
# CODE EXPLAINATION
A contact manager is a vital tool for organizing and storing contact details efficiently, offering quick access to names, phone numbers, and emails. It simplifies communication and relationship management for individuals and organizations. This C++ program implements a Contact Management System (Phonebook) using a binary tree data structure for efficient organization and retrieval of contact information. Here's an explanation of the code:-

=> Node Structure: - The program defines a structure node to represent each node in the binary tree. Each node contains pointers to its left and right children, along with information such as name, phone number, and email.

=> Binary Tree Class:- The Binary Tree class contains member functions to perform various operations on the binary tree.
a)	The create function allows users to add new contacts to the phonebook, ensuring uniqueness based on the phone number and validating the email format.
b)	The insert function is a wrapper for the create function.
c)	The update function allows users to change the phone number for a given contact.
d)	The search function searches for a contact by name and displays the contact details if found.
e)	The deleteNode and findMin functions are used for deleting a node from the binary tree.
f)	The deleteContact function allows users to remove a contact by specifying the name.
g)	The inorder function performs an in-order traversal of the binary tree, displaying contact information.
h)	The display function is a wrapper for the inorder function.

=> Main Function: - In the main function, an instance of the BinaryTree class is created.
The program presents a menu to the user with options to search, insert, display all contacts, delete a contact, update a phone number, or exit.
The user can interactively choose and perform these operations.
The program continues running until the user chooses to exit.

=> User Input and Validation: - The program includes input validation for the contact number and email address to ensure they meet specified criteria.
It also checks for the uniqueness of contact numbers during the creation of new contacts.

=> Displaying Contact Information: - The program neatly displays contact information in a tabular format.



