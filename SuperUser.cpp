//
// Created by Gerald Martinez on 10/12/22.
//
#include <string>
#include "SuperUser.h"
using namespace std;

SuperUser::SuperUser() :User()
{
    Name ="";
    Alias = "";
    Password = "";
    UserType=SUPERUSER;
}
SuperUser::SuperUser(string nm,  string alias, string pwd) : User( nm, alias, pwd)
{
    Name =nm;
    Alias = alias;
    Password = pwd;
    UserType=SUPERUSER;
}
//return UserType
int SuperUser::getUserType() const
{
    return UserType;
}

// return the Name
string SuperUser::getName() const {
    return Name;
}

// return the Alias
string SuperUser::getAlias() const {
    return Alias;
}

// return the Password
string SuperUser::getPassword() const {
    return Password;
}

// return the Alias
void SuperUser::setAlias(string a) {
    Alias = a;
}

// set the UserType
void SuperUser:: setUserType(int i)
{
    UserType=i;
}
void SuperUser:: changeAlias(string a)
{
    setAlias(a);
}
void SuperUser::setName(string nm) {
    Name =nm;

}
// set the Password
void SuperUser::setPassword(string p) {
    Password = p;
}
//delete a an area

