
#include <iostream>
#include <algorithm>
#include <random>


using namespace std;

const int DECK_SIZE = 52;
const int HAND_SIZE = 10;
 int NUM_TRIALS = 10000;

// Function to initialize a deck of cards
void initializeDeck(int deck[]) {
    for (int i = 0; i < DECK_SIZE; ++i) {
        deck[i] = i;
    }
}

void shuffleDeck(int deck[]) {
    random_device rd;
    default_random_engine rng(rd());
    shuffle(deck, deck + DECK_SIZE, rng);
}

// Function to draw 10 cards from the deck
void drawCards(int deck[], int hand[]) {
    // Select the first 10 cards
    for (int i = 0; i < HAND_SIZE; ++i) {
        hand[i] = deck[i];
    }
}


void printDeck(int deck[]){
    for (int i = 0; i < DECK_SIZE; i++){
        cout << deck[i] << " ";
    }
}

void printHand(int hand[]){
    for (int i = 0; i < HAND_SIZE; i++){
        cout << hand[i] << " ";
    }
}

void printHandSuits(int hand[]){
    for (int i = 0; i < HAND_SIZE; i++){
        cout << hand[i] / 13 << " ";
    }
}

// Function to count cards of each suit
void countSuits(const int hand[], int suitCounts[]) {
    fill(suitCounts, suitCounts + 4, 0); // Initialize counts to 0
    
    for (int i = 0; i < HAND_SIZE; ++i) {
        int suit = hand[i] / 13;  // Determine suit (0: Hearts, 1: Diamonds, 2: Clubs, 3: Spades)
        ++suitCounts[suit];
    }
}

// Function to check if at least one suit has at least 5 cards
bool hasAtLeastFiveOfSameSuit(const int suitCounts[]) {
    for (int i = 0; i < 4; ++i) {
        if (suitCounts[i] >= 5) {
            return true;
        }
    }
    return false;
}

int main() {
    system("clear");
    int deck[DECK_SIZE];
    int hand[HAND_SIZE];
    int suitCounts[4];
    int successfulTrials = 0;

    cout << "How many trials would you like to run?" << endl << "Number of trials: ";
    cin >> NUM_TRIALS;


    for (int i = 0; i < NUM_TRIALS; ++i) {
        initializeDeck(deck);
        //printDeck(deck);
        // cout << endl;
        shuffleDeck(deck);
        //printDeck(deck);
        //cout << endl;
        drawCards(deck, hand);
        //printHand(hand);
        //cout << endl;
        //printHandSuits(hand);
        //cout << endl;
        countSuits(hand, suitCounts);

        if (hasAtLeastFiveOfSameSuit(suitCounts)) {
            ++successfulTrials;
        }
    }


    double probability;
    probability = static_cast<double>(successfulTrials) / NUM_TRIALS;

    cout << "Successful trials: " << successfulTrials << ", Number of trials: " << NUM_TRIALS << endl;
    
    
    cout << "Estimated probability: " << probability << endl; // output estimated probability

    return 0;
}
