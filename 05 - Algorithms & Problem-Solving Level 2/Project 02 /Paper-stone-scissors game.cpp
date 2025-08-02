// #### paper stone scissors game ####

#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;


enum enGameChoice{Stone = 1, Paper = 2, Scissor = 3};
enum enWinner{Player1 = 1 , Computer = 2, Draw = 3};
struct stRoundInfo
{
  short roundNumber = 0;
  enGameChoice player1Choice;
  enGameChoice computerChoice;
  enWinner winner;
  string winnerName = "";
};
struct stGameResult
{
    short gameRounds = 0;
    short player1WinTimes = 0;
    short computerWinTimes = 0;
    short drawTimes = 0;
    enWinner winner;
    string winnerName = "";
};


int randomeNumber (int from , int to)
{
  int randomeNumber = rand() % (to - from + 1) + from;
  return randomeNumber;
}


void setWinnerScreenColor(enWinner winner)
{
  switch (winner)
  {
  case enWinner::Player1:
    system("color 2f");
    break;
  
  case enWinner::Computer:
    system("color 4f");
    cout << "\a";
    break;  

  default:
    system("Color 6f");
    break;
  }
}


enGameChoice readPlayerChoice()
{
    short playerChoice = 0;
    do
    {
      cout << "Choose one:\n [1]- Stone.\n [2]- Paper.\n [3]- Scissor.\n";
      cin >> playerChoice;
    } while (playerChoice < 1 || playerChoice > 3);
    
    return (enGameChoice)playerChoice;
}


enGameChoice getComputerChoice()
{ 
    short computerChoice = randomeNumber(1 , 3);

    return (enGameChoice) computerChoice;

}


enWinner whoWinnTheRound(stRoundInfo roundInfo)
{
  if(roundInfo.player1Choice == roundInfo.computerChoice)
  {
    return enWinner::Draw;
  }
  switch (roundInfo.player1Choice)
  {
  case enGameChoice::Stone:
    {
      if (roundInfo.computerChoice == enGameChoice::Paper)
    {  return enWinner::Computer;
    }
    break;
    }

  case enGameChoice::Paper:
  {
    if (roundInfo.computerChoice == enGameChoice::Scissor)
   { return enWinner::Computer;
   }
   break;}
  
  case enGameChoice::Scissor:
  {
    if (roundInfo.computerChoice == enGameChoice::Stone)
   { return enWinner::Computer;
   }
   break;}

  }

 return enWinner::Player1;

}


string winnerName(enWinner winner)
{
  string arrWinnerName[3] = {"Player1" , "Computer" , "Drawl"};
  return arrWinnerName [winner - 1];
}


string choiceName (enGameChoice choiceName)
{
  string arrChoiceName[3] = {"Stone", "Paper", "Scissor"};
  return arrChoiceName [choiceName-1];
}

void printRoundResults(stRoundInfo roundInfo)
{
  cout << "\n--------------------------- Round Number: [" << roundInfo.roundNumber << "] ---------------------------\n\n";
  cout << "1- Player1 Choice: " << choiceName(roundInfo.player1Choice) << endl;
  cout << "2- Computer Choice: " << choiceName(roundInfo.computerChoice)<< endl;
  cout << "3- Round Winner: [" << roundInfo.winnerName << "]" << endl;
  cout << "----------------------------------------------------------------------------------------------------------\n\n";
setWinnerScreenColor(roundInfo.winner);

}


enWinner whowonTheGame(short player1WinTimes , short computerWonTimes)
{
  if(player1WinTimes > computerWonTimes)
    {
      return enWinner::Player1;
    }
  else if (computerWonTimes > player1WinTimes)
   {
      return enWinner::Computer;
   }
  else
  {
    return enWinner::Draw;
  }
}


stGameResult fillGameResult(int gameRoundNumber , short Player1WinTimes , short computerWinTimes, short drawTimes)
{
  stGameResult gameResults;

  gameResults.gameRounds = gameRoundNumber;
  gameResults.player1WinTimes = Player1WinTimes;
  gameResults.computerWinTimes = computerWinTimes;
  gameResults.drawTimes = drawTimes;
  gameResults.winner = whowonTheGame(Player1WinTimes , computerWinTimes);
  gameResults.winnerName = winnerName(gameResults.winner);

  return gameResults;

}


stGameResult playGame (short howManyRounds)
{
  stRoundInfo roundInfo;

  short player1winTimes = 0 , computerWinTimes = 0 , drawTimes = 0;
  for(short gameRound = 1; gameRound <= howManyRounds ; gameRound++)
 { 
  
  
  cout << "\n Round [" << gameRound << "] Begains \n\n\n";
  roundInfo.roundNumber = gameRound;
  roundInfo.player1Choice = readPlayerChoice();
  roundInfo.computerChoice = getComputerChoice();
  roundInfo.winner = whoWinnTheRound(roundInfo);  
  roundInfo.winnerName = winnerName(roundInfo.winner);

  if (roundInfo.winner == enWinner::Player1)
     player1winTimes++;
  else if (roundInfo.winner == enWinner::Computer)
     computerWinTimes++;
  else
      drawTimes++;

printRoundResults(roundInfo);



}
return fillGameResult(howManyRounds , player1winTimes , computerWinTimes ,drawTimes);

}


string Tabs(short howManyTabs)
{
  string t = "";

  for(short i = 1 ; i < howManyTabs; i++)
  {
    t = t + "\t";
    cout << t;
  }

  return t;
}


void showGameOverScreen()
{
  cout<<Tabs(2) <<"-------------------------------------------------------------------------------------------\n";
  cout<<Tabs(2) <<"                                ++++ Game Over ++++                                        \n";
  cout<<Tabs(2) <<"-------------------------------------------------------------------------------------------\n";
}


short readHowManyRounds()
{
  short howManyRounds = 1;

  do 
  {
    cout << "How many rounds do you want to play?\n Enter a number between 1 and 10: ";
    cin >> howManyRounds;
  }
  while(howManyRounds < 1 || howManyRounds > 10);
  return howManyRounds;
}


void showFinalGameResults(stGameResult gameresults)
{
  cout <<Tabs(2) <<"------------------------------------[ Game Result ]------------------------------------\n\n";
  cout <<Tabs(2) << "Game rounds: "<< gameresults.gameRounds<< ".\n";
  cout <<Tabs(2) << "Player1 win times: "<< gameresults.player1WinTimes<< ".\n";
  cout <<Tabs(2) << "Computer win times: "<< gameresults.computerWinTimes<< ".\n";
  cout <<Tabs(2) << "Draw times: "<< gameresults.drawTimes<< ".\n";
  cout <<Tabs(2) << "Final winner: "<< gameresults.winnerName<< ".\n";
  cout <<Tabs(2) <<"---------------------------------------------------------------------------------------\n\n";
  setWinnerScreenColor(gameresults.winner);
}


void resetScreen()
{
  system ("cls");
  system("color 0f");
}


void startGame()
{
  char playAgain = 'y';
do
  {
    resetScreen();
    stGameResult gameResult = playGame(readHowManyRounds());
    showGameOverScreen();
    showFinalGameResults(gameResult);


    cout << endl << Tabs(3) << "Do you want to play again? Enter Y/N";
    cin >> playAgain;
}
while (playAgain == 'y' || playAgain == 'Y');
}
int main()
{
  
  srand((unsigned) time (NULL));

  startGame();

  return 0;
}













