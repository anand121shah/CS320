#include <iostream>
#include "player.h"
#include "pickups.h"

using namespace std;

void getPlayer(){

}

void getInitial(){

}

void runChildhood(){

}

bool runGame(){

}

int main(){
	while(true){
		getPlayer();
		getInitial();
		runChildhood();
		if(runGame())
			cout << "Congratulations! You have passed the tests! You are now appointed as the owner of the organization." << endl;
		else
			cout << "You failed to become a successful. You are now an average ACU Graduate!" << endl;

		cout << "Do you want to restart the game? (y/n)" << endl;
		char i;
		cin >> i;
		if(i == 'n')
			break;
	}
}