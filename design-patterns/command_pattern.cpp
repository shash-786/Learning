/*
    Command Pattern Example in C++
*/

#include <iostream>
#include <ctime>
#include <vector>
#include <stack>

class Character
{
public:
    std::string name;
    int x, y;
    Character(std::string _name) : name(_name) {}

    void move(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

class command
{
public:
    virtual ~command() {}
    virtual void execute(Character &c) = 0;
    virtual void unexecute(Character &c) = 0;
};

class move : public command
{
private:
    int x, y;

public:
    void execute(Character &c)
    {
        int randomx = rand() % 4;
        int randomy = rand() % 4;
        c.move(randomx, randomy);
        x = randomx;
        y = randomy;
        std::cout << "moved to " << x << "," << y << std::endl;
    }

    void unexecute(Character &c)
    {
        c.move(-x, -y);
        std::cout << "moved back to " << -x << "," << -y << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    std::srand(std::time(0));
    Character *c1 = new Character("Shashank");
    std::stack<command *> commands;

    move *m1 = new move();
    m1->execute(*c1);
    commands.push(m1);

    move *m2 = new move();
    m2->execute(*c1);
    commands.push(m2);

    move *m3 = new move();
    m3->execute(*c1);
    commands.push(m3);

    move *m4 = new move();
    m4->execute(*c1);
    commands.push(m4);

    while (!commands.empty())
    {
        commands.top()->unexecute(*c1);
        commands.pop();
    }

    return 0;
}
