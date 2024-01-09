#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

#define MAX_PLAYERS 10

using namespace std;

/*
	Class representing an N-sided die
*/
class Dice {
private: 
	int numSides;
public:
	// Perform a single roll of the die	
	int getSides(){return numSides;}
	int roll(){return rand() % numSides + 1;}
	Dice() : numSides(6) {}; // default constructor, create a dice of standard size
	Dice(int size) : numSides(size) {}; // create a dice of given size
};

/*
	Class representing a Game Player
*/
class Player {
private:
	string name;
	int score;
public:
	// Getter : Player Name
	string getName() {return name;}
  void SetName(string NewName){
        name = NewName;   // initalises name
    }
	// Getter : Score
	int getScore() {return score;}
	// Increases the player's score by a specified value
	void addToScore(int val) {
	}
};

/*
	Abstract class DiceGame
*/
class DiceGame {
protected:
	Player* players[MAX_PLAYERS];
	Dice* dice;
	int numPlayers, numDice;

public:
	//	Pure virtual function	
	virtual void play() = 0;
  void initPlayers(){
    vector<string> Player;
    vector<int> score;
  }
// Highest Score function
  void getHighestScore(){
    string line;
    int score;
    string number,name,highName;
    int max = 0;
    ifstream myfile ("Score.txt");
    
    if (myfile.is_open()) { // when the file is open, it will calculate and print which player has the high score
      while (getline (myfile, line)){
        stringstream ss(line);
        ss >> score;
        
        if(score > max){  // when score is greater than max, max becomes the current score and the highName becomes the current name
                    max = score;
                    highName = name;
                }
            }
            myfile.close();
        } else {
            cout << "Unable to open file";
        }
        cout << "High Score: " << highName << " : " << max << endl;
    }
};

int main(){
  srand(time(NULL));
  ofstream outf{ "Sum.txt" };
	char YN;
  std::cout << "Would you like to play a Game? (y/n): ";
	std::cin >> YN; std::cout << std::endl;
  if((YN == 'y') || (YN == 'Y')){
    do{
      char AB;
      int dSides = 0, DN = 0, PN = 0, i = 0, KOC = 0, C1 =0, add = 0, C2 = 0, KO = 0, HI = 0, HIN = 0;
      string pName;
		  vector<int> TDN; vector<string> TPN; vector<int> TPS; // TDN is a vector of each dice sides, TPN is to store all player names, TPS is to store the final player score
      cout << "How many dice do you want to have?: "; cin >> DN;
      cout << "How many sides would you like all the dice to have?: "; cin >> dSides;
      for (i = 1; i < DN+1; i++) { // runs a loop to roll all dice
        TDN.push_back(dSides); Dice die(dSides); add = die.roll(); KOC = KOC + add;
      }
      cout << "How many Players do you want to have?: "; cin >> PN;
      for (i = 1; i < PN+1; i++) { // get all players names
        cout << "What will Player " << i <<"'s name be?: "; cin >> pName; TPN.push_back(pName); C2 = C2+1;
      }
      cout << "A) Knockout or B) Boston Dice? (A/B): "; cin >> AB; cout << std::endl;
      if ( (AB == 'A') || (AB == 'a') ){ // runs either boston dice or knockout
        cout << "The game you have chosen to play is Knockout" << endl; 
        cout << "The Knockout Condition of "<<DN<<" dice is " << KOC << endl;
        for(auto& it : TPN){
          if (!outf){ // runs if the file can't be opened
            cout << "Uh oh, Score.txt could not be opened for writing!\n";
            return 1;
          }
          int sum = 0, C1 = 0, add = 0, dSides = 0, KO = 0, rt = 0;
          cout << it << " rolls";
          do{
            C1 = C1+1;
            for(auto& rt : TDN) { // calculated the sides of the die
              dSides = rt; Dice die(dSides); add = die.roll(); sum = sum + add; // Calls dSides, add, and sum
            }
            cout << ' ' << sum; outf << sum << ' ';
            if (sum == KOC){ // runs if the sum equals KOC
              cout << ". " << it << " has rolled the knockout score after " << C1 << " rolls" << endl; 
              TPS.push_back(C1); KO = 1;
            } else {
            sum = 0; add = 0; dSides = 0; KO = 0;
            }
          }while(KO == 0); // makes a new line while KO equals zero
          outf << endl;
        }
        C1 = 0;
        for (i = 0; i < TPS.size(); i++) { // find the highest knockout score from all players
          if (TPS[i] > HI) {
              HI = TPS[i]; HIN = C1;
          }
          C1 = C1 + 1;
        }
        cout << "The Winner is " << TPN[HIN] << " with a final Knockout score of " << HI << endl;
      } else if ( (AB == 'B') || (AB == 'b') ){ // runs if the user decides to play Boston Dice
        cout << "The game you have chosen to play is Boston Dice" << endl;  
        for(auto& it : TPN){ // loop to go through all players and assign a score
          vector<int> DBDN = TDN; vector<int> DNT;int DN2 = DN;
          int sum = 0, C1 = 0, add = 0, dSides = 0, i = 0, d = 0, m=0;
          for (i =0; i < DN2; i++) {
            for (d = 0; d < DN; d++) {
              dSides = DBDN[d]; Dice die(dSides); add = die.roll(); DNT.push_back(add); 
            }
            HI = 0; HIN = 0;
            for (m = 0; m < DNT.size(); m++) { // highest dice roll
              if (DNT[m] > HI) {
                HI = DNT[m]; HIN = C1;
              }
              C1 = C1 + 1;
            } 
            sum = sum + HI; outf << HI << " "; DNT.clear();
          }
          DN2 = DN2-1;
          TPS.push_back(sum);
        }
        C1 = 0; HIN = 0; HI = 0; i = 0;
        for (i = 0; i < TPS.size(); i++) { // find the highest score of all players
          if (TPS[i] > HI) {
            HI = TPS[i]; HIN = C1;
          }
          C1 = C1 + 1;
        }
        cout << "The Winner is " << TPN[HIN] << " with a final Boston Dice score of " << HI << endl;
      } else {
        cout << "Not a valid input" << endl;
      }
		  cout << endl << "Would you like to play again? (y/n): ";
		  cin >> YN; cout << endl;
      ofstream ofs;
      ofs.open("Score.txt", ofstream::out | ofstream::trunc); // opens  and clears the score.txt file after the games are played
      ofs.close();
	  } while ((YN == 'y') || (YN == 'Y'));
    cout << "Have a good day";
  }else{
    cout << "Have a good day";
  }
  return(0);
}