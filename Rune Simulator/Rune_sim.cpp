// Rune simulator Program
/*
simluates rolling 10,000 runes to see how many quad speed runes I can obtain
Mathematically, since each rune has 4 substats, and each has an equal chance of rolling, the probability of 
a quad roll is (1/4)^4 or 0.25^4 = 1/256. 
I will also be measuring how good the quad roll is. The minimum quad speed roll obtainable is 20, and the maximum is 30.
therefore an average quad should be 25 speed.

Follow up: wonder if the speeds will arrange as a bell curve??
*/
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <random>
#include <iterator>
#include <vector>
using namespace std;

// to store all the different possible stats
vector<string> rune_statnames;

// stores the stats of the runes along with their min/max values in a hashtable format
unordered_map<string, pair<int, int>> rune_vals;

// array to store the actual rune
/*
Array format ([element number] - value):
[0] - Slot
[1] - Main stat
[2] ... [5] - Substats
*/
pair<string, int> rune[6]; 

// function to retrieve the rune values from Rune_stats.txt into an unordered_map for 0(1) time value retrieval
/*
Variables:
infile: the input file to be read
*/
void file_parser(ifstream& infile)
{   
    string statname;    // name of the stat
    int min_val, max_val; // min and max values of the stats

    // iterates through the file and adds the values to the vector and the unordered map
    while (infile >> statname >> min_val >> max_val){
        rune_statnames.push_back(statname);
        rune_vals[statname] = make_pair(min_val, max_val);
    }
}


// maybe try using another hashtable?
// use a string vector to store the stat names, and then use a hashtable to increment them?

// STILL HAVE TO TEST
/*
Function to generate a rune. It randomly picks a slot, and then a main stat with 4 substats. if the rune has a certain
main stat, it cannot have the same as a substat. Also, all the mainstats are stored as 0 for simplicity.
Variables:
length - contains the length of the vector containing the all possible stat names
*/
void rune_generator(int length)
{
    string mainstat; // main stat of the rune
    pair<string, int> stat; // saves each of the 4 substats and the slot/mainstat one after another
    int slot = rand() % 7 + 1; // picks the rune's slot

    pair<string, string> restricted; // restricted substats for certain slots

    // the condition for random to generate correctly
    int val = length - 1;

    // storing the rune slot into the rune array
    stat.first = "slot";
    stat.second = slot;
    rune[0] = stat;

    /*
    Selects the main stat of the rune based on the slot.
    There are certain restricted main stats based on the slots, and restricted tracks those for slots 1,3,5
    for the rest we keep picking until we get a viable one
    */
    switch(slot)
    {
        case 1:
            mainstat = "ATK";
            restricted.first = "DEF";
            restricted.second = "DEF%";
            break;

        case 2:
            // this portion picks the correct possible mainstat for a slot 2 rune. 
            // there is similar code for slots 4 and 6, as they have different restrictions
            while (1){
                // randomly picks the substat
                mainstat = rune_statnames.at(rand() % val);
                if (mainstat == "Accuracy" || mainstat == "Resistance" || mainstat == "CRI_RATE"
                || mainstat == "CRI_DMG")
                    continue;
                else break;
            }
            break;
        
        case 3:
            mainstat = "DEF";
            restricted.first = "ATK";
            restricted.second = "ATK%";
            break;
        
        case 4:
            while (1){
                mainstat = rune_statnames.at(rand() % val);
                if (mainstat == "SPD" || mainstat == "Accuracy" || mainstat == "Resistance")
                    continue;
                else break;
            }
            break;
        
        case 5:
            mainstat = "HP";
            break;
        
        case 6:
            while (1){
                mainstat = rune_statnames.at(rand() % val);
                if (mainstat == "SPD" || mainstat == "CRI_RATE" || mainstat == "CRI_DMG")
                    continue;
                else break;
            }
            cout << "nice\n";
            break;
        
        default:
            cout << "How the hell did this trigger??????\n";
            break;
    }

    // adding the main stat to the rune array
    stat.first = mainstat;
    stat.second = 0;
    rune[1] = stat;

    for (int stat_count = 2; stat_count < 6; stat_count++)
    {
        int val_range;

        // picks a substat, and keeps picking if it selects a restricted substat or the same as the mainstat
        while (1)
        {
            stat.first = rune_statnames.at(rand() % val);
            if (stat.first == restricted.first || stat.first == restricted.second || 
            stat.first == mainstat) continue;
            else break;    
        }

        // picks the value of substat
        val_range = rune_vals[stat.first].first - rune_vals[stat.first].second + 1;
        stat.second = rand() % val_range + rune_vals[stat.first].first;

        // adding the substat to the rune
        rune[stat_count].first = stat.first;
        rune[stat_count].second = stat.second;
    }
    return;
}

int main()
{   
    string filename = "Rune_stats.txt";
    
    /*
    Eventually, over here, add a part that allows people to choose what stat they want to roll, and how many trials of it
    they want
    */

    // the input file
    ifstream input_file;

    // opening the file
    input_file.open(filename);

    // runs the function to read the values from the text file and transfer them to an unordered map
    file_parser(input_file);

    input_file.close();

    // length of the vector containing stat names
    int length = rune_statnames.size();

    // creates a rune
    rune_generator(length); 
 

    return 0;
}