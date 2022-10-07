/*features: 
 - Add Client name
 - Assign Client registration number
 - Add Client's phone number, home address, and email
 - Modify Client's data
 - Delete Client's data
*/
#include <fstream>
#include <iostream>
#include <stdio.h>
#include<ios> //used to get stream size
#include<limits> 
#include <string.h>
#include <stdbool.h>
#include <vector>

using namespace std; 
int count = 0; 
int main()
{
    int input; 
    string deleteData;
    string clientFirstName; 
    string clientLastName; 
    string clientMiddleName; 
    char clientAddress[100]; 
    string clientEmail; 
    string clientPhonenumber; 
    int RegistrationID = 0;
    
    cout << "|------------Menu------------|"<< endl; 
    cout << "   1: Register Client Data"<< endl; 
    cout << "   2: Modify Client Data"<< endl; 
    cout << "   3: Delete Client Data"<< endl; 
    cout << "   4: Exit Program"<< endl; 
    cin >> input; 

    if (input == 1){ //Register Client Data
        cout << "Enter Client Name: "; 
        cin >> clientFirstName;
        cin >> clientMiddleName; // if none type NA
        cin >> clientLastName; 
        cout <<endl; 
            
        cout << "Assign Registration ID: ";
        cin >> RegistrationID; 
        cout <<endl; 
            
        cout << "Enter Address: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(clientAddress,100);
        cout <<endl; 
            
        cout << "Enter Email Address: ";
        cin >> clientEmail; 
        cout <<endl; 
            
        cout << "Enter Phone Number: ";
        cin >> clientPhonenumber; 
        cout <<endl; 
            
            
        ofstream file;
		file.open(clientFirstName + clientMiddleName + clientLastName + ".txt");
		file << "Name: " << clientFirstName << " " << clientMiddleName << " " << clientLastName << endl; 
		file << "RegistrationID: " << RegistrationID<< endl; 
		file << "Mailing Address: " << clientAddress<< endl; 
		file << "Email: " << clientEmail<< endl; 
		file << "Phone Number: " << clientPhonenumber<< endl; 
		    
		file.close();
		count++;
		main();
    }
    else if (input == 2){ //Modify Client Data
        string moddedFirstName; 
        string moddedMiddleName; 
        string moddedLastName; 
        char moddedAddress[100];
        string moddedEmail; 
        string moddedNumber; 
        string filename; 
        int line_number; 
        
        cout << "Choose the line you wish to modify: " <<endl; 
        cout << "   0: Change Client Name" << endl;
        cout << "   1: Client RegistrationID is Unchangeable" << endl;
        cout << "   2: Change Client Address" << endl;
        cout << "   3: Change Client Email" << endl;
        cout << "   4: Change Client Phone Number" << endl;
        cout << "Chose: "; 
        cin >> line_number; 
        cout << endl; 
        cout << "Enter file name: ";
        cin >> filename; 
        cout << endl; 
        
        fstream read_file; 
        read_file.open(filename);
        
        if (read_file.fail()){
            cout << "Error Opening File." << endl;
            return 1; 
        }
        vector <string> lines; 
        string line; 
        
        while (getline(read_file,line))
            lines.push_back(line);
            
        read_file.close(); 
        if (line_number > lines.size()){
            cout << "Line " << line_number; 
            cout << " not in file." << endl; 
            cout << "File has " << lines.size(); 
            cout << " lines." << endl; 
            
            return 1; 
        }
        
        ofstream write_file; 
        write_file.open(filename); 
        
        if (write_file.fail()){
            cout << "Error opening file." << endl; 
            return 1;
        }
        
        for (int i = 0; i < lines.size(); i++){
            if (i != line_number){
                write_file << lines[i] << endl; 
            
            }else if (line_number == 0){ //name 
                cout << "Enter New First Name: "; 
                cin >> moddedFirstName; 
                cout << "\nEnter New Middle Name";
                cin >> moddedMiddleName; 
                cout << "\nEnter New Last Name";
                cin >> moddedLastName;
                cout << endl; 
                write_file << "Name: " << moddedFirstName << " " << moddedMiddleName << " " << moddedLastName << endl;

            }else if (line_number == 1){ //reg id
                write_file << lines[1] << endl; 
            
                
            }else if (line_number == 2){//address
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.getline(moddedAddress,100);
                cout <<endl; 
                write_file << "Mailing Address: " << moddedAddress << endl; 
            }else if (line_number == 3){ //Email
                cout << "Enter New Email Address: ";
                cin >> moddedEmail; 
                cout <<endl; 
                write_file << "Email: " << moddedEmail << endl; 
            }else if (line_number == 4){
                cout << "Enter New Phone Number: ";
                cin >> moddedNumber; 
                cout <<endl;
                write_file << "Phone Number: " << moddedNumber << endl; 
            }
         
        }
        
        
        write_file.close(); 
        main(); 
    }
    else if (input == 3){ //Delete Client Data
        int status;
        char fileName[80];
        cout<<"Enter the Name of File (Client Name + .txt): ";
        cin>>fileName; //remember to include client full name + ".txt"
    
        cout << "Warning: You are about to delete Client Data" << endl;
        cout << "Do you wish to continue? Type Yes or No " << endl;
        cin >> deleteData; 
        if (deleteData == "yes" || deleteData == "Yes"){
            status = remove(fileName);
            if(status==0)
                cout<<"\nFile Deleted Successfully!" << endl;
            else
                cout<<"\nError Occurred! No such file found." << endl;
            cout << "Returning back to the main menu" << endl;
            main(); 
            
        }
        else if (deleteData == "no" || deleteData == "No"){
            cout << "\n No files deleted" << endl; 
            cout << "Returning back to the main menu" << endl;
            main(); 
        }
    }
    else{
        cout << "Thank you for using our services." << endl; 
        cout << "Goodbye now!" << endl; 
        
        exit(3);
    }
    
    return 0;
}

