#include <iostream>
#include <string>

// Base class for Single Inheritance
class Employee{
protected:
    std::string name;
    int employeeId;

public:
    Employee(const std::string &empName, int empId) : name(empName), employeeId(empId){
        std::cout << __FUNCTION__ << std::endl;
    }

    void display() const{
        std::cout << "Employee: " << name << ", ID: " << employeeId << std::endl;
    }
};

// Derived class for Single Inheritance
class Developer : public Employee{
private:
    std::string programmingLanguage;

public:
    Developer(const std::string &empName, int empId, const std::string &lang)
        : Employee(empName, empId){
        this->programmingLanguage = lang;
    }

    void show() const{
        display();
        std::cout << "Specialization: Developer, Programming Language: " << programmingLanguage << std::endl;
    }
};

// Base classes for Multiple Inheritance
class ProjectManager{
protected:
    std::string projectManaged;

public:
    ProjectManager(const std::string &project) : projectManaged(project) {}

    void manageProject() const{
        std::cout << "Project Manager managing project: " << projectManaged << std::endl;
    }
};

class TeamLead{
protected:
    int teamSize;

public:
    TeamLead(int size) : teamSize(size) {}

    void leadTeam() const{
        std::cout << "Team Lead leading a team of " << teamSize << " members." << std::endl;
    }
};

// Derived class for Multiple Inheritance
class TechLead : public Employee, public ProjectManager, public TeamLead{
public:
    TechLead(const std::string &empName, int empId, const std::string &project, int teamSize)
        : Employee(empName, empId), ProjectManager(project), TeamLead(teamSize) {}

    void displayInfo() const{
        display();
        manageProject();
        leadTeam();
    }
};

// Base class for Multi-level Inheritance
class HRManager : public Employee{
public:
    HRManager(const std::string &empName, int empId) : Employee(empName, empId){
        std::cout << __FUNCTION__ << std::endl;
    }

    void handleHRDuties() const{
        std::cout << "HR Manager handling human resources duties." << std::endl;
    }
};

// Derived class for Multi-level Inheritance
class HRDirector : public HRManager{
public:
    HRDirector(const std::string &empName, int empId) : HRManager(empName, empId){
        std::cout << __FUNCTION__ << std::endl;
    }

    void manageHRDepartment() const{
        std::cout << "HR Director managing the HR department." << std::endl;
    }
};

// Base class for Hierarchical Inheritance
class Executive : public Employee{
public:
    Executive(const std::string &empName, int empId) : Employee(empName, empId) {}

    void makeExecutiveDecisions() const{
        std::cout << "Executive making executive decisions." << std::endl;
    }
};

// Derived classes for Hierarchical Inheritance
class CEO : public Executive{
public:
    CEO(const std::string &empName, int empId) : Executive(empName, empId) {}

    void leadCompany() const{
        makeExecutiveDecisions();
        std::cout << "CEO leading the company." << std::endl;
    }
};

// Base classes for Hybrid Inheritance
class MarketingManager : public Employee{
public:
    MarketingManager(const std::string &empName, int empId) : Employee(empName, empId) {}

    void createMarketingStrategy() const{
        std::cout << "Marketing Manager creating a marketing strategy." << std::endl;
    }
};

class SalesManager : public Employee{
public:
    SalesManager(const std::string &empName, int empId) : Employee(empName, empId) {}

    void boostSales() const{
        std::cout << "Sales Manager boosting sales." << std::endl;
    }
};

class BusinessDevelopmentManager : public MarketingManager, public SalesManager{
public:
    BusinessDevelopmentManager(const std::string &empName, int empId)
        : MarketingManager(empName, empId), SalesManager(empName, empId) {}

    void coordinateBusinessDevelopment() const{
        createMarketingStrategy();
        boostSales();
        std::cout << "Business Development Manager coordinating business development efforts." << std::endl;
    }
};

int main(){
    // Single Inheritance
    Developer dev("Ramu Kaka", 101, "C++");
    dev.show();

    // Multiple Inheritance
    TechLead techLead("Anna Dev", 202, "Project X", 5);
    techLead.displayInfo();

    // Multi-level Inheritance
    HRDirector hrDirector("Lucy Madam", 303);
    hrDirector.handleHRDuties();
    hrDirector.manageHRDepartment();

    // Hierarchical Inheritance
    CEO ceo("Devi Lal", 404);
    ceo.leadCompany();

    // Hybrid Inheritance
    BusinessDevelopmentManager bdManager("Sam Uncle", 606);
    bdManager.coordinateBusinessDevelopment();

    return 0;
}
