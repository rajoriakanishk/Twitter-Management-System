#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class NODE
{
public:
    string ID;
    string NAME;
    string TWEET;
    NODE *NEXT ;

    NODE(string X , string Y , string Z)
    {
        ID = X;
        NAME = Y;
        TWEET = Z;
        NEXT = nullptr;
    }
};
class singlylinklist
{
public:
    string TID;
    string UNAME;
    string UTWEET;
    int CountNode;
    int AutoTID;
    NODE *START , *END ;
    singlylinklist()
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
        cout<<"\nEnter TID :-"<<TID<<endl;
        cout<<"Enter User Name :- ";
        getline(cin,UNAME);
        cout<<"Enter Tweet :- ";
        getline(cin,UTWEET);
    }

    //Insert Operation
    void InsertOperation()
    {
        system("cls");
        cout<<"\n==============Insertion Opertaion==============\n";
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
            NODE *TEMP = new NODE(TID,UNAME,UTWEET);
            if (TEMP == nullptr){
                cout<<"Insufficient Memory\n";
                return 0;
            }
            if(START == nullptr){
                END = START = TEMP;
            }else {
                TEMP->NEXT = START;
                START = TEMP;
            }
            CountNode++;
            AutoTID++;
        }else if (x == 2){
            cout<<"----------Insertion at End----------\n";
            getdata();
            NODE *TEMP = new NODE(TID,UNAME,UTWEET);
            if (TEMP == nullptr){
                cout<<"Insufficient Memory\n";
                return 0;
            }
            if(START == nullptr){
                END = START = TEMP;
            }else {
                END->NEXT = TEMP;
                END = TEMP;
            }
            CountNode++;
            AutoTID++;
        }else if (x == 3){
            cout<<"----------Insertion at given Position----------\n";
            cout<<"Total Number of Nodes Are -- "<<CountNode<<endl;
            int pos;
            cout<<"Enter Position Between 0 and "<<CountNode<<" - ";
            cin>>pos;
            cin.ignore();
            getdata();
            NODE *TEMP = new NODE(TID,UNAME,UTWEET);
            if (TEMP == nullptr){
                cout<<"Insufficient Memory";
                return 0;
            }
            int i ;
            NODE *TEMP1 = START;
            for(i = 2 ; i < pos ; i++){
                TEMP1 = TEMP1->NEXT;
            }
            if(START == nullptr){
                END = START = TEMP;
            }else {
                TEMP->NEXT = TEMP1->NEXT;
                TEMP1->NEXT=TEMP;
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


    //Show Module
    void Traversal()
    {
        system("cls");
        cout<<"\n----------Link List----------\n\n";
        cout<<"Head -> ";
        NODE *TEMP = START;
        if ( START == nullptr){
            cout<<"NULL  \n\nLinklist is Empty";
        }
        else {
            while(TEMP != nullptr){
                cout<<"[ "<<TEMP->ID<<" , ";
                cout<<TEMP->NAME<<" , ";
                cout<<TEMP->TWEET<<" ] -> ";
                TEMP=TEMP->NEXT;
            }
            cout<<"Null";
        }
        cout<<"\n\nDo you want to -- \n";
        cout<<"1.Continue the Same\n";
        cout<<"2.Go to Main Menu\n";
        cout<<"3.Exit\n";
        char c = getch();
        if(c == '1'){
            Traversal();
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
        cout<<"4.Exit\n";
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
            cout<<"Search Tweet by Tweet ID----------\n\n";
            NODE *TEMP = START;
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
                        cout<<TEMP->NAME<<" , ";
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

            NODE *TEMP = START;
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
                    if(TEMP->NAME == uname){
                        cout<<"\n[ "<<TEMP->ID<<" , ";
                        cout<<TEMP->NAME<<" , ";
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
        cout<<"\n==============Deletion Opertaion==============\n";
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
        NODE *TEMP ;
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
            }

            CountNode--;
            delete(TEMP);
            cout<<"Node Deleted Successfully...\n";

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
                TEMP = START ;
                while(TEMP->NEXT != END){
                    TEMP = TEMP->NEXT;
                }
                NODE *TEMP1 = END;
                TEMP->NEXT = nullptr;
                END = TEMP;
                delete(TEMP1);
            }
            CountNode--;
            cout<<"Node Deleted Successfully...\n";
        }
        else if (x == 3)
        {
            cout<<"\n----------Delete from given Position----------\n";
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
                for(i = 2 ; i < pos ; i++){
                    TEMP = TEMP->NEXT;
                }
                if(TEMP->NEXT == END){
                    NODE *TEMP1 = END;
                    TEMP->NEXT = nullptr;
                    END = TEMP;
                }else{
                    NODE *TEMP1 = TEMP->NEXT;
                    TEMP->NEXT = TEMP1->NEXT;
                    delete(TEMP1);
                }
            }
            CountNode--;
            cout<<"\nNode Deleted Successfully...\n";
        }
        char c = ContinueOperation();
        if(c == '1'){
            DeleteNode(x);
        }else if(c == '2'){
            DeleteOperation();
        }else if(c == '3'){
            MainMenu();
        }

    }

    //Continue Menu
    int ContinueOperation()
    {
        cout<<"\nDo you want to -- \n";
        cout<<"1.Continue the Same\n";
        cout<<"2.Go to Previous Menu\n";
        cout<<"3.Go to Main Menu\n";
        cout<<"4.Exit\n";
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
        cout<<"\n==============Count Node Module==============\n\n";
        cout<<"Total Number of Nodes -- "<<CountNode<<" Available Nodes\n\n";
        cout<<"Do you want to -- \n";
        cout<<"1.Continue the Same\n";
        cout<<"2.Go to Main Menu\n";
        cout<<"3.Exit\n";
        char c = getch();
        if(c == '1'){
            countnode();
        }else if(c == '2'){
            MainMenu();
        }else if(c == '3'){
            exit(0);
        }
    }
    //MAIN MENU
    void MainMenu()
    {
        system("cls");
        cout<<"\n==============Singly LinkList Operations==============\n";
        cout<<"1.Insertion Operation\n";
        cout<<"2.Traversal Operation\n";
        cout<<"3.Search Operation\n";
        cout<<"4.Delete Operation\n";
        cout<<"5.Count Node\n";
        cout<<"6.Go To Main Link List Menu\n\n";
        cout<<"Choose one of Them -- ";
        char c = getch();
        if(c == '1'){
            InsertOperation();
        }else if (c == '2'){
            Traversal();

        }else if (c == '3'){
            SearchOperation();
        }else if (c == '4'){
            DeleteOperation();
        }else if (c == '5'){
            countnode();
        }else if (c == '6'){
            cout << "\n\nThank you for using my Singly Link List Operations...\n\n";
            return;
        }
    }

    void thankyouLine()
    {
        cout<<"\n\nThank you for using my Application...\n\n";
    }

};

