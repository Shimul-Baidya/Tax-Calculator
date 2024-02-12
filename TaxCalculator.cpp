#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits> // For clearing input buffer

using namespace std;

void clearScreen() {
    cout << "\033[2J\033[H";  // ANSI escape sequence to clear screen
}

class TaxRate {
public:
    void displayrate() {
        cout << "Next 100000     |    5%  " << endl;
        cout << "Next 300000     |   10%  " << endl;
        cout << "Next 400000     |   15%  " << endl;
        cout << "Next 500000     |   20%  " << endl;
        cout << "Rest            |   25%  " << endl;
    }
};

class TaxSlabGeneral {
protected:
    string zone, gender;
    double amount;
    int age;
public:
    TaxSlabGeneral(string z, string g, double amnt, int a) {
        zone = z;
        amount = amnt;
        gender = g;
        age = a;
    }
    virtual void displaytaxslab() = 0;
};

class TaxSlabMale : public TaxSlabGeneral {
private:
    int taxfreeamnt;
public:
    TaxSlabMale(string z, string g, double amnt, int a) : TaxSlabGeneral(z, g, amnt, a) {
        taxfreeamnt = 350000;
    }
    void displaytaxslab() override {
        cout << endl <<"Gender is: "<< gender << endl;
        cout << "Age is: " << age << endl;
        cout << "The zone is: " << zone << endl;
        cout << "Amount you have given: "<< amount << endl;
        cout << "As you are Male following this taxSlab you Tax is going to be dictated: " << endl << endl;;
        cout << "~~~~~Amount~~~~~|~~~~~Percentage of tax(%)     "<<endl;
        cout << "1st **"<<taxfreeamnt<<"    |    0%  " << endl;
    }
};

class TaxSlabFemale : public TaxSlabGeneral {
private:
    int taxfreeamnt;
public:
    TaxSlabFemale(string z, string g, double amnt, int a) : TaxSlabGeneral(z, g, amnt, a) {
        taxfreeamnt = 400000;
    }
    void displaytaxslab() override {
        cout << endl <<"Gender is: "<< gender << endl;
        cout << "Age is: " << age << endl;
        cout << "The zone is: " << zone << endl;
        cout << "Amount you have given: "<< amount << endl;
        cout << "As you are Female following this taxSlab you Tax is going to be dictated: " << endl << endl;;
        cout << "~~~~~Amount~~~~~|~~~~~Percentage of tax(%)     "<<endl;
        cout << "1st **"<<taxfreeamnt<<"    |    0%  " << endl;
    }
};

class TaxSlab3genorpch : public TaxSlabGeneral {
private:
    int taxfreeamnt;
public:
    TaxSlab3genorpch(string z, string g, double amnt, int a) : TaxSlabGeneral(z, g, amnt, a) {
        taxfreeamnt = 475000;
    }
    void displaytaxslab() override {
        cout << endl <<"Gender is: "<< gender << endl;
        cout << "Age is: " << age << endl;
        cout << "The zone is: " << zone << endl;
        cout << "Amount you have given: "<< amount << endl;
        cout << "As you are Physically challenged/3rd gender following this taxSlab you Tax is going to be dictated: " << endl << endl;;
        cout << "~~~~~Amount~~~~~|~~~~~Percentage of tax(%)     "<<endl;
        cout << "1st **"<<taxfreeamnt<<"    |    0%  " << endl;
    }
};

class TaxSlabFreedomF : public TaxSlabGeneral {
private:
    int taxfreeamnt;
public:
    TaxSlabFreedomF(string z, string g, double amnt, int a) : TaxSlabGeneral(z, g, amnt, a) {
        taxfreeamnt = 500000;
    }
    void displaytaxslab() override {
        cout << endl <<"Gender is: "<< gender << endl;
        cout << "Age is: " << age << endl;
        cout << "The zone is: " << zone << endl;
        cout << "Amount you have given: "<< amount << endl;
        cout << "As you are Freedom Fighter following this taxSlab you Tax is going to be dictated: " << endl << endl;;
        cout << "~~~~~Amount~~~~~|~~~~~Percentage of tax(%)     "<<endl;
        cout << "1st **"<<taxfreeamnt<<"    |    0%  " << endl;
    }
};

class IncomeDetails {
private:
    bool detailsEntered; // Flag to track if income details have been entered
    double avgMonthlyIncome; // Average monthly income
    string incomesource;
    double basicsal, houserent, medical, transport, convenyance;
    double incentiv, festivbonus;
    double extra;
    string zon, gen;
    double a, tax;
    int ag;

public:
    IncomeDetails() : detailsEntered(false), avgMonthlyIncome(0) {
        loadFromFile(); // Load income details from file during initialization
    }

    void getdetails();
    double calculateAvgMonthlyIncome();
    void display();
    void saveToFile();
    void loadFromFile();
    bool isDetailsEntered() { return detailsEntered; }
};

void IncomeDetails::getdetails() {
    cout << "Enter the Income Source Type      : ";
    cin >> incomesource;
    cout << "Enter the Basic Salary            : ";
    cin >> basicsal;
    cout << "Enter the House rent              : ";
    cin >> houserent;
    cout << "Enter the Medical Expenses        : ";
    cin >> medical;
    cout << "Enter the Transportation Expenses : ";
    cin >> transport;
    cout << "Enter the Conveyance              : ";
    cin >> convenyance;
    cout << "Enter the Incentives              : ";
    cin >> incentiv;
    cout << "Enter the Festival Bonuses        : ";
    cin >> festivbonus;
    cout << "Enter the Extra if any otherwise 0: ";
    cin >> extra;

    // Additional user information
    cout << "Enter your Gender( Male, Female, physically challenged/3rd gender, Freedom Fighter(Gazeted)): ";
    cin >> gen;
    cout << "Enter your Area Zone: ";
    cin >> zon;
    cout << "Enter your Age: ";
    cin >> ag;

    detailsEntered = true; // Set flag to true after details are entered
    avgMonthlyIncome = calculateAvgMonthlyIncome(); // Calculate average monthly income
    saveToFile(); // Save details to file
}

double IncomeDetails::calculateAvgMonthlyIncome() {
    double monthlyFestivBonus = festivbonus / 12; // Divide yearly bonus by 12 to get monthly bonus
    return basicsal + houserent + medical + transport + convenyance + incentiv + monthlyFestivBonus + extra;
}

void IncomeDetails::display() {
    if (detailsEntered) {
        cout << "Income Source Type       : " << incomesource << endl;
        cout << "Basic Salary of the month: " << basicsal << endl;
        cout << "House rent               : " << houserent << endl;
        cout << "Medical Expenses         : " << medical << endl;
        cout << "Transportation Expenses  : " << transport << endl;
        cout << "Conveyance               : " << convenyance << endl;
        cout << "Incentives               : " << incentiv << endl;
        cout << "Festival Bonuses         : " << festivbonus << endl;
        cout << "Extra                    : " << extra << endl;
        cout << "Average Monthly Income   : " << avgMonthlyIncome << endl;

        // Additional user information
        cout << "Gender                   : " << gen << endl;
        cout << "Area Zone                : " << zon << endl;
        cout << "Age                      : " << ag << endl;
    } else {
        cout << "Income details have not been entered yet." << endl;
    }
}

void IncomeDetails::saveToFile() {
    ofstream outFile("income_details.txt", ios::app);
    if (outFile.is_open()) {
        outFile << incomesource << " " << basicsal << " " << houserent << " " << medical << " " << transport << " "
                << convenyance << " " << incentiv << " " << festivbonus << " " << extra << " " << gen << " " << zon << " "
                << ag << " " << avgMonthlyIncome << endl;
        outFile.close();
    } else {
        cout << "Unable to open file for saving income details." << endl;
    }
}

void IncomeDetails::loadFromFile() {
    ifstream inFile("income_details.txt");
    if (inFile.is_open()) {
        while (inFile >> incomesource >> basicsal >> houserent >> medical >> transport >> convenyance >> incentiv >>
               festivbonus >> extra >> gen >> zon >> ag >> avgMonthlyIncome) {
            // Read data from file
        }
        inFile.close();
    } else {
        cout << "No income details found." << endl;
    }
}

class Taxcalculator {
private:
    double totalamnt;
public:
    double calculateTax(double famnt) {
        totalamnt = famnt;
        double tax = 0;
        int cnt;
        while (totalamnt > 0) {
            if (totalamnt >= 100000) {
                tax += 100000 * (5.0 / 100);
                totalamnt -= 100000;
                cnt=1;
            }
            if (totalamnt >= 300000) {
                tax += 300000 * (10.0 / 100);
                totalamnt -= 300000;
                cnt=2;
            }
            if (totalamnt >= 400000) {
                tax += 400000 * (15.0 / 100);
                totalamnt -= 400000;
                cnt=3;
            }
            if (totalamnt >= 500000) {
                tax += 500000 * (20.0 / 100);
                totalamnt -= 500000;
                cnt=4;
            } else {
                if(cnt == 1)
                    tax += totalamnt * (10.0 / 100);
                else if(cnt == 2)
                    tax += totalamnt * (15.0/100);
                else if(cnt == 3)
                    tax += totalamnt * (20.0 / 100);
                else if(cnt == 4)
                    tax += totalamnt * (25.0/100);
                totalamnt = 0;
            }
        }
        return tax;
    }
};

class User {
private:
    IncomeDetails incomeDetails;
    Taxcalculator taxCalculator;

public:
    void updateIncomeDetails() {
        cout << "Update Income Details:" << endl;
        incomeDetails.getdetails(); // Get income details from user
        cout << "\nPress any key to return to the user profile menu...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get(); // Wait for user to press any key
    }

    void viewIncomeDetails() {
        cout << "View Income Details:" << endl;
        incomeDetails.loadFromFile(); // Load income details from file
        incomeDetails.display();
        if (!incomeDetails.isDetailsEntered()) {
            cout << "\nPlease update your income details first." << endl;
            cout << "Press any key to update your income details...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); // Wait for user to press any key
            updateIncomeDetails();
        } else {
            cout << "\nPress any key to return to the user profile menu...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); // Wait for user to press any key
        }
    }

    void calculateTax() {
        if (incomeDetails.isDetailsEntered()) {
            TaxRate taxRate;
            cout << "Tax Rates:" << endl;
            taxRate.displayrate();
            cout << endl;
            cout << "Monthly Tax: " << taxCalculator.calculateTax(incomeDetails.calculateAvgMonthlyIncome()) << endl;
            cout << "\nPress any key to return to the user profile menu...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); // Wait for user to press any key
        } else {
            cout << "Please enter your income details first." << endl;
            cout << "Press any key to return to the user profile menu...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(); // Wait for user to press any key
        }
    }

    void logout() {
        cout << "Logging out..." << endl;
    }

    void displayMenu() {
        int choice;
        do {
            clearScreen();
            cout << "\t\t\t_________________________________________________________\n";
            cout << "\t\t\t_________________User Profile Menu______________________\n";
            cout << "\t\t\t| 1. View Income Details                                |\n";
            cout << "\t\t\t| 2. Update Income Details                              |\n";
            cout << "\t\t\t| 3. Calculate Tax                                      |\n";
            cout << "\t\t\t| 4. Logout                                             |\n";
            cout << "\t\t\t|_______________________________________________________|\n\n";
            cout << "\t\t\tPlease Enter Your Choice: ";
            cin >> choice;
            cout << endl;

            switch (choice) {
                case 1:
                    viewIncomeDetails();
                    break;
                case 2:
                    updateIncomeDetails();
                    break;
                case 3:
                    calculateTax();
                    break;
                case 4:
                    logout();
                    return; // Return to main menu
                default:
                    cout << "\t\t\tPlease select from the options given above.\n" << endl;
            }
        } while (true);
    }
};

class Login {
private:
    User user;

public:
    Login() {}

    void displayMenu() {
        int choice;
        do {
            clearScreen();
            cout << "\t\t\t__________________________________________________________________\n";
            cout << "\t\t\t_____________________Welcome to the Login Page____________________\n";
            cout << "\t\t\t_____________________          MENU           ____________________\n\n\n";

            cout << "\t\t\t| Press 1 to LOGIN                   |" << endl;
            cout << "\t\t\t| Press 2 to REGISTER                |" << endl;
            cout << "\t\t\t| Press 3 to EXIT                    |" << endl;

            cout << "\n\t\t\tPlease Enter Your Choice: ";
            cin >> choice;
            cout << endl;

            switch (choice) {
                case 1:
                    login();
                    break;
                case 2:
                    registration();
                    break;
                case 3:
                    cout << "\t\t\tThank you!\n" << endl;
                    exit(0);
                default:
                    cout << "\t\t\tPlease select from the options given above.\n" << endl;
            }
        } while (choice != 3);
    }

    void login() {
        clearScreen();

        cout << "\t\t\tPlease enter username and password" << endl;
        cout << "\t\t\tUSERNAME: ";
        string userId, password;
        cin >> userId;
        cout << "\t\t\tPASSWORD: ";
        cin >> password;

        ifstream input("records.txt");

        string id, pass;
        bool found = false;

        while (input >> id >> pass) {
            if (id == userId && pass == password) {
                found = true;
                break;
            }
        }
        input.close();

        if (found) {
            clearScreen();
            cout << "\t\t\t" << userId << ", your login is successful" << endl;
            user.displayMenu(); // Directly go to user profile menu
        } else {
            clearScreen();
            cout << "\t\t\tLogin Error... Please check your username and password" << endl;
            char choice;
            cout << "\t\t\tPress any key to go back to the main menu: ";
            cin >> choice;
        }
    }

    void registration() {
        string ruserId, rpassword;
        clearScreen();

        cout << "\t\t\tEnter the username: ";
        cin >> ruserId;
        cout << "\t\t\tEnter the password: ";
        cin >> rpassword;

        ofstream outputFile("records.txt", ios::app);
        outputFile << ruserId << ' ' << rpassword << endl;
        outputFile.close(); // Close the file after writing

        clearScreen();
        cout << "\t\t\tRegistration is successful" << endl;
        char choice;
        cout << "\t\t\tPress any key to go back to the main menu: ";
        cin >> choice;
    }
};

int main() {
    Login login;
    login.displayMenu();
    return 0;
}
