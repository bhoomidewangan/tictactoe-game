#include <iostream>
using namespace std;

void printBoard(char arr[][3])
{
    cout<<"----------------------------"<<endl;
    cout<<"| "<<arr[0][0]<<" | "<<arr[0][1]<<" | "<<arr[0][2]<<" |"<<endl;
    cout<<"|-----------|"<<endl;
    cout<<"| "<<arr[1][0]<<" | "<<arr[1][1]<<" | "<<arr[1][2]<<" |"<<endl;
    cout<<"|-----------|"<<endl;
    cout<<"| "<<arr[2][0]<<" | "<<arr[2][1]<<" | "<<arr[2][2]<<" |"<<endl;
    cout<<"----------------------------"<<endl;
}

bool check(char arr[][3], int  n)
{
    int row = (n-1)/3;
    int col = (n-1)%3;
    if(arr[row][0]!=' ' && arr[row][0]==arr[row][1] && arr[row][1]==arr[row][2] && arr[row][2]==arr[row][0])
        return true;
    else if(arr[0][col]!=' ' && arr[0][col]==arr[1][col] && arr[1][col]==arr[2][col] && arr[2][col]==arr[0][col])
        return true;
    else if(arr[0][0]!=' ' && arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] && arr[2][2]==arr[0][0])
        return true;
    else if(arr[0][2]!=' ' && arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0] && arr[2][0]==arr[0][2])
        return true;
    else 
        return false;
}

int main()
{
    int k=0, i, count=0;

    int freq[9];
    for(int ir=0;ir<9;ir++)
    {
        freq[ir]=0;
    }

    char arr[3][3];
    for(int ir=0;ir<3;ir++)
    {
        for(int jc=0;jc<3;jc++)
        {
            arr[ir][jc]=' ';
        }
    }

    cout<<"Player 1 is X"<<endl;
    cout<<"Player 2 is O"<<endl;
    cout<<"Position numbers are from 1 to 9"<<endl;
    cout<<"Let's start the game."<<endl;
    printBoard(arr);

    while(k!=1)
    {
        cout<<"Enter the position player 1"<<endl;
        cin>>i;
        if(i>=1 && i<=9)
            freq[i-1]++;
        while(i>9 || i<1 || freq[i-1]!=1)
        {
            cout<<"Invaild input"<<endl;
            cout<<"Enter another number"<<endl;
            cin>>i;
            if(i>=1 && i<=9)
                freq[i-1]++;
        }
        count++;
        arr[(i-1)/3][(i-1)%3]='X';
        printBoard(arr);
        if(check(arr, i))
        {
            k=1;
            cout<<"Player 1 wins"<<endl;
            break;
        }


        if(count==9)
        {
            cout<<"Tie"<<endl;
            break;
        }


        cout<<"Enter the position player 2"<<endl;
        cin>>i;
        if(i>=1 && i<=9)
            freq[i-1]++;
        while(i>9 || i<1 || freq[i-1]!=1)
        {
            cout<<"Invaild input"<<endl;
            cout<<"Enter another number"<<endl;
            cin>>i;
            if(i>=1 && i<=9)
                freq[i-1]++;
        }
        count++;
        arr[(i-1)/3][(i-1)%3]='O';
        printBoard(arr);
        if(check(arr, i))
        {
            k=1;
            cout<<"Player 2 wins"<<endl;
            break;
        }
    }
    return  0;
}