// #### paper stone scissors game ####
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <windows.h>
using namespace std;


enum enGameChoice{Stone = 1 , Paper = 2, Scissors = 3};
enum enWinner {Player1 = 1, Computer = 2, NoWinner = 3};
struct stRoundInfo
{
  short RoundNumber = 0;
  enGameChoice Player1Choice;
  enGameChoice ComputerChoice;
  enWinner RoundWinner;
  string WinnerName = "";
};


struct stGameResults
{
  short GameRounds = 0;
  short Player1WinTimes = 0;
  short ComputerWinTimes = 0;
  short DrawTimes = 0;
  enWinner Winner;
  string WinnerName = "";
};


int randomeNumber (int from , int to)
{
  int randomeNumber = rand() % (to - from + 1) + from;
  return randomeNumber;
}


void SetWinnerScreenColor (enWinner Winner)
{
  switch (Winner)
  {
  case enWinner::Player1:
      system ("color 2f");
    break;
  case enWinner::Computer:
     { system("color 4f");
      Beep(750,300);
      break;
     }
  default:
      system("color 6f");
    break;
  }
}


enGameChoice ReadPlayer1Choice()
{
  
  short Player1Choice = 0;
  do
 { cout << "Choose one frome the list: \n [1]- Stone.\n [2]- Paper.\n [3]- Scissors.\n";
  cin >> Player1Choice;
}
while (Player1Choice < 0 || Player1Choice > 3);

return (enGameChoice)Player1Choice;
}


enGameChoice GetComputerChoice()
{
  return (enGameChoice)randomeNumber(1,3);
}


enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
  if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
      return enWinner::NoWinner;

  switch (RoundInfo.Player1Choice)
  {
  case enGameChoice::Stone:
      if(RoundInfo.ComputerChoice == enGameChoice::Paper)
          return enWinner::Computer;
          break;
  
   case enGameChoice::Scissors:
      if(RoundInfo.ComputerChoice == enGameChoice::Stone)
          return enWinner::Computer;
           break;

   case enGameChoice::Paper:
      if(RoundInfo.ComputerChoice == enGameChoice::Scissors)
        return enWinner::Computer;
           break;
  }

  return enWinner::Player1;
}


string WinnerName(enWinner Winner)
{
  string arrWinnerName[3] = {"Player1","Computer","No Winner"};
  return arrWinnerName[Winner-1];
}


string ChoiceName(enGameChoice ChoiceName)
{
  string arrChoiceName[3] = {"Stone","Paper","Scissors"};
  return arrChoiceName[ChoiceName-1];
}


void PrintRoundResults(stRoundInfo roundInfo)
{
  cout << "\n--------------------------- Round Number: [" << roundInfo.RoundNumber << "] ---------------------------\n\n";
  cout << "1- Player1 Choice: " << ChoiceName(roundInfo.Player1Choice) << endl;
  cout << "2- Computer Choice: " << ChoiceName(roundInfo.ComputerChoice)<< endl;
  cout << "3- Round Winner: [" << roundInfo.WinnerName << "]" << endl;
  cout << "----------------------------------------------------------------------------------------------------------\n\n";
SetWinnerScreenColor(roundInfo.RoundWinner);

}

void resetScreen()
{
  system("cls");
  system("color 0f");

}


string Tabs(short howManyTabs)
{
  string t = "";
  for(int i = 1 ; i <= howManyTabs ; i++)
  {
    t += "\t";
    cout << t;
  }
  return t;
}


short readHowManyRounds()
{
  short HowManyRounds = 1;
  do
 { cout << "How Many Rounds Do You Want To Play? \nEnter A Number Between 1 and 10: ";
  cin >> HowManyRounds;
}
while(HowManyRounds < 1 || HowManyRounds > 10);

  return HowManyRounds;
}


void ShowGameOverScreen()
{
  cout<<Tabs(1)<<"===============================================================================================================\n";
  cout<<Tabs(1)<<"==============================================   +[Game Over]+   ==============================================\n";
  cout<<Tabs(1)<<"===============================================================================================================\n";

}


enWinner WhoWonTheGame(short Player1WinTimes , short ComputerWinTimes)
{
  if (Player1WinTimes > ComputerWinTimes)
  {
    return enWinner::Player1;
  }
  else if (ComputerWinTimes > Player1WinTimes)
  {
    return enWinner::Computer;
  }
  else 
  return enWinner::NoWinner;
}


stGameResults FillGameResults(short GameRounds , short Player1WinTimes , short ComputerWinTimes , short DrawTimes)
{
   stGameResults GameResults;
   
   GameResults.GameRounds = GameRounds;
   GameResults.Player1WinTimes = Player1WinTimes;
   GameResults.ComputerWinTimes = ComputerWinTimes;
   GameResults.DrawTimes = DrawTimes;
   GameResults.Winner = WhoWonTheGame(Player1WinTimes,ComputerWinTimes);
   GameResults.WinnerName = WinnerName(GameResults.Winner);

   return GameResults;
}


stGameResults PlayGame(short HowManyRounds)
{
  stRoundInfo RoundInfo;
  short Player1WinTimes =0, ComputerWinTimes=0 , DrawTimes=0;
  for(short GameRound = 1 ; GameRound <= HowManyRounds ; GameRound++)
  {
    cout << "----------------------------  [ Round " << GameRound << "] Begains  ----------------------------\n\n";
    RoundInfo.RoundNumber = GameRound;
    RoundInfo.Player1Choice = ReadPlayer1Choice();
    RoundInfo.ComputerChoice = GetComputerChoice();
    RoundInfo.RoundWinner = WhoWonTheRound(RoundInfo);
    RoundInfo.WinnerName = WinnerName (RoundInfo.RoundWinner);

    if(RoundInfo.RoundWinner == enWinner::Computer)
        ComputerWinTimes++;
    else if (RoundInfo.RoundWinner == enWinner::Player1)
        Player1WinTimes++;
    else
        DrawTimes++;

    PrintRoundResults(RoundInfo);
  }


 return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}


void ShowFinalGameResult(stGameResults GameResult)
{
  cout<< Tabs(1) <<"----------------------------------------------------[Final Game Results]-------------------------------------------------\n";
  cout<< Tabs(3) <<"Game Rounds: "<<GameResult.GameRounds<<".\n";
  cout<< Tabs(3) <<"Player1 Win Times: "<< GameResult.Player1WinTimes<<".\n";
  cout<< Tabs(3) <<"Computer Win Times: "<< GameResult.ComputerWinTimes<< ".\n";
  cout<< Tabs(3) <<"Draw Times: "<< GameResult.DrawTimes <<".\n";
  cout<< Tabs(3) <<"Final Winner Name: "<< GameResult.WinnerName<<".\n";
  cout<< Tabs(1) <<"-------------------------------------------------------------------------------------------------------------------------\n";
  

  SetWinnerScreenColor(GameResult.Winner);
}


void StartGame()
{
  char PlayAgain = 'y';

  do
  {
    resetScreen();
    stGameResults gameResults = PlayGame(readHowManyRounds());
    ShowGameOverScreen();
    ShowFinalGameResult(gameResults);


    cout << Tabs(1) << "Do You Want To Play Again? Answer Y/N ";
    cin >> PlayAgain;
  } while(PlayAgain == 'Y' || PlayAgain == 'y');
  

 
  
}
int main()
{
  srand((unsigned) time (NULL));
  
 StartGame();

  return 0;
}
