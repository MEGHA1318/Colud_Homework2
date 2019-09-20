#include "Node.h"

int main() {
	std::cout << "This program is executing the homework 2.1.\n";
	std::cout << "Enter the number of node you like to execute in the Maekawa’s algorithm: ";

	int n = 0; //number of nodes
	std::cin >> n; // Scan the number

	Node *nodes[10];//declared with  pointer array

	//Init nodes and add them to the node array called nodes

	for (int i = 0; i < n; i++) {
		Node *P = new Node(i, 'R', 'F');
		nodes[i] = P;
	}


	std::cout << "\n";


	int o = floor(sqrt(n)); 
	std::cout << "The O value is " << o << "\n";

	int m = o;
	std::cout << "The M value is " << o << " \n";


	std::cout << "\n";


	std::vector<std::vector<int>> VotingSets;
	std::vector<int> set;

	int voteIndex = 0;

	for (int i = 0; i < n; i++) {//assigning voting sets
		
		if (i%m == 0 && i != 0)
		{ 
			++voteIndex; VotingSets.push_back(set); set.clear(); 
		}
		nodes[i]->setVotingSet(voteIndex);

		set.push_back(i);
	}
	
	VotingSets.push_back(set);

	std::cout << " Voting Sets are \n";
	for (int i = 0; i < o; i++) 
	{

		for (int j = 0; j < m; j++) 
		{
			std::cout << "  ID: " << VotingSets[i][j] << " ";
			if (VotingSets[i][j] < 10) { std::cout << " "; }
		}
		std::cout << " \n";
	}

	


	int process, time = 1;

	do {
		std::cout << "\ nWhich process do you want to try to gain the access to the CS: ";
		std::cin >> process;
		if (process < 0 || process > n) { process = 0; std::cout << "     ***Process Done, process 0 chosen instead***\n"; }

		std::cout << "\n How many milliseconds do you want to process to be in the CS (enter number 0 to stop): ";
		std::cin >> time;

		if (time != 0) {
			std::cout << "\n";
			nodes[process]->setState('W');
			std::cout << "Node " << process << " state set to Wanted. Requests to enter CS sent to Voting Set | ";
			nodes[process]->Request(*nodes, n);

			nodes[process]->setState('H');
			std::cout << "\n     Process " << process << " entering CS, state changed to Held.\n";
			nodes[process]->Progress(time);
		}
	} while (time != 0);
}