//
// Created by Gerald Martinez on 10/27/22.
//
#include <vector>
using namespace std;
#ifndef BLOGPART4_USERLIST_H
#define BLOGPART4_USERLIST_H


template <class U> class UserList {
public:
    UserList();

    //add to list
    void addToList (U* item);
    //display number of items in the list
    void countList();
    //size of list
    int listSize();
    //set alias

private:
    vector<U*> list;
};


#endif //BLOGPART4_USERLIST_H
