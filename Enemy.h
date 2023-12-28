
#include "GameField.h"
#include "PlayerMovement.h"


template<typename MovementScheme, typename InteractionScheme>
class Enemy {
public:
    Enemy(GameField* mField = nullptr, PlayerMovement* pmovement = nullptr, int mx = 3, int my = 0);
    void Move();
    void Interact();
    int getCoordX();
    int getCoordY();
    void setCoord(int newX, int newY);
    GameField& getField();
    PlayerMovement& getMovement();
    void printQ();

private:
    GameField* field;
    PlayerMovement* movement;
    int x, y;

};

template<typename MovementScheme, typename InteractionScheme>
inline Enemy<MovementScheme, InteractionScheme>::Enemy(GameField* mField, PlayerMovement* pmovement, int mx, int my )
{
    /*if (mField == nullptr || pmovement == nullptr) {
        throw "Error in class Enemy";
    }*/
    field = mField;
    movement = pmovement;
    x = mx;
    y = my;
}

template<typename MovementScheme, typename InteractionScheme>
void Enemy<MovementScheme, InteractionScheme>::Move() {
    MovementScheme::Move(*this);
}

template<typename MovementScheme, typename InteractionScheme>
void Enemy<MovementScheme, InteractionScheme>::Interact() {
    InteractionScheme::Interact(*this);
}

template<typename MovementScheme, typename InteractionScheme>
int Enemy<MovementScheme, InteractionScheme>::getCoordX()
{
    return x;
}

template<typename MovementScheme, typename InteractionScheme>
int Enemy<MovementScheme, InteractionScheme>::getCoordY()
{
    return y;
}

template<typename MovementScheme, typename InteractionScheme>
void Enemy<MovementScheme, InteractionScheme>::setCoord(int newX, int newY)
{
    x = newX;
    y = newY;
}

template<typename MovementScheme, typename InteractionScheme>
GameField& Enemy<MovementScheme, InteractionScheme>::getField()
{
    return *field;
}



template<typename MovementScheme, typename InteractionScheme>
PlayerMovement& Enemy<MovementScheme, InteractionScheme>::getMovement()
{
    return *movement;
}

template<typename MovementScheme, typename InteractionScheme>
void Enemy<MovementScheme, InteractionScheme>::printQ()
{
    std::cout << "X: " << x << "\nY:" << y;
}
