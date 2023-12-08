//libs
#include <iostream>
#include <fstream>
#include <string>
//useful shortcuts
void Cout(std::string val) {
    std::cout << val << std::endl;
}
void IntCin(int val) {
    std::cout << val << std::endl;
}
void Cin(std::string& var,const std::string& text) {
    std::cout << text << ' ';
    std::getline(std::cin, var);
}
void Error(){
     std::cerr << "Error: now run for your life >:)" << std::endl;
}
//guts of the code
bool Login(std::string& username, std::string& password){
std::ifstream Logs("Logs.txt");
    if (!Logs)
    {
        Error();
        return 1;
    }
    else{
        std::string DataName, DataPass;
        while(Logs >> DataName >> DataPass){
            if (DataName == username && DataPass == password){
                std::cout<< "Welcome " << username << ".Hope you enjoy using our service!" << std::endl;
                return true;
            }
            
        }
        return false;
}
}
void Register(std::string& username, std::string& password){
    std::fstream Logs("Logs.txt", std::ios::in |std::ios::app);
   if (!Logs.is_open()) {
        Error();
    } else {
        // Check if the username already exists
        std::string existingUsername;
        bool usernameExists = false;

        while (Logs >> existingUsername) {
            if (existingUsername == username) {
                Cout("Username already exists. Please choose a different username.");
                usernameExists = true;
                break;
            }
        }

        //adding da user
        if (!usernameExists) {
            Logs.clear(); // Clear eof coz yes

            // skip life
            Logs.seekp(0, std::ios::end);

            Logs << username << ' ' << password << std::endl;
            Cout("Welcome, We hope you enjoy our service!");
        } else {
            Cout("Registration failed. Username already exists.");
        }
    }
}
    
int main(){
    Cout("test");
    std::string method;
        Cout("============================================================");
        Cout("Welcome to the Service that is prob useless \n");
        Cin(method,"PICK EITHER LOGGING IN OR SIGNING UP [L/S]:");
        Cout("============================================================");
        std::string username, password;
        if (method == "L" || method == "l"){
            do
            {
            Cin(username, "Please enter your username:");
            Cin(password, "Please enter your password:");
            }while (!Login(username, password));
        }
        else if (method == "S" || method == "s")
        {
            Cin(username, "Please enter a new username:");
            Cin(password, "Please enter a new password:");
            Register(username, password);
        }
        else
        {
            Cout("How about you crash out of my life idiot");
        }
        
        
        return 0;
    }

    
    
