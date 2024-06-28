#include <iostream>
using namespace std;

void display_Board();
int checkWin();
void system();

char board[]= {'0','1','2','3','4','5','6','7','8','9'};

int main()
{
    int player=1,input,status=-1;
    display_Board();


    while (status==-1)
    {
        player=(player%2==0) ? 2 : 1;
        char mark=(player==1) ? 'X' :'*';
        cout<<"\nPlease Enter Number For Player "<<player<<" : ";
        cin>>input;
        if(input<1 || input>9)
        {
            cout<<"invalid input";
        }

        board[input]=mark;
        display_Board();

        int result=checkWin();

        if(result==1)
        {
            cout<<"\n\t\t----------------------------\n";
            cout<<"\t\t| The Winner is : Player "<<player <<" |";
            cout<<"\n\t\t----------------------------\n";
            return 0;
        }
        else if(result==0)
        {
            cout<<"\n\t\t--------------------\n";
            cout<<"\t\t| The Game is draw |";
            cout<<"\n\t\t--------------------\n";
            return 1;
        }

        player++;
    }


}

void display_Board()
{
    system("cls");
    cout<<"\n\n   \t\t Tick  Cross  Game\n\t\t-------------------\n"<<endl;
    cout<<"\tPlayer 1 = X\n  \tPlayer 2 = *\n\n\n";
    cout<<" \t\t     |     |    \n";
    cout<<" \t\t  "<<board[7]<<"  |  "<<board[8]<<"  |  "<<board[9]<<"  \n";
    cout<<" \t\t_____|_____|_____  \n";
    cout<<" \t\t     |     |    \n";
    cout<<" \t\t  "<<board[4]<<"  |  "<<board[5]<<"  |  "<<board[6]<<"  \n";
    cout<<" \t\t_____|_____|_____   \n";
    cout<<" \t\t     |     |    \n";
    cout<<" \t\t  "<<board[1]<<"  |  "<<board[2]<<"  |  "<<board[3]<<" \n";
    cout<<" \t\t     |     |    \n";



}


int checkWin()
{

    if(board[1]==board[2] && board[2]==board[3])
    {
        return 1;
    }
    if(board[1]==board[4] && board[4]==board[7])
    {
        return 1;
    }
    if(board[7]==board[8] && board[8]==board[9])
    {
        return 1;
    }
    if(board[3]==board[6] && board[6]==board[9])
    {
        return 1;
    }
    if(board[1]==board[5] && board[5]==board[9])
    {
        return 1;
    }
    if(board[3]==board[5] && board[5]==board[7])
    {
        return 1;
    }
    if(board[2]==board[5] && board[5]==board[8])
    {
        return 1;
    }
    if(board[4]==board[5] && board[5]==board[6])
    {
        return 1;
    }

    int count=0;
    for (int i = 1; i <=9; i++)
    {
        if(board[i]=='X' || board[i]=='*')
        {
            count++;
        }
    }

    if(count==9)
    {
        return 0;
    }
    return -1;
}
