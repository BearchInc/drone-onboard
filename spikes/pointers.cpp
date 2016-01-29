#include <string>
#include <iostream>
#include <functional>

using namespace std;

class message
{
public:
    string content;
    message(string content) : content(content) {}
};

typedef function<void(message*)> OnGreetingsHandler;

class Brain
{
public:
    OnGreetingsHandler OnGreetings;
};

int main(int argc, char **argv)
{
    string droneName = "R2D2";
    message* m = new message("Well hello there!");

    Brain brain;

    brain.OnGreetings = [droneName](message* m) {
        cout << m->content << " " << droneName << endl;
    };

    brain.OnGreetings(m);
}
