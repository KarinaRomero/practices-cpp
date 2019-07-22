
class Player
{
public:
    Player();
    ~Player();

    int GetPositionX();
    int GetPositionY();

    int GetLastPositionX();
    void SetLastPositionX(int newX);

    int GetLastPositionY();
    void SetLastPositionY(int newY);

    void ResetToSafePosition();

    void CallInput();

private:
    int x;
    int y;
    int lastX;
    int lastY;

protected:
};
