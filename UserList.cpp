//
// Created by Gerald Martinez on 10/27/22.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "UserList.h"
template <class U> UserList<U>::UserList()
{

}
template <class U> void UserList<U>::addToList(U *item)
{
    //only add an item if it is not already in the list
    if(find(list.begin(),list.end(),item)==list.end())
    {
        //item not in list
        // add to vector
        list.push_back(item);
    }

}

//display list of items
template <class U> void UserList<U>::countList()
{
    cout<<"Number of Users in list: "<<list.size()<<endl;
}
//size of list
template <class U> int UserList<U>::listSize()
{
    return list.size();
}