#include <SFML/Graphics.hpp>

using namespace sf;

class Plate : public Drawable{

private:

    RectangleShape shape;
    Vector2f bok={10,80};
    float velocity = 10.f;
    Vector2f plateVelocity={0, velocity};
    Keyboard::Key KeyUP;
    Keyboard::Key KeyDOWN;



public:

    Plate(float x, float y, Keyboard::Key Up, Keyboard::Key Down);
    Plate() = delete;
    ~Plate() = default;

    float left();
    float right();
    float top();
    float bottom();

    Vector2f getPosition();

    FloatRect getGlobalBounds();

    void update();

    void draw(RenderTarget& target, RenderStates state) const override;


};
