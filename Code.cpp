#include <bits/stdc++.h>
#include <fstream>
using namespace std;

// with this unque id, only teachers are allowed to proceed & to create a test
const int T_unique_id = 12345;

class Teacher
{
public:
    string ques;
    string ans;
    string opt;                     
    // option for the question if it is multiple correct
    int marks;                      
    // finals marks
    int m;                          
    // variable which take input for the one choice from  the different choice available
    int ChOfQue;                    
    // choice of questions
    static int i;                   
    // initializing a static variable in order to get input questions serial wise
    void Welcome();                 
    // welcome screen for teacher
    void create_test();             
    // will open a new text file named test.txt and creating the test
    void open_test();               
    // opening the previous created test
    void student_responses();       
    // opening the student responses for the test and can accesible by teacher anytime
    void student_responses(string); 
    // taking the input of answers of question of the test
};

// explicit implementation of static variable
int Teacher::i = 1;

void Teacher::Welcome()
{
    cout << "\nWelcome Teacher!!!" << endl;
    // while (1) bcz the pregram will not end until the user did not give the command to terminate it by input, till then it will repeat itself by asking the differnet choices for the input...
    while (1)
    {
        // available operations for the input which can be choosen freely any option freely
        cout << "\n\n1.See Student Responses\n2.Create Test\n3.Open previous created test\n4.Terminate the program\nEnter Choice: ";
        cin >> m; 
        // taking input for the choice
        if (m == 1)
        {
            cout << "\nOpening student answer sheet...\n"
                 << endl;
            student_responses(); 
            // calling a member function of teacher named as student_responses()
        }
        else if (m == 2)
        {
            cout << "\nYou choose to create test...\n"
                 << endl;
            ofstream Clear("stu_ans.txt"); 
            // clearing stu_ans.txt which contains the ans given by student
            create_test();                 
            // calling a member function of teacher named as create_test()
            cout << "\nTest created successfully!!!\n"
                 << endl;
        }
        else if (m == 3)
        {
            cout << "Opening last created Test..." << endl;
            open_test(); 
            // opening the previous created test if available
        }
        else if (m == 4)
        {
            cout << "Program ended!!!" << endl;
            exit(0); 
            // terminating the program as the choice given by the user
        }
        else
        {
            // if input given by the user is not matching with any option provided the loop will continue
            cout << "wrong input!" << endl;
        }
    }
}

// checking any type of txt file whether it is empty or not, here teacher can check is there any created test available here or not and teacher can also check if any student here attempted the check by checking stu_ans.txt file here
bool CheckEmpty(string Fname)
{
    ifstream OPEN(Fname);
    string p1;
    getline(OPEN, p1, '\n'); 
    // taking input for the first line
    if (p1 == "")
    //if p1 is empty means text file is empty
    {
        return true;
    }
    else
    {
        return false;
    }
}

// checking whether the file available or not
bool CheckExist(string Fname)
{
    ifstream OPEN(Fname);
    if (OPEN.fail())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// opening the student reponses file
void Teacher::student_responses()
{
    if (CheckExist("stu_ans.txt"))
    {
        cout << "ERROR 404, Not attempted yet..." << endl;
        return;
    }
    if (CheckEmpty("stu_ans.txt"))
    {
        cout << "No Student Response found!" << endl;
        return;
    }
    else
    {
        ifstream stt("stu_ans.txt");
        cout << stt.rdbuf();
        //printing whole content of text file
        stt.close();
    }
}

// opening the student reponses by the particular file name
void Teacher::student_responses(string filename)
{
    if (CheckExist(filename))
    {
        cout << "You have not attempted any test yet..." << endl;
        return;
    }
    if (CheckEmpty(filename))
    {
        cout << "No Response found" << endl;
        return;
    }
    else
    {
        ifstream F2(filename);
        cout << F2.rdbuf();
        F2.close();
    }
}

// opening the previous created test if available
void Teacher::open_test()
{
    if (CheckExist("test.txt"))
    {
        cout << "NO TEST PRESENT..." << endl;
        return;
    }
    if (CheckEmpty("test.txt"))
    {
        cout << "TEST IS EMPTY" << endl;
        return;
    }
    ifstream op("test.txt");
    cout << op.rdbuf();
    op.close();
}

// creating the test (only teachers is allowed)
void Teacher::create_test()
{
    ofstream a1("Ques.txt"); 
    // creating Ques.txt file
    ofstream a2("Ans.txt");  
    // creating Ans.txt file
    ofstream a3("test.txt"); 
    // creating test.txt file
    char ch = 'y';
    int j = 1;
    cout << "\nEnter Questions & Answers\n"
         << endl;
    // while(ch == y) bcz it will input the questions until the user gives the input n for no, it will continue itself till the input given is y
    while (ch == 'y')
    {
        string s = to_string(i);                                     
        // changing i to a sting in order to push as a string in the text file
        cout << "\nType Of Question?(1 for mcq, 2 for One Liner): "; 
        // taking input for the typopoe of questions
        cin >> ChOfQue;                                              
        // choice of quetsions
        if (ChOfQue == 1)
        {
            fflush(stdin); 
            // clearing the previous taken input as buffer
            cout << "\nType the Que." << i << ": ";
            getline(cin, ques); 
            // taking the question as input
            a1 << "Q" << s << ". " << ques << "\n";
            a3 << "Q" << s << ". " << ques << "\n";
            j = 1;            
            // for number question
            while (ch == 'y') 
            // will take the input till the choice of the user is y
            {
                string s = to_string(j);
                fflush(stdin);
                cout << "Type Option." << j << ": ";
                getline(cin, opt);
                a1 << "Option" << s << ". " << opt << "\n";
                a3 << "Option" << s << ". " << opt << "\n";
                cout << "\nAdd more Options?(Press y or n): ";
                cin >> ch;
                j++;
            }
            a1 << "*\n";
            fflush(stdin);
            cout << "Type the Correct Option: ";
            getline(cin, ans); 
            // taking the correct options for the mcq;
            a2 << "A" << s << ". " << ans << "\n";
            a3 << "A" << s << ". " << ans << "\n\n";
        }
        else
        {
            fflush(stdin); 
            // clearing the previous taken input
            cout << "\nType the Que." << i << ": ";
            getline(cin, ques);
            ques += "\n";
            a3 << "Q" << s << ". " << ques;
            a1 << "Q" << s << ". " << ques << "*\n";
            fflush(stdin);
            cout << "Type the Ans." << i << ": ";
            getline(cin, ans);
            ans += "\n";
            a3 << "A" << s << ". " << ans << "\n";
            a2 << "A" << s << ". " << ans;
        }
        // taking the input to add more questions if y it will continue else it will terminate the creating test function
        cout << "\nWant to add more Ques?(Press y or n): ";
        cin >> ch;
        i++;
    }
    a1.close();
    a2.close();
    a3.close();
}

// single level inheritance
// student : derived class
// teacher : base class
class Student : public Teacher 
// taking teacher member functions in the public section of student
{
    int n;
    string name;
    string batch;
    string rollno;
    string File;
    int marks = 0;

public:
    // constructor for the student class
    Student();
    void Attempt_test(); 
    // will attempt the test
    void details();      
    // will open the details of student who attempted the test
};

Student::Student()
{
    cout << "\nCiao! Student" << endl; 
    // greeting the students...

    // will run this while loop untill the user gives the input for the terminating the program
    while (1)
    {
        // various choices available for the student
        cout << "\n1.See your Previous Test Responses\n2.Attempt Test\n3.Terminate the program\nEnter Choice: ";
        cin >> n;
        if (n == 1)
        {
            // creating the test for the particular student deifferently
            cout << "Please Enter your name: ";
            cin >> name;
            cout << "Please Enter your Roll.no: ";
            cin >> rollno;
            File = name + rollno + ".txt";
            cout << "FILE: " << File << endl; 
            // name of the file for the particular student
            cout << "\nopening your last submited test response\n"
                 << endl;
            student_responses(File);
            // calling the teacher class member function which is inherit to the student class
        }
        else if (n == 2)
        {
            // as input given by the user attempting the test...
            cout << "\nopening the test paper...\n";
            Attempt_test();
        }
        else if (n == 3)
        {
            // terminating the program
            cout << "Program ended successfully" << endl;
            exit(0);
        }
    }
}

// student class member function
void Student::Attempt_test()
{
    ifstream b1("Ques.txt");                       
    // for questions printing line by line
    ofstream b2("stu_ans.txt", std::fstream::app); 
    // creating the student response text file
    ifstream b3("Ans.txt");                        
    // for checking the ans given by the student with the ans given by the teacher
    details();                                     
    // taking the deatils of the student
    ofstream b4(File, std::fstream::app);          
    // file of the student
    int count = 0;
    string z, answer;
    marks = 0;
    cout << "\nINSTRUCTIONS: " << endl;
    cout << "1. All Questions are mandatory\n2. +4 marks for correct Answers\n3. -1 marks for wrong Answers\n4. In MCQs, Mark Answers in number\nAll the best!!...\n\n";
    getline(b1, z, '\n'); 
    // taking the questions from the text file line by line
    while (1)
    {
        string s = to_string(i); 
        // converting i to string
        while (z != "*")
        {
            cout << z << endl;
            b2 << z << "\n";
            b4 << z << "\n";
            getline(b1, z, '\n');
        }
        fflush(stdin);
        cout << "\nWrite Ans." << i << ": ";
        getline(cin, ans); 
        // taking the ans for the questions
        cout << endl;
        ans = "A" + s + ". " + ans;
        getline(b3, answer, '\n');
        // calculating the marks along with taking the input as it decrease the runtime of the loop
        if (answer == ans)
        {
            marks += 4;
            b2 << ans <<"  :-  Right Answer, +4" <<"\n\n";
            b4 << ans <<"  :-  Right Answer, +4" <<"\n\n";
        }
        else
        {
            marks -= 1;
            b2 << ans <<"  :-  Wrong Answer, -1" <<"\n\n";
            b4 << ans <<"  :-  Wrong Answer, -1" <<"\n\n";
        }
        getline(b1, z, '\n');
        // will break the loop if we reach to the end of the file
        if (b1.eof())
        {
            break;
        }
        i++;
    }
    cout << "\nThank you for attempting the test, you have scored " << marks << " marks in the test" << endl;
    b2 << "Total Marks Obtained: " << marks << "\n";
    b2 << "******************************\n\n";
    b4 << "Total Marks Obtained: " << marks << "\n";
    cout << "\nWant to view ANSWER KEY?(Press y or n): ";
    cin >> z;
    if (z == "y")
    {
        cout << "Here is the Answer key....\n\n";
        open_test(); 
        // opening the open_test.txt file bcz it contains the ans also along with questions
    }
    // closing all the file
    b1.close();
    b2.close();
    b3.close();
    b4.close();
}

void Student::details()
{
    // taking the details of the student who attempted the for the future refernce
    ofstream c1("stu_ans.txt", std::fstream::app);
    cout << "\nEnter the following details..." << endl;
    fflush(stdin);
     // clearing the previous inputs
    cout << "\nEnter your Name : ";
    getline(cin, name);
    fflush(stdin);
    cout << "\nEnter your Batch : ";
    cin >> batch;
    fflush(stdin);
    cout << "\nEnter your Roll no : ";
    cin >> rollno;
    File = name + rollno + ".txt";
    ofstream F1(File);
     // f1 : file for the particular student

    c1 << "******************************\n";
    c1 << "Name\tBatch\t\tRoll.no\n";
    F1 << "Name\tBatch\t\tRoll.no\n";
    c1 << name << "\t" << batch << "\t\t\t" << rollno << "\n\n";
    F1 << name << "\t" << batch << "\t\t\t" << rollno << "\n\n";
    // closing the opened file
    c1.close();
    F1.close();
}

void encrypt(string filename){

}

void decrypt(string filename){

}

// register login : every user have to login or register before entering the program whether he/she is a teacher or student
void Register_Login()
{
    int choice, n = 1;
    string name, password,
        inName, inPassword,
        registerName, registerPassword;

    while (n == 1) 
    // running the code untill it will login or register successfully
    {
        cout << "1.Register\n2.Login\n"
             << "Enter Choice: ";
        cin >> choice;
        if (choice == 1)
        {
            ofstream g("Login_credentials.txt", std::fstream::app); 
            // creating a file for storing the data of logincredential for the future refernce
            fflush(stdin);
            // pushing all the data in the text file accordingly to register
            cout << "\n\n"
                 << "New Username: ";
            getline(cin, registerName);
            cout << "New Password: ";
            getline(cin, registerPassword);
            g << registerName;
            g << '\n';
            g << registerPassword;
            g << '\n';
            cout << "Successfully Registered!!, Now Please Login" << endl;
            g.close();
        }
        if (choice == 2)
        {
            while (1)
            {
                ifstream f("Login_credentials.txt");
                fflush(stdin);
                // taking the input for the login credentials
                cout << "\n\n"
                     << "Enter Username: ";
                getline(cin, inName);
                cout << "Enter Password: ";
                getline(cin, inPassword);
                // after taking the input checking with the lohin credentials available in the text file, if it matches will continue the program else repeat asking login or register
                while (!f.eof())
                {
                    // checking line by line
                    getline(f, name, '\n');
                    getline(f, password, '\n');
                    if (inName == name && inPassword == password)
                    {
                        n = 2;
                        break;
                    }
                }
                if (n == 2)
                {
                    cout << "Login Successful\n"
                         << "Welcome, " << inName;
                    break;
                }
                cout << "Incorrect Credentials, please try again" << endl;
                // closing the opened file
                f.close();
            }
        }
        cout << "\n\n\n\n";
    }
}

int main()
{
    int choice, id, n;
    cout << "\t\tWelcome to our Exam Portal\n\n" // greeting
         << endl;
    Register_Login();                                                          
    // registering or login for the students or the teacher
    cout << "Are you a Teacher/Student (Press 1 for Teacher,2 for Student): "; 
    // asking for the teacher or student
    cin >> choice;
    if (choice == 1) // for teacher
    {
        cout << "\nEnter Teacher Unique Id to proceed: ";
        cin >> id;             
        // checking for the unique id
        if (id == T_unique_id) 
        // if true will create a teacher class object, then various functions for the teacher class will be availabale
        {
            Teacher T1;
            T1.Welcome();
        }
        else
        {
            // if wrong input
            cout << "Wrong id, could not proceed" << endl;
        }
    }
    else
    {
        // if choice is 2
        Student S1;
    }
    return 0;
}