/*
  7. import sys
  8.
  9.
 17.
 18. while True:  # Main game loop.

 60.
 61.     # Check if any of the buckets has the goal amount of water:
 62.     for waterAmount in waterInBucket.values():
 63.         if waterAmount == GOAL:
 64.             print('Good job! You solved it in', steps, 'steps!')
 65.             sys.exit()
 66.
 67.     # Let the player select an action to do with a bucket:
 68.     print('You can:')
 69.     print('  (F)ill the bucket')
 70.     print('  (E)mpty the bucket')
 71.     print('  (P)our one bucket into another')
 72.     print('  (Q)uit')
 73.
 74.     while True:  # Keep asking until the player enters a valid action.
 75.         move = input('> ').upper()
 76.         if move == 'QUIT' or move == 'Q':
 77.             print('Thanks for playing!')
 78.             sys.exit()
 79.
 80.         if move in ('F', 'E', 'P'):
 81.             break  # Player has selected a valid action.
 82.         print('Enter F, E, P, or Q')
 83.
 84.     # Let the player select a bucket:
 85.     while True:  # Keep asking until valid bucket entered.
 86.         print('Select a bucket 8, 5, 3, or QUIT:')
 87.         srcBucket = input('> ').upper()
 88.
 89.         if srcBucket == 'QUIT':
 90.             print('Thanks for playing!')
 91.             sys.exit()
 92.
 93.         if srcBucket in ('8', '5', '3'):
 94.             break  # Player has selected a valid bucket.
 95.
 96.     # Carry out the selected action:
 97.     if move == 'F':
 98.         # Set the amount of water to the max size.
 99.         srcBucketSize = int(srcBucket)
100.         waterInBucket[srcBucket] = srcBucketSize
101.         steps += 1
102.
103.     elif move == 'E':
104.         waterInBucket[srcBucket] = 0  # Set water amount to nothing.
105.         steps += 1
106.
107.     elif move == 'P':
108.         # Let the player select a bucket to pour into:
109.         while True:  # Keep asking until valid bucket entered.
110.             print('Select a bucket to pour into: 8, 5, or 3')
111.             dstBucket = input('> ').upper()
112.             if dstBucket in ('8', '5', '3'):
113.                 break  # Player has selected a valid bucket.
114.
115.         # Figure out the amount to pour:
116.         dstBucketSize = int(dstBucket)
117.         emptySpaceInDstBucket = dstBucketSize - waterInBucket[dstBucket]
118.         waterInSrcBucket = waterInBucket[srcBucket]
119.         amountToPour = min(emptySpaceInDstBucket, waterInSrcBucket)
120.
121.         # Pour out water from this bucket:
122.         waterInBucket[srcBucket] -= amountToPour
123.
124.         # Put the poured out water into the other bucket:
125.         waterInBucket[dstBucket] += amountToPour
126.         steps += 1
127.
128.     elif move == 'C':
129.         pass  # If the player selected Cancel, do nothing.
*/


#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	cout << "Water Bucket Puzzle\n\n";
	int GOAL = 4; // The exact amount of water to have in a bucket to win.
	int steps = 0; // Keep track of how many steps the player made to solve this.
	// The amount of water in each bucket:
	map <char, int> waterInBucket;
	waterInBucket['8'] = 0;
	waterInBucket['5'] = 0;
	waterInBucket['3'] = 0;
	while (true) {
		// Display the current state of the buckets:
		cout << "Try to get " << GOAL << "L of water into one of these\n";
		cout << "buckets:\n";

		vector <string> waterDisplay; // Contains strings for water or empty space.
		// Get the strings for the 8L bucket:
		for (int i = 1; i < 9; ++i) {
			if (waterInBucket['8'] < i) {
				waterDisplay.push_back("      "); // Add empty space.
			} else {
				waterDisplay.push_back("WWWWWW"); // Add water.
			}
		}

		// Get the strings for the 5L bucket:
		for (int i = 1; i < 6; ++i) {
			if (waterInBucket['5'] < i) {
				waterDisplay.push_back("      "); // Add empty space.
			}
			else {
				waterDisplay.push_back("WWWWWW"); // Add water.
			}
		}

		// Get the strings for the 3L bucket:
		for (int i = 1; i < 4; ++i) {
			if (waterInBucket['3'] < i) {
				waterDisplay.push_back("      "); // Add empty space.
			}
			else {
				waterDisplay.push_back("WWWWWW"); // Add water.
			}
		}

		// Display the buckets with the amount of water in each one:
		cout << "8|" << waterDisplay[7] << "|\n";
		cout << "7|" << waterDisplay[6] << "|\n";
		cout << "6|" << waterDisplay[5] << "|\n";
		cout << "5|" << waterDisplay[4] << "|  5|" << waterDisplay[12] << "|\n";
		cout << "4|" << waterDisplay[3] << "|  4|" << waterDisplay[11] << "|\n";
		cout << "3|" << waterDisplay[2] << "|  3|" << waterDisplay[10] << "|  3|" << waterDisplay[15] << "|\n";
		cout << "2|" << waterDisplay[1] << "|  2|" << waterDisplay[9] << "|  2|" << waterDisplay[14] << "|\n";
		cout << "1|" << waterDisplay[0] << "|  1|" << waterDisplay[8] << "|  1|" << waterDisplay[13] << "|\n";
		cout << " +------+   +------+   +------+\n";
		cout << "    8L         5L         3L\n";




		break; ///////////////
	}

	return 0;
}