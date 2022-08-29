// C++ program to illustrate bookshop
// management system using File Handling
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

// Bookshop Class
class bookshop
{
public:
  void control_panel();
  void add_book();
  void show_book();
  void check_book();
  void update_book();
  void del_book();
};

// Function to display the menus
void bookshop::control_panel()
{
  system("cls");
  cout << "********** BOOKSHOP MANAGEMENT SYSTEM **********\n";
  cout << "\t\t_____________\n";
  cout << "\t\t| MAIN MENU |\n";
  cout << "\t\t*************\n";
  cout << "\n\tPress 1 to ADD BOOK";
  cout << "\n\tPress 2 to DISPLAY BOOKS";
  cout << "\n\tPress 3 to CHECK PARTICULAR BOOK";
  cout << "\n\tPress 4 to UPDATE BOOK";
  cout << "\n\tPress 5 to DELETE BOOK";
  cout << "\n\tPress 6 to EXIT";
}

// Function to add book
void bookshop::add_book()
{
  system("cls");
  fstream file;
  int no_copy;
  string b_name, a_name, b_id;
  cout << "\n\n\t\t\t\tADD BOOKS";
  cout << "\n\nEnter The Book ID : ";
  cin >> b_id;
  cout << "\nEnter The Name of the Book  : ";
  cin >> b_name;
  cout << "\nEnter the Author's Name : ";
  cin >> a_name;
  cout << "\nEnter the No. of Books : ";
  cin >> no_copy;
  /* G: //H/Repos/E-book-Store/data */
  // Open file in append or
  // output mode
  file.open("G://H/Repos/cllg/E-book-Store/data/book.txt",
            ios::out | ios::app);
  file << "\n"
       << " " << b_id << " "
       << b_name << " " << a_name
       << " " << no_copy;
  file.close();
}

// Function to display book
void bookshop::show_book()
{
  system("cls");
  fstream file;
  int no_copy;
  string b_name, b_id, a_name;
  cout << "\t\t\t\t\t===============\n";
  cout << "\t\t\t\t\t|  BOOK LIST  |\n";
  cout << "\t\t\t\t\t===============\n";

  // Open the file in input mode
  file.open("G://H/Repos/cllg/E-book-Store/data/book.txt", ios::in);
  if (!file)
    cout << "\n\nFile Opening Error!";
  else
  {
    cout << "=====================================================================================\n";

    cout << "Book ID" << setw(16) << "Book" << setw(17)
         << "Author" << setw(22) << "No. of Books\n";

    cout << "=====================================================================================\n";
    /*     file >> b_id >> b_name;
    file >> a_name >> no_copy;
 */
    // Till end of file is reached
    while (!file.eof())
    {

      file >> b_id >> b_name;
      file >> a_name >> no_copy;
      cout << " " << b_id
           << setw(20) << b_name
           << setw(18) << a_name
           << setw(15) << no_copy
           << "\n";
    }

    system("pause");

    // Close the file
    file.close();
  }
}

// Function to check the book
void bookshop::check_book()
{
  system("cls");
  fstream file;
  int no_copy, count = 0;
  string b_id, b_name, a_name, b_idd;

  cout << "\n\n\t\tCheck "
       << "Particular Book";

  // Open the file in input mode
  file.open("G://H/Repos/cllg/E-book-Store/data/book.txt", ios::in);
  if (!file)
    cout << "\n\nFile Opening Error!";
  else
  {

    cout << "\n\nPlease Enter the Book ID : ";
    cin >> b_idd;
    file >> b_id >> b_name;
    file >> a_name >> no_copy;

    while (!file.eof())
    {

      if (b_idd == b_id)
      {

        system("cls");
        cout << "\n\n\t\t\t"
             << "--BOOK DETAILS--";
        cout << "\n\nBook ID : "
             << b_id;
        cout << "\nName : "
             << b_name;
        cout << "\nAuthor : "
             << a_name;
        cout << "\nNo. of Books : "
             << no_copy;
        cout << endl
             << endl;
        count++;
        break;
      }
      file >> b_id >> b_name;
      file >> a_name >> no_copy;
    }
    system("pause");
    file.close();
    if (count == 0)
      cout << "\n\nBook ID Not"
           << " Found...";
  }
}

// Function to update the book
void bookshop::update_book()
{
  system("cls");
  fstream file, file1;
  int no_copy, no_co, count = 0;
  string b_name, b_na, a_name;
  string a_na, b_idd, b_id;

  cout << "\n\n\t  Update Book Record";
  file1.open("G://H/Repos/cllg/E-book-Store/data/book1.txt",
             ios::app | ios::out);
  file.open("G://H/Repos/cllg/E-book-Store/data/book.txt", ios::in);

  if (!file)
    cout << "\n\nFile Opening Error!";
  else
  {

    cout << "\n\nBook ID : ";
    cin >> b_id;
    /*     file >> b_idd >> b_name;
    file >> a_name >> no_copy; */

    // Till end of file is reached

    while (!file.eof())
    {
      file >> b_idd >> b_name;
      file >> a_name >> no_copy;
      if (b_id == b_idd)
      {
        system("cls");
        cout << "\t\t"
             << "Update Book Record";
        cout << "\n\nNew Book Name : ";
        cin >> b_na;
        cout << "\nAuthor Name : ";
        cin >> a_na;
        cout << "\nNo. of Books : ";
        cin >> no_co;
        file1 << "\n"
              << " " << b_id
              << " " << b_na
              << " " << a_na
              << " " << no_co;
        count++;
      }
      else
      {
        file1 << "\n"
              << " " << b_idd
              << " " << b_name
              << " " << a_name
              << " " << no_copy;
      }
    }
    if (count == 0)
      cout
          << "\n\nBook ID"
          << " Not Found...";
  }
  cout << endl;
  system("pause");

  // Close the files
  file.close();
  file1.close();
  remove("G://H/Repos/cllg/E-book-Store/data/book.txt");
  rename("G://H/Repos/cllg/E-book-Store/data/book1.txt",
         "G://H/Repos/cllg/E-book-Store/data/book.txt");
}

// Function to delete book
void bookshop::del_book()
{
  system("cls");
  fstream file, file1;
  int no_copy, count = 0;
  string b_id, b_idd, b_name, a_name;
  cout << "\n\n\t   ---Delete a Book---";

  // Append file in output mode
  file1.open("G://H/Repos/cllg/E-book-Store/data/book1.txt",
             ios::app | ios::out);
  file.open("G://H/Repos/cllg/E-book-Store/data/book.txt",
            ios::in);

  if (!file)
    cout << "\n\nFile Opening Error...";
  else
  {

    cout << "\n\nEnter Book's ID that you want to delete : ";
    cin >> b_id;

    while (!file.eof())
    {
      file >> b_idd >> b_name;
      file >> a_name >> no_copy;

      if (b_id == b_idd)
      {

        /*  //system("cls");
        cout << "\n\n\t\t\t\t"
             << "Delete a Book"; */
        cout << "\n\nBook is Deleted "
                "Successfully...\n\n";
        count++;
      }
      else
        file1 << "\n"
              << " " << b_idd
              << " " << b_name
              << " " << a_name
              << " " << no_copy;
    }
    if (count == 0)
      cout << "\n\nBook ID "
           << "Not Found...";
  }
  system("pause");

  // Close the file
  file.close();
  file1.close();
  remove("G://H/Repos/cllg/E-book-Store/data/book.txt");
  rename("G://H/Repos/cllg/E-book-Store/data/book1.txt",
         "G://H/Repos/cllg/E-book-Store/data/book.txt");
}

// Function for book shop record
void bookShopRecord()
{
  int choice;
  char x;
  bookshop b;

  while (1)
  {

    b.control_panel();
    cout << "\n\nEnter your choice : ";
    cin >> choice;
    switch (choice)
    {

    case 1:
      do
      {

        b.add_book();
        cout << "\n\nWant to add"
             << " another book? "
                "(y/n) : ";
        cin >> x;
      } while (x == 'y');
      break;

    case 2:
      b.show_book();
      break;

    case 3:
      b.check_book();
      break;
    case 4:
      b.update_book();
      break;

    case 5:
      b.del_book();
      break;

    case 6:
      exit(0);
      break;

    default:
      cout << "\n\nINVALID CHOICE\n";
    }
  }
}

// Driver Code
int main()
{
  // Function Call
  bookShopRecord();

  return 0;
}
