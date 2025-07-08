#include <iostream>
#include <string>
#include <algorithm>
#define MAX_BOOKS 6
#define MAX_USERS 10
#define MAX_Copies 10
#define SEARCH_TYPES 2
#define MAX_SYSTEM_OPERATIONS 10
using namespace std;

int Selected_operation;

struct BOOK{
    string Book_name;
    int Book_ID;
    int total_quantity;
    string Borrowers_names[MAX_Copies];
    int total_borrowed = 0;
};


struct Book_Center{
    BOOK Books[MAX_BOOKS];
    int Books_counter =0;


    bool Is_available_to_add(void){
        if(Books_counter != MAX_BOOKS){
            return true;
        }else{
            return false;
        }
    }

    void Insert_book(string B_name, int B_id, int B_quantity){
        Books[Books_counter].Book_name = B_name;
        Books[Books_counter].Book_ID = B_id;
        Books[Books_counter].total_quantity = B_quantity;
        Books_counter++;
    }

    void Adding_book(void){
        if(!Is_available_to_add()){
            cout << "Sorry, we can't add any books at the moment ...  " << endl;
        }else{
            cout << "Enter Book Info: id & name & total quantity: " ;
            string B_name;
            int B_id, B_quantity;
            cin >> B_id >> B_name >> B_quantity;
            Insert_book(B_name, B_id, B_quantity);
        }
    }

    void Print_Library(void){
        for(int i=0; i<Books_counter; i++){
            cout << "ID = " << Books[i].Book_ID << " name = " << Books[i].Book_name 
            << " total_quantity = " << Books[i].total_quantity << " total_borrowed = " << Books[i].total_borrowed << endl;
        }
    }


    bool book_is_exists(string bookName){
        for(int i=0; i<Books_counter; i++){
            if(Books[i].Book_name == bookName){
                return true;
            }
        }
        return false;
    }

    int Get_book_index(string bookName){
        for(int i=0; i<Books_counter; i++){
            if(Books[i].Book_name == bookName){
                return i;
            }
        }
        return -1;
    }


    bool Is_copy_avalilable(string book_name){
        for(int i=0; i<Books_counter; i++){
            if(Books[i].Book_name == book_name){
                if(Books[i].total_quantity != 0){
                    return true;
                }else{
                    return false;
                }
            }
        }
        return false;
    }

    void Book_Borrowing_query(int Book_index, string username){
            Books[Book_index].Borrowers_names[Books[Book_index].total_borrowed] = username;
            Books[Book_index].total_quantity--;
            Books[Book_index].total_borrowed++;
    }

    void Book_borrowing_process(string Book_name, string User_name){
        if(book_is_exists(Book_name)){
            Book_Borrowing_query(Get_book_index(Book_name), User_name);
        }else{
            cout << "Book name is Invalid ... " << endl;
        }
    }

    int Get_borrower_index(int book_index, string borrower_name){
        for(int i=0; i<Books_counter; i++){
            if(i == book_index){
                for(int j=0; j<Books[i].total_borrowed; j++){
                    if(Books[i].Borrowers_names[j] == borrower_name){
                        return j;
                    }
                }
            }
        }
        return -1;
    }

    void Book_returning_Query(int book_index, string borrower_name){
        int borrower_index = Get_borrower_index(book_index, borrower_name);
        if(borrower_index == 0){
            for(int x=0; x<Books[book_index].total_borrowed-1; x++){
                Books[book_index].Borrowers_names[x] = Books[book_index].Borrowers_names[x+1];
            }Books[book_index].total_borrowed--;
        }else if(book_index == Books[book_index].total_borrowed-1){
            Books[book_index].total_borrowed--;
        }else{
            for(int z=borrower_index; z<Books[book_index].total_borrowed-1; z++){
                Books[book_index].Borrowers_names[z] = Books[book_index].Borrowers_names[z+1];
            }Books[book_index].total_borrowed--;
        }
        Books[book_index].total_quantity++;
        
    }

    

    void print_Who_borrowed_book_by_name(void){
        string bookName;
        cout << "Enter Book name: ";
        cin >> bookName;
        if(book_is_exists(bookName)){
            int book_index = Get_book_index(bookName);
            for(int i=0; i<Books_counter; i++){
                if(i==book_index){
                    if(Books[i].total_borrowed != 0){
                    for(int j=0; j<Books[i].total_borrowed; j++){
                        cout << Books[i].Borrowers_names[j] << endl;
                    }
                  }else{
                    cout << "No one Borrowed This Book ... " << endl;
                  }

                }
            }
        }else{
            cout << "Book name is Invalid ... " << endl;
        }
    }

    int ID_search(int ID){
        for(int i=0; i<Books_counter; i++){
            if(Books[i].Book_ID == ID){
                cout << "The book is exists:" << endl;
                cout << "Id = " << Books[i].Book_ID << endl;
                cout << "name = " << Books[i].Book_name << endl;
                cout << "Quantity = " << Books[i].total_quantity << endl;
                cout << "Borrow from him = " << Books[i].total_borrowed << endl;
                return 1;
            }
        }
        cout << "Book With ID: " << ID << " Not Exists" << endl;
        return -1;
    }

     int Prefix_search(string prefix){
        bool Found = false;
        for(int i=0; i<Books_counter; i++){
            if(Books[i].Book_name.substr(0, prefix.length()) == prefix){
                cout << Books[i].Book_name << endl;
                Found = true;
            }
        }
        if(Found){
            return 1;
        }else{
            cout << "Book With Prefix: \"" << prefix << "\" Not Exists" << endl;
            return -1;
        }

    }


    void search_for_a_book(void){
        int B_ID;
        string B_prefix;
        if(Books_counter == 0){
            cout << "The library is empty, no books to look for." << endl;
        }else{
            int search_type;
            while(true){
                cout << "search query." << endl;
                cout << "1) Search by ID" << endl;
                cout << "2) Search by Prsfix" << endl;
                cout << "Select Operation: ";
                cin >> search_type;
                if(search_type > 0 && search_type <= SEARCH_TYPES){
                    break;
                }else{
                    cout << "Invalid selection, Please try again ... " << endl;
                }
            }

            switch(search_type){
               case 1:
                  cout << "Enter Book ID: ";
                  cin >> B_ID;
                  ID_search(B_ID);
                  break;

                case 2:
                  cout << "Enter Book Prefix: ";
                  cin >> B_prefix;
                  Prefix_search(B_prefix);
                  break;

            }
            
            
            
            
        }

    }
};
Book_Center Library_Book_Work;



struct USER{
    string UserName;
    int User_ID;
    int Integrity = 0;
    string Books_borroweded[MAX_BOOKS];
    int total_borrowed = 0;
};

struct User_Cnter{
    USER Users[MAX_USERS];
    int Users_counter =0;

    bool Is_available_to_add(void){
        if(Users_counter != MAX_USERS){
            return true;
        }
        return false;
    }

    void Insert_user(string U_name, int U_ID){
        Users[Users_counter].UserName = U_name;
        Users[Users_counter].User_ID = U_ID;
        Users_counter++;
    }
    void Adding_user(void){
        if(!Is_available_to_add()){
            cout << "Sorry, we can't add any users at the moment ...  " << endl;
        }else{
            cout << "Enter User name and national ID: " ;
            string User_name;
            int User_ID;
            cin >> User_name >> User_ID;
            Insert_user(User_name, User_ID);
        }
    }


    bool User_is_exists(string username){
        for(int i=0; i<Users_counter; i++){
            if(Users[i].UserName == username){
                return true;
            }
        }
        return false;
    }

    int Get_user_index(string username){
        for(int i=0; i<Users_counter; i++){
            if(Users[i].UserName == username){
                return i;
            }
        }
        return -1;
    }

    void Book_borrowing_query(int userIndex, string Book_name){
        Users[userIndex].Books_borroweded[Users[userIndex].total_borrowed] = Book_name;
        Users[userIndex].total_borrowed++;
    }

    int Get_book_index(int user_index, string book_name){
        for(int i=0; i<Users_counter; i++){
            if(i == user_index){
                for(int j=0; j<Users[i].total_borrowed; j++){
                    if(Users[i].Books_borroweded[j] == book_name){
                        return j;
                    }
                }
            }
        }
        return -1;
    }
    
    void Book_returning_query(int userIndex, string book_name){
        int book_index = Get_book_index(userIndex, book_name);
        if(book_index == 0){
            for(int x=0; x<Users[userIndex].total_borrowed; x++){
                Users[userIndex].Books_borroweded[x] = Users[userIndex].Books_borroweded[x+1];
            }Users[userIndex].total_borrowed--;
        }else if(book_index == Users[userIndex].total_borrowed-1){
            Users[userIndex].total_borrowed--;
        }else{
            for(int y=book_index; y<Users[userIndex].total_borrowed-1; y++){
                Users[userIndex].Books_borroweded[y] = Users[userIndex].Books_borroweded[y+1];
            }Users[userIndex].total_borrowed--;
        }
    }

    

    bool User_is_already_borrowed_it(int user_index, string book_name){
        for(int i=0; i<Users[user_index].total_borrowed; i++){
            if(Users[user_index].Books_borroweded[i] ==book_name ){
                return true;
            }
        }
        return false;
    }


    void Print_all_users(void){
        if(Users_counter != 0){
        for(int i=0; i<Users_counter; i++){
            if(Users[i].total_borrowed == 0){
                cout << "User with name:" << " \"" << Users[i].UserName << "\" and id: \"" << Users[i].User_ID << "\" "
                << "Not borrowed Any Books ... " << endl; 
            }else{
                cout << "User with name:" << " \"" << Users[i].UserName << "\" and id: \"" << Users[i].User_ID << "\" "
                << "borrowed Books With IDs: ";
                for(int j=0; j<Users[i].total_borrowed; j++){
                    int book_indix = Library_Book_Work.Get_book_index(Users[i].Books_borroweded[j]);
                    int bookID = Library_Book_Work.Books[book_indix].Book_ID;
                    cout << bookID << " ";
                }
                cout << endl;
            }
        }}else{
            cout << "There are no users currently ... " << endl;
        }
    }
};

User_Cnter Library_User_Work;






void user_borrow_book(void){
    string book_name;
    string user_name;
    cout << "Enter user name and book name: " ;
    cin >> user_name >> book_name;
    if(Library_Book_Work.book_is_exists(book_name)){
        if(Library_Book_Work.Is_copy_avalilable(book_name)){
            if(Library_User_Work.User_is_exists(user_name)){
                if(!Library_User_Work.User_is_already_borrowed_it(Library_User_Work.Get_user_index(user_name), book_name)){
                    Library_Book_Work.Book_Borrowing_query(Library_Book_Work.Get_book_index(book_name), user_name);
                    Library_User_Work.Book_borrowing_query(Library_User_Work.Get_user_index(user_name), book_name);
                }else{
                    cout << "Sorry, You Can't Borrowed this book, You have already borrowed this book.";
                }
            }else{
                cout << "Sorry. User name is Invalid ... " << endl;
            }
        }else{
            cout << "Unfortunately, copies of this book are sold out ... " << endl;
        }
    }else{
        cout << "Sorry, Book name is Invalid ... " << endl;
    }
}

void user_return_book(void){
    string book_name;
    string user_name;
    cout << "Enter user name and book name: ";
    cin >> user_name >> book_name;
    if(Library_Book_Work.book_is_exists(book_name)){
        if(Library_User_Work.User_is_exists(user_name)){
            if(Library_User_Work.User_is_already_borrowed_it(Library_User_Work.Get_user_index(user_name), book_name)){
                Library_Book_Work.Book_returning_Query(Library_Book_Work.Get_book_index(book_name), user_name);
                Library_User_Work.Book_returning_query(Library_User_Work.Get_user_index(user_name), book_name);
            }else{
                cout << "The user has not yet borrowed this book ... " << endl;
            }
        }else{
            cout << "user name is Invalid ... " << endl;
        }
    }else{
        cout << "Book name is Invalid ... " << endl;
    }
}

















bool ID_Sort(BOOK &e, BOOK &x){
    if(e.Book_ID == x.Book_ID){
        return e.Book_name < x.Book_name;
    }
    return e.Book_ID < x.Book_ID;
}

bool Name_Sort(BOOK &e, BOOK &x){
    return e.Book_name < x.Book_name;
}


void Menu(void){
    cout << "Library Menu:" << endl;
    cout << "1) Add Book" << endl;
    cout << "2) Search Book By Name Or Prefix " << endl;
    cout << "3) Print Who Borrowed Book By Name" << endl;
    cout << "4) Print library By ID" << endl;
    cout << "5) Print library By Name" << endl;
    cout << "6) Add User" << endl;
    cout << "7) User Borrow Book" << endl;
    cout << "8) User Return Book" << endl;
    cout << "9) print users" << endl;
    cout << "10) Exit" << endl;
    cout <<"==========================================\n\n";
}

void Get_Choise(void){
    cout << "Enter Your Menu Choice [1 - " << MAX_SYSTEM_OPERATIONS << "] : ";
    cin >> Selected_operation;
}



int main(void){
    Menu();
    while(true){
        while(true){
            Get_Choise();
            if(Selected_operation > 0 && Selected_operation <= MAX_SYSTEM_OPERATIONS){
                break;
            }else{
                cout << "Invalid Selection, Please try again ... " << endl << endl;
            }
        }

        switch (Selected_operation){
        case 1:
            Library_Book_Work.Adding_book();
            break;
        case 2:
            Library_Book_Work.search_for_a_book();
            break;
        case 3:
            Library_Book_Work.print_Who_borrowed_book_by_name();
            break;
        case 4:
            sort(Library_Book_Work.Books, Library_Book_Work.Books+Library_Book_Work.Books_counter, ID_Sort);
            Library_Book_Work.Print_Library();
            break;
        case 5:
            sort(Library_Book_Work.Books, Library_Book_Work.Books+Library_Book_Work.Books_counter, Name_Sort);
            Library_Book_Work.Print_Library();
            break;
        case 6:
            Library_User_Work.Adding_user();
            break;
        case 7:
            user_borrow_book();
            break;
        case 8:
            user_return_book();
            break;
        case 9:
            Library_User_Work.Print_all_users();
            break;
        case 10:
            return 0;
        }
        
    }

}



// to Enhance
// 1.admin trying add book, but this book is already exist
// 2.admin tring add books more than the allowed copies
// 3. increasing number of book copies