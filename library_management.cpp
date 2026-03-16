#include <iostream>
#include<vector>
using namespace std;

class Books{
   
        int book_id;
        string book_name;
        string author;
        bool is_issued;
     public:

        Books(int id, string name, string author1){
            book_id=id; 
            book_name = name;
            author=author1;
            is_issued=false;
        }
        int getId(){
            return book_id;
        }
        bool getIssuedStatus(){
            return is_issued;
        }

        void issue(){
            is_issued=true;
        }

        void returnBook(){
            is_issued=false;
        }


        void display(){
            cout<<book_id<<" "
                <<book_name<<" "
                <<author<<" ";


                if(is_issued){
                    cout<<"Unavailable"<<endl;;
                }
                else{
                    cout<<"Available"<<endl;
                }
        }
};
class Member {
    public:
        string member_name;
        int member_id;
        int issued_book_id;

        Member(int id, string name){
            member_name=name;
            member_id=id;
            issued_book_id=-1;
        }

        void issue_book(int book_name){

        }
};

class Library{
    public:
    
vector<Books> library;

    Library(){
    library.push_back(Books(1,"book1","author1"));
    library.push_back(Books(2,"book2","author2"));
    library.push_back(Books(3,"book3","author3"));
    }

//issue book

void issueBook( int id){

    for(auto &v : library){

        if(v.getId() == id){

            if(!v.getIssuedStatus()){
                v.issue();
                cout<<"\nBook issued successfully\n\n";
            }
            else{
                cout<<"Book already issued\n";
            }

            return;
        }
    }

    cout<<"Book not found\n";
}


//returning book
void returnBook( int id){

    for(auto& v: library){
        if(v.getId()== id){
            if(v.getIssuedStatus()){
                v.returnBook();
                cout<<"\n Returned successfully \n\n";
            }
            else{
                cout<<"not issued earlier";
            }
            return;
        }
    }
    cout<<"book not found";
}

//search books

int searchBook(int id) {
    for(auto& v:library){
        if(v.getId()==id){
           v.display();
        }
    }
}

//add books

void addBook(){
    int id;
    string name, author;
    cout<<"\n enter the Book id -> "<<endl;
    cin>>id;

    cout<<"Add Book Name -> "<<endl;
    cin>>name;

    cout<<"Add Author -> "<<endl;
    cin>> author;

    library.push_back(Books(id, name, author));

}

//show all

void showAll(){

    for(auto &v : library){
        v.display();
    }

}

};


int main(){
    Library lib;

int choice;
int id;
do{


cout<<"\n__________________________________________________________________________"<<endl;
cout<<"  1  ->  Add Book  "<<endl;
cout<<"  2  ->  Issue Book  "<<endl;
cout<<"  3  ->  Return Book  "<<endl;
cout<<"  4  ->  Search Book     "<<endl;
cout<<"  5  ->  Show All Books  "<<endl;
cout<<"  6  ->  Exit"<<endl;

cin>>choice;

switch(choice){

case 1:
lib.addBook();
break;

case 2:
cout<<"enter the book id-> \n";
cin>>id;
lib.issueBook(id);
break;

case 3:
cout<<"Enter book id: ";
cin>>id;
lib.returnBook(id);
break;

case 4:
cout<<"Enter book id: ";
cin>>id;
lib.searchBook(id);
break;

case 5:

lib.showAll();
break;

case 6:
cout<<"Exiting...\n";
break;

default:
break;

}

}while(choice!=6);
    return 0;
}




























/*Book
 └── data of book

Library
 ├── addBook()
 ├── issueBook()
 ├── returnBook()
 ├── searchBook()
 └── showBooks()

main
 └── menu + calls Library
 */