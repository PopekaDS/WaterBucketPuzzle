// Water Bucket Puzzle, by Al Sweigart
// A water pouring puzzle.
// More info: https://en.wikipedia.org/wiki/Water_pouring_puzzle
// This code is available at https://nostarch.com/big-book-small-python-programming
// #81 WATER BUCKET PUZZLE
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int stringToInt(const string request) {
	int response = 0;
	for (char c : request) {
		if (c >= '0' && c <= '9') {
			response = response * 10 + (c - '0');
		}
	}
	return response;
}

int main() {
	std::cout << "Water Bucket Puzzle\n\n";
	int GOAL = 4; // The exact amount of water to have in a bucket to win.
	int steps = 0; // Keep track of how many steps the player made to solve this.
	// The amount of water in each bucket:
	map <string, int> waterInBucket;
	waterInBucket["8"] = 0;
	waterInBucket["5"] = 0;
	waterInBucket["3"] = 0;
	while (true) {
		// Display the current state of the buckets:
		std::cout << "Try to get " << GOAL << "L of water into one of these\n";
		std::cout << "buckets:\n";

		vector <string> waterDisplay; // Contains strings for water or empty space.
		// Get the strings for the 8L bucket:
		for (int i = 1; i < 9; ++i) {
			if (waterInBucket["8"] < i) {
				waterDisplay.push_back("      "); // Add empty space.
			} else {
				waterDisplay.push_back("WWWWWW"); // Add water.
			}
		}

		// Get the strings for the 5L bucket:
		for (int i = 1; i < 6; ++i) {
			if (waterInBucket["5"] < i) {
				waterDisplay.push_back("      "); // Add empty space.
			}
			else {
				waterDisplay.push_back("WWWWWW"); // Add water.
			}
		}

		// Get the strings for the 3L bucket:
		for (int i = 1; i < 4; ++i) {
			if (waterInBucket["3"] < i) {
				waterDisplay.push_back("      "); // Add empty space.
			}
			else {
				waterDisplay.push_back("WWWWWW"); // Add water.
			}
		}

		// Display the buckets with the amount of water in each one:
		std::cout << "8|" << waterDisplay[7] << "|\n";
		std::cout << "7|" << waterDisplay[6] << "|\n";
		std::cout << "6|" << waterDisplay[5] << "|\n";
		std::cout << "5|" << waterDisplay[4] << "|  5|" << waterDisplay[12] << "|\n";
		std::cout << "4|" << waterDisplay[3] << "|  4|" << waterDisplay[11] << "|\n";
		std::cout << "3|" << waterDisplay[2] << "|  3|" << waterDisplay[10] << "|  3|" << waterDisplay[15] << "|\n";
		std::cout << "2|" << waterDisplay[1] << "|  2|" << waterDisplay[9] << "|  2|" << waterDisplay[14] << "|\n";
		std::cout << "1|" << waterDisplay[0] << "|  1|" << waterDisplay[8] << "|  1|" << waterDisplay[13] << "|\n";
		std::cout << " +------+   +------+   +------+\n";
		std::cout << "    8L         5L         3L\n";

		// Check if any of the buckets has the goal amount of water:
		for (auto waterAmount : waterInBucket) {
			if (waterAmount.second == GOAL) {
				std::cout << "Good job! You solved it in " << steps << " steps!\n";
				return 0;
			}
		}

		// Let the player select an action to do with a bucket:
		std::cout << "You can:\n";
		std::cout << "  (F)ill the bucket\n";
		std::cout << "  (E)mpty the bucket\n";
		std::cout << "  (P)our one bucket into another\n";
		std::cout << "  (Q)uit\n";

		string move = "";
		while (true) {
			std::cout << "> ";
			getline(cin, move);
			transform(move.begin(), move.end(), move.begin(), ::toupper);
			
			if (move == "QUIT" || move == "Q") {
				std::cout << "Thanks for playing!\n";
				return 0;
			}

			if (move == "F" || move == "E" || move == "P") {
				break; // Player has selected a valid action.
			}
			std::cout << "Enter F, E, P, or Q\n";
		}

		// Let the player select a bucket:
		string srcBucket = "";
		while (true) { // Keep asking until valid bucket entered.
			std::cout << "Select a bucket 8, 5, 3, or QUIT:\n";
			std::cout << "> ";
			getline(cin, srcBucket);
			transform(srcBucket.begin(), srcBucket.end(), srcBucket.begin(), ::toupper);
			if (srcBucket == "QUIT") {
				std::cout << "Thanks for playing!\n";
				return 0;
			}
			if (srcBucket == "8" || srcBucket == "5" || srcBucket == "3") {
				break; // Player has selected a valid bucket.
			}
		}

		// Carry out the selected action:
		int srcBucketSize = 0;
		if (move == "F") {
			// Set the amount of water to the max size.
			srcBucketSize = stringToInt(srcBucket);
			waterInBucket[srcBucket] = srcBucketSize;
			steps++;
		} else if (move == "E") {
			// Set water amount to nothing.
			waterInBucket[srcBucket] = 0;
			steps++;
		} else if (move == "P") {
			// Let the player select a bucket to pour into:
			string dstBucket = "";
			while (true) { // Keep asking until valid bucket entered.
				cout << "Select a bucket to pour into: 8, 5, or 3\n";
				std::cout << "> ";
				getline(cin, dstBucket);
				transform(dstBucket.begin(), dstBucket.end(), dstBucket.begin(), ::toupper);
				if (dstBucket == "8" || dstBucket == "5" || dstBucket == "3") {
					break;
				}
			}

			// Figure out the amount to pour:
			int dstBucketSize = stringToInt(dstBucket);
			int emptySpaceInDstBucket = dstBucketSize - waterInBucket[dstBucket];
			int waterInSrcBucket = waterInBucket[srcBucket];
			int amountToPour = min(emptySpaceInDstBucket, waterInSrcBucket);

			// Pour out water from this bucket:
			waterInBucket[srcBucket] -= amountToPour;

			// Put the poured out water into the other bucket:
			waterInBucket[dstBucket] += amountToPour;
			steps++;
		}
	}

	return 0;
}
