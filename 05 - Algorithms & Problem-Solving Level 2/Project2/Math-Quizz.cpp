#include <iostream>
#include <vector>
#include <ctime>  
#include "MyMathLib.hpp"
using namespace std;


enum enQuestionLevel {Easy = 1 , Med = 2 , Hard = 3 , Mix = 4};
enum enOperationType {Add = 1 , Sub = 2, Mul = 3 , Div = 4 , Pow = 5 , Mixed = 6};

struct stQuestion 
{
    short QuestionNumber = 0 ;
    int Number1 = 0;
    int Number2 = 0;
    int PlayerAnswer = 0;
    int TheRightAnswer = 0 ;
    enOperationType OpType;
    enQuestionLevel QuestionLevel;
    bool AnswerResult = false;

};
struct stQuizz
{

    vector <stQuestion> QuestionList;
    enOperationType OpType;
    enQuestionLevel QuizzLevel;
    short NumberOfQuestions = 0;
    short NumberOfRightAnswers = 0;
    short NumberOfWrongAnswers = 0;
    bool IsPass = false;

};



void WelcomeingScreen()
{
  cout << "\n------------------------------------------------------------------------------------------\n\n" << endl;
  cout << "++++++++++++++++++++++++++++  WELCOME TO THE MATH QUIZZ  ++++++++++++++++++++++++++++" << endl << endl;
  cout << "\n------------------------------------------------------------------------------------------\n\n";

}


void ShowGameOverScreen()
{
  cout<<"\t"<<"===============================================================================================================\n";
  cout<<"\t"<<"==============================================   +[Game Over]+   ==============================================\n";
  cout<<"\t"<<"===============================================================================================================\n";

}
short ReadNumberOfQuestions()
{
    short NumberOfQuestions = 0;

    do 
    {
        cout << "- How Many Questions Do you Want? \n- Enter a number between 1 and 10: ";
        cin >> NumberOfQuestions ;
    }
    while (NumberOfQuestions < 1 || NumberOfQuestions > 10); return NumberOfQuestions;
}


enQuestionLevel ReadQuestionLevel()
{
    short QuestionLevel = 0;
    do
    {    cout << "Choose The Questions Level: \n[1]-Easy.\n[2]-Med.\n[3]-Hard.\n[4]-Mixed Levels. "<< endl << "Enter your choise: ";
         cin >> QuestionLevel;
    }
    while (QuestionLevel < 1 || QuestionLevel > 4);

    return (enQuestionLevel) QuestionLevel;
}


enOperationType ReadOperationType()
{
    short Optype = 0;
    do
    {
        cout << "Choose The Operation Type:\n [1]-Addition.\n[2]-Subtraction.\n[3]-Multiplacation.\n[4]-Divition.\n[5]-Power.\n[6]-Mixed Operation." << endl << "Enter your choise: ";   
        cin >> Optype;
    } while (Optype < 1 || Optype > 6);
    return enOperationType (Optype);
    
}


short RandomeNumber (short from , short to)
{
  short randomeNumber = rand() % (to - from + 1) + from;
  return randomeNumber;
}


int SimpleCalculator(int Number1 , int Number2 , enOperationType OperationType)
{
    switch (OperationType)
    {
    case enOperationType::Add :
      return Number1 + Number2;
    case enOperationType::Sub :
      return Number1 - Number2;
    case enOperationType::Mul :
      return Number1 * Number2;
    case enOperationType::Div :
      return Number1 / Number2;
    case enOperationType::Pow :
      return MyMathLibrary::MyPower(Number1,Number2);
    default:
      return Number1 + Number2;
}
}


int ReadQuestionAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}


void ResetScreen()
{
    system("cls");
    system("color 0f");

}


char GetOperationSymbol(enOperationType OperationSymbol)
{
  switch(OperationSymbol)
  {
    case enOperationType::Add:
      return '+';
    case enOperationType::Sub:
      return '-';
    case enOperationType::Mul:
      return 'x';
    case enOperationType::Div:
      return '*' ;
    case enOperationType::Pow:
      return '^' ;
    default:
      return '+';
  }
}


void SetScreenColor(bool IsPass)
{
  if(IsPass)
    system("color 2f");
  else
  { 
    system("color 4f");
      cout << "\a";
  }
}


string GetQuestionLevelText(enQuestionLevel QuestionLevel)
{
  switch (QuestionLevel)
  {
  case enQuestionLevel::Easy:
    return "Easy Level";
  case enQuestionLevel::Med:
    return "Medium Level";
  case enQuestionLevel::Hard:
    return "Hard Level";
  case enQuestionLevel::Mix:
    return "Mixed Level";
  default:
    return "";
}
}


string GetFinalResultText(bool IsPass)
{
  if(IsPass) return "PASS :-)";
  else return "FAIL :-(";
    
}


stQuestion GeneratAQuestion(enQuestionLevel QuestionLevel , enOperationType OperationType)
{
  stQuestion Question;
  if(OperationType == enOperationType ::Mixed)
       OperationType = enOperationType (RandomeNumber(1 , 6)); 
  if(QuestionLevel == enQuestionLevel::Mix)
    QuestionLevel = enQuestionLevel (RandomeNumber(1,3));

  Question.OpType = OperationType;

  switch (QuestionLevel)
  {
    case enQuestionLevel::Easy:
        {
          Question.Number1 = RandomeNumber(1,50);
          Question.Number2 = RandomeNumber(1,50);

          Question.TheRightAnswer = SimpleCalculator(Question.Number1,Question.Number2,OperationType);
          Question.QuestionLevel = QuestionLevel;
         
          return Question;

        }

    case enQuestionLevel::Med:
        {
          Question.Number1 = RandomeNumber(50,100);
          Question.Number2 = RandomeNumber(50,100);

          Question.TheRightAnswer = SimpleCalculator(Question.Number1,Question.Number2,OperationType);
          Question.QuestionLevel = QuestionLevel;
         
          return Question;
        }

   case enQuestionLevel::Hard:
        {
          Question.Number1 = RandomeNumber(100,1000);
          Question.Number2 = RandomeNumber(100,1000);

          Question.TheRightAnswer = SimpleCalculator(Question.Number1,Question.Number2,OperationType);
          Question.QuestionLevel = QuestionLevel;
         
          return Question;
        }
  }
          return Question;


}


void GenerateQuestions(stQuizz &Quizz)
{
  for (short QuestionNumber = 0 ; QuestionNumber < Quizz.NumberOfQuestions ; QuestionNumber++)
       Quizz.QuestionList.push_back(GeneratAQuestion(Quizz.QuizzLevel,Quizz.OpType));
}


void CorrectTheQuestionsAnswers( stQuizz &Quizz , short QuestionNumber)
{
  if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].TheRightAnswer)
  {
    system("color 4f");
    cout << "Wrong Answer :-(\n";

    cout << "The Right Answer is: " << Quizz.QuestionList[QuestionNumber].TheRightAnswer;
    Quizz.QuestionList[QuestionNumber].AnswerResult = false;
    Quizz.NumberOfWrongAnswers ++ ;

  }

  else
  {
    system("color 2f");
    Quizz.QuestionList[QuestionNumber].AnswerResult = true;
    cout << "Right Answer :-)\n";
    Quizz.NumberOfRightAnswers ++;

  }
  cout << endl;
}


void PrintTheQuestion(stQuizz &Quizz , short QuestionNumber)
{
  cout << "------------------------------------------------------------------------------------------------------------------------------------\n";
  cout <<endl<<endl<<"Question Number [ " << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << " ]\n\n";
  if(Quizz.OpType == enOperationType::Pow)
      cout << Quizz.QuestionList[QuestionNumber].Number1 << " " << GetOperationSymbol(Quizz.QuestionList[QuestionNumber].OpType) << " " << Quizz.QuestionList[QuestionNumber].Number2 << " = ";
  else
 { cout << "  " << Quizz.QuestionList[QuestionNumber].Number1 << endl;
  cout <<GetOperationSymbol(Quizz.QuestionList[QuestionNumber].OpType) << endl;
  cout << "  "<< Quizz.QuestionList[QuestionNumber].Number2 << endl; 
  cout << "_____________\n";
}
}


void AskAndCorrectAnswers(stQuizz &Quizz)
{
  for (short QuestionNumber = 0 ; QuestionNumber < Quizz.NumberOfQuestions ; QuestionNumber++)
  {
    PrintTheQuestion(Quizz,QuestionNumber);
    Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
    CorrectTheQuestionsAnswers(Quizz,QuestionNumber);
  }
Quizz.IsPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}


void PrintFinalQuizzResult(stQuizz Quizz)
{
    ShowGameOverScreen();
    cout << "- Number Of Questions: " << Quizz.NumberOfQuestions << endl;
    cout << "- Quizz's Level: " << GetQuestionLevelText(Quizz.QuizzLevel) << endl;
    cout << "- The Operation Type: "<< GetOperationSymbol(Quizz.OpType) << endl;
    cout << "- Number Of Right Answers: " << Quizz.NumberOfRightAnswers << endl;
    cout << "- Number Of Wrong Answers: " << Quizz.NumberOfWrongAnswers << endl;
    cout << "- Final Result: " << GetFinalResultText(Quizz.IsPass);  
}
void playMathGame()
{
  stQuizz Quizz;
  WelcomeingScreen();


  Quizz.NumberOfQuestions = ReadNumberOfQuestions();
  Quizz.OpType = ReadOperationType();
  Quizz.QuizzLevel = ReadQuestionLevel();

  GenerateQuestions(Quizz);
  AskAndCorrectAnswers(Quizz);
  PrintFinalQuizzResult(Quizz);

}


void StartGame()
{
  char PlayAgain = 'Y';
  do
  {
    ResetScreen();
    playMathGame();
    cout << "\nDo You Want To Play Again? \n Answer [Y/N]: ";
    cin >> PlayAgain;

  } while (PlayAgain == 'Y' || PlayAgain == 'y');
  

}


int main()
{

srand((unsigned) time (NULL));
  
 StartGame();

    return 0;
}
