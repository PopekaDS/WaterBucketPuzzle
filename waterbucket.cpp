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

class WaterBucketPuzzle {
private:
	int GOAL = 4; // The exact amount of water to have in a bucket to win
	int steps = 0; // Keep track of how many steps the player made to solve this
	std::map <std::string, int> waterInBucket; // The amount of water in each bucket

	int stringToInt(const std::string& str) {
		int result = 0;
		for (char c : str) {
			if (c >= '0' && c <= '9') {
				result = result * 10 + (c - '0');
			}
		}
		return result;
	}

	void displayBuckets() {
		// Display the current state of the buckets
		std::cout << "Try to get " << GOAL << "L of water into one of these buckets:\n";

		std::vector<std::string> waterDisplay; // Contains std::strings for water or empty space

		// Get std::strings for 8L bucket
		for (int i = 1; i < 9; ++i) {
			if (waterInBucket["8"] < i) {
				waterDisplay.push_back("      "); // Add empty space
			}
			else {
				waterDisplay.push_back("WWWWWW"); // Add water
			}
		}

		// Get std::strings for 5L bucket
		for (int i = 1; i < 6; ++i) {
			if (waterInBucket["5"] < i) {
				waterDisplay.push_back("      "); // Add empty space
			}
			else {
				waterDisplay.push_back("WWWWWW"); // Add water
			}
		}

		// Get std::strings for 3L bucket
		for (int i = 1; i < 4; ++i) {
			if (waterInBucket["3"] < i) {
				waterDisplay.push_back("      "); // Add empty space
			}
			else {
				waterDisplay.push_back("WWWWWW"); // Add water
			}
		}

		// Display the buckets with the amount of water in each one
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
	}

	// Check if any of the buckets has the goal amount of water
	bool checkWinCondition() {
		for (const auto& bucket : waterInBucket) {
			if (bucket.second == GOAL) {
				std::cout << "Good job! You solved it in " << steps << " steps!\n";
				return true;
			}
		}
		return false;
	}

	std::string getPlayerMove() {
		std::string move;
		while (true) {
			std::cout << "> ";
			std::getline(std::cin, move);
			transform(move.begin(), move.end(), move.begin(), ::toupper);

			if (move == "QUIT" || move == "Q") {
				return "QUIT";
			}

			if (move == "F" || move == "E" || move == "P") {
				return move; // Player has selected a valid action
			}
			std::cout << "Enter F, E, P, or Q\n";
		}
	}

	// Let the player select a bucket
	std::string getBucketSelection(const std::string& prompt) {
		std::string bucket;
		// Keep asking until valid bucket entered
		while (true) {
			std::cout << prompt;
			std::cout << "> ";
			std::getline(std::cin, bucket);
			transform(bucket.begin(), bucket.end(), bucket.begin(), ::toupper);

			if (bucket == "QUIT") {
				return "QUIT";
			}

			if (bucket == "8" || bucket == "5" || bucket == "3") {
				return bucket; // Player has selected a valid bucket
			}
		}
	}

	void fillBucket(const std::string& bucket) {
		// Set the amount of water to the max size
		waterInBucket[bucket] = stringToInt(bucket); 
		steps++;
	}

	void emptyBucket(const std::string& bucket) {
		// Set water amount to nothing.
		waterInBucket[bucket] = 0;
		steps++;
	}

	void pourBucket(const std::string& srcBucket) {
		// Let the player select a bucket to pour into
		std::string dstBucket = getBucketSelection("Select a bucket to pour into: 8, 5, or 3\n");
		if (dstBucket == "QUIT") {
			std::cout << "Thanks for playing!\n";
			exit(0);
		}

		// Figure out the amount to pour
		int dstBucketSize = stringToInt(dstBucket);
		int emptySpaceInDst = dstBucketSize - waterInBucket[dstBucket];
		int waterInSrc = waterInBucket[srcBucket];
		int amountToPour = std::min(emptySpaceInDst, waterInSrc);

		waterInBucket[srcBucket] -= amountToPour; // Pour out water from this bucket
		waterInBucket[dstBucket] += amountToPour; // Put the poured out water into the other bucket
		steps++;
	}

public:
	WaterBucketPuzzle() {
		GOAL = 4;
		steps = 0;
		waterInBucket["8"] = 0;
		waterInBucket["5"] = 0;
		waterInBucket["3"] = 0;
	}

	void play() {
		std::cout << "Water Bucket Puzzle\n\n";

		while (true) {
			displayBuckets();

			if (checkWinCondition()) {
				return;
			}

			// Let the player select an action to do with a bucket
			std::cout << "You can:\n";
			std::cout << "  (F)ill the bucket\n";
			std::cout << "  (E)mpty the bucket\n";
			std::cout << "  (P)our one bucket into another\n";
			std::cout << "  (Q)uit\n";

			std::string move = getPlayerMove();
			if (move == "QUIT") {
				std::cout << "Thanks for playing!\n";
				return;
			}

			std::string bucket = getBucketSelection("Select a bucket 8, 5, 3, or QUIT:\n");
			if (bucket == "QUIT") {
				std::cout << "Thanks for playing!\n";
				return;
			}

			// Carry out the selected action
			if (move == "F") {
				fillBucket(bucket);
			}
			else if (move == "E") {
				emptyBucket(bucket);
			}
			else if (move == "P") {
				pourBucket(bucket);
			}
		}
	}
};
