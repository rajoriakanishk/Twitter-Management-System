#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class DNODE
{
public:
    DNODE *PREV ;
    string ID;
    string UNAME;
    string TWEET;
    DNODE *NEXT  ;
    DNODE(string X , string Y , string Z)
    {
        PREV = nullptr;
        ID = X;
        UNAME = Y;
        TWEET = Z;
        NEXT = nullptr;
    }
};
class Doublylinklist
{
public:
    string TID;
    string UNAME;
    string UTWEET;
    int CountNode;
    int AutoTID;
    DNODE *START , *END ;
    Doublylinklist()
    {
        AutoTID=1001;
        CountNode=0;
        START=nullptr;
        END=nullptr;
    }


    //Get Data
    void getdata()
    {
        TID = "TWEET" + to_string(AutoTID);
        cout<<"Enter TID :-"<<TID<<endl;
        cout<<"Enter User Name :- ";
        getline(cin,UNAME);
        cout<<"Enter Tweet :- ";
        getline(cin,UTWEET);
    }

    //Insertion Operation
    void InsertOperation()
    {
        system("cls");
        cout<<"==============Insertion Opertaion==============\n";
        cout<<"1.Insert at Beggining\n";
        cout<<"2.Insert at End\n";
        cout<<"3.Insert at given Position\n";
        cout<<"4.Go to Main Menu\n";
        cout<<"5.Exit\n";
        char c = getch();
        if(c == '1'){
            InsertNode(1);
        }else if (c == '2'){
            InsertNode(2);
        }else if (c == '3'){
            InsertNode(3);
        }else if (c == '4'){
            MainMenu();
        }else if (c == '5'){
            thankyouLine();
            exit(0);
        }
    }

       //Insert Module
    int InsertNode(int x)
    {
        system("cls");
        if(x == 1){
            cout<<"----------Insertion at Beggining----------\n";
            getdata();
            DNODE *TEMP = new DNODE(TID,UNAME,UTWEET);
            if (TEMP == nullptr){
                cout<<"Insufficient Memory\n";
                return 0;
            }
            if(START == nullptr){
                END = START = TEMP;
            }else {
                TEMP->NEXT = START;
                START->PREV = TEMP;
                START = TEMP;
            }
            CountNode++;
            AutoTID++;
        }else if (x == 2){
            cout<<"----------Insertion at End----------\n";
            getdata();
            DNODE *TEMP = new DNODE(TID,UNAME,UTWEET);
            if (TEMP == nullptr){
                cout<<"Insufficient Memory\n";
                return 0;
            }
            if(START == nullptr){
                END = START = TEMP;
            }else {
                END->NEXT = TEMP;
                TEMP->PREV = END;
                END = TEMP;
            }
            CountNode++;
            AutoTID++;
        }else if (x == 3){
            cout<<"----------Insertion at given Position----------\n";
            cout<<"Total Number of Nodes Are -- "<<CountNode<<endl;
            int pos;
            getdata();
            cout<<"Enter Position Between 0 and "<<CountNode<<"- ";
            cin>>pos;
            DNODE *TEMP = new DNODE(TID,UNAME,UTWEET);
            if (TEMP == nullptr){
                cout<<"Insufficient Memory";
                return 0;
            }
            int i ;
            DNODE *TEMP1 = START;
            for(i = 2 ; i < pos ; i++){
                TEMP1 = TEMP1->NEXT;
            }
            if(START == nullptr){
                END = START = TEMP;
            }else {
                TEMP->NEXT = TEMP1->NEXT;
                TEMP1->NEXT=TEMP;
                TEMP->PREV = TEMP1;//!this is the question
                TEMP->NEXT->PREV =TEMP;//!this is the question
                if (TEMP1 == END){
                    END = TEMP1->NEXT;
                }
            }
            CountNode++;
            AutoTID++;
        }
        char c = ContinueOperation();
        if(c == '1'){
            InsertNode(x);
        }else if(c == '2'){
            InsertOperation();
        }else if(c == '3'){
            MainMenu();
        }

    }

    //Traversal Module
    void TraversalOperation()
    {
        system("cls");
        cout<<"==============Traversal Module==============\n\n";
        cout<<"1.Forward Traversal \n";
        cout<<"2.Backward Traversal \n";
        cout<<"3.Main Menu \n";
        cout<<"4.Exit\n\n";
        char c = getch();
        if(c == '1'){
            Traversal(1);
        }else if(c == '2'){
            Traversal(2);
        }else if(c == '3'){
            MainMenu();
        }else if(c == '4'){
            exit(0);
        }
    }

    //Show Module
    int Traversal(int x)
    {
        system("cls");
        if(x == 1){
            cout<<"\n\n----------Link List----------\n\n";
            cout<<"NULL <- ";
            DNODE *TEMP = START;
            if ( START == nullptr){
                cout<<"NULL  \n\nLinklist is Empty";
                return 0;
            }
            else {
                while(TEMP != nullptr){
                    cout<<"[ "<<TEMP->ID<<" , ";
                    cout<<TEMP->UNAME<<" , ";
                    cout<<TEMP->TWEET<<" ] -> ";
                    TEMP=TEMP->NEXT;
                }
                cout<<"Null";
            }
        } else if(x == 2){
            cout<<"\n\n----------Link List----------\n\n";
            cout<<"NULL <- ";
            DNODE *TEMP = END;
            if ( START == nullptr){
                cout<<"NULL  \n\nLinklist is Empty";
            }
            else {
                while(TEMP != nullptr){
                    cout<<"[ "<<TEMP->ID<<" , ";
                    cout<<TEMP->UNAME<<" , ";
                    cout<<TEMP->TWEET<<" ] -> ";
                    TEMP=TEMP->PREV;
                }
                cout<<"Null";
            }
        }
        cout<<"\n\nDo you want to -- \n";
        cout<<"1.Continue the Same\n";
        cout<<"2.Go to Main Menu\n";
        cout<<"3.Exit";
        char c = getch();
        if(c == '1'){
            Traversal(x);
        }else if(c == '2'){
            MainMenu();
        }else if(c == '3'){
            thankyouLine();
            exit(0);
        }
    }

    //Search Operation
    void SearchOperation()
    {
        system("cls");
        cout<<"==============Search Module==============\n\n";
        cout<<"1.Search by Tweet ID \n";
        cout<<"2.Search by User Name \n";
        cout<<"3.Main Menu \n";
        cout<<"4.Exit\n\n";
        char c = getch();
        if(c == '1'){
            searchNode(1);
        }else if(c == '2'){
            searchNode(2);
        }else if(c == '3'){
            MainMenu();
        }else if(c == '4'){
            exit(0);
        }
    }

    //Search Module
    int searchNode(int x)
    {
        system("cls");
        if (x == 1){
            cout<<"----------Search Tweet by Tweet ID----------\n\n";
            DNODE *TEMP = START;
            if (START == nullptr){
                cout<<"Head -> Null  \n\nLink List is Empty...";
                return 0;
            }else{
                int counter=0;
                cout<<"Enter Tweet ID to find the Tweet -- ";
                string TweetID;
                getline(cin,TweetID);
                while (TEMP != nullptr){
                    if(TEMP->ID == ("TWEET" + TweetID)){
                        cout<<"\n[ "<<TEMP->ID<<" , ";
                        cout<<TEMP->UNAME<<" , ";
                        cout<<TEMP->TWEET<<" ]\n";
                        counter++;
                    }
                    TEMP = TEMP->NEXT;
                }
                if(counter == 0){
                    cout<<"\nNo Tweet Found\n\n";
                }
            }
        }
        else if(x == 2){
            cout<<"----------Search Tweet by User Name----------\n\n";

            DNODE *TEMP = START;
            if (START == nullptr){
                cout<<"Head -> Null  \n\nLink List is Empty...";
                return 0;
            }else{
                int counter=0 ;
                cout<<"Enter user Name to find the Tweet -- ";
                string uname;
                getline(cin,uname);
                cout<<endl<<"Head -> ";
                while (TEMP != nullptr){
                    if(TEMP->UNAME == uname){
                        cout<<"\n[ "<<TEMP->ID<<" , ";
                        cout<<TEMP->UNAME<<" , ";
                        cout<<TEMP->TWEET<<" ]\n";
                        counter++;
                    }
                    TEMP = TEMP->NEXT;
                }
                if(counter == 0){
                    cout<<"\nNo Tweet Found\n\n";
                }
            }
        }
        cout<<"Do you want to -- \n";
        cout<<"1.Continue the Same\n";
        cout<<"2.Go to Main Menu\n";
        cout<<"3.Exit\n";
        char c = getch();
        if(c == '1'){
            searchNode(x);
        }else if(c == '2'){
            MainMenu();
        }else if(c == '3'){
            thankyouLine();
            exit(0);
        }
    }

    //Delete Operation
    void DeleteOperation()
    {
        system("cls");
        cout<<"==============Deletion Opertaion==============\n\n";
        cout<<"1.Delete from Beggining\n";
        cout<<"2.Delete from End\n";
        cout<<"3.delete from a given Position\n";
        cout<<"4.Go to Main Menu\n";
        cout<<"5.Exit\n";
        char c = getch();
        if(c == '1'){
            DeleteNode(1);
        }else if (c == '2'){
            DeleteNode(2);
        }else if (c == '3'){
            DeleteNode(3);
        }else if (c == '4'){
            MainMenu();
        }else if (c == '5'){
            thankyouLine();
            exit(0);
        }
    }
    //Delete Module
    int DeleteNode(int x)
    {
        system("cls");
        DNODE *TEMP ;
        if(x == 1){
            cout<<"----------Delete from Beggining----------\n";
            if(START == nullptr)
            {
                cout<<"Link List is Empty...\n\n";
                return 0;
            }
            else if (START->NEXT == nullptr)
            {
                TEMP = START;
                END = START = nullptr;
            }else
            {
                TEMP = START;
                START = TEMP->NEXT;
                START->PREV = nullptr;
            }

            CountNode--;
            delete(TEMP);
            cout<<"\nNode Deleted Successfully...\n";

        }
        else if (x == 2)
        {
            cout<<"----------Delete from End----------\n";
            if(START == nullptr)
            {
                cout<<"Link List is Empty...\n\n";
                return 0;
            }
            else if (START->NEXT == nullptr)
            {
                TEMP = START;
                END = START = nullptr;
            }
            else
            {
                TEMP = END;
                END = END->PREV;
                END->NEXT=nullptr;
                /*!
                TEMP=END;
                TEMP->PREV->NEXT=NULLPTR;
                END=TEMP->PREV;
                */
                delete(TEMP);
            }
            CountNode--;
            cout<<"\nNode Deleted Successfully...";
        }
        else if (x == 3)
        {
            cout<<"\n\n----------Delete from given Position----------\n";
            if (START == nullptr){
                cout<<"Link List is Empty...\n\n";
                return 0;
            }
            int pos ,i;
            cout<<"Enter Position Between 1 and "<<CountNode<<"- ";
            cin>>pos;
            if (pos == 1 && START==END){
                TEMP = START ;
                END = START = nullptr;
            }
            else{
                TEMP =START;
                for(i = 1 ; i < pos ; i++){
                    TEMP = TEMP->NEXT;
                }
                if(TEMP == END){
                    TEMP->PREV->NEXT = nullptr;
                    END = TEMP->PREV;
                    delete(TEMP);
                }else{
                    TEMP->PREV->NEXT = TEMP->NEXT;
                    TEMP->NEXT->PREV = TEMP->PREV;
                    delete(TEMP);
                }
            }
            CountNode--;
            cout<<"Node Deleted Successfully...";
        }
        char c = ContinueOperation();
        if(c == '1'){
            DeleteNode(x);
        }else if(c == '2'){
            InsertOperation();
        }else if(c == '3'){
            MainMenu();
        }

    }

    //Continue Module
    int ContinueOperation()
    {
        cout<<"Do you want to -- \n";
        cout<<"1.Continue the Same\n";
        cout<<"2.Go to Previous Menu\n";
        cout<<"3.Go to Main Menu\n";
        cout<<"4.Exit";
        char c = getch();
        if(c == '4'){
            thankyouLine();
            exit(0);
        }else {
            return(c);
        }
    }

    //Count Node Module
    void countnode()
    {
        system("cls");
        cout<<"==============Count Node Module==============";
        cout<<"\n\nTotal Number of Nodes -- "<<CountNode<<"Available Nodes\n\n";
        cout<<"Do you want to -- \n";
        cout<<"1.Continue the Same\n";
        cout<<"2.Go to Main Menu\n";
        cout<<"3.Exit";
        char c = getch();
        if(c == '1'){
            countnode();
        }else if(c == '2'){
            MainMenu();
        }else if(c == '3'){
            exit(0);
        }
    }
    //Main Menu
    void MainMenu()
    {
        system("cls");
        cout<<"==============Doubly LinkList Operations===========\n";
        cout<<"1.Insertion Operation\n";
        cout<<"2.Traversal Operation\n";
        cout<<"3.Search Operation\n";
        cout<<"4.Delete Operation\n";
        cout<<"5.Count Node\n";
        cout<<"6.Go To Main Link List Menu\n\n";
        char c = getch();
        if(c == '1'){
            InsertOperation();
        }else if (c == '2'){
            TraversalOperation();
        }else if (c == '3'){
            SearchOperation();
        }else if (c == '4'){
            DeleteOperation();
        }else if (c == '5'){
            countnode();
        }else if (c == '6'){
            cout << "\n\nThank you for using my Doubly Link List Operations...\n\n";
            return;
        }
    }

    void thankyouLine()
    {
        cout<<"\n\nThank you for using my Application...\n\n";
    }
};

