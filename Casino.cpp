//Casino Game
#include <iostream> //basic input output stream
#include <cstdlib> //For random
#include <ctime> //For Time
#include <vector> //For vector
#include <iomanip> //For setw
using namespace std;
//Casino Rules Function
void showRules()
{
    cout<<setw(70)<<"BOSS Casino Rules"<<endl;
    cout<<"\nThere are 5 types of bets. Enter each choice and bet amount. You may skip some choices but you must bet at least one. Read the following for bet details and rewards.";
    cout<<"\n\n1. Enter a single number. If it is the winning number, you will get 36 times your bet amount.";
    cout<<"\n2. Enter the ending. 0 to 9. If you choose correctly, you will get 10 times your bet amount. ";
    cout<<"\n3. Choose (1 to 12) or (13 to 24) or (25 to 36). If you choose correctly, you will get 3 times your bet amount.";
    cout<<"\n4. Choose (1 to 18) or (19 to 36). If you choose correctly, you will get 2 times your bet amount.";
    cout<<"\n5. Choose odd or even. If you choose correctly, you will get 2 times your bet amount.";
}

//Function to ask amount for each bet
int askAmount(int currentBalance)
{
    int amt=0;
    while (true)
    {
        if (currentBalance > 0)
        {
            cout<<"Maximum bet amount: "<<currentBalance<<endl;
            cout<<"Enter your bet amount: ";
            cin>>amt;
            if (amt<=currentBalance)
            {
                break;
            }
            else
            {
                cout<<"Your balance is lower than your bet amount. Try again."<<endl;
            }
        }
        else
        {
            cout<<"No money is left to bet. This choice is recognized as skip."<<endl;
            break;
        }
    }
    return amt;
}

//Main Function
int main()
{
    string name;
    string hist="";
    int balance,currentBalance,initialBalance,random;
    int betNum[5];
    int betAmt[5];
    int round=0;
    char ans;
    vector<string>history;
    srand(time(0));
    cout<<setw(70)<<"Welcome to BOSS casino. Good Luck!"<<endl;
    cout<<"\n\nEnter your name: ";
    getline(cin, name);
    cout<<"Note: You must have at least 5000 to play BOSS casino."<<endl;
    cout<<"\nEnter the starting balance to play game (MMK): ";
    cin>>initialBalance;
    hist="Your initial Balance = ";
    hist+=to_string(initialBalance);
    history.push_back(hist);
    history.push_back(" ");
    do
    {
        if (initialBalance<5000)
        {
            cout<<"You don't have enough money! You are not allowed to play BOSS casino."<<endl;
            goto finish;
        }

        else
        {
start:
            round++;
            hist="Round ";
            hist+=to_string(round);
            history.push_back(hist);
            system("cls");
            showRules();
            cout<<"\n\nYour current balance : "<<initialBalance<<endl;
            currentBalance = initialBalance;
            int winAmt = 0;
            int totalBetAmt=0;
            bool betStatus = false;
            cout<<name<<", Are you ready to bet and win?"<<endl;
            system("pause");
            //Bet One
            while (true)
            {
                cout<<"\n1. Enter a single number (1-36). Type '0' to skip. Your bet: ";
                cin>>betNum[0];
                if (betNum[0] >=0 && betNum[0] <=36)
                {
                    if (betNum[0] != 0)
                    {
                        betAmt[0]=askAmount(currentBalance);
                        currentBalance -= betAmt[0];
                        betStatus = true;
                    }
                    else
                    {
                        betAmt[0] = 0;
                    }
                    break;
                }
                else
                {
                    cout<<"Invalid Input! Try again."<<endl;
                }
            }
            //Bet Two
            while (true)
            {
                cout<<"2. Enter the ending (0-9). Type '10' to skip. Your bet: ";
                cin>>betNum[1];
                if (betNum[1] >=0 && betNum[1] <=10)
                {
                    if (betNum[1] !=10)
                    {
                        betAmt[1]=askAmount(currentBalance);
                        currentBalance -= betAmt[1];
                        betStatus = true;
                    }
                    else
                    {
                        betAmt[1] = 0;
                    }
                    break;
                }
                else
                {
                    cout<<"Invalid Input! Try again."<<endl;
                }
            }
            //Bet Three
            while (true)
            {
                cout<<"3. Choose (1 to 12) or (13 to 24) or (25 to 36). Type '1' for (1-12), '2' for (13-24), '3' for (25-36), '0' to skip. Your bet: ";
                cin>>betNum[2];
                if (betNum[2] >=0 && betNum[2] <=3)
                {
                    if (betNum[2] != 0)
                    {
                        betAmt[2]=askAmount(currentBalance);
                        currentBalance -= betAmt[2];
                        betStatus = true;
                    }
                    else
                    {
                        betAmt[2] = 0;
                    }
                    break;
                }
                else
                {
                    cout<<"Invalid Input! Try again."<<endl;
                }
            }
            //Bet Four
            while (true)
            {
                cout<<"4. Choose (1 to 18) or (19 to 36). Type '1' for (1-18), '2' for (19-36), '0' to skip. Your bet: ";
                cin>>betNum[3];
                if (betNum[3] ==0 || betNum[3] == 1 || betNum[3] ==2)
                {
                    if (betNum[3] != 0)
                    {
                        betAmt[3]=askAmount(currentBalance);
                        currentBalance -= betAmt[3];
                        betStatus = true;
                    }
                    else
                    {
                        betAmt[3] = 0;
                    }
                    break;
                }
                else
                {
                    cout<<"Invalid Input! Try again."<<endl;
                }
            }
            //Bet Five
            while (true)
            {
                cout<<"5. Choose odd or even. Type '1' for odd, '2' for even, '0' to skip. Your bet: ";
                cin>>betNum[4];
                if (betNum[4] ==0 || betNum[4] == 1 || betNum[4] ==2)
                {
                    if (betNum[4] != 0)
                    {
                        betAmt[4]=askAmount(currentBalance);
                        currentBalance -= betAmt[4];
                        betStatus = true;
                    }
                    else
                    {
                        betAmt[0] = 0;
                    }
                    break;
                }
                else
                {
                    cout<<"Invalid Input! Try again."<<endl;
                }
            }
            if (betStatus == false)
            {
                cout<<"Sorry! You didn't make any bets. Select again!"<<endl;
                system("pause");
                goto start;
            }
            //Calculating total bet amount
            totalBetAmt = initialBalance - currentBalance;
            //Generating Random number from 1 to 36
            random = rand()%36+1;
            //Calculation for Bet 1
            if (random == betNum[0])
            {
                winAmt += betAmt[0] * 36;
            }
            //Calculation for Bet 2
            if (random % 10 == betNum[1])
            {
                winAmt += betAmt[1] * 10;
            }
            //Calculation for Bet 3
            bool winstatus = false;
            if (random <=12)
            {
                if (betNum[2] == 1)
                {
                    winstatus = true;
                }
            }
            else if (random >12 && random <=24)
            {
                if (betNum[2] == 2)
                {
                    winstatus = true;
                }
            }
            else
            {
                if (betNum[2] == 3)
                {
                    winstatus = true;
                }
            }
            if (winstatus == true)
            {
                winAmt += betAmt[2] * 3;
            }
            //Calculation for Bet 4
            winstatus = false;
            if (random <=18)
            {
                if (betNum[3] == 1)
                {
                    winstatus = true;
                }
            }
            else
            {
                if (betNum[3] == 2)
                {
                    winstatus = true;
                }
            }
            if (winstatus == true)
            {
                winAmt += betAmt[3] * 2;
            }
            //Calculation for Bet 5
            winstatus = false;
            if (random % 2 != 0)
            {
                if (betNum[4] == 1)
                {
                    winstatus = true;
                }
            }
            else
            {
                if (betNum[4] == 2)
                {
                    winstatus = true;
                }
            }
            if (winstatus == true)
            {
                winAmt += betAmt[4] * 2;
            }

            //Show to the user
            system("cls");
            cout<<"Generating a winner number. Good Luck!!"<<endl;
            system("pause");
            cout<<"\nWinner Number: "<<random<<endl;
            cout<<"Total Bet: "<<totalBetAmt<<endl;
            int profit = winAmt - totalBetAmt;

            if (profit >0)
            {
                cout<<"Congratulations! You win!"<<endl;
                cout<<"Total Win Amount: "<<winAmt<<endl;
                cout<<"Profit: + "<<profit<<endl;
                hist = "Profit: ";
                hist += to_string(profit);
                history.push_back(hist);
            }
            else
            {
                cout<<"You lost! Good Luck in the next round!"<<endl;
                cout<<"Total Win Amount: "<<winAmt<<endl;
                cout<<"Loss Amount : "<<profit<<endl;
                hist = "Loss : ";
                hist += to_string(profit);
                history.push_back(hist);
            }
            currentBalance += winAmt;
            cout<<"Your initial balance : "<<initialBalance<<endl;
            cout<<"Your current balance: "<<currentBalance<<endl;
            cout<<"\nDo you want to continue playing at BOSS casino, "<<name<<" ? If yes, type 'y', if no, type 'n'. If you want to see your bet history, type 'h'. Your answer: ";
            cin>>ans;
            initialBalance = currentBalance;
            if (ans == 'h')
            {
                system("cls");
                cout<<"Your bet history: "<<endl;
                for (int i=0; i<history.size(); ++i)
                {
                    cout<<history[i]<<endl;
                }
                cout<<"Your current balance: "<<currentBalance<<endl;
                cout<<"\nDo you want to continue playing at BOSS casino, "<<name<<" ? If yes, type 'y', if no, type 'n'. Your answer: ";
                cin>>ans;
            }
        }
    }
    while (ans == 'y');
finish:
    cout<<"Thank you very much for playing BOSS casino! See you again, "<<name<<endl;
    return 0;
}
