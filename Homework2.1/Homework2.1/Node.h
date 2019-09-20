#include <iostream>
#include <string>
#include <time.h>
#include <vector>
#include <thread>
#include <math.h> 

#ifndef NODE_H
#define NODE_H

class Node{

public:
    Node();
    Node(int ID, char Voted, char State){ID = ID; voted = Voted; state = State;}

    void Progress(int Time);

    void Request(Node *nodes, int n);

    void GrantAccess(int requestersID);
    
	void ReleaseAccess();

    void getID(){std::cout << ID;}// to get the ID

    void setState(char newState){state = newState;}
    
	char getState(){return state;}

    char getVoted(){return voted;}

    void setVotingSet(int set){votingSet = set;}
   
	int getVotingSet(){return votingSet;}

private:
    int ID;

    char voted;
	char state;


    int votingSet;
    std::vector<int> queue;//FIFO Queue for holding request
};

void Node::Progress(int Time){

	time_t task_time;
	time(&task_time);
    
    printf("Task Time is = -%s", ctime(&task_time)); 

    std::cout << "   Node " << ID << " All the Received response in the  Progressing task in CS bound to take is " << Time << " millisecond.\n";
   

    task_time = time(NULL);

    printf("Task Time is = -%s", ctime(&task_time));

    std::cout << "\nNode " << ID << " are from queues of voting set nodesamd continuing this on next queued request.";
}

void Node::Request(Node *nodes, int n){
   
	int o = floor(sqrt(n));
    int m = o;
  
    int matrixIndex = 0;

    for(int i = 0; i < o; i++){
      
		for(int j = 0; j < m; ++j){
        
			if(i == votingSet && matrixIndex != ID){
               
				nodes[matrixIndex].GrantAccess(ID);
                
				std::cout << matrixIndex << " | ";
                
				nodes[matrixIndex].ReleaseAccess();
            }
            ++matrixIndex;
        }
    }

    int column;
    column = ID % (m);

    for(int i = 0; i < n; i++){
        if(i%m == column && i != ID){
            nodes[i].GrantAccess(ID);
            std::cout << i << " | ";
            nodes[matrixIndex].ReleaseAccess();
        }
    }
    std::cout << "\n";
}

void Node::GrantAccess(int RequestersID){
   

    voted = 'T';
}

void Node::ReleaseAccess(){
    
	voted = 'F';
}

#endif#pragma once
