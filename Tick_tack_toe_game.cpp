#include<iostream>
#include<string>
using namespace std;
char GRID[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}}; 
char turn = 'x';
int row;
int col;
bool tie = false;
string n1;
string n2;

void Display_board(){
     
    cout<<"   |   |   \n";
    cout<<" "<<GRID[0][0]<<" | "<<GRID[0][1]<< " | "<<GRID[0][2]<<" \n" ;
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<" "<<GRID[1][0]<<" | "<<GRID[1][1]<< " | "<<GRID[1][2]<<" \n" ;
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<" "<<GRID[2][0]<<" | "<<GRID[2][1]<< " | "<<GRID[2][2]<<" \n" ;
    cout<<"   |   |   \n";
}

void Play_your_turn(){
    int d ;
    if(turn=='x'){
        cout<<n1<<" please enter the GRID NUMBER: ";
        
    }
    if(turn=='0'){
        cout<<n2<<" please enter the GRID NUMBER: ";
        
    }
    cin>>d;
    if(d==1){
        row = 0;
        col = 0;
    }
    else if(d==2){
        row = 0;
        col = 1;
    }
    else if(d==3){
        row = 0;
        col = 2;
    }
    else if(d==4){
        row = 1;
        col = 0;
    }
    else if(d==5){
        row = 1;
        col = 1;
    }
    else if(d==6){
        row = 1;
        col = 2;
    }
    else if(d==7){
        row = 2;
        col = 0;
    }
    else if(d==8){
        row = 2;
        col = 1;
    }
    else if(d==9){
        row = 2;
        col = 2;
    }
    else{
        cout<<"invalid input!!!\n";
        Play_your_turn();
    }

    if(turn=='x'&& GRID[row][col]!='x'&&GRID[row][col]!='0') //unused space
    { 
       GRID[row][col]='x';
       turn ='0';
    }
    else if(turn=='0'&& GRID[row][col]!='x'&&GRID[row][col]!='0') //unused space
    { 
       GRID[row][col]='0';
       turn ='x';
    }
    else{
        cout<<"there is no empty space!!\n";
        Play_your_turn();
    }
    Display_board();
}

bool check_draw_win(){
    //To check if any column or row matches 
    for(int i = 0 ; i<3 ; i++){
        if(GRID[i][0]==GRID[i][1]&&GRID[i][1]==GRID[i][2] || GRID[0][i]==GRID[1][i]&&GRID[1][i]==GRID[2][i]){
            return false;
            
        }

    }
    //To check if any diagonal matches
    if(GRID[0][0]==GRID[1][1]&&GRID[0][0]==GRID[2][2]||GRID[0][2]==GRID[1][1]&&GRID[1][1]==GRID[2][0]){
        return false;
        
    }
    
    //To check whether to continue the game

    for(int i = 0 ; i< 3 ; i++){
        for(int j = 0 ; j<3 ; j++){
            if(GRID[i][j]!='x'&&GRID[i][j]!='0')return true;
            
        }
    }
    
    //To check whether the game is a tie or not

    tie =true;
    return false;

}

int main(){
    
    cout<<"\t\t*-----Welcome to TICK TACK TOE GAME-----*\n\n";
    cout<<"ENTER Player 1: ";
    cin>>n1;
    cout<<"ENTER Player 2: ";
    cin>>n2;

    cout<<" Player 1 is [X] "<<n1<<" He/She plays first\n";
    cout<<" Player 2 is [0] "<<n2<<" He/She plays second\n";

    while(check_draw_win()){
        Display_board();
        Play_your_turn();
        check_draw_win();
    }
    if(turn=='x'&&tie==false){
        cout<<n2<<" WINS!!";
    }
    else if(turn=='0'&&tie==false){
        cout<<n1<<" WINS!!";
    }
    else{
        cout<<"Its a draw!! Play again with us!!";
    }

    return 0;

}