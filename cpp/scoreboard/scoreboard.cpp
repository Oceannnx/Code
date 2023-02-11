#include <iostream>
#include <algorithm>
#include <iomanip> 
using namespace std;

struct Score {
    string name;
    int score;
};

struct node {
    Score data;
    node *next;
    node *prev;
};
class Scoreboard {
private:
    node *head, *tail;
public:
    Scoreboard() {
        head = NULL;
        tail = NULL;
    }

    void addScore(string name, int score) {
        node *temp = new node;
        temp->data.name = name;
        temp->data.score = score;
        temp->next = NULL;
        temp->prev = tail;
        if (head == NULL) {
            head = temp;
        } else {
            tail->next = temp;
        }
        tail = temp;
    }

    void showTopScores() {
        node *temp = new node;
        temp = head;
        Score scores[100];
        int count = 0;
        while (temp != NULL) {
            scores[count].name = temp->data.name;
            scores[count].score = temp->data.score;
            temp = temp->next;
            count++;
        }
        sort(scores, scores + count, [](const Score &a, const Score &b) {
            return a.score > b.score;
        });
        int n = min(count, 3);
        cout << "Top " << n << " scores:" << endl;
        for (int i = 0; i < n; i++) {
            cout << setw(10) << left << scores[i].name << ": " << scores[i].score << endl;
        }
    }
};

int main() {
    int score, choise;
    string name;
    Scoreboard scores;
    scores.addScore("Ono",100);
    scores.addScore("Louis",120);
    scores.addScore("Bibi",95);
    scores.showTopScores();
    while(true){
        cout << "Enter 1 to add score" << endl << "Enter 2 to Show score" << endl << "Enter -1 to quit : ";
        cin >> choise;
        if(choise == -1){
            break;
        }
        else if (choise == 1){
            cout << "Enter name : ";
            cin >> name;
            cout << "Enter score : ";
            cin >> score;
            scores.addScore(name,score);
        }
        else if (choise == 2){
            scores.showTopScores();
        }
    }
    return 0;
}

/// Santijit Kamnak 65090500457