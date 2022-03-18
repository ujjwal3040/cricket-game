#include<vector>
#include"player-1[1].h"
class Team{
	public:
		Team();
		std::string name;
		int totalRunsScored;
		int wicketsLost;
		int totalBallsBowled;
		std::vector<Player>players;
};
