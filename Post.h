//
// Created by 18604 on 3/10/2022.
//

#include <iostream>

// students - you need to put program header here
using namespace std;

#ifndef BLOGPART3_POST_H
#define BLOGPART3_POST_H
//////////////////////////////////////////////////////
//structure for post
class Post {
public:

    Post();
    Post(string txt, string t, string u, int lo,int li, int dL, int h);
    //return the number of likes
    int getLikes();
    int getLoves();
    int getHates();
    int getDislikes();
    //set the number of likes
    int setLikes(int l);
    int setLoves(int l);
    int setHates(int h);
    int setDislikes(int d);

    // return the Title
    string getTitle() const;

    // return the Text
    string getText() const;

    // return the User
    string getUser() const;

    // return the Title
    void setTitle(string t);

    // return the Text
    void setText(string txt);

    // set the User
    void setUser(string u);

//overload <<
    friend ostream& operator <<(ostream& outputStream, const Post& p);

    //overload ==
    bool operator ==(const Post& otherPost);


private:
    string Title; //title
    string Text; //title
    string User;
    int love;
    int like;
    int hate;
    int dislike;
};

#endif //BLOGPART3_POST_H
