#include <iostream>
using namespace std;

char space[3][3]= {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    // rows and column numbers that will represent where the x and o will go based on what number the player will select
int row;
int column;
char symbol = 'x';
bool tie = false;

void functionOne() {
    cout << "    |    |    \n";
    cout << " " << space[0][0] << "  |  " << space[0][1] << " |  " << space[0][2] << "  \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << " " << space[1][0] << "  |  " << space[1][1] << " |  " << space[1][2] << "  \n";
    cout << "____|____|____\n";
    cout << "    |    |    \n";
    cout << " " << space[2][0] << "  |  " << space[2][1] << " |  " << space[2][2] << "  \n";
    cout << "    |    |    \n";
}

void functionTwo() {
    string p1 = " ";
    string p2 = " "; 
    int digit;

    if (symbol == 'x'){
        cout << p1 << "Please enter a number to place your symbol 'x': ";
        cin >> digit;   
    }
    if (symbol == 'o'){
        cout << p2 << "Please enter a number to place your symbol 'o': ";
        cin >> digit;
    }

    if (digit == 1){
        row = 0;
        column = 0;
    } else if (digit == 2){
        row = 0;
        column = 1;
    } else if (digit == 3){
        row = 0;
        column = 2;
    } else if (digit == 4){
        row = 1;
        column = 0;
    } else if (digit == 5){
        row = 1;
        column = 1;
    } else if (digit == 6){
        row = 1;
        column = 2;
    } else if (digit == 7){
        row = 2;
        column = 0;
    } else if (digit == 8){
        row = 2;
        column = 1;
    } else if (digit == 9){
        row = 2;
        column = 2;
    } else if (digit < 1 || digit > 9){
        cout << "Invalid !!!" << endl;
    } else {
        cout << "Invalid !!!" << endl;
    }

    if (symbol == 'x' && space[row][column] != 'x' && space[row][column] != 'o'){
        space[row][column] = 'x';
        symbol = 'o';
    }
    else if (symbol == 'o' && space[row][column] != 'x' && space[row][column] != 'o'){
        space[row][column] = 'o';
        symbol = 'x';
    }
    else {
        cout << "No empty space!" << endl;
        functionTwo();
    }
    functionOne();

}

bool functionThree(){
    bool tie = false;
    //checking for horizontal and vertical wins
    for (int i = 0; i < 3; ++i){
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
        return true; 
    }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]){
        return true; 
    } 
    // checking for diagonal wins 
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            if (space[i][j] != 'x' && space[i][j] != 'o'){
                return false;
            }
        }
    }
    tie = true;
    return false;
}

int main () {
    bool tie = false;
    string p1 = " "; 
    string p2 = " ";

    cout << "Enter the name of Player one: ";
    getline (cin, p1);
    cout << "Enter the name of Player two: ";
    getline (cin, p2);
    cout << p1 << " is Player one and will be assigned to x and play first. \n";
    cout << p2 << " is Player two and will be assigned to o and play second. \n";

    while (!functionThree()){
        functionOne();
        functionTwo();
        functionThree();
    }

    if (symbol == 'x' && tie == false){
        cout << p2 << " Wins!!" << endl;
    } else if (symbol == 'o' && tie == false) {
        cout << p1 << " Wins!!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
}
