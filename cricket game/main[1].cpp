#include"game-1[1].h"
using namespace std;
int main() {
	
	Game game;
	game.welcome();
	cout<<"\tPress Enter Key To Continue";
	getchar(); 
	game.showAllPlayers();
	cout<<"\tPress Enter Key To Continue";
	getchar(); 
	game.selectPlayers();
	game.showTeamPlayers();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout <<"\nPress Enter to toss";
	getchar();
	game.toss();
	game.startFirstInnings();
	game.startSecondInnings();
	game.display();
	return 0;
}


