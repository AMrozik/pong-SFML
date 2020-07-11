#include "Plate.h"

#define MAX_WIDTH 1280
#define MAX_HEIGHT 720
#define MIN_WIDTH 0
#define MIN_HEIGHT 0

using namespace sf;

Plate::Plate(float x, float y, Keyboard::Key Up, Keyboard::Key Down){
    shape.setPosition(x, y);
    shape.setOrigin(5.f, 40.f);
    shape.setFillColor(Color::Blue);
    shape.setSize(Plate::bok);
    this->KeyUP = Up;
    this->KeyDOWN = Down;
}

float Plate::left(){
    return shape.getPosition().x - shape.getOrigin().x;
}
float Plate::right(){
    return shape.getPosition().x + shape.getOrigin().x;
}
float Plate::top(){
    return shape.getPosition().y - shape.getOrigin().y;
}
float Plate::bottom(){
    return shape.getPosition().y + shape.getOrigin().y;
}

void Plate::draw(RenderTarget& target, RenderStates state) const{
    target.draw(this->shape, state);
}

void Plate::update(){
    shape.move(this->plateVelocity);
    if(Keyboard::isKeyPressed(KeyUP) && this->top() > MIN_HEIGHT+20)
        plateVelocity.y = -velocity;
    else if(Keyboard::isKeyPressed(KeyDOWN) && this->bottom() < MAX_HEIGHT-20)
        plateVelocity.y = velocity;
    else
        plateVelocity.y = 0;
}

Vector2f Plate::getPosition(){
    return this->shape.getPosition();
}

FloatRect Plate::getGlobalBounds(){
    return this->shape.getGlobalBounds();
}
