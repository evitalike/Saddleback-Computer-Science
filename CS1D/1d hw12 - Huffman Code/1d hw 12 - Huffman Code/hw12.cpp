// ===================================================
// Program: Assignment 12 - Huffman Code
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1D - 5:00 PM M W
// ===================================================
// The purpose of this program is to use Huffman Code compression
// algorithms to compress the Gettysburg Address into a smaller file size than if it were
// in regular ascii text. The Gettysburg Address is loaded, analyzed for frequencies,
// encoded, decoded, and displayed after decoding, and the compression ratios are displayed.
// ===================================================

#include <iostream>
#include "MinHeap.h"
using namespace std;

int main()
{
	cout << "===================================================\n"
		<< "Program: Assignment 12 - Huffman Code\n"
		<< "===================================================\n"
		<< "Programmer: Aaron Geesink\n"
		<< "Class: CS 1D - 5:00 PM M W\n"
		<< "==================================================="
		<< "\nThe purpose of this program is to use Huffman Code compression"
		<< "\nalgorithms to compress the Gettysburg Address into a smaller file size than if it were "
		<< "\nin regular ascii text. The Gettysburg Address is loaded, analyzed for frequencies,"
		<< "\nencoded, decoded, and displayed after decoding, and the compression ratios are displayed."
		<< "\n===================================================\n\n";

	string input = "Four score and seven years ago our fathers brought forth on this continent, a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal. Now we are engaged in a great civil war, testing whether that nation, or any nation so conceived and so dedicated, can long endure. We are met on a great battle - field of that war. We have come to dedicate a portion of that field, as a final resting place for those who here gave their lives that that nation might live. It is altogether fitting and proper that we should do this. But, in a larger sense, we cannot dedicate -- we cannot consecrate -- we cannot hallow-- this ground. The brave men, living and dead, who struggled here, have consecrated it, far above our poor power to add or detract. The world will little note, nor long remember what we say here, but it can never forget what they did here. It is for us the living, rather, to be dedicated here to the unfinished work which they who fought here have thus far so nobly advanced. It is rather for us to be here dedicated to the great task remaining before us -- that from these honored dead we take increased devotion to that cause for which they gave the last full measure of devotion -- that we here highly resolve that these dead shall not have died in vain -- that this nation, under God, shall have a new birth of freedom-- and that government of the people, by the people, for the people, shall not perish from the earth.";
	vector<pair<int, string> > letters;
	bool charExists;
	for (int i = 0; i < input.length(); i++)
	{
		charExists = false;
		for (int j = 0; j < letters.size(); j++)
		{
			if (input.substr(i, 1) == letters[j].second)
			{
				letters[j].first++;
				charExists = true;
				break;
			}
		}
		if (!charExists)
		{
			letters.push_back(make_pair(1, input.substr(i, 1)));
		}
	}

	sort(letters.begin(), letters.end());
	string *arr = new string[letters.size()];
	int *freq = new int[letters.size()];

	cout << "Characters with their Frequencies:\n";
	for (int i = 0; i < letters.size(); i++)
	{
		string *a = new string[2];
		*a = letters[i].second.c_str();
		arr[i] = a[0];
		freq[i] = letters[i].first;
		cout << letters[i].second << ": " << letters[i].first << endl;
	}

	cout << endl;

	string encodedString, decodedString;
	calcFreq(input, input.length());
	HuffmanCodes(input.length());
	cout << "Characters with their Huffman Codes:\n";
	for (auto v = codes.begin(); v != codes.end(); v++)
		cout << v->first << ' ' << v->second << endl;

	for (auto i : input)
		encodedString += codes[i];

	cout << "\nEncoded Huffman data:\n" << encodedString << endl;

	decodedString = decode_file(minHeap.top(), encodedString);
	cout << "\nDecoded Huffman Data:\n" << decodedString << endl;

	cout << "\nCompression ratios:"
		<< "\nGettysburg ASCII size: " << input.size() * 8 << " Bits"
		<< "\nGettysburg encoded compression size: " << encodedString.size() << " Bits\n";
	cout << input.size() * 8 << "/" << encodedString.size() << " = " << input.size() * 8 / float(encodedString.size()) << endl;

	system("pause");
	return 0;
}

// ===================================================