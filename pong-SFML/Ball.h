#include <SFML/Graphics.hpp>

using namespace sf;

class Ball : public Drawable{

public:
    Ball(float x, float y);
    Ball() = delete;
    ~Ball() = default;

    void draw(RenderTarget& target, RenderStates state) const override;

    Vector2f getPosition();

    void update();

    float left();
    float right();
    float top();
    float bottom();

    FloatRect getGlobalBounds();

    void bounceX();
    void bounceY();

private:
    CircleShape shape;
    const float ballRadius = 10.0f;
    float ballVelocity = 4.0f;
    Vector2f velocity {ballVelocity, ballVelocity};
};


