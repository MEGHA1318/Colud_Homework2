#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <cmath>

void minmin();
void maxmin();
void Sufferage();

void process(int task, int machine, int time);
int SearchMin(int task[7]);
int searchSecondMin(int task[7]);
int searchMachine(int task, int machine);


int task0[7]{ 13,79,23,71,60,27,2 };
int task1[7]{ 31,13,14,94,60,61,57 };
int task2[7]{ 17,1,100,23,36,8,86 };
int task3[7]{ 19,28,10,4,58,73,40 };
int task4[7]{ 94,75,100,58,100,68,46 };
int task5[7]{ 8,24,3,32,4,94,89 };
int task6[7]{ 10,57,13,1,92,75,29 };
int task7[7]{ 80,17,38,40,66,25,88 };

int main() {
	std::cout << "Homework 2.2  min-min, max-min, Sufferage.\n\n";

	std::cout << "                         Executing Algorithm Min-Min                      \n";
	minmin();
	std::cout << "===========================================================================\n\n";

	std::cout << "\n                          Executing Algorithm Max-Min                       \n";
	maxmin();
	std::cout << "===========================================================================\n\n";

	std::cout << "\n                          Executing Algorithm Sufferage                    \n";
	Sufferage();
	std::cout << "===========================================================================\n\n";
}

void process(int task, int machine, int time) {
	std::cout << "Task  " << task << " is executed on machine  " << machine << "  Which had a durration of | ";

	if (time < 10) { std::cout << " "; }

	std::cout << time << "  milliseconds.\n";
}

void minmin() {
	std::vector<int> MinTimes;

	MinTimes.push_back(SearchMin(task0));
	MinTimes.push_back(SearchMin(task1));
	MinTimes.push_back(SearchMin(task2));
	MinTimes.push_back(SearchMin(task3));
	MinTimes.push_back(SearchMin(task4));
	MinTimes.push_back(SearchMin(task5));
	MinTimes.push_back(SearchMin(task6));
	MinTimes.push_back(SearchMin(task7));


	for (int j = 0; j < 8; ++j) {
		int i, min = 100, minTime = 100;
		
		for (i = 0; i < MinTimes.size(); ++i) {
			
			if (MinTimes[i] < minTime) {
				min = i;
				minTime = MinTimes[i];
				
			}
		}

		process(min, searchMachine(min, MinTimes[min]), minTime);
		MinTimes[min] = 100;
		
	}
}

void maxmin() {
	
	std::vector<int> MinTimes;

	MinTimes.push_back(SearchMin(task0));
	MinTimes.push_back(SearchMin(task1));
	MinTimes.push_back(SearchMin(task2));
	MinTimes.push_back(SearchMin(task3));
	MinTimes.push_back(SearchMin(task4));
	MinTimes.push_back(SearchMin(task5));
	MinTimes.push_back(SearchMin(task6));
	MinTimes.push_back(SearchMin(task7));

	

	for (int j = 0; j < 8; ++j) {
		int i, max = 0, maxTime = 0;
		
		for (i = 0; i < MinTimes.size(); ++i) {
			
			if (MinTimes[i] > maxTime) {
				max = i;
				maxTime = MinTimes[i];
				
			}
		}
		process(max, searchMachine(max, MinTimes[max]), maxTime);
		MinTimes[max] = 0;
		
	}
}

void Sufferage() 
{
	std::vector<int> MinTimes, SecondMinTimes;

	MinTimes.push_back(SearchMin(task0));
	MinTimes.push_back(SearchMin(task1));
	MinTimes.push_back(SearchMin(task2));
	MinTimes.push_back(SearchMin(task3));
	MinTimes.push_back(SearchMin(task4));
	MinTimes.push_back(SearchMin(task5));
	MinTimes.push_back(SearchMin(task6));
	MinTimes.push_back(SearchMin(task7));

	SecondMinTimes.push_back(searchSecondMin(task0));
	SecondMinTimes.push_back(searchSecondMin(task1));
	SecondMinTimes.push_back(searchSecondMin(task2));
	SecondMinTimes.push_back(searchSecondMin(task3));
	SecondMinTimes.push_back(searchSecondMin(task4));
	SecondMinTimes.push_back(searchSecondMin(task5));
	SecondMinTimes.push_back(searchSecondMin(task6));
	SecondMinTimes.push_back(searchSecondMin(task7));



	for (int j = 0; j < 8; ++j) {
		int i, max = 0, Time = 0;
		for (i = 0; i < MinTimes.size(); ++i)
		{
			if (SecondMinTimes[i] - MinTimes[i] > Time && SecondMinTimes[i] != 100 && MinTimes[i] != 100) {
				max = i;
				Time = SecondMinTimes[i] - MinTimes[i];
				
			}
		}

		process(max, searchMachine(max, MinTimes[max]), MinTimes[max]);
		MinTimes[max] = 100;
	}
}

int SearchMin(int task[7]) {
	int min = task[0];

	for (int i = 0; i < 7; ++i) {
		if (task[i] < min) { min = task[i]; }
	}

	return min;
}

int searchMachine(int task, int time) {
	int machine=10;

	for (int i = 0; i < 7; ++i) {
		if (task0[i] == time)
		{
			machine = i;
			
		}
		else if (task1[i] == time)
		{
			machine = i;
		}
		else if (task2[i] == time)
		{
			machine = i;
		}
		else if (task3[i] == time)
		{
			machine = i;
		}
		else if (task4[i] == time)
		{
			machine = i;
		}
		else if (task5[i] == time)
		{
			machine = i;
		}
		else if (task6[i] == time)
		{
			machine = i;
		}
		else if (task7[i] == time)
		{
			machine = i;
		}

	}
	return machine;
}
		

int searchSecondMin(int task[7]) {
	int min = 100;
	int secondMin = 100;

	for (int i = 0; i < 7; ++i) {
		if (task[i] < min) {
			min = task[i];
			
			if (i == 0) { secondMin = min; }
		}
		if (task[i] < secondMin && task[i] != min) {
			secondMin = task[i];
			
		}
	}
	

	return secondMin;
}