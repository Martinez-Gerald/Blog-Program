//
// Created by Gerald Martinez on 10/12/22.
//

#ifndef BLOGPART4_SUPERUSER_H
#define BLOGPART4_SUPERUSER_H
#include "User.h"
#include <string>

class SuperUser : public User
        {
        public:
            SuperUser();
            SuperUser( string nm,  string alias, string pwd);
    //return UserType
    int getUserType() const;
    // return the Name
    string getName() const;

    // return the Alias
    string getAlias() const;

    // return the Password
    string getPassword() const;

    // return the Alias
    void setAlias(string a);

    // set User type
    void setUserType(int i);
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


#endif //BLOGPART4_SUPERUSER_H
