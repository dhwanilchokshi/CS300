
#include "Provider_Directory.h"



int main()
{
    ifstream file;
    
    file.open("Provider_Directory.txt");
    
    if (!file.is_open())
        cout << "Unable to find/open the test file!";
    else if (file.eof())
        cout << "The file is empty!\n";
    else
    {
        Provider_Directory list;
        while (!file.eof())
        {
            string name, code, cost;
            getline(file, name);
            getline(file, code);
            getline(file, cost);
            list.insert_service(name, code, cost); //add a service to the list of services (tree)
        }
        list.display_services();
    }
    file.close();
    file.clear();
    return 1;
}

//end