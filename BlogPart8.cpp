#include <iostream>
#include <vector>
#include <fstream>
#include "Post.h"
#include "Area.h"
#include "User.h"
#include "SuperUser.h"
#include "UserList.h"
#include "UserList.cpp"

using namespace std;


////////////////////////////////////////////////////
// sets up Areas
void initAreas(vector<Area> *Areas);
//sets up Users
template <class T>
void initUsers(vector<T> *Users,UserList<User> *allUsers);
//display menu
void displayMenu();

//User selects an action
void promptAction(string &strCh);

//implement Action
template <class T>
void implementAction(vector<Area> *areas, string strCh, string strAlias, vector<T> *Users, int *index,UserList<User> *allUsers);
void DisplayBlogAreas(vector<Area> areas);
void DisplayPostsABlog(Area a);
void AddaPost(Area &a, string strAlias);
void DisplayAPost(int postId, Post p);
void EditaPost(int PostId,Area &a, string strAlias);
void DeleteAnArea(int AreaId, vector<Area> *areas,string strAlias);
//get a valid blog area id
int getValidBlogArea(int NumAreas);
// add a reaction
void AddaReaction(int PostId, Area &a, string strAlias);
//get a valid post id
int getValidPostId(Area a);

//get a valid string max chars
string getValidString(int maxChars);

//log in user
template <class T>
int Login(vector<T> *Users, int *index);

// Save data to file
void SaveData(vector<Area> areas);
//load data from file
void LoadData(vector<Area> *areas);
//
int main() {
    int index;

    vector<User> users;
    vector<Area> areas;
    //list of users
    UserList<User> allUsers;
    initUsers(&users, &allUsers);
    LoadData(&areas);
    //initAreas(&areas);

    //log in
    Login(&users, &index);

    string UserAction;
    do {
        promptAction(UserAction);
        implementAction(&areas, UserAction,users[index].getAlias(), &users, &index,&allUsers);

    } while ((UserAction != "Q") && (UserAction != "q"));
    //continue until user decides to quit


    return 0;
}
////////
template <class T>
int Login(vector<T> *Users, int *index)
{
    User u;
    string name;
    string password;
    do{
        cout<<"Login:"<<endl;
        cout<<"Name:";
        u.setName(getValidString(20));
        cout<<endl;
        cout<<"Password:";
        u.setPassword(getValidString(20));
        for(int i=0; i<6;i++) // loop through User vector and check if input matching existing member
        {
            if(Users->at(i).getName()==u.getName()&&Users->at(i).getPassword()==u.getPassword())
            {
                name=u.getName();
                password=u.getPassword();
                *index=i;
                if(i==0)
                {
                    cout<<"-----SUPER USER-----"<<endl;
                }
                cout<<"Hello "<<Users->at(*index).getName()<<endl;
                return i; //return index of instance User
            }
        }
    }while ((name != u.getName())||(password != u.getPassword()));

}



// sets up areas
void initAreas(vector<Area> *areas) {
    //init Com Sci
    Area a1,a2,a3,a4,a5;
    a1.setName("Com Sci");
    a1.setDescription("This blog is where people post about computer science.");

    //add a post to the Com Sci area
    Post p{"I love programming",
           "Programming is so much fun.",
           "Tom",
           0,
           0,
           0,
           0
    };
    a1.AddPost(p);

    //add another post to the Com Sci area
    Post p2;
    p2.setTitle("C++ versus Python");
    p2.setText("I like C++ more than Python.");
    p2.setUser("Sally");
    p2.setLoves(0);
    p2.setDislikes(0);
    p2.setLikes(0);
    p2.setHates(0);
    a1.AddPost(p2);

    areas->push_back(a1);

    //init Current Events
    a2.setName("Current Events");
    a2.setDescription("This blog is where people post current events.");

    //add a post to the Current Events area
    Post p3{"Picnic Saturday",
            "Join us at the park for a picnic on Saturday",
            "Sue",
            0,
            0,
            0,
            0
    };
    a2.AddPost(p3);
    areas->push_back(a2);


    //init Movies
    a3.setName("Movies");
    a3.setDescription("This blog is where people post things about movies.");
    //add a post to the Movies area
    p = {"My Fav Movie",
         "Star Wars",
         "Billy",
         0,
         0,
         0,
         0
    };
    a3.AddPost(p);
    //add a post to the Movies area
    p = {"Movie I despise",
         "The clock work orange",
         "Jean",
         0,
         0,
         0,
         0
    };
    a3.AddPost(p);
    areas->push_back(a3);

    //init Food
    a4.setName("Food");
    a4.setDescription("This blog is where people post things about food.");
    //add a post to the Food area
    p = {"My fav Pizza",
         "I love Pizza with extra cheese and onions",
         "Bailey",
         0,
         0,
         0,
         0};
    a4.AddPost(p);
    //add a post to the Food area
    p = {"Icecream",
         "I love coffe icecream with chocolate jimies",
         "Joe",
         0,
         0,
         0,
         0
    };
    a4.AddPost(p);
    areas->push_back(a4);

    //init Vacation
    a5.setName("Vacation");
    a5.setDescription("This blog is where people post things about vacations.");
    //add a post to the Vacation area
    p = {"Best place to Vacation",
         "Baniff Canada",
         "Kyle",
         0,
         0,
         0,
         0};
    a5.AddPost(p);
    //add a post to the Vacation area
    p = {"Worst Vacation",
         "Stayed at home",
         "Mary Jo",
         0,
         0,
         0,
         0};
    a5.AddPost(p);
    areas->push_back(a5);

}
//sets up users
template <class T>
void initUsers(vector<T> *Users, UserList<User> *allUsers)
{

    User u1,u2,u3,u4,u5,u6;
    u1=SuperUser("Gerald","Gerry","test123");

    Users->push_back(u1);
    u2=User("Kyle","Ksizle","test123");
    Users->push_back(u2);
    u3=User("Zachary","Zach","test123");
    Users->push_back(u3);
    u4=User("Hannah","Gracie","test123");
    Users->push_back(u4);
    u5=User("Skylar","Sky","test123");
    Users->push_back(u5);
    u6=User("Isabel","Izzy","test123");
    Users->push_back(u6);
    allUsers->addToList(&u1);
    allUsers->addToList(&u2);
    allUsers->addToList(&u3);
    allUsers->addToList(&u4);
    allUsers->addToList(&u5);
    allUsers->addToList(&u6);

}
//delete an area
void DeleteAnArea(int AreaId, vector<Area> *areas,string strAlias)
{
        areas->erase(areas->begin()+AreaId);
}
//change alias



//display menu
void displayMenu() {
    cout << "Please select from the following options..." << endl;
    cout << " A  - Display Blog areas" << endl;
    cout << " B  - Display all posts for a blog" << endl;
    cout << " C  - Add a post to a blog" << endl;
    cout << " D  - Display a post for a blog" << endl;
    cout << " E  - Edit a post for a blog" << endl;
    cout << " F  - Delete a post for a blog" << endl;
    cout << " G  - Love/Like/Dislike/Hate a post"<<endl;
    cout << " H  - Delete an area"<<endl;
    cout << " I  - Change your alias"<<endl;
    cout << " Z  - Display all users"<<endl;
    cout << " Q  - Quit" << endl;
}

//User Action
void promptAction(string &strCh) {
    displayMenu();

    //prompt user for choice
    cout << "What would you like to do?" << endl;
    cin >> strCh;
}

//implement Users Action
template <class T>
void implementAction(vector<Area> *areas, string strCh, string strAlias, vector<T> *Users, int *index,UserList<User> *allUsers) {
    if ((strCh == "A") || (strCh == "a")) {
        DisplayBlogAreas(*areas);
    } else if ((strCh == "B") || (strCh == "b")) {
        cout << "Display all posts for a blog..." << endl;
        int blogId = getValidBlogArea(areas->size());
        DisplayPostsABlog((*areas)[blogId]);
    } else if ((strCh == "C") || (strCh == "c")) {
        cout << "Add a post to a blog..." << endl;
        int blogId = getValidBlogArea(areas->size());
        AddaPost((*areas)[blogId], strAlias);
    } else if ((strCh == "D") || (strCh == "d")) {
        cout << "Display a post for a blog..." << endl;
        int blogId = getValidBlogArea(areas->size());
        Area area = (*areas)[blogId];
        int postId = getValidPostId(area);
        Post p;
        bool found = (*areas)[blogId].getPost(postId, p);
        if (found) {
            DisplayAPost(postId, p);
        }
    }
    else if ((strCh == "E") || (strCh == "e")) {
        cout << "Edit a post for a blog..." << endl;
        int blogId = getValidBlogArea(areas->size());
        int postId = getValidPostId((*areas)[blogId]);
        Post p;
        bool found = (*areas)[blogId].getPost(postId, p);
        if (found) {
            DisplayAPost(postId, p);
            EditaPost(postId,(*areas)[blogId], strAlias);
        }
    }
    else if ((strCh == "F") || (strCh == "f")) {
        cout << "Delete a post for a blog..." << endl;
        int blogId = getValidBlogArea(areas->size());
        int postId = getValidPostId((*areas)[blogId]);
        (*areas)[blogId].deletePost(postId);
        cout<<"Post deleted"<<endl;
    }
    else if((strCh == "G") || (strCh == "g")) {
        cout<< "Love/Like/Dislike/Hate a post....."<<endl;
        int blogId = getValidBlogArea(areas->size());
        int postId = getValidPostId((*areas)[blogId]);
        Post p;
        bool found = (*areas)[blogId].getPost(postId, p);
        if (found) {
            AddaReaction(postId,(*areas)[blogId], strAlias);
        }
    }
    else if((strCh == "H") || (strCh == "h"))
    {
        cout<< "Delete an area....."<<endl;
        if(strAlias==Users->at(0).getAlias())
        {
            int blogId = getValidBlogArea(areas->size());
            DeleteAnArea(blogId,areas, strAlias);
        }
        else {
            cout << "You are not a super user and do not have permissions to perform this action."<<endl;
        }
    }
    else if((strCh == "I") || (strCh == "i"))
    {
        cout<< "Change your alias....."<<endl;
        cin.ignore();
        if(strAlias==Users->at(0).getAlias())
        {
            cout<< "Please enter in your new alias....."<<endl;
            Users->at(*index).changeAlias(getValidString(20));
        }
        else
        {
            cout<<"You are not a super user and do not have permissions to perform this action."<<endl;
        }
    }
    else if((strCh == "Z") || (strCh == "z"))
    {
        cout<< "Display all users....."<<endl;
        cin.ignore();
        if(strAlias==Users->at(0).getAlias())
        {
            int count=0;
            allUsers->countList();
            while(count<=allUsers->listSize()-1)
            {

                cout<<"Name: "<<Users->at(count).getName()<<endl;
                count++;
            }
        }
        else
        {
            cout<<"You are not a super user and do not have permissions to perform this action."<<endl;
        }
    }
    else if ((strCh == "Q") || (strCh == "q")) {
        //user has selected to quit
        cout << "Bye..." << endl;
        SaveData(*areas);
    } else {
        //user has selected an invalid option
        cout << strCh << " is not a valid option." << endl;
    }
}

////////////////////////////
void DisplayBlogAreas(vector<Area> areas) {
    cout << "Display Blog areas..." << endl;
    //user has selected to display blog areas
    for (int i = 0; i < areas.size(); i++) {
        cout << "Area Index:" << i << endl;
        cout << areas[i];
        cout << "******************" << endl;
    }

}

//////////////////
void DisplayPostsABlog(Area a) {
    cout << "Posts for " << a.getName() << endl;

    //user has selected to display blog areas
    for (int i = 0; i <= a.getIndxLastPost(); i++) {
        Post p;
        bool found = a.getPost(i, p);
        if (found) {
            cout << "Post Index:" << i << endl;
            cout << p;
            if(p.getLikes()==0 && p.getDislikes()==0 && p.getHates()==0 && p.getLoves()==0)
            {
                cout<<"There are no posted responses to this."<<endl;
            }
            else
            {
                cout<<"Num Love   = "<< p.getLoves()<<endl;
                cout<<"Num Like   = "<< p.getLikes()<<endl;
                cout<<"Num Dislike   = "<< p.getDislikes()<<endl;
                cout<<"Num Hate   = "<< p.getHates()<<endl;
            }
            cout << "******************" << endl;
        }
    }

}
/////////////////
void AddaPost(Area &a, string strAlias)
{
    cin.ignore();

    Post p;
    string Title;
    do {
        cout << "Please enter in the title..." << endl;
        Title = getValidString(20);
        p.setTitle(Title);
    }  while (!a.UniqueNewPost(p));


    cout << "Please enter in the text..." << endl;
    string Text = getValidString(500);

    p.setText(Text);
    p.setUser(strAlias);

    if (a.AddPost(p))
        cout << "Post successfully added" << endl;
    else
        cout << "Error adding Post " << endl;

}
void EditaPost(int PostId,Area &a, string strAlias)
{
    cin.ignore();
    Post p;
    string Title;
    do {
        cout << "Please enter in the title..." << endl;
        Title = getValidString(20);
        p.setTitle(Title);
    }  while (!a.UniqueNewPost(p));

    cout << "Please enter in the text..." << endl;
    string Text = getValidString(500);

    p.setText(Text);
    p.setUser(strAlias);


    if (a.EditAPost(PostId, p)) {
        cout<<"Post Editted"<<endl;
    }


}
void AddaReaction(int PostId, Area &a, string strAlias)
{
    cin.ignore();
    Post p;
    int reaction;

    cout<<"Select"<<endl;
    cout<<" 1 = Love"<<endl;
    cout<<" 2 = Like"<<endl;
    cout<<" 3 = Dislike"<<endl;
    cout<<" 4 = Hate"<<endl;

    do{
        cin>>reaction;
        if(reaction==1)
        {
            int l=1;
            p.setLoves(l);
        }
        else if (reaction==2)
        {
            int l=1;
            p.setLikes(l);
        }
        else if(reaction==3)
        {
            int dL=1;
            p.setDislikes(dL);
        }
        else if(reaction==4)
        {
            int h=1;
            p.setHates(h);
        }
        else
        {
            cout<<"Invalid reaction."<<endl;
        }
    }while(reaction>4 || reaction<1);

    if (a.AddaReaction(PostId, p)) {
        cout<<"Response to Post Saved."<<endl;
    }
}

/////////////////
void DisplayAPost(int postId, Post p)
{
    cout << "Post Index:" << postId << endl;
    cout << p << endl;
    if(p.getLikes()==0 && p.getDislikes()==0 && p.getHates()==0 && p.getLoves()==0)
    {
        cout<<"There are no posted responses to this."<<endl;
    }
    else
    {
        cout<<"Num Love   = "<< p.getLoves()<<endl;
        cout<<"Num Like   = "<< p.getLikes()<<endl;
        cout<<"Num Dislike   = "<< p.getDislikes()<<endl;
        cout<<"Num Hate   = "<< p.getHates()<<endl;

    }
    cout << "******************" << endl;
}


//////////////
int getValidBlogArea(int NUM_AREAS) {
    int area;
    cout << "Please enter in a Blog Area Index" << endl;
    cin >> area;
    while ((area < 0) || (area >= NUM_AREAS)) {
        cout << "Please enter in a Blog Area Index" << endl;
        cin >> area;
    }
    return area;
}

///////////////
int getValidPostId(Area area) {
    int PostId;
    do {
        cout << "Please enter in a valid post id for area: " << area.getName() << endl;
        cin >> PostId;
    } while ((PostId < 0) || (PostId > area.getIndxLastPost()));
    return PostId;
}


////////////////////////
/////////////////////////

///////////////////////////////////////
const std::string WHITESPACE = " \n\r\t\f\v";

///////////////////////////
string ltrim(const std::string &s) {
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

string rtrim(const std::string &s) {
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

string getValidString(int maxChars) {
    string text;
    do {
        cout << "Please enter in a string with at least 1 character and at most " << maxChars << " characters." << endl;
        getline(cin, text);
        text = trim(text);
    } while ((text.length() == 0) || (text.length() > maxChars));
    return text;
}


void SaveData(vector<Area> areas)
{
    ofstream outputFile("BlogData.txt");
    if (outputFile.fail( ))
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    //cout << "Output file opened.\n";
    for (int i = 0; i < areas.size(); i++) {
        outputFile << areas[i].getName()<<endl;
        outputFile << areas[i].getDescription()<<endl;
        outputFile << areas[i].getIndxLastPost()<<endl;
        for (int j = 0; j < areas[i].getIndxLastPost(); j++) {
            Post p;
            bool found = areas[i].getPost(j, p);
            if (found) {
                outputFile << p.getTitle()<<endl;
                outputFile << p.getUser()<<endl;
                outputFile << p.getText()<<endl;
                outputFile <<p.getLoves()<<endl;
                outputFile << p.getLikes()<<endl;
                outputFile <<p.getDislikes()<<endl;
                outputFile <<p.getHates()<<endl;
            }
        }

    }


    //close file
    outputFile.close( );
}

void LoadData(vector<Area> *areas)
{
    ifstream fin("BlogData.txt");

    if (fin.fail( ))
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    //cout << "Output file opened.\n";
    string strName;
    while (getline(fin,strName)) {
        string strDescription;
        getline(fin,strDescription);
        Area a;
        a.setName(strName);
        a.setDescription(strDescription);
        //cout<<strName<<endl;
        //cout<<strDescription<<endl;
        int NumPosts;
        fin>>NumPosts;
        //cout<<NumPosts<<endl;
        fin.ignore();
        for (int i=0;i<NumPosts;i++)
        {
            string strTitle, strUser, strText,lo, li, dL, h;
            getline(fin,strTitle);
            getline(fin,strUser);
            getline(fin,strText);
            getline(fin,lo);
            getline(fin,li);
            getline(fin,dL);
            getline(fin,h);
            int hate=stoi(h);
            int love=stoi(lo);
            int like=stoi(li);
            int dislike=stoi(dL);
            Post p {strTitle,strUser,strText, love, like,  dislike,  hate};
            a.AddPost(p);
        }
        areas->push_back(a);
    }
    //close file
    fin.close( );

}
