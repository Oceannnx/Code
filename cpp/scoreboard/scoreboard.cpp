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
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
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
    int player_count,score;
    string name;
    Scoreboard scores;
    cout << "Enter player : " << endl;
    cin >> player_count;
    for(int i=0; i<player_count; i++){
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter score : ";
        cin >> score;
        scores.addScore(name, score);
    }
    scores.showTopScores();
    return 0;
}
