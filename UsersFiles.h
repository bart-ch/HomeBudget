#ifndef USERSFILES_H
#define USERSFILES_H

#include "User.h"
#include "Markup.h"
#include "AncillaryMethods.h"
#include "XmlFile.h"
#include <vector>

using namespace std;

class UsersFiles :public XmlFile
{
    void changePasswordInFile(int idOfLoggedInUser,string newPassword);

public:
    UsersFiles(string filename);
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    vector <User> changePasswordOfLoggedInUser(int idOfLoggedInUser,vector <User> users);

};

#endif // USERSFILES_H
