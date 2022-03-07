#include<iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn ='X';
bool draw = false;
void displayboard(){
system("cls");
cout<<"\t\t\t  #Tic Tac Toe#\n\n";
cout<<"\tPlayer[1] : X\n\tplayer[2] : O\n\n";
cout<<"\t\t\t     |     |     \n";
cout<<"\t\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
cout<<"\t\t\t_____|_____|_____\n";
cout<<"\t\t\t     |     |     \n";
cout<<"\t\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
cout<<"\t\t\t_____|_____|_____\n";
cout<<"\t\t\t     |     |     \n";
cout<<"\t\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
cout<<"\t\t\t     |     |     \n";
}
void playerturn(){
int choice,row,col;
if(turn=='X'){
	cout<<"Player[X] turn : ";
}
if(turn=='O'){
	cout<<"Player[O] turn : ";
}

cin>>choice;

switch(choice){
	case 1:
		row=0,col=0;
		break;
	case 2:
		row=0,col=1;
		break;
	case 3:
		row=0,col=2;
		break;
	case 4:
		row=1,col=0;
		break;
	case 5:
		row=1,col=1;
		break;
	case 6:
		row=1,col=2;
		break;
	case 7:
		row=2,col=0;
		break;
	case 8:
		row=2,col=1;
		break;
	case 9:
		row=2,col=2;
		break;
	default:
		cout<<"Invalid Input";
		break;	
	
}
if(turn=='X' && board[row][col]!='X' && board[row][col]!='O'){
	board[row][col]='X';
	turn='O';
}
else if(turn=='O' && board[row][col]!='X' && board[row][col]!='O'){
	board[row][col]='O';
	turn='X';
}
else{
	cout<<"?? Box Already filled\nTry Again\n";
	playerturn();
}
displayboard();
}
bool gamesense(){
//	to check win
	for(int i=0;i<3;i++){
		if(board[i][0]==board[i][1] && board[i][0]==board[i][2] ||
		 board[0][i]==board[1][i] && board[0][i]==board[2][i] ||
		 board[0][0]==board[1][1] && board[0][0]==board[2][2] ||
		 board[0][2]==board[1][1] && board[0][2]==board[2][0]){
			return false;
		}
	}	
//	game in progress(check every boxes are filled or not)
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j]!='X' && board[i][j]!='O'){
				return true;
			}
		}
	}
//	game draw
draw = true;
return false;
}
main()
{
	while(gamesense())
	{
	displayboard();
	playerturn();	
	}
	
	if(turn=='X' && draw == false){
		cout<<"Player2 [O] wins !! Congratulations !!";
	}
	else if(turn=='O' && draw == false){
		cout<<"Player1 [X] wins !! Congratulations !!";
	}
	else{
		cout<<"!! Game Draw !!";
	}
	return 0;
}

