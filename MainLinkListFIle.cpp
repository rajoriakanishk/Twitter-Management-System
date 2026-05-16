#include "singlyLinkListBYME.hpp"
#include "DoublyLinkListBYME.hpp"

int main()
{
    singlylinklist sl;
    Doublylinklist dl;
    while (true)
    {
        system("cls");
        cout<<"\n\n==============Main Link List Menu==============\n";
        cout<<"1.Singly Link List\n";
        cout<<"2.Doubly Link List\n";
        cout<<"3.Exit\n";
        char c = getch();
        if(c == '1'){
            sl.MainMenu();
        }else if (c == '2'){
            dl.MainMenu();
        }else if (c == '3'){
            break;
        }
    }
    cout<<"\n\nThank you for using my Application...\n\n";
    return 0;
}