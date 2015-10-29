// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3110-001
// Assignment: lab2: Records Office II
// Due:        22:00:00, September 24, 2013
// Purpose:    Continuation of lab1, addition of multiple objects representing different
//             statuses of people at a University (Student, Faculty, Administrator). Also
//             incorporates class templates in order to create, add to, delete from, and print
//             from multiple linked lists based on the type of object passed.
// Input:      Pre-formatted file.
// Output:     Print to terminal.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//************************************************************************************************
//************************************************************************************************
//************************************************************************************************

// base class
class Person{

public:
    Person();  // default constructor
    
    // base class set methods
    void setName(string);
    void setMnum(int);
    void setEmail(string);
    
    // base class get methods
    string getName();
    int getMnum();
    string getEmail();
    
    // pure virtual method
    virtual void print()=0;
    
protected:
    // base class data members
    string pName;
    int pMnum;
    string pEmail;
};

//************************************************************************************************
//************************************************************************************************
//************************************************************************************************

// Method:      default constructor
// Purpose:     instantiate an object of the Person class
// Pre-cond:    none
// Post-cond:   object instantiated
Person::Person(){}

//************************************************************************************************

// Method:      setName
// Purpose:     sets the "pName" data member
// Pre-cond:    string is passed in
// Post-cond:   data member is set
void Person::setName(string inName){
    pName = inName;
}  // end setName

//************************************************************************************************

// Method:      setMnum
// Purpose:     sets the "pMnum" data member
// Pre-cond:    int is passed in
// Post-cond:   data member is set
void Person::setMnum(int inMnum){
    pMnum = inMnum;
}  // end setMnum

//************************************************************************************************

// Method:      setEmail
// Purpose:     sets the "pEmail" data member
// Pre-cond:    string is passed in
// Post-cond:   data member is set
void Person::setEmail(string inEmail){
    pEmail = inEmail;
}  // end setEmail

//************************************************************************************************

// Method:      getName
// Purpose:     called to access data member "pName"
// Pre-cond:    data member "pName" has a value
// Post-cond:   returns "pName"
string Person::getName(){
    return pName;
}  // end getName

//************************************************************************************************

// Method:      getMnum
// Purpose:     called to access data member "pMnum"
// Pre-cond:    data member "pMnum" has a value
// Post-cond:   returns "pMnum"
int Person::getMnum(){
    return pMnum;
}  // end getMnum

//************************************************************************************************

// Method:      getEmail
// Purpose:     called to access data member "pEmail"
// Pre-cond:    data member "pEmail" has a value
// Post-cond:   returns "pEmail"
string Person::getEmail(){
    return pEmail;
}  // end getEmail

//************************************************************************************************
//************************************************************************************************
//************************************************************************************************

// child class of Person, inheriting all public methods
class Administrator:public Person{

public:
    // default constructor
    Administrator();
    
    // get, set, and print methods
    void setTitle(string);
    void setAll(string, int, string, string);
    string getTitle();
    void print();
    
private:
    // data member
    string aTitle;
};

//************************************************************************************************
//************************************************************************************************
//************************************************************************************************

// Method:      default constructor
// Purpose:     instantiate an object of the Administrator class
// Pre-cond:    none
// Post-cond:   object instantiated
Administrator::Administrator(){}

//************************************************************************************************

// Method:      setTitle
// Purpose:     sets the "aTitle" data member
// Pre-cond:    string is passed in
// Post-cond:   data member is set
void Administrator::setTitle(string inTitle){
    aTitle = inTitle;
}  // end setTitle

//************************************************************************************************

// Method:      setAll
// Purpose:     sets all the data members of Administrator object at once by calling all
//              individual set methods
// Pre-cond:    all values passed in
// Post-cond:   all data members are set
void Administrator::setAll(string inName, int inMnum, string inEmail, string inTitle)
{
    setName(inName);
    setMnum(inMnum);
    setEmail(inEmail);
    setTitle(inTitle);
}  // end setAll

//************************************************************************************************

// Method:      getTitle
// Purpose:     called to access data member "aTitle"
// Pre-cond:    data member "aTitle" has a value
// Post-cond:   returns "aTitle"
string Administrator::getTitle(){
    return aTitle;
}  // end setAll

//************************************************************************************************

// Method:      print
// Purpose:     print data from Administrator object to terminal
// Pre-cond:    Administrator object exists
// Post-cond:   data from Student object printed to terminal
void Administrator::print(){
	cout << "\tFull Name:\t" << getName()<< endl;
	cout << "\tM Number:\t" << getMnum() << endl;
	cout << "\tEmail Addr:\t" << getEmail() << endl;
	cout << "\tTitle:\t\t" << getTitle() << endl;
	return;
}  // end print

//************************************************************************************************
//************************************************************************************************
//************************************************************************************************

// child class of Person, inheriting all public methods
class Faculty:public Person{

public:
    // default constructor
    Faculty();
    
    // get, set, and print methods
    void setDept(string);
    void setTenure(bool);
    void setAll(string, int, string, string, bool);
    string getDept();
    bool getTenure();
    void print();
    
private:
    // data members
    string fDept;
    bool fTenure;
};

//************************************************************************************************
//************************************************************************************************
//************************************************************************************************

// Method:      default constructor
// Purpose:     instantiate an object of the Faculty class
// Pre-cond:    none
// Post-cond:   object instantiated
Faculty::Faculty(){}

//************************************************************************************************

// Method:      setDept
// Purpose:     sets the "fDept" data member
// Pre-cond:    string is passed in
// Post-cond:   data member is set
void Faculty::setDept(string inDept){
    fDept = inDept;
}  // end setDept

//************************************************************************************************

// Method:      setTenure
// Purpose:     sets the "fTenure" data member
// Pre-cond:    bool is passed in
// Post-cond:   data member is set
void Faculty::setTenure(bool inTenure){
    fTenure = inTenure;
}  // end setTenure

//************************************************************************************************

// Method:      setAll
// Purpose:     sets all the data members of Faculty object at once by calling all individual
//              set methods
// Pre-cond:    all values passed in
// Post-cond:   all data members are set
void Faculty::setAll(string inName, int inMnum, string inEmail, string inDept, bool inTenure)
{
    setName(inName);
    setMnum(inMnum);
    setEmail(inEmail);
    setDept(inDept);
    setTenure(inTenure);
}  // end setAll

//************************************************************************************************

// Method:      getDept
// Purpose:     called to access data member "fDept"
// Pre-cond:    data member "fDept" has a value
// Post-cond:   returns "fDept"
string Faculty::getDept(){
    return fDept;
}  // end getDept

//************************************************************************************************

// Method:      getTenure
// Purpose:     called to access data member "fTenure"
// Pre-cond:    data member "fTenure" has a value
// Post-cond:   returns "fTenure"
bool Faculty::getTenure(){
    return fTenure;
}  // end getTenure

//************************************************************************************************

// Method:      print
// Purpose:     print data from Faculty object to terminal
// Pre-cond:    Faculty object exists
// Post-cond:   data from Student object printed to terminal
void Faculty::print(){
	cout << "\tFull Name:\t" << getName()<< endl;
	cout << "\tM Number:\t" << getMnum() << endl;
	cout << "\tEmail Addr:\t" << getEmail() << endl;
	cout << "\tDepartment:\t" << getDept() << endl;
	cout << "\tTenured:\t";
    switch (getTenure()) {
        case 0 : cout << "no\n"; break;
        case 1 : cout << "yes\n"; break;
    } // end switch
	return;
}  // end print

//************************************************************************************************
//************************************************************************************************
//************************************************************************************************

// child class of Person, inheriting all public methods
class Student:public Person{
    
public:
    // default constructor
    Student();
    
    // get, set, and print methods
    void setYear(int);
    void setMajor(string);
    void setAll(string, int, string, int, string);
    int getYear();
    string getMajor();
    void print();
    
private:
    //  data members
    int sYear;
    string sMajor;
};

//************************************************************************************************
//************************************************************************************************
//************************************************************************************************

// Method:      default constructor
// Purpose:     instantiate an object of the Student class
// Pre-cond:    none
// Post-cond:   object instantiated
Student::Student(){} // default constructor

//************************************************************************************************

// Method:      setYear
// Purpose:     sets the "sYear" data member
// Pre-cond:    int is passed in
// Post-cond:   data member is set
void Student::setYear(int inYear){
    sYear = inYear;
} // end setYr

//************************************************************************************************

// Method:      setMajor
// Purpose:     sets the "sMajor" data member
// Pre-cond:    string is passed in
// Post-cond:   data member is set
void Student::setMajor(string inMajor){
    sMajor = inMajor;
} // end setMaj

//************************************************************************************************

// Method:      setAll
// Purpose:     sets all the data members of Student object at once by calling all individual
//              set methods
// Pre-cond:    all values passed in
// Post-cond:   all data members are set
void Student::setAll(string inName, int inMnum, string inEmail, int inYear, string inMajor)
{
    setName(inName);
    setMnum(inMnum);
    setEmail(inEmail);
    setYear(inYear);
    setMajor(inMajor);
}  // end setAll

//************************************************************************************************

// Method:      getYear
// Purpose:     called to access data member "sYear"
// Pre-cond:    data member "sYear" has a value
// Post-cond:   returns "sYear"
int Student::getYear(){
    return sYear;
}  // end getYear

//************************************************************************************************

// Method:      getMaj
// Purpose:     called to access data member "sMajor"
// Pre-cond:    data member "sMajor" has a value
// Post-cond:   returns "sMajor"
string Student::getMajor(){
    return sMajor;
}  // end getMaj

//************************************************************************************************

// Method:      print
// Purpose:     print data from Student object to terminal
// Pre-cond:    Student object exists
// Post-cond:   data from Student object printed to terminal
void Student::print(){
	cout << "\tFull Name:\t" << getName()<< endl;
	cout << "\tM Number:\t" << getMnum() << endl;
	cout << "\tEmail Addr:\t" << getEmail() << endl;
	cout << "\tGrade:\t\t";
    switch(getYear()){
        case 0 : cout << "Freshman\n"; break;
        case 1 : cout << "Sophomore\n"; break;
        case 2 : cout << "Junior\n"; break;
        case 3 : cout << "Senior\n"; break;
    }  // end switch
	cout << "\tMajor:\t\t" << getMajor() << endl;
	return;
} // end print

//************************************************************************************************
//************************************************************************************************
//************************************************************************************************

template <typename T>
class TemplatedList{
    
public:
    TemplatedList();  // default constructor
    ~TemplatedList(); // destructor
    
	// public methods
	T* find(int);
    void push_back(T*);
    void obliterate(int);
    
private:
	// node for the doubly-linked list, contains pointer to a templated object,
	// initializes all pointers to NULL
    struct ListNode{
        T *personPtr;
        ListNode *next;
        ListNode *prev;
		ListNode() : personPtr(NULL), next(NULL), prev(NULL){}
    };
    
    ListNode *dummyHead; // dummy head of the doubly-linked list
};

//************************************************************************************************
//************************************************************************************************
//************************************************************************************************

// Method:      default constructor
// Purpose:     instantiate an object of the StudentList class
// Pre-cond:    none
// Post-cond:   object instantiated
template <typename T>
TemplatedList<T>::TemplatedList(){
    dummyHead = new ListNode;
} // end default constructor

//************************************************************************************************

// Method:      destructor
// Purpose:     completely destroy all nodes in the linked list and delete any objects
// Pre-cond:    list exists and pointers all point to something
// Post-cond:   all pointers null and all objects deleted
template <typename T>
TemplatedList<T>::~TemplatedList(){
	ListNode *p = dummyHead;
    while (p != NULL){
        dummyHead = dummyHead->next;
        p->next = NULL;
        p->prev = NULL;
		delete p->personPtr;
        p->personPtr = NULL;
        delete p;
        p = NULL;
        p = dummyHead;
    } // end while
}  // end destructor

//************************************************************************************************

// Method:      find
// Purpose:     traverses the linked list and returns a pointer to an object if an object
//              with id exists, otherwise returns null
// Pre-cond:    int id passed into the method
// Post-cond:   returns a pointer to an object if an object with id exists, otherwise returns
//              NULL
template <typename T>
T* TemplatedList<T>::find(int id){
    
	// establish traversal pointer and traverse the list
  ListNode *p = dummyHead->next;
    while (p != NULL){
        
		// if the id of the object linked to the current node == id, return the pointer to
		// that object
        if (p->personPtr->getMnum() == id){
            return p->personPtr;
        }  // end if

		else  // continue to the next node
            p = p->next;
    }  // end while
    
	// if no node is found, return NULL
    return NULL;

}  // end find

//************************************************************************************************

// Method:      push_back
// Purpose:     adds a new ListNode with a pointer to the dereferenced object passed in
// Pre-cond:    pointer to an object passed in, a templated list object has been initialized
// Post-cond:   new ListNode added to the end of the list and next = NULL
template <typename T>
void TemplatedList<T>::push_back(T* newPerson){
    
	// initialize temporary ListNode and point it to the object passed in
    ListNode *temp = new ListNode;
	temp->personPtr = newPerson;
    
	// intialize traversal pointer and traverse to the end of the list
	ListNode *p = dummyHead;
	while (p->next != NULL){
		p = p->next;
	}  // end while
    
    // add node to the end of the list
	p->next = temp;
	temp->prev = p;
    
	// set pointers to NULL
    p = NULL;
    temp = NULL;
    
} // end push_back

//************************************************************************************************

// Method:      obliterate
// Purpose:     deletes an object with a given m number and removes the corresponding node
// Pre-cond:    list is initialized, m number is passed in as id
// Post-cond:   if a node is found that points to a given object with the m number passed in,
//              that object is deleted and the node is removed. if no node exists, cout.
template <typename T>
void TemplatedList<T>::obliterate(int id){

	// initialize traversal pointer at the first node after the dummy head and traverse the list
	ListNode *p = dummyHead->next;
    while (p != NULL){
        
		// if the m number of the object == id, delete the object and remove that node from
		// the list
		if (p->personPtr == find(id) && find(id)->getMnum() == id){  // is this redundant????
			delete p->personPtr;
            if (p->next != NULL)
                p->next->prev = p->prev;
            p->prev->next = p->next;
            
			// set p to NULL and return control to calling function
			p = NULL;
            return;
        }  // end if
        
		else  // continue to the next node
            p = p->next;
    }  // end while

    p = NULL;  // set pointer to NULL
  
} // end obliterate

//************************************************************************************************
//************************************************************************************************
//************************************************************************************************

class RecordsOffice{
    
public:
    RecordsOffice();  // default constructor
    void importRecords(string);  // reads in and executes commands from a file
    
private:
	// doubly-linked lists w/ dummy heads, acts as the databases of students, faculty and admins
    TemplatedList<Student> stuList;
    TemplatedList<Faculty> facList;
    TemplatedList<Administrator> adminList;
};

//************************************************************************************************
//************************************************************************************************
//************************************************************************************************

// Method:      default constructor
// Purpose:     instantiate an object of the RecordsOffice class
// Pre-cond:    none
// Post-cond:   object instantiated
RecordsOffice::RecordsOffice(){}

//************************************************************************************************

// Method:      importRecords
// Purpose:     Read commands in from an input file and execute
// Pre-cond:    preformatted input file name passed in
// Post-cond:   Have read completely through the input file and executed all commands
void RecordsOffice::importRecords(string fileName){
    
    // pointers to temp Student, Faculty, and Administrator objects
    Student *tempStudent;
    Faculty *tempFaculty;
    Administrator *tempAdmin;
    
    char command;  // stores the command character
    
	// temporarily holds personal data that is read in from input file and stored based
    // on the command (F, A, S)
	string tName;
    int tMnum;
    string tEmail;
    int tYear;
    string tMajor;
    string tDept;
    string tTitle;
    bool tTen;
    
	// open input file and get the first command
    ifstream myIn;
    myIn.open(fileName);
    myIn >> command;
    
	while(myIn)  // EOF loop
    {
        switch(command){
                // initialize a new Student object, read in student data, copy student data into
                // Student object, add Student object to the linked list, print student data to
                // terminal
			case 'S':
                tempStudent = new Student;
                myIn >> tName >> tMnum >> tEmail >> tYear >> tMajor;
                tempStudent->setAll(tName, tMnum, tEmail, tYear, tMajor);
                stuList.push_back(tempStudent);
                cout << "\nNote: Adding " << tMnum << " ...\nAdding Student:\n";
                tempStudent->print();
                break;
                
                // initialize a new Faculty object, read in faculty data, copy student data into
                // Faculty object, add Faculty object to the linked list, print faculty data to
                // terminal
            case 'F':
                tempFaculty = new Faculty;
                myIn >> tName >> tMnum >> tEmail >> tDept >> tTen;
                tempFaculty->setAll(tName, tMnum, tEmail, tDept, tTen);
                facList.push_back(tempFaculty);
                cout << "\nNote: Adding " << tMnum << " ...\nAdding Faculty:\n";
                tempFaculty->print();
                break;
                
                // initialize a new Administrator object, read in administrator data, copy
                // administrator data into Administrator object, add Administrator object to
                // the linked list, print administrator data to terminal
            case 'A':
                tempAdmin = new Administrator;
                myIn >> tName >> tMnum >> tEmail >> tTitle;
                tempAdmin->setAll(tName, tMnum, tEmail, tTitle);
                adminList.push_back(tempAdmin);
                cout << "\nNote: Adding " << tMnum << " ...\nAdding Administrator:\n";
                tempAdmin->print();
                break;
                
                // read in m number of person to delete, searches three lists for matching m number,
                // if found, delete. else ouput error statement.
			case 'D':
                myIn >> tMnum;
                cout << "\nNote: Deleting " << tMnum << " ...\n";
                if (stuList.find(tMnum) != NULL)
                    stuList.obliterate(tMnum);
                else if (adminList.find(tMnum) != NULL)
                    adminList.obliterate(tMnum);
                else if (facList.find(tMnum)!= NULL)
                    facList.obliterate(tMnum);
                else
                {
                    cout << "ERROR: cannot delete person with M number " << tMnum;
                    cout << ", M number not found!" << endl;
                }
                break;
                
                // read in m number of person to print, searches three lists for matching m number,
                // if found, print. else ouput error statement.
			case 'P':
                myIn >> tMnum;
				cout << "\nNote: Printing " << tMnum << " ...\n";
                if (stuList.find(tMnum) != NULL){
					cout << "Student:\n";
					stuList.find(tMnum)->print();
				}  // end if
                else if (adminList.find(tMnum) != NULL){
					cout << "Administrator:\n";
					adminList.find(tMnum)->print();
				}  // end else if
                else if (facList.find(tMnum)!= NULL){
					cout << "Faculty:\n";
					facList.find(tMnum)->print();
				}  // end else if
                else
                {
                    cout << "ERROR: cannot print person with M number " << tMnum;
                    cout << ", M number not found!" << endl;
                }  // end if
                break;
        }  // end switch
        
        // set pointers to NULL and read in next command
        tempFaculty = NULL;
		tempAdmin = NULL;
        tempStudent = NULL;
        myIn >> command;
    }  // end while
    myIn.close();  // close input file
}  // end importRecords

//************************************************************************************************
//************************************************************************************************
//************************************************************************************************

int main(/*int argc, const char * argv[]*/)
{
    //string commandsFileName = "lab1-commands-short.tab"; // for initial development
    //string commandsFileName = "lab1-commands.tab";
    //string commandsFileName = "lab1-commands-test.tab"; // for testing & grading
    //string commandsFileName = "/Users/migration/Desktop/xCode/ADS/lab2-work/short.tab";
    string commandsFileName = "/Users/migration/Desktop/xCode/ADS/lab2-work/long.tab";
    
    RecordsOffice records;
    cout << "Importing " << commandsFileName << endl;
    records.importRecords(commandsFileName);
    
    return 0;
    
}

//************************************************************************************************
//************************************************************************************************
//************************************************************************************************

