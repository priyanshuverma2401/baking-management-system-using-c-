#include<iostream>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<cmath>
#include<conio.h>
#include<fstream>
#include<windows.h>

#define RATE 4
long globalArray[100]= {0};
using namespace std;

class bank
{


    long accountNumber;
    char name[100], acctype[100],lname[50];
    float bal;
    char pin[4];
    float openingBal;
    float statement[100]= {0};
    float netBal[100]= {0};
    static int countr;
    float fd[100]={0};
    float period[100]={0};
    float loanAmountArr[100]={0};
    float loanPeriodArr[100]={0};
    //  static long long account=240123100;
public:



    bank()
    {
        countr+=1;

        cout<<"\n Enter Details of customer "<<countr<<":"<<endl;
        cout<<"-----------------------";
        cout<<"\n Accout No. ";
reEnterAccountNumber:
        while(!(cin>>accountNumber))
        {
            cin.clear();
         //   cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"invalid input! please try again\n";
        }
        for(int i=0; 1; i++)
        {
            if(accountNumber==globalArray[i])
            {
                cout<<"\naccount with account "
                    <<"number "<<accountNumber
                    <<" already exists.\ntry again\nre-enter : ";
                goto reEnterAccountNumber;
                break;
            }
            //  accountNumber=account;
            if(globalArray[i]==0)
            {
                globalArray[i]=accountNumber;
                break;
            }
        }
        cout<<"\n first Name : ";
        cin>>name;
        cout<<"\n last Name : ";
        cin>>lname;

        cout<<"\n Account Type : ";
        cin>>acctype;

        cout<<"\n set 4 digit pin : ";
        cin>>pin;

        bal=1500;
        openingBal=bal;
        cin.clear();
    }
    long returnAcc() {
        return accountNumber;
    }
    float returnBal() {
        return bal;
    }
    void addBal(float x) {
        bal+=x;
        for(int i=0; i<100; i++)
        {

            if(statement[i]==0)
            {
                statement[i]=x;
                netBal[i]=bal;
                break;
            }
        }
    }
    void wbal(float y)
    {
        char inpin[4];
        cout<<"\n enter 4 digit pin : ";
        cin>>inpin;
        int n= (pin==inpin);
        if(n==0)
        {
            float withAmount =y;

            cout<<"deducting amount...please wait for a while...";
            usleep(2000000);
            if((bal-withAmount)<0) {
                cout<<"\n insufficient amount\n";
                cout<<"\n Cannot Withdraw Amount";

            }
            else if((bal-withAmount)<1000 &&(bal-withAmount)>0 ) {
                cout<<"\nwarning:\n\ninsufficient balance"
                    <<": your balance will be less than "
                    <<"threshold balance\n\n"
                    <<"do you want to continue : (y/n)\n";
                char r;
                cin>>r;
                if(r=='y') {
                    bal-=withAmount;
                    cout<<"\nbalace deducted successfully\n"<<endl;
                }
                else {
                    exit(0);
                }
            }
            else {
                cout<<"\nbalance deducted successfully!!! \n";
                bal-=withAmount;
                cout<<" remaining balance is : "<<bal;
            }
        }

        else {
            cout<<"\n\npin not matched! try again\n";

        }
        for(int i=0; i<100; i++)
        {
            if(statement[i]==0)
            {
                statement[i]=-y;
                netBal[i]=bal;
                break;
            }
        }

    }
    // int takeIntegerInput();
    void printStatement ();
    friend void scheme(bank);
    //friend void interestCal(bank);
    //friend void interestCal(float);
    int loan();
    void showLoan();
    void showFd();
    void fixedDeposite();
    void deposit();
    void withdraw();
    void display();
    void preDisplay() {

        cout<<name<<"\t\t"<<accountNumber;

    }

};
int bank :: countr;
//long long bank :: account;
void bank::printStatement()
{
    cout<<endl;
    cout<<"opening balance : "<<openingBal<<endl;
    for(int k=0; k<100; k++)
    {
//if(statement[k]==0) break;
        if(statement[k]>0)
        {

            cout<<"*Credited : "<<statement[k]<<endl;
            cout<<"\tnet balance : "<<netBal[k]<<endl;
            cout<<endl<<endl;
            continue;
        }
        else if(statement[k]<0)
        {
            cout<<"*withdrawn : "<<statement[k]<<endl;
            cout<<"\tnet balance : "<<netBal[k]<<endl;
            cout<<endl<<endl;
            continue;
        }
        else if(statement[k]==0)
        {
            cout<<"-----------------------------------";
            cout<<"\ncurrent balance : "<<bal<<endl;
            cout<<"-----------------------------------";
            return ;
            break;
        }
    }
}
int takeIntegerInput()
{
    int n;
    while(!(cin>>n))
    {
        cin.clear();
       // cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"invalid input! please try again\n";
    }
    return n;
}
float takeFloatInput()
{
    float n;
    while(!(cin>>n))
    {
        cin.clear();
       // cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"invalid input! please try again\n";
    }
    return n;
}
long takeLongIntegerInput()
{
    long n;
    while(!(cin>>n))
    {
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"invalid input! please try again\n";
    }
    return n;
}
double takeDoubleInput()
{
    double n;
    while(!(cin>>n))
    {
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"invalid input! please try again\n";
    }
    return n;
}

void scheme(bank cc) {
    float age;
    char gender;
    double salary;
    cout << "\nEnter your age: ";
    age=takeFloatInput();
    cout << "\nEnter your gender (M/F): ";
    cin >> gender;
    cout << "\nEnter your salary per month: ";
    salary=takeDoubleInput();

    if (age >= 18 && salary >= 20000) {
        cout << cc.name << ", you are eligible for the government scheme." << endl;
    } else {
        cout << cc.name << ", you are not eligible for the government scheme." << endl;
    }

    if (age >= 60) {
        cout << cc.name << ", you are eligible for the senior citizen scheme." << endl;
    } else {
        cout << cc.name << ", you are not eligible for the senior citizen scheme." << endl;
    }

    if ((gender == 'F'||gender == 'f') && salary <= 10000) {
        cout << cc.name << ", you are eligible for the women empowerment scheme." << endl;
    } else {
        cout << cc.name << ", you are not eligible for the women empowerment scheme." << endl;
    }


}
float interestCal (float bal2,float year) {

    float p=bal2;
    float  r = RATE, t=year;
    int n;
    int type;
    double interest;
reEnter4:
    cout<<"\npress 1 for compound interest\n";
    cout<<"press 2 for simple interest\n";

    type=takeIntegerInput();
    if(type==1) {
        //cout << "\nEnter the number of years: ";
        // t=takeFloatInput();
reEnter5:
        cout << "\nEnter the frequency of "
             <<" compounding \n1. for yearly\n"
             <<" 2. for half-yearly\n"
             <<" 3. for quarterly\n ";
        n=takeIntegerInput();
        if(n<1||n>3)
            goto reEnter5;
        if(n==3)
            n++;
        float amount = p * pow(1 + (r / n)/100, n * t);
        interest = amount-p;



        cout<<"\n\nfor amount Rs."<< p<<" with interest rate rate "
            <<RATE<<"% which adds Rs. "<<interest
            <<" as a interest.\n ";
        return amount;
    }
    else if(type==2) {
        // float period ;
        // cout<<"\nenter loan period: ";
        //period=takeFloatInput();
        interest=(p*RATE*t)/100;
        cout<<"\n\nfor amount Rs."<< p<<" with interest rate rate "
            <<RATE<<"% which adds Rs. "<<interest
            <<" as a interest .\n";
        return (p+interest);

    }
    else
    {
        cout<<"\ninvalid choice ! try again"<<endl;
        goto reEnter4;
    }
}
void bank :: fixedDeposite ()
{
    float fdAmount,fdPeriod;
    cout<<"\nenter Amount for fixed deposite: "<<endl;
reEnterAmountFd:
    fdAmount=takeFloatInput();
    if(fdAmount>bal)
    {
        cout<<"\ninsufficient amount\n"
            <<"your current balance is "<<bal<<endl;
        cout<<"re-enter amount: ";
        goto reEnterAmountFd;
    }
    cout<<"\nenter period for fixed deposite: "<<endl;
    fdPeriod=takeFloatInput();
    float fdFinal=interestCal(fdAmount,fdPeriod);
    cout<<"\ntotal amount will be returned after "
        <<fdPeriod<<" year is "<<fdFinal;
    cout<<"\n\ndo you want to deposite Rs."
        <<fdAmount<<" for "<<fdPeriod<<" years.<y/n>"<<endl;

    char f;
    cin>>f;
    if(f=='y') {
        wbal(fdAmount);
        for(int i=0; 1; i++)
        {
            if(fd[i]==0)
            {
                fd[i]=fdAmount;
                period[i]=fdPeriod;
                break;
            }
        }
    }
    else {
        goto  reEnterAmountFd;
    }

}
void bank::showFd()
{
    float totalFd=0;
    for(int i=0; 1; i++)
    {
        if(fd[i]==0)
        {
            for(int j=0; 1; j++)
            {
                if(fd[j]==0) break;
                totalFd+=fd[j];
            }
            cout<<"\ntotal FD: "<<totalFd<<endl;
            break;
        }
        else{
            cout<<"\n*deposited "<<fd[i]<<" for "<<period[i]
                <<" years."<<endl;
            }
    }
}
int bank :: loan()
{
float loanAmount;
reEnterLoanAmount:
cout<<"\nenter loan amount: ";

loanAmount=takeFloatInput();

float totalTransaction=0;
for(int i=0;i<100;i++)
{
if(statement[i]==0)
{
cout<<endl<<name<<",your total transaction is "
    <<" Rs."<<totalTransaction;
    break;
}
totalTransaction+=(abs(statement[i]));

}
if(totalTransaction<loanAmount)
{
cout<<"\nyou are not eligible for loan amount "
    <<" of Rs. "<<loanAmount;
    cout<<endl<<endl;
    cout<<"\nyou are eligible for loan amount "
        <<"upto Rs."<<totalTransaction;
        int cp;
        choice1:
       cout<<"\n[1]. cancel\n"
            <<"\n[2]. continue with loan\n";
            cp=takeIntegerInput();
            if(cp==1)
             return 0;
            else if(cp==2)
        goto reEnterLoanAmount;
        else {
        cout<<"\nchosse within range<1/2>\n";
        goto choice1;
        }
}
else
{
float loanPeriod;
cout<<"\nenter loan period: "<<endl;
loanPeriod=takeFloatInput();
cout<<"\n you are eligible for loan amount Rs."<<loanAmount<<endl;
 float finalLoanAmount=interestCal(loanAmount,loanPeriod);
cout<<"\ntotal amount will have to be returned "
    <<" after "<<loanPeriod<<" year is rs."<<finalLoanAmount<<endl;
    cout<<"do you want to continue <y/n>"<<endl;
    char loanChoice;
    cin>>loanChoice;
    if(loanChoice=='y'){
cout<<"\nLoan amount of Rs."<<loanAmount
    <<" added successfully to account "<<accountNumber;
    bal+=loanAmount;
    
    for(int k=0;;k++)
    {
    if(loanAmountArr[k]==0)
    {
    
    loanAmountArr[k]=loanAmount;
    loanPeriodArr[k]=loanPeriod;
    break;
    }
    }
    for(int h=0;;h++)
    {
    if(statement[h]==0)
    {
    
    statement[h]=loanAmount;
     netBal[h]=bal;
    break;
    }
    }
    cout<<"\nyour current balance is Rs."<<bal<<endl;
}
return 0;
}
}
void bank::showLoan()
{
 float totalLoan=0;
for(int k=0;;k++)
{
if(loanAmountArr[k]==0)
{
cout<<"\n----------------------------------------"<<endl;

cout<<name<<", your total loan amount : "<<totalLoan<<endl;
cout<<"\n----------------------------------------"<<endl;
break;
}
else{
cout<<"\n*loan amount of Rs."<<loanAmountArr[k]
    <<" for "<<loanPeriodArr[k]<<" years."<<endl;
    totalLoan+=loanAmountArr[k];
}
}
}
/*void interestCal (float bal2,float year) {

    float p=bal2;
    float  r = RATE, t=year;
    int n;
    int type;
    double interest;
reEnter4:
    cout<<"\npress 1 for compound interest\n";
    cout<<"press 2 for simple interest\n";

    type=takeIntegerInput();
    if(type==1) {
        //cout << "\nEnter the number of years: ";
       // t=takeFloatInput();
reEnter5:
        cout << "\nEnter the frequency of "
             <<" compounding \n1. for yearly\n"
             <<" 2. for half-yearly\n"
             <<" 3. for quarterly\n ";
        n=takeIntegerInput();
        if(n<1||n>3)
            goto reEnter5;
        if(n==3)
            n++;
        double amount = p * pow(1 + (r / n)/100, n * t);
        interest = amount-p;

        cout<<"\n\nfor amount Rs."<< p<<" with interest rate rate "
            <<RATE<<"% which adds Rs. "<<interest
            <<" as a interest "
            <<"total amount will have to be returned after "
            <<t<<" year is "<<amount;
    }
    else if(type==2) {
       // float period ;
       // cout<<"\nenter loan period: ";
        //period=takeFloatInput();
        interest=(p*RATE*t)/100;
        cout<<"\n\nfor amount Rs."<< p<<" with interest rate rate "
            <<RATE<<"% which adds Rs. "<<interest
            <<" as a interest "
            <<"total amount will  be returned after "
            <<period<<" year is "<<bal2+interest;
    }
    else
    {
        cout<<"\ninvalid choice ! try again"<<endl;
        goto reEnter4;
    }
}*/
/*void interestCal (bank bb) {

    float p=bb.bal;
    float  r = RATE, t;
    int n;
    int type;
    double interest;
reEnter4:
    cout<<"\npress 1 for compound interest\n";
    cout<<"press 2 for simple interest\n";

    type=takeIntegerInput();
    if(type==1) {
        cout << "\nEnter the number of years: ";
        t=takeFloatInput();
reEnter5:
        cout << "\nEnter the frequency of "
             <<" compounding \n1. for yearly\n"
             <<" 2. for half-yearly\n"
             <<" 3. for quarterly\n ";
        n=takeIntegerInput();
        if(n<1||n>3)
            goto reEnter5;
        if(n==3)
            n++;
        double amount = p * pow(1 + (r / n)/100, n * t);
        interest = amount-p;

        cout<<"\n\nfor amount Rs."<< p<<" with interest rate rate "
            <<RATE<<"% which adds Rs. "<<interest
            <<" as a interest "
            <<"total amount will have to be returned after "
            <<t<<" year is "<<amount;
    }
    else if(type==2) {
        float period ;
        cout<<"\nenter loan period: ";
        period=takeFloatInput();
        interest=(bb.bal*RATE*period)/100;
        cout<<"\n\nfor amount Rs."<< bb.bal<<" with interest rate rate "
            <<RATE<<"% which adds Rs. "<<interest
            <<" as a interest "
            <<"total amount will have to be returned after "
            <<period<<" year is "<<bb.bal+interest;
    }
    else
    {
        cout<<"\ninvalid choice ! try again"<<endl;
        goto reEnter4;
    }
}*/
void bank::deposit()
{
    float depAmount;
    cout<<"\n Enter Deposit Amount = ";
    depAmount=takeFloatInput();
    cout<<"\n\ndepositing amount...please wait...\n\n";
    usleep(2000000);
    bal+=depAmount;
    cout<<" amount "<<depAmount
        <<" deposited successfully.!!"
        <<" new updated balance is : "<<bal;

    for(int i=0; i<100; i++)
    {
        if(statement[i]==0)
        {
            statement[i]=depAmount;
            netBal[i]=bal;
            break;
        }
    }


}
void bank::withdraw()
{
    float withAmount;
    cout<<"\n Enter Withdraw Amount = ";
    withAmount=takeFloatInput();
    cout<<"deducting amount...please wait for a while...";
    usleep(2000000);
    if((bal-withAmount)<0) {
        cout<<"\ninsufficient amount\n";
        cout<<"\n Cannot Withdraw Amount";
    }
    else if((bal-withAmount)<1000 &&(bal-withAmount)>0 ) {
        cout<<"\nwarning:\n\ninsufficient balance"
            <<": your balance will be less than "
            <<"threshold balance\n\n"
            <<"do you want to continue : (y/n)\n";
        char r;
        cin>>r;
        if(r=='y') {
            bal-=withAmount;
            for(int i=0; i<100; i++)
            {
                if(statement[i]==0)
                {
                    statement[i]=-withAmount;
                    netBal[i]=bal;
                    break;
                }

            }
        }
        else {
            exit(0);
        }
    }
    else {
        cout<<"\nbalance deducted successfully!!! \n";
        bal-=withAmount;
        for(int i=0; i<100; i++)
        {
            if(statement[i]==0)
            {
                statement[i]=-withAmount;
                netBal[i]=bal;
                break;
            }
        }
        cout<<" remaining balance is : "<<bal;
    }
}
void bank::display()
{
    cout<<"\n ----------------------";
    cout<<"\n Accout No. : "<<accountNumber;
    cout<<"\n Name : "<<name<<" "<<lname;
    cout<<"\n Account Type : "<<acctype;
    cout<<"\n Balance : "<<bal;
}
int main()
{
    /*string pass="2045";
    cout <<"\nenter password: ";
  //  pass=takeIntegerInput();

    string password = "";
    char ch;

 //   cout << "Enter password: ";

    while(true)
    {
        ch = _getch();

        if(ch == 13) // If Enter is pressed
            break;
        else if(ch == 8) // If Backspace is pressed
        {
            if(password.length() > 0)
            {
                password.erase(password.length() - 1);
                cout << "\b \b";
            }
        }
        else
        {
            password += ch;
            cout << "*";
        }
    }
    

 //   cout << endl << "Password: " << password;

    











    cout<<"\nchecking password...\n ";
    if(pass != password) {
        usleep(1000000);
        cout<<"\nsorry!! wrong password ! try again\n";
        main();
    }


    usleep(1000000);
    cout<<"\npassword matched.\n\n";
    system("cls");*/
//cout<<"\n\n----------------------------------------"<<endl;
    cout<<"|---------------------------------------|"<<endl;
    cout<<"|===============WELCOME=================|"<<endl;
    cout<<"|======TO BANKING MANAGEMENT SYSTEM=====|"<<endl;
    cout<<"|---------------------------------------|"<<endl;
reRead:
    cout<<endl<<endl;
    cout<<"|---------------------------------------|"<<endl;
    cout<<"|****read all instructions carefully****|"<<endl;
    cout<<"|---------------------------------------|"<<endl;
    cout<<endl;
    cout<<"1. minimum opening balance is 1500.\n\n";
    cout<<"2. interest rate is 4% annual.\n\n";
    cout<<"3. field marked with * must be filled properly.\n\n";
    cout<<"4. invalid input may cause termination"
        <<" of programm or may show undefined "
        <<"behaviour.\n\n";
    /*usleep(2000000);
    cout<<"5";
    cout<<" ";
    usleep(2000000);
    cout<<"4";
    cout<<" ";
    usleep(2000000);
    cout<<"3";
    cout<<" ";
    usleep(2000000);
    cout<<"2";
    cout<<" ";
    usleep(2000000);
    cout<<"1";
    cout<<" ";
    usleep(2000000);
    cout<<"0";
    cout<<" ";*/
    usleep(2000000);

    cout<<"\npress enter to continue: "<<endl;
    getchar();
    cout<<"-----------------------------------------"<<endl;
    int i,p,j;
    cout<<"enter number of new customer for "
        <<"opening account: ";
    p=takeIntegerInput();
    int & n = p;
    cout<<"\n";
    bank b1[n];
    cout<<"\n\n----------------------------";
mainMenu:
    cout<<"\ndisplaying details:\n ";
//cout<<"\n--------------------------------";
    cout<<"S.no.        NAME      ACC.NO. ";
//cout<<"\n ---------------------------------";
    cout <<endl;
    for(i=0; i<n; i++) {

        cout<<i+1<<"\t";
        b1[i].preDisplay();
        cout<<"\n";
        cout<<" ";
    }

    cout<<"\n\n----------------------------";
    long id,op;
reEnter7:
    cout<<"\nenter S.no. for further"
        <<" operation\n";
    id=takeIntegerInput();
    if(id>p||id<1)
        goto reEnter7;
operation:
    cout<<"which operation do you "
        <<"want to perform\n\n"
        <<"[1]. for DEPOSITE \n\n"
        <<"[2]. for WITHDRAW \n\n"
        <<"[3]. for DISPLAY DETAILS\n\n"
        <<"[4]. display all CUSTOMER LIST\n\n"
        <<"[5]. for TRANSFER amount \n\n"
        <<"[6]. for FIXED DEPOSITE \n\n"
        <<"[7]. SCHEMES  eligibility\n\n"       
        <<"[8]. PRINT PASSBOOK \n\n"
        <<"[9]. for LOAN\n\n"
        <<"[0]. EXIT\n\n";
chooseAgain:
    op=takeIntegerInput();
    cout<<"\n\n----------------------------";
    // char dp;
    if(op<0||op>9)
    {
        cout<<"\nchoice out of range !! \nchoose within the range !"<<endl;
        goto chooseAgain;
    }
    

    if (op==0)
        exit(0);

    else if(op==1)
        b1[id-1].deposit();
        

    else if (op==2)
        b1[id-1].withdraw();
        

   else if (op==3){
        cout<<"\n\norganizing data for display..please wait...";
        b1[id-1].display();
        }

    else if (op==6){
        //  cout<<"\n\ncalculating interest..please wait...";
        //  usleep(2000000);
reChoice:
        cout<<"\nselect:<1/2>\n"
            <<"1. show previous FD\n"
            <<"2. deposite\n"<<endl;
        int choice=takeIntegerInput();
        if(choice>2||choice<1){
            goto reChoice;
            }
        else if(choice==1){
            cout<<"*******PREVIOUS FD*************"<<endl;
        b1[id-1].showFd();
        }
        else{
            cout<<"**********CREATING NEW FD************"<<endl;
        b1[id-1].fixedDeposite();
}
        }

    else if (op==7){
        scheme(b1[id-1]);
        }

    else if(op ==4)
        goto mainMenu;
       else if(op==9) {
    cout<<"\nselect: <1/2> \n";
    reEnter11:
      cout<<"[1]. SHOW LOAN \n"
          <<"[2]. NEW LOAN \n";
        int chs=takeIntegerInput();
        if(chs==1)
        {
        cout<<"\n**********PREVIOUS LOAN***********"<<endl;
        b1[id-1].showLoan();
        }
        else if(chs==2)
    {
    cout<<"\n*************NEW LOAN*****************"<<endl;   
   int l= b1[id-1].loan();
    }
    else {
    cout<<"\nchoose within range<1/2>"<<endl;
    goto reEnter11;
    }
    }

    else if(op==8){
        cout<<endl;
        cout<<"|-------------------------------------|"<<endl;
        cout<<"|================PASSBOOK=============|"<<endl;
        cout<<"      "<<b1[id-1].returnAcc()<<endl;
        cout<<"|-------------------------------------|";
        cout<<endl;
        b1[id-1].display();
        b1[id-1].showFd();
        cout<<endl;
        b1[id-1].printStatement();
        }

    else if (op==5){
withdrawalFailed:
        long ac,dc;
reEnter:

        cout<<" \nenter account number "
            <<"to be debited : ";
        dc=takeLongIntegerInput();
        int flag1=0;
        for(i=0; i<n; i++) {


            if(dc==b1[i].returnAcc()) {
                flag1=1;
                b1[i].display();
                cout<<"\ndo you want to continue(y/n) \n";
                char vp;
                cin>>vp;
                if(vp=='y')
                    break;
                else
                    goto reEnter;
            }
        }
        if(flag1==0) {
            cout<<"\n account not found..try again\n ";
            goto reEnter;

        }
reEnter2:
        cout<<"\n enter account number "
            <<"to be credited : ";
        ac=takeLongIntegerInput();
        int flag =0;
        for(j=0; j<n; j++) {
            if(ac==b1[j].returnAcc()) {

                flag =1;
                b1[j].display();
                cout<<"\ndo you want to continue(y/n) \n";
                char up;
                cin>>up;
                if(up=='y')
                    break;
                else
                    goto reEnter;
            }

        }
        if(flag==0) {
            cout<<"\n account not found..try again\n ";
            goto reEnter2;

        }
        float amount;

        cout<<"\nenter amount to be credited: ";
        amount=takeFloatInput();
        cout<<"deducting amount from aacnt no. "
            <<b1[i].returnAcc()<<" please wait...\n";

        float  bal11=b1[i].returnBal();
        b1[i].wbal(amount);
        float bal12=b1[i].returnBal();
        if(bal11 == bal12) {
            cout<<"\n withdrawal failed\n";
            goto withdrawalFailed;
        }
        else {
            b1[j].addBal(amount);
            cout<<"\ndeducting balance...\n";
            usleep(2000000);
            cout<<"balance deducted successfully!!\n";
            cout<<"crediting amount...please wait...\n";
            usleep(2000000);
            cout<<"\ntransfer successful!!";
        }
       }
        //default:
        //cout<<"you haven't enter valid choice";

    


    cout<<"\n\n----------------------------";
    cout<<"\n do you want further "
        <<" operation:(y/n)\n";
    char c;
    cin>>c;
    if(c=='y')
        goto operation;
    else
        exit(0);

    cout<<"\n\nthank you for using this program\n!!!";

    return 0;
}
