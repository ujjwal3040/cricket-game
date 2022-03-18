#include"game-1[1].h"
using namespace std;

Game::Game(){
	playersPerTeam=4;
	maxBalls=6;
	totalPlayers=11;
	players[0]="Virat";
	players[1]="Rohit";
	players[2]="Dhawan";
	players[3]="Pant";
	players[4]="Karthik";
	players[5]="KLRahul";
	players[6]="Jadeja";
	players[7]="Hardik";
	players[8]="Bumarh";
	players[9]="BKumar";
	players[10]="Ishant";


isFirstInnings=false;
teamA.name="Team-A";
teamB.name="Team-B";
}
void Game::welcome(){
	cout<<"\t--------------------------------------------------\n";
	cout<<"\t|======================CRIC-IN====================|\n";
	cout<<"\t|                                                 |\n";
	cout<<"\t|\tWelcome to the Virtual Cricket Game\t  |\t\n";
	cout<<"\t -------------------------------------------------\n\n";
	cout<<"\t --------------------------------------------------\n";
	cout<<"\t|===================Instructions===================|\n";
	cout<<"\t --------------------------------------------------\n";
	cout<<"\t| 1. creat 2 teams (Team-A and Team-B with 4       |\n";
	cout<<"\t|    players each) from a given pool of 11 players.|\n";
	cout<<"\t| 2. Lead the toss and decide the choice of play.  |\n";
	cout<<"\t| 3. Each innings will be of 6 balls.              |\n";
	cout<<"\t----------------------------------------------------\n\n";   
	
		  }
		  
	bool Game::validateSelectedPlayer(int index){
		int n;
		vector<Player>players;
		players=teamA.players;
		n=players.size();
		for(int i=0;i<n;i++){
			if(players[i].id==index){
				return false;
			}
		}
		players=teamB.players;
		n=players.size();
		for(int i=0;i<n;i++){
			if(players[i].id==index){
				return false;}}
				return true;
	}	  
	
	void Game::showTeamPlayers(){
	vector<Player>teamAPlayers=teamA.players;	
	vector<Player>teamBPlayers=teamB.players;
	cout<<endl<<endl;
	cout<<"--------------------------\t\t-----------------------------"<<endl;
	cout<<"|===========Team-A========\t\t|===========Team-B=========|"<<endl;
	cout<<"--------------------------\t\t-----------------------------"<<endl;
	for(int i=0;i<playersPerTeam;i++){
		cout<<"|\t"<<"["<<i<<"] "<<teamAPlayers[i].name<<"\t |"<<"\t\t"
		
		<<"|\t"<<"["<<i<<"] "<<teamBPlayers[i].name<<"\t |"<<endl;
	}
		cout<<"--------------------------\t\t-----------------------------"<<endl;
	}
	
	
	void Game::showAllPlayers(){
		cout<<endl;
		cout<<"\t----------------------------------------"<<endl;
		cout<<"\t|=========Pool of Players==============|"<<endl;
		cout<<"\t----------------------------------------"<<endl;
		cout<<endl;
		for(int i=0;i<totalPlayers;i++){
		 cout<<"\t\t["<<i<<"]"<<" "<<players[i]<<endl;}
		}
		
		int Game::takeIntegerInput(){
			int n;
			while(!(cin>>n)){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<
				"invalid input! Please try again with valid input:";
			}
			return n;
		}
		void Game::selectPlayers(){
			cout<<endl;
			cout<<"\t----------------------------------------"<<endl;
			cout<<"\t|========Create Team-A and Team-B=======|"<<endl;
			cout<<"\t----------------------------------------"<<endl;
			for(int i=0;i<playersPerTeam;i++){
				teamASelection:
				cout<<endl<<"\tSelect player "<<i+1<<" of Team A-";
				int playerIndexTeamA=takeIntegerInput();
				
				if(playerIndexTeamA<0||playerIndexTeamA>10){
					cout<<endl<<"\tPlease select from the given players"<<endl;
					goto teamASelection;
				}
				else if( !validateSelectedPlayer(playerIndexTeamA)){
					cout<<endl<<"\tPlayer has been already selected.Plesse select from other player"<<endl;
						goto teamASelection;
				}
				else{
				Player teamAPlayer;
				teamAPlayer.id=playerIndexTeamA;
				teamAPlayer.name=players[playerIndexTeamA];
				teamA.players.push_back(teamAPlayer);	
				}
				
			    teamBSelection:
				cout<<endl<<"\tSelect player "<<i+1<<" of Team B-";
				int playerIndexTeamB=takeIntegerInput();
					if(playerIndexTeamB<0||playerIndexTeamB>10){
					cout<<endl<<"\tPlease select from the given players"<<endl;
					goto teamBSelection;
				}
				else if( !validateSelectedPlayer(playerIndexTeamB)){
					cout<<endl<<"\tPlayer has been already selected.Plesse select from other player"<<endl;
						goto teamBSelection;
				}
				else{
				Player teamBPlayer;
				teamBPlayer.id=playerIndexTeamB;
				teamBPlayer.name=players[playerIndexTeamB];
				teamB.players.push_back(teamBPlayer);
}
			
			
		}}
		void Game::toss()	{
			cout <<endl;
			cout << "******************************************************" << endl;
			cout << "******************Let's Toss**************************" << endl;
			cout << "******************************************************" << endl << endl;
			cout << "Tossing the coin..." << endl << endl;
			
			srand(time(NULL));
			int randomValue = rand() % 2;
			
			switch(randomValue){
				case 0:
					cout << "Team-A WON THE TOSS" << endl << endl;
					tossChoice(teamA);
					break;
					case1:
						cout << "Team-B WON THE TOSS" << endl << endl;
						tossChoice(teamB);
						break;
			}
		}
	void Game::tossChoice(Team tossWinnerTeam){
		
		cout << "Enter 1 to bat or 2 to bowl first. " << endl
		<< "1. Bat" << endl
		<< "2. Bowl" << endl;
		
		int tossInput = takeIntegerInput();
		
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		
		switch (tossInput) {
			case 1:
				cout << endl << tossWinnerTeam.name << "won the toss and elected to bat first" << endl << endl;
				
				if (tossWinnerTeam.name.compare("Team-A") == 0){
					battingTeam = &teamA;
					bowlingTeam = &teamB;
				}else{
					battingTeam = &teamB;
					bowlingTeam = &teamA;
				}
				
				break;
				case 2:
					cout << endl << tossWinnerTeam.name << "won the toss and choose to bowl first" << endl << endl;
					if (tossWinnerTeam.name.compare("Team-A") == 0){
						bowlingTeam = &teamA;
						battingTeam = &teamB;
					}else{
						bowlingTeam = &teamB;
						battingTeam = &teamA;
					}
					
					break;
					default:
						cout << endl << "Invalid input. Please try again:" << endl << endl;
						tossChoice(tossWinnerTeam);
						break;
		}
	}
	
	void Game::startFirstInnings(){
		cout << "\t\t ||| FIRST INNINGS STARTS |||" << endl << endl;
		isFirstInnings = true;
		initializePlayers();
		playInnings();
	}
	
	void Game::initializePlayers(){
		batsman = &battingTeam->players[0];
		bowler = &bowlingTeam->players[0];
		
		cout << battingTeam->name << " - " << batsman->name << " is batting " << endl;
		cout << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;
	}
	
	void Game::playInnings(){
		for (int i = 0; i < maxBalls; i++) {
			cout << "Press Enter to bowl...";
			getchar();
			cout << "Bowling..." << endl;
			bat();
			
			if (!validateInningsScore()){
				break;
			}
		}
	}
	
	void Game::bat(){
		
		srand(time(NULL));
		int runsScored = rand() % 7;
		batsman->runsScored = batsman->runsScored + runsScored;
		battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
		batsman->ballsPlayed = batsman->ballsPlayed + 1;
		
		bowler->ballsbowled = bowler->ballsbowled + 1;
		bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
		bowler->runsGiven = bowler->runsGiven + runsScored;
		
		if (runsScored != 0) {
			cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << "runs!" << endl << endl;
			showGameScorecard();
		}else{
			cout << endl << bowler->name << " to " << batsman->name << "OUT!" << endl << endl;
			
			battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
			bowler->wicketsTaken = bowler->wicketsTaken + 1;
			
			showGameScorecard();
			
			int nextPlayerIndex = battingTeam->wicketsLost;
			batsman = &battingTeam->players[nextPlayerIndex];
		}
		
	}		
	
	bool Game::validateInningsScore(){
		if (isFirstInnings){
			if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls){
				cout << "\t\t ||| FIRSTINNINGS ENDS ||| " << endl << endl;
				
				cout << battingTeam->name << " " << battingTeam->totalRunsScored << " _ "
				<<battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")" << endl;
				
				cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1 << "runs to win the match" << endl << endl;
				
				
				return false;
			}
		}else{
			if(battingTeam->totalRunsScored>bowlingTeam->totalRunsScored){
				cout << "\t\t ||| 	SECOND INNINGS ENDS ||| " << endl << endl;
			//	cout<<"bacause batting team score is greater than bowling team score";
				cout<<"\n"<<battingTeam->name<<"wins the match";
				return false;
			}
			else{
				if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls){
					cout << "\t\t ||| SECOND INNINGS ENDS ||| " << endl << endl;
				//	cout<<"all wickets lost or all balls finish";
					//return false;
					if(battingTeam->totalRunsScored==bowlingTeam->totalRunsScored){
					//	cout<<"\n match is tied ";
					return false;}
					else{
						if(battingTeam->totalRunsScored>bowlingTeam->totalRunsScored){
							cout<<"\n"<<battingTeam->name<<" wins the match";
							
					return false;}
					else{cout<<bowlingTeam->name<<" wins the match";
					return false;
					}
					}
				}
			}
		}
		return true;
	}
	
	void Game::showGameScorecard() {
		
		cout << "----------------------------------------------------------------------" << endl;
		
		cout << "\t" << battingTeam->name << " " << battingTeam->totalRunsScored << " -"
		<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") | " << batsman->name
		<< " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "
		<< bowler->ballsbowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << "\t" << endl;
		
		cout << "----------------------------------------------------------------------" << endl << endl;
	}
	
	void Game::	startSecondInnings(){
		cout << "\t\t ||| SECOND INNINGS STARTS |||" << endl << endl;
		isFirstInnings = false;
		Team *t1=battingTeam;
		battingTeam=bowlingTeam;
		bowlingTeam=t1;
		//swap(battingTeam,bowlingTeam)
		
		initializePlayers();
		playInnings();
	}
	
	void Game::display(){
		cout<<endl<<endl<<"\t\t||| MATCH ENDS |||\n";
			isFirstInnings = false;
		Team *t1=battingTeam;
		battingTeam=bowlingTeam;
		bowlingTeam=t1;
	
		cout <<endl<< "\t" << battingTeam->name << " " << battingTeam->totalRunsScored << " _ "
		<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")\n";
		
		cout<<"\t=========================================================\n";
		cout<<"\t|    PLAYER             BATTING           BOWLING        \n";
		cout<<"\t|--------------------------------------------------------|\n";
		
		for(int i=0;i<4;i++){
			batsman = &battingTeam->players[i];
			bowler = &bowlingTeam->players[i];
			cout<<"\t| ["<<i<<"] "<<batsman->name<<"\t\t"<<batsman->runsScored<<"("<<batsman->ballsPlayed
			<<")"<<"\t\t"<<batsman->ballsPlayed<<"-"<<batsman->runsScored<<"-"<<batsman->wicketsTaken<<" \t\t|\n";
				cout<<"\t|--------------------------------------------------------|\n";
		
			}
			cout <<endl<< "\t" << bowlingTeam->name << " " << bowlingTeam->totalRunsScored << " - "
			<< bowlingTeam->wicketsLost << " (" << battingTeam->totalBallsBowled << ")\n";
			
			cout<<"\t========================================================\n";
			cout<<"\t|   PLAYER               BATTING          BOWLING       |\n";
			cout<<"\t|-------------------------------------------------------|\n";
			
			for(int j=0;j<4;j++){
				batsman = &battingTeam->players[j];
				bowler = &bowlingTeam->players[j];
				
				cout<<"\t| ["<<j<<"] "<<bowler->name<<"\t\t"<<bowler->runsScored<<"("<<bowler->ballsPlayed
				<<")"<<"\t\t"<<bowler->ballsPlayed<<"-"<<bowler->runsScored<<"-"<<bowler->wicketsTaken<<"\t\t|\n";
					cout<<"\t|-------------------------------------------------------|\n";
		
			}
	}
		
		     
