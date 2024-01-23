#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class NumberGuessing {
private:
    int guess;
    int attempts = 0;
    int maxattempts = 15;
    int secretnumber; 
    
public:
    NumberGuessing() {
        Invalid:
        cout<<"Enter 1 for Easy"<<"-> "<<"Enter 2 for Medium"<<"->"<<"Enter 3 for Hard"<<endl;
        int Level;
        cin>>Level;
        if(Level==1){
            maxattempts=15;
        }else if(Level==2){
            maxattempts=10;
        }else if(Level==3){
            maxattempts=5;
        }else{
            goto Invalid;
        }
        srand(time(0));
          secretnumber = rand() % 100 + 1;
    }
    void playgame() {
        cout << "Welcome to our number guessing game" << endl;
        cout << "Guess The Number between 1 to 100" << endl;

        while (attempts < maxattempts) {
            
            cout << "Enter Your Guess" << endl;
            cin >> guess;

            attempts++;

            if (guess == secretnumber) {
                cout << "Congratulations! You Won The Game" << endl;
                   break;  
            } else if (guess < secretnumber) {
                cout << "Too Low! Please Try Again" << endl;
            } else if (guess > secretnumber) {
                cout << "Too High! Please Try Again" << endl;
            }
        }

        if (attempts == maxattempts) {
            cout << "Sorry, Your guess is wrong" << endl << "The Correct Number is -> " << secretnumber << endl;
        }
    }
};

int main() {
    NumberGuessing NG;
    NG.playgame();  
    return 0;       
}