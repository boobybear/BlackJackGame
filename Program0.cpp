#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class project{
   public:
   void extraction(ifstream& first); // file extractor
   void extraction2(ifstream& second);  // file extracter
   void random(); 
   void de();
   void random1();
   void game();
   void game2();
   void compare();
   int *arrayval = nullptr;
   string *arrayNames = nullptr;
   private:
   int player[100];
   int dealer[100]; // arrays for each player
   int playerSum; // holds palyers sum
   int dealerSum; // dealers sum
   int split; 
};

int main() {
   project driver;
   ifstream first("FileName.txt");
   driver.extraction(first);
   ifstream second("values.txt");
   driver.extraction2(second);
   driver.random();              /*Very small driver kept neat I use alot of classes*/
   driver.random1();
   driver.game();
   driver.game2();
   driver.compare();
   driver.de(); // deletes arrays in the end
    return 0;
}


void project::extraction(ifstream &first){
   int i = 0;
   arrayNames = new string[5];
   if(!first.is_open()){
      cout << "File Fail" << endl; // inputs into a dymically array if it fails program will not work so it ends
   }
   while (first >> *(arrayNames + i))
   {
      i++;
   }
   if(first.eof()){
      first.close();
   }
   
}

void project::extraction2(ifstream &second){
   int i = 0;
   arrayval = new int[15];
   if(!second.is_open()){
      cout << "File Fail" << endl;
   }
   while (second >> *(arrayval + i))  // inputs into a dymically array if it fails program will not work so it ends
   {
      i++;
   }
   if(second.eof()){
      second.close();
   }
   
}

void project::random() { //Random number generation for the player
   int i = 0;
    int rollValue1;
    int maxValue = 10;  
    srand(time(0));
    for(i = 0; i < 10; i++){
    for (int counter = 0; counter < 1; counter++) {

        rollValue1 = rand() % maxValue; 
      }
      player[i] = *(arrayval + rollValue1); // this proved to be quite diffcult but in the end i just had to nest a loop in order ot get diffrent outputs
    }
}

void project::random1() { //Random Number Generation for dealer
   int i = 0;
    int rollValue1;
    int maxValue = 10;   
    srand(time(0));
    for(i = 0; i < 10; i++){
    for (int counter = 0; counter < 1; counter++) { // from chapter 3 the random function I have a nested for loop for difrent outputs a single only outputted same values over and over
        rollValue1 = rand() % maxValue; 
      }
      dealer[i] = *(arrayval + rollValue1); // dealer was able to get assinged cards
    }
}

void project::game() { //Players game
   int i = 2;
   playerSum = player[0] + player[1]; // this is from the random funciton
   dealerSum = dealer[9] + dealer[10]; // also from the random funciton 10 options in total 
   string input;
   bool hasSplit = false;  // bool for logical purpoes
   
   cout << "Welcome to this game of black jack" << endl << endl;
   cout << "The opponents facing each other are " << *(arrayNames) << " and " << *(arrayNames + 1) << endl << endl << endl;
   cout << "Player one goes first with a sum of " << playerSum << endl;
   
   while (playerSum < 21 && input != "stand" && input != "Stand") { // logicla loop for black jack
      cout << "Choose your action: ";
      cout << *(arrayNames) << endl;  // menu
      cout << "1. Hit\n"; //menu options
      cout << "2. Stand\n";
      cout << "3. Split\n";
      cin >> input;

      if (input == "Hit" || input == "hit") {
         cout << "Player chose to hit" << endl;
         playerSum += *(player + i);
         cout << endl;
         cout << "New sum is " << playerSum << endl;
         cin.ignore();
         i++;
      }
      else if (input == "stand" || input == "Stand") {
         cout << endl;
         cout << "Player chose to stand, dealer's turn" << endl;
      }
      else if (input == "split" || input == "Split") {
         if (hasSplit) { 
            cout << "You can only split once." << endl; // divites cards by 2 only avaible once
         } else {
            playerSum = playerSum / 2; 
            cout << "After split, your sum is " << static_cast<float>(playerSum) << endl;
            hasSplit = true; 
         }
      }
   }
}


void project::game2(){ // Dealers Game
   string input;
   int i = 10;
   cout << endl << endl << "Dealers time to strike" << endl; 
   cout << "/**********************************************************************************/ " << endl;
   cout << endl << endl << endl;
   while (dealerSum != 22 && input != "stand" && input != "Stand") // loops until its over 18
   {
      if(dealerSum < 18){
         cout << "Dealer chose to hit: " << endl << endl; // simple automated dealer opponent
         dealerSum += *(dealer + i);
         cout << "New sum is " << dealerSum << endl;
         i = i - 1;
      }
      else{
         cout << "Dealer choose to stand " << endl << endl << endl; // when dealer stands it ends the game 
            cout << "/**********************************************************************************/ " << endl;
         input = "stand";
         cout << "The sum in the end is " << " Dealer with " << dealerSum << " compared to player with " << playerSum << endl;
      }
   }
   
}


void project::compare() { //End Comparison to see who wins 
    cout << endl << endl << endl;

    string end = "The winner of this match is";
    if (playerSum > 21 && dealerSum > 21) {
        cout << "Game result is a tie (both busted)" << endl;
    }

    else if (dealerSum > 21) {
        cout << end << " " << *(arrayNames);  // Player wins
    }

    else if (playerSum > 21) {
        cout << end << " " << *(arrayNames + 1);  // Dealer wins
    }

    else if (playerSum > dealerSum) {
        cout << end << " " << *(arrayNames);  // Player wins
    }
    else if (dealerSum > playerSum) {
        cout << end << " " << *(arrayNames + 1);  // Dealer wins
    }

    else {
        cout << "Game result is a tie" << endl;
    }

    cout << endl << endl << endl;
}

void project::de(){ 
   delete [] arrayNames , arrayval;  // dealocates memory
}


/*
void project::print(){ // testing to make sure everything has been extracted
   int i = 0;
   while (i < counter1)
   {
     cout << peep[i] << endl;
     i++;
   }
   i = 0;
   while (i < counter2)
   {
     cout << car[i] << endl;
     i++;
   }
   i = 0;
   while (i < counter3)
   {
     cout << val[i] << endl;
     i++;
   }
   
   
}
*/