#include "UsersFiles.h"

UsersFiles::UsersFiles(string filename)
    :  XmlFile(filename)
{
}

void UsersFiles::addUserToFile(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId",user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password",user.getPassword());
    xml.AddElem("Name",user.getName());
    xml.AddElem("Surname",user.getSurname());

    xml.Save(getFileName());

}

vector <User> UsersFiles::loadUsersFromFile()
{
    User user;
    vector <User> users;
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (fileExists)
    {
        xml.FindElem("Users");
        xml.IntoElem();
        while(xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("UserId");
            user.setId(atoi(xml.GetData().c_str()));
            xml.FindElem("Login");
            user.setLogin(xml.GetData());
            xml.FindElem("Password");
            user.setPassword(xml.GetData());
            xml.FindElem("Name");
            user.setName(xml.GetData());
            xml.FindElem("Surname");
            user.setSurname(xml.GetData());

            xml.OutOfElem();

            users.push_back(user);
        }
    }
    return users;
}

vector <User> UsersFiles::changePasswordOfLoggedInUser(int idOfLoggedInUser,vector <User> users)
{
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = AncillaryMethods::getSingleLine();
    newPassword = AncillaryMethods::checkIfPasswordHasAtLeast4Character(newPassword);

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == idOfLoggedInUser)
        {
            users[i].setPassword(newPassword);
            cout << "The password has been changed." << endl << endl;
            system("pause");
        }
    }
    changePasswordInFile(idOfLoggedInUser,newPassword);

    return users;
}

void UsersFiles::changePasswordInFile(int idOfLoggedInUser,string newPassword)
{
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (fileExists)
    {
        xml.FindElem("Users");
        xml.IntoElem();

        while(xml.FindElem("User"))
        {
            xml.IntoElem();
            xml.FindElem("UserId");

            if(idOfLoggedInUser == atoi(xml.GetData().c_str()))
            {
                xml.FindElem("Password");
                xml.SetData(newPassword);
                break;
            }
            xml.OutOfElem();

        }
        xml.Save("users.xml");
    }
}


