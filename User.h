//
// Created by 18604 on 3/10/2022.
//
#include <iostream>

// students - you need to put program header here
using namespace std;


#ifndef BLOGPART3_USER_H
#define BLOGPART3_USER_H


class User {
public:
    User();
    User(string nm, string alias, string pwd);
    enum UserTypes {NORMAL,SUPERUSER};
    //return the UserType
    int getUserType() const;

    // return the Name
    string getName() const;

    // return the Alias
    string getAlias() const;

    // return the Password
    string getPassword() const;

    //set the UserType
    void setUserType(int i);

    // return the Alias
    void setAlias(string a);

    //
    void setName(string nm);

    // set the Password
    void setPassword(string p);

private:
    string Alias; //title
    string Password; //title
    string Name;
    int UserType;
};


#endif //BLOGPART3_USER_H
