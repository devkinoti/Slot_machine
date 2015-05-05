#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int Random(int low, int high, int bet);

int main()
{
	//random seed
	srand(time(0));

	int players_chips = 1000;
	int choice = 0;
	//int new_players_chips = 0;

	bool quit = false;

	int bet = 0;

	while (!quit)
	{
		cout << "Players_chips available " << players_chips << endl;
		cout << "1) Play slots" << " " << "2) exit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:

			cout << "Playing slots" << endl;
			cout << "Enter your bet " << endl;
			cin >> bet;

			if (bet > 0 && bet < players_chips)
			{
				//play on
				int low = 2;
				int high = 7;
				int sample = Random(2, 7, bet);

				if (sample == 10)
				{
					players_chips = players_chips + (bet * 10);
				}

				if (sample == 5)
				{
					players_chips = players_chips + (bet * 5);
				}

				if (sample == 3)
				{
					players_chips = players_chips + (bet * 3);
				}
				if (sample == -bet)
				{
					players_chips = players_chips - bet;
				}

				//cout << "player_chips " << players_chips << endl;
				if (players_chips == 0)
				{
					cout << "Game over" << endl;
					break;
				}

			}
			else
			{
				cout << endl;
				cout << "illegal bet" << endl;
				break;
			}
			break;
		case 2:
			cout << "Exiting slot machine game..." << endl;
			quit = true;
			break;
		default:
			cout << "Please enter a valid choice " << endl;
			break;
		}

	}

}

int Random(int low, int high, int bet)
{
	int r0 = 0;
	int r1 = 0;
	int r2 = 0;

	int winnings = 0;

	r0 = low + rand() % ((high + 1) - low);
	r1 = low + rand() % ((high + 1) - low);
	r2 = low + rand() % ((high + 1) - low);
	cout << endl;
	cout << "Your numbers are ... " << endl;
	cout << endl;
	cout << r0 << " " << r1 << " " << r2 << " " << endl;
	cout << endl;

	if (r0 == 7 && r1 == 7 && r2 == 7)
	{
		cout << "placeholder -- win ten times" << endl;
		cout << "you win " << endl;
		winnings = 10;
	}
	if ((r0 == r1 == r2) && (r0 != 7 && r1 != 7 && r2 != 7))
	{
		cout << "placeholder -- win 5 times " << endl;
		cout << "you win" << endl;
		winnings = 5;
	}
	if (((r0 == r1) || (r1 == r2) || (r0 == r2)) && !((r0 == r1) && (r0 == r2)))
	{
		cout << "placeholder -- win 3 times " << endl;
		cout << "you win" << endl;
		winnings = 3;
	}
	if ((r0 != r1) && (r0 != r2) && (r1 != r2))
	{
		cout << "lose bet value " << endl;
		cout << "you lose" << endl;
		winnings = -bet;
	}

	return winnings;
}
