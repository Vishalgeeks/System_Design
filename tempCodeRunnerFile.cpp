#include <iostream>
#include<vector>
using namespace std;

class Books{
    public:
        int book_id;
        string book_name;
        string author;
        bool is_issued;
        
        Books(int id, string name, string author1){
            book_id=id; 
            book_name = name;
            author=author1;
            is_issued=false;
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
void issueBook(vector<Books> &library, int id){

    for(auto &v : library){

        if(v.book_id == id){

            if(!v.is_issued){
                v.is_issued = true;
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
void returnBook(vector<Books>& library , int id){

    for(auto& v: library){
        if(v.book_id == id){
            if(v.is_issued){
                v.is_issued =false;
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


int searchBook(vector<Books>& library, int id) {
    for(auto& v:library){
        if(v.book_id==id){
            cout<<"\n BOOK ID-> "<<v.book_id<<" "<<"BOOK NAME->"<<v.book_name<<" " <<"AUTHOUR ->"<<v.author<<endl;
        }
    }
}

void addBook(vector<Books>& library){
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

void showAll(vector<Books>& library){

    for(auto &v : library){
        cout<<v.book_id<<" "
            <<v.book_name<<" "
            <<v.author<<" "
            <<v.is_issued<<endl;
    }

}

vector<Books> books;



int main(){
    vector<Books> library;

    library.push_back(Books(1,"book1","author1"));
    library.push_back(Books(2,"book2","author2"));
    library.push_back(Books(3,"book3","author3"));

    issueBook(library,2);
    for(int i=0;i<library.size();i++){
    cout<<library[i].book_id<<" "
        <<library[i].book_name<<" "
        <<library[i].author<<" "
        <<library[i].is_issued<<endl;
}

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
addBook(library);
break;

case 2:
cout<<"enter the book id-> \n";
cin>>id;
issueBook(library,id);
break;

case 3:
cout<<"Enter book id: ";
cin>>id;
returnBook(library,id);
break;

case 4:
cout<<"Enter book id: ";
cin>>id;
searchBook(library,id);
break;

case 5:

showAll(library);
break;

case 6:
cout<<"Exiting...\n";
break;

}

}while(choice!=6);
    return 0;
}