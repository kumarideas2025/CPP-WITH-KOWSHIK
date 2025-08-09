#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int password;

    // Private constructor
    Employee(int sp)
    {
        this->password = sp;
    }

    // Private method to print the password
    void getprintD()
    {
        cout << "Password is: " << this->password << endl;
    }

public:
    // Static method to create an instance of Employee
    static Employee createEmployee(int sp)
    {
        Employee emp(sp);
        emp.getprintD(); // Call the private method to print the password
        return emp;
    }
};

int main()
{
    // Create an employee using the static method
    Employee kow = Employee::createEmployee(777);
    return 0;
}
