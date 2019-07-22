
class Player
{
public:
    Player();
    ~Player();
    int GetPositionX();
    int GetPositionY();
    void CallInput();

private:
    int x;
    int y;

protected:
};
