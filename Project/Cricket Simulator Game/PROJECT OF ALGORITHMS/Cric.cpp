
						//Cricket Match Simulation
#include <iostream>
#include<iomanip>
#include<ctime>
#include<string>
#include<cstdlib>							//Headerfiles
#include<cmath>
using namespace std;

void toss(string,string);					//TOSS

void Batbowl(string,string);					//BAT/BOWL

void Bowlingboard(string);					//BOWLERS

void Battingboard(string);					//BATSMAN

int FallofWickets();						//WICKETS

int Oversbowled(int);						//OVERS & FIRST INNINGS

int Second_Innings(int);					//SECOND INNINGS

void compare(int , int,string,string);			//COMPARISION OF SCORES

double runrate(int,int);					//RUNRATE GENERATOR

void Total_Score(int,int,string,string);			//TOTAL SCORE 

void ScoreCard(string);					//SCORECARD

void BowlerCard(string);					//BOWLERS


//....................................................................//
void toss(string teama,string teamb) {

	cout<<"------------------------------------------------------"<<endl;
	cout<<endl;
	cout<<"WE GOT THE TWO CAPTAINS AND WE ARE READY FOR THE TOSS"<<endl<<endl;
	cout<<"\t\t--------HEADS IS THE CALL--------\t"<<endl; 
	cout<<endl;
srand(time(0));
int x=rand()%2;					//RANDOM RESULT 
switch(x)
{
case 0:
cout<<teama<<" have won the toss"<<endl;			//CASE 0 TELLS TEAM A
break;
case 1:
cout<<teamb<<" have won the toss"<<endl;			//CASE 1 TELLS TEAM B

break;
}
}

//---------------------------------------------------------------//






void Batbowl(string teama,string teamb){
srand(time(0));
int y=rand()%2;				//RANDOM 
switch(y)
{
case 0:
cout<<teama<<" WILL BAT "<<endl;				//WHO  WILL BAT AND WHO WILL BALL
cout<<teamb<<" WILL BOWL"<<endl;

break;

case 1:
cout<<teamb<<" WILL BAT FIRST"<<endl;
cout<<teama<<" WILL BOWL"<<endl; 

break;
}
}
//................................................................//



//................................................................//


double runrate(int Over,int Runs)
{
double runrate; 
runrate=(Runs/Over);				//RUNATE GENERATOR
return runrate;
}



//---------------------------------------------------------------//






	int Oversbowled(int N)			//INNINGS 1
	{					//N IS OVERS
	float Balls;
	int sum2=0;
	int k=0;				//VARIABLES



	srand(time(0));
			
	for(int i=0;i<N;i++)				//0.1- 0.2 - 0.3 DISPLAY
	{
	for(int j=1;j<7;j++)
	{
	
	int RD;
	
	  for (int index = 0; index < 1; index++) {
	   if(k>=10){
	   break;				//WICKETS>10 BREAK
	   }
	    RD = (rand() % 8) + (-1); 	//RAND FUNCTION TO GENERATE -1 TO 6 RANDOM NUMBERS
	if(cin.get()=='\n')
		{    
	
	cout<<"Over"<<"\t\t\t\t"<<"RUNS"<<endl;
	cout<<i<< "."<<j<<"\t\t\t\t"<< RD <<endl;	//DISPLAY OF OVERS 0.1-0.2 ETC
	int score=RD;
	
	if(score!=-1){
	sum2=sum2+score;
		}					//SCORE ADDITION
	cout<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	
	if(RD==-1)					//OUT
	{
	k++;
	
	cout<<"------Wicket !!! Big Blow Number "<< k <<" for the batting team------"<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	}
	
	
	if(RD==0)					//MISS
	{
	cout<<"-----Swing and a Miss------"<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	}
	if(RD==1)					//SINGLE
	{
	cout<<"------Just a little flick for a Single------ "<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	}
	if(RD==2)					//DOUBLE
	{
	cout<<"------Excellent Running------"<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	}
	if(RD==3)					//TRIPLE
	{
		cout<<"------Fast between the Wickets------"<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	}
	if(RD==4)					//FOUR
	{
	cout<<"------Classy Cover Drive for 4------"<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	}
	if(RD==6)					//MAXIMUM SIX
	{
	cout<<"------Thats Sixxx! A Big one this time------"<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	}
	cout<<endl;
	
	cout<<"Score : "<<sum2<<"/"<<k<<endl;		//	SCORE/WICKETS
	cout<<endl;
	
					}			
		
				}
	
			}
	
		}
	system("clear");
	
	cout<<"THE TOTAL SCORE IS : "<<sum2<<endl;							//SCORE OF INNINGS
	cout<<endl;
	cout<<sum2+1<<" IS REQUIRED TO WIN THE MATCH "<<endl;					//TARGET
	cout<<endl;
	cout<<"\t\t------ITS GOING TO BE A TOUGH CHASE !!-----\t\t"<<endl;
	cout<<endl;
	
	
	
	 return sum2;											//RETURNING SCORE
	}

//......................................................................//


void compare(int a, int b,string teama,string teamb) {
if (a==b) 
{
cout<<"MATCH TIED\n";										//TIED
}
else if (a>b) {

cout<<"CONGRATULATIONS "<<teama<<"IS WINNER WITH SCORE OF "<<a<<"."<<endl;				//TEAM A WINNER

}
else 
cout<<"CONGRATULATIONS "<<teamb<<" IS WINNER WITH SCORE OF "<<b<<endl;				////TEAM B WINNER
}

//----------------------------------------------------------------//
void Battingboard(string playing[15]){								//BATTING BOARD TO DISPALY BATSMEN

cout<<"\t\t\tBATTING BOARD"<<endl;
cout<<"\t\t----------------------------\t\t"<<endl;
for(int i=0;i<11;i++){

cout<<playing[i]<<endl;
}

}
//......................................................................//

void Bowlingboard(string play[6])
{
cout<<endl;
cout<<"\t\t\tBOWLING BOARD"<<endl;									//BOWLING BOARD TO DISPLAY BOWLERS
cout<<"\t\t----------------------------\t\t"<<endl;
for(int i=6;i<11;i++){

cout<<play[i]<<endl;
}
}

//..............................................................//

int Second_Innings(int A)					//SECOND INNINGS
{
float Balls;
int sum=0;
int k=0;

srand(time(0));
cout<<"OVER"<<"\t\t\t\t"<<"RUNS"<<endl;			//OVERS AND RUNS
for(int i=0;i<A;i++)
{
for(int j=1;j<7;j++)//1 or 7
{

int RD;

  for (int index = 0; index < 1; index++) {
   if(k>=10){							//WICKETS > 10 BREAK
   break;
   }
    RD = (rand() % 8) + (-1); 
if(cin.get()=='\n')
{    

cout<<i<< "."<<j<< "\t\t\t\t"<< RD <<endl;
cout<<endl;
int score=RD;

if(score!=-1){
sum=sum+score;										//SUM OF SCORE
}
cout<<endl;
cout<<"--------------------------------------------------------------"<<endl;

if(RD==-1)								//WICKET
{


k++;
cout<<"------Wicket !!! Big Blow Number "<< k <<" for the batting team------"<<endl;
cout<<"--------------------------------------------------------------"<<endl;


}

if(RD==0)								//MISS
{
cout<<"-----Swing and a Miss------"<<endl;
cout<<"--------------------------------------------------------------"<<endl;
}
if(RD==1)								//SINGLE
{
cout<<"------Just a little flick for a Single------ "<<endl;
cout<<"--------------------------------------------------------------"<<endl;
}
if(RD==2)								//DOUBLE
{
cout<<"------Excellent Running------"<<endl;
cout<<"--------------------------------------------------------------"<<endl;
}
if(RD==3)								//TRIPLE
{
cout<<"------Fast between the Wickets------"<<endl;
cout<<"--------------------------------------------------------------"<<endl;
}
if(RD==4)								//FOUR
{
cout<<"------Classy Cover Drive for 4------"<<endl;
cout<<"--------------------------------------------------------------"<<endl;
}
if(RD==6)								//MAXIMUM SIX
{
cout<<"------Thats Sixxx! A Big one this time------"<<endl;
cout<<"--------------------------------------------------------------"<<endl;
}
cout<<endl;


cout<<"Score : "<<sum<<"/"<<k<<endl;					//SCORE/WICKETS
cout<<endl;
cout<<"--------------------------------------------------------------"<<endl;
				}			
	
			}

		}

	}
system("clear");			//TO CLEAR

cout<<"THE TOTAL SCORE OF INNINGS IS : "<<sum<<endl;
cout<<endl;
return sum;


}

//......................................................................................................//

void Total_Score(int A,int B,string teamA,string teamB){			//SUB FUNCTION OF TOTAL SCORE
cout<<endl;
cout<<"TOTAL SCORE BY "<< teamA<<" IS "<<A<<endl;
cout<<endl;
cout<<"TOTAL SCORE BY "<< teamB<<" IS "<<B<<endl;
}


//...............................................................//


void ScoreCard(string PlayersA[15]){


			cout<<"\t\t\t\t---------------------------BATTING ORDER------------------------"<<endl;
cout<<endl;
cout<<endl;
cout<<""""<<""<<setw(26)<<"BATSMAN"<<setw(30)<<"RUNS"<<setw(33)<<"BALLS"<<setw(36)<<"MATCHES"<<endl;
cout<<""""<<""<<setw(26)<<PlayersA[0]<<setw(30)<<"22"<<setw(33)<<"15"<<setw(36)<<"44"<<endl;
cout<<""""<<""<<setw(26)<<PlayersA[1]<<setw(30)<<"8"<<setw(33)<<"2"<<setw(36)<<"27"<<endl;
cout<<""""<<""<<setw(26)<<PlayersA[2]<<setw(30)<<"13"<<setw(33)<<"6"<<setw(36)<<"54"<<endl;
cout<<""""<<""<<setw(26)<<PlayersA[3]<<setw(30)<<"27"<<setw(33)<<"11"<<setw(36)<<"60"<<endl;
cout<<""""<<""<<setw(26)<<PlayersA[4]<<setw(30)<<"4"<<setw(33)<<" 7"<<setw(36)<<"87"<<endl;
cout<<""""<<""<<setw(26)<<PlayersA[5]<<setw(30)<<"11"<<setw(33)<<"15"<<setw(36)<<"43"<<endl;		//using setw 
cout<<""""<<""<<setw(26)<<PlayersA[6]<<setw(30)<<"23"<<setw(33)<<"7"<<setw(36)<<"54"<<endl;
cout<<""""<<""<<setw(26)<<PlayersA[7]<<setw(30)<<"21"<<setw(33)<<"8"<<setw(36)<<"64"<<endl;
cout<<""""<<""<<setw(26)<<PlayersA[8]<<setw(30)<<"20"<<setw(33)<<"18"<<setw(36)<<"74"<<endl;
cout<<""""<<""<<setw(26)<<PlayersA[9]<<setw(30)<<"16"<<setw(33)<<"11"<<setw(36)<<"67"<<endl;
cout<<""""<<""<<setw(26)<<PlayersA[10]<<setw(30)<<"23"<<setw(33)<<"22"<<setw(36)<<"24"<<endl;
}

void BowlerCard(string PB[15]){

cout<<"\t\t\t\t\t\t----------------------------\t\t"<<endl;


			cout<<"\t\t\t\t--------------------------BOWLERS---------------------------"<<endl;
												//BOWLING BOARD TO DISPLAY BOWLERS
cout<<"\t\t\t\t\t\t----------------------------\t\t"<<endl;

cout<<"\t\t\t\t------------------------------------------------------------"<<endl;
cout<<""""<<""<<setw(26)<<"BOWLERS" <<"\t\t\t\t	"<<"MATCHES"<<"\t\t\t\t	"<<"WICKETS"<<"\t\t	"<<"\t"<<"CAREER-BEST"<<endl;

cout<<""""<<""<<setw(26)<<PB[7] <<"\t\t\t\t	"<<"88"     <<"\t\t\t\t	"<<"3" <<"\t\t	"<<"\t\t4-35"<<endl;
cout<<""""<<""<<setw(26)<<PB[8] <<"\t\t\t\t	"<<"68"     <<"\t\t\t\t	"<<"1" <<"\t\t	"<<"\t\t4-15"<<endl;
cout<<""""<<""<<setw(26)<<PB[9]<<"\t\t\t\t	"<<"99"     <<"\t\t\t\t	"<<"0" <<"\t\t	"<<"\t\t6-30"<<endl;	
cout<<""""<<""<<setw(26)<<PB[10] <<"\t\t\t\t	"<<"49"     <<"\t\t\t\t	"<<"2" <<"\t\t	"<<"\t\t7-10"<<endl;
cout<<""""<<""<<setw(26)<<PB[11] <<"\t\t\t\t	"<<"59"     <<"\t\t\t\t	"<<"4" <<"\t\t	"<<"\t\t3-20"<<endl;
}



//...............................................................//

int main()
{
   
string PlayersA[15];
string PlayersB[15];								//STRING ARRAY FOR TEAM A AND TEAM B
string TeamA,TeamB;
int total_scoreA=0, totB=0;
cout<<"----------------------------------------------------------------"<<endl;
cout<<"SAMPLE OF TEAM"<<endl; 
int *array=new int [15];							//TEAM FORMAT USING DYNAMICALLY FORMAT OF RUBRIK
for(int i=0;i<11;i++)
{
array[i]=i;
cout<<i<<" Batsman["<<i<<"]";
}
cout<<"----------------------------------------------------------------"<<endl;


						//MATCH FROM START//

	cout << "\n\n";
	cout << "\t---------------------------------------------------------\n";
	cout << "\t|*******************************************************|\n";
	cout << "\t---------------------------------------------------------\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|  ` SIMULATOR OF CRICKET MATCH FROM ALI RAZA KHAN '\t|\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t_______________\t\t\t\t_________________\n";
	cout << "\t|\t_______\t\t\t\t_______\t\t|\n";
	cout << "\t|\t| | | |\t\t\t\t| | | |\t\t|\n";
	cout << "\t|\t```````\t\t\t\t```````\t\t|\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|\t\t\t__________\t\t\t|\n";
	cout << "\t|\t\t\t|        |\t\t\t|\n";
	cout << "\t|\t\t\t|        |\t\t\t|\n";
	cout << "\t_______________\t\t|        |\t_________________\n";
	cout << "\t|\t_______\t\t|        |\t_______\t\t|\n";
	cout << "\t|\t| | | |\t\t|        |\t| | | |\t\t|\n";
	cout << "\t|\t```````\t\t|        |\t```````\t\t|\n";
	cout << "\t|\t\t\t|        |\t\t\t|\n";
	cout << "\t|\t\t\t|        |\t\t\t|\n";
	cout << "\t|_______________________________________________________|\n";


cout<<endl;




cout<<"\t\tENTER TWO TEAMS WHICH WILL PLAY :"<<endl;
cout<<"Enter First Team : ";
cin>>TeamA;
cout<<"Enter Second Team : ";
cin>>TeamB;												//TEAM FROM USER

cout<<endl;
cout<<"------------------------------------------------------"<<endl;
cout<<"\t\t WE ARE LIVE FROM MELBOURNE CRICKET GROUND\t\t"<<endl;
cout<<endl;
cout<< "\t\tTHE MATCH IS BETWEEN " <<TeamA<< " AND " <<TeamB <<" "<<endl;
cout<<endl;

  
cout<<"ENTER PLAYERS OF "<< TeamA<<endl;						//INPUT PLAYERS OF TEAM A
cout<<"------------------------------------------------------"<<endl;
for(int i=0;i<11;i++){
cin>>PlayersA[i];
}
cout<<endl;
cout<<endl;





cout<<"ENTER PLAYERS OF "<<TeamB<<endl;						//INPUT PLAYERS OF TEAM B
cout<<"------------------------------------------------------"<<endl;
for(int i=0;i<11;i++){
cin>>PlayersB[i];
}






cout<<endl;
cout<<"WE HAVE THE PLAYING-XII FOR "<<TeamA<<endl;			//TEAM A
cout<<endl;
cout<<"------------------------------------------------------"<<endl;

cout<<TeamA<<endl;
for(int i=0,j=1;i<11,j<12;i++,j++){
cout<<j<<"-"<<PlayersA[i]<<endl;
}

cout<<endl;
cout<<"WE HAVE THE PLAYING-XII FOR "<<TeamB<<endl;			//TEAM B

cout<<endl;
cout<<"------------------------------------------------------"<<endl;
cout<<TeamB<<endl;
for(int i=0,j=1;i<11,j<12;i++,j++){
cout<<j<<"-"<<PlayersB[i]<<endl;
}



toss(TeamA,TeamB);				//TOSS

cout<<endl;

cout<<endl;

Batbowl(TeamA,TeamB);		//BAT/BOWL

cout<<endl;


int choice;

 cout<<"WHAT DO YOU WANT FROM " <<TeamA<<" (1 for bat & 2 for bowl)"<<endl;

 cout<<endl;
 cin>>choice;										//USER CAN DECIDE HIMSELF/HERSELF

 if (choice==1)
 {
 cout<<TeamA<<" WILL BAT "<<endl;

Battingboard(PlayersA);
	
cout<<endl; 						//BATTING BOWLING BOARD ACCORDING TO CHOICE

 Bowlingboard(PlayersB);

 cout<<endl;


 }


if (choice==2)

 {

 cout<<TeamB<<" WILL BAT "<<endl;

Battingboard(PlayersB);

cout<<endl;						//BATTING BOWLING BOARD ACCORDING TO CHOICE

Bowlingboard(PlayersA);

cout<<endl;


 }


int till_where;

cout<<"ENTER NUMBER OF OVERS:"<<endl;						//OVERS ./. NO CONFIGRATION FILE

cin>>till_where;

cout<<endl<<endl;
cout<<"------------------------------------------------------"<<endl;			//1ST INNINGS
cout<<"\t\t\t"<<"1ST INNINGS"<<endl<<endl; 

cout<<"------------------------------------------------------"<<endl;

total_scoreA=Oversbowled(till_where);								//SCORE OF INNINGS

double RRate1=runrate(till_where,total_scoreA);

cout<<"THE RUNRATE OF FIRST INNINGS IS "<<RRate1+0.5<<endl;							//RUNRATE

cout<<endl<<endl;

 if(choice==1)
{
ScoreCard(PlayersA);
BowlerCard(PlayersB);
}
if(choice==2)
{
ScoreCard(PlayersB);
BowlerCard(PlayersA);
}



cout<<"------------------------------------------------------"<<endl;
cout<<"\t\t\t"<<"2ND INNINGS"<<endl<<endl; 									//2ND INNINGS

cout<<"------------------------------------------------------"<<endl;

totB=Second_Innings(till_where);								//SCORE OF INNINGS

double RRate2=runrate(till_where,totB);							//RUNRATE

cout<<"THE RUNRATE OF SECOND INNINGS IS "<<RRate2<<endl;

cout<<"------------------------------------------------------"<<endl;

compare(total_scoreA,totB,TeamA,TeamB);
cout<<PlayersA[3]<<" IS BATSMAN OF THE MATCH"<<endl;								//COMPARE SCORE TO DECIDE WINNER
cout<<PlayersB[10]<<" IS BOWLER OF THE MATCH"<<endl;
cout<<"------------------------------------------------------"<<endl;

cout<<endl;

Total_Score(total_scoreA,totB,TeamA,TeamB);								//DISPLAYING TOTAL SCORE 

cout<<"------------------------------------------------------"<<endl;





  if(choice==1)
{
ScoreCard(PlayersB);
BowlerCard(PlayersA);
} 
 if(choice==2)
{
ScoreCard(PlayersA);
BowlerCard(PlayersB);
}


return 0;
}
