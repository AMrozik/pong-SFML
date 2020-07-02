#include "Ball.h"
#include <iostream>

#define MAX_WIDTH 1280
#define MIN_WIDTH 0
#define MAX_HEIGHT 720
#define MIN_HEIGHT 0

using namespace sf;

Ball::Ball(float x, float y){
    shape.setPosition(x, y);
    shape.setRadius(this->ballRadius);
    shape.setFillColor(Color::Red);
    shape.setOrigin(this->ballRadius, this->ballRadius);
}

void Ball::draw(RenderTarget& target, RenderStates state) const{
    target.draw(this->shape, state);
}

float Ball::left(){
    return shape.getPosition().x - shape.getRadius();
}
float Ball::right(){
    return shape.getPosition().x + shape.getRadius();
}
float Ball::top(){
    return shape.getPosition().y - shape.getRadius();
}
float Ball::bottom(){
    return shape.getPosition().y + shape.getRadius();
}

void Ball::update(){

    shape.move(this->velocity);

    if(this->left() <= MIN_WIDTH){
        this->velocity.x = -velocity.x;
    }
    else if(this->right() >= MAX_WIDTH){
        this->velocity.x = -velocity.x;
    }

    if(this->top() <= MIN_HEIGHT){
        this->velocity.y = -velocity.y;
    }
    else if(this->bottom() >= MAX_HEIGHT){
        this->velocity.y = -velocity.y;
    }
}

void Ball::bounceX(){
    this->velocity.x*=(-1);
}

void Ball::bounceY(){
    this->velocity.y*=(-1);
}

Vector2f Ball::getPosition(){
    return this->shape.getPosition();
}

FloatRect Ball::getGlobalBounds(){
    return this->shape.getGlobalBounds();
}
