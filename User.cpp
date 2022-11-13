//
// Created by Gerald on 10/10/2022.
//

#include "User.h"

User::User() {
    Name ="";
    Alias = "";
    Password = "";
    UserType= NORMAL;
}
void User:: changeAlias(string a)
{
    setAlias(a);
}
User::User(string nm, string alias, string pwd) {
    Name =nm;
    Alias = alias;
    Password = pwd;
    UserType= NORMAL;
}
// return the UserType
int User:: getUserType() const
{
    return UserType;
}

// return the Name
string User::getName() const {
    return Name;
}

// return the Alias
string User::getAlias() const {
    return Alias;
}

// return the Password
string User::getPassword() const {
    return Password;
}

// return the Alias
void User::setAlias(string a) {
    Alias = a;
}

//set the UserType
void User:: setUserType(int i)
{
    UserType=i;
}

//set the name
void User::setName(string nm) {
    Name =nm;

}

// set the Password
void User::setPassword(string p) {
    Password = p;
}
