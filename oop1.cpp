#include<iostream>
using namespace std;

// class is a collection of data and function under the same name
class Book{
    public:
        int bookid(){
            return id;
        }
        Book(int d){
            this->id = d;
        }
    private:
        int id;
};

int main(){
    Book ob(101);
    cout<<ob.bookid()<<endl;
    return 0;
}