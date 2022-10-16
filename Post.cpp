//
// Created by 18604 on 3/10/2022.
//

#include "Post.h"

Post::Post() {
    this->Title = "";
    this->Text = "";
    this->User = "";
    this->love=0;
    this->like=0;
    this->hate=0;
    this->dislike=0;
}

Post::Post(string txt, string t, string u, int lo,int li, int dL, int h) {
    this->Title = t;
    this->Text = txt;
    this->User = u;
    this->love=lo;
    this->like=li;
    this->hate=h;
    this->dislike=dL;
}

//
int Post::getLikes()
{
    return this->like;
}

int Post::getLoves()
{
    return this->love;
}

int Post::getHates()
{
    return this->hate;
}

int Post::getDislikes()
{
    return this-> dislike;
}
// return the likes
int Post::setLikes(int l)
{
    this->like += l;
}

int Post::setLoves(int l)
{
    this->love += l;
}

int Post::setHates(int h)
{
    this->hate+= h;
}

int Post::setDislikes(int d)
{
    this->dislike += d;
}

// return the Title
string Post::getTitle() const {
    return this->Title;
};

// return the Text
string Post::getText() const {
    return this->Text;
};

// return the User
string Post::getUser() const {
    return this->User;
};

// return the Title
void Post::setTitle(string t) {
    this->Title = t;
};

// return the Text
void Post::setText(string txt) {
    this->Text = txt;
};

// set the User
void Post::setUser(string u) {
    this->User = u;
};

//overload <<
//overload <<
ostream& operator <<(ostream& outputStream, const Post& p)
{
    outputStream << "Title:" << p.Title << endl;
    outputStream << "By:" << p.User << endl;
    outputStream << "Text:" << p.Text << endl;
    return outputStream;
}

//overload ==
bool Post::operator==(const Post& otherPost)
{
    return (this->Title==otherPost.Title);
}
