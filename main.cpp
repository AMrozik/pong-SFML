#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include "Ball.h"
#include "Plate.h"

#define MAX_WIDTH 1280
#define MIN_WIDTH 0
#define MAX_HEIGHT 720
#define MIN_HEIGHT 0

using namespace sf;

template <class T1, class T2> void Collider1(T1& plate, T2& ball){
    if(ball.getGlobalBounds().intersects(plate.getGlobalBounds())){
        if(ball.left() >= 100)
            ball.bounceX();
        else
            ball.bounceY();
    }

    /*if(ball.left() >= plate.right()){
        if(ball.getGlobalBounds().intersects(plate.getGlobalBounds()))
            ball.bounceX();
    }
    else{
        if(ball.getGlobalBounds().intersects(plate.getGlobalBounds()))
            ball.bounceY();
    }*/
}

template <class T1, class T2> void Collider2(T1& plate, T2& ball){
    if(ball.getGlobalBounds().intersects(plate.getGlobalBounds())){
        if(ball.right() <= 1180)
            ball.bounceX();
        else
            ball.bounceY();
    }
}

int main()
{
    RenderWindow window(VideoMode(MAX_WIDTH, MAX_HEIGHT), "SFML works!");
    //window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(30);
    Ball ball(640.f, 360.f);
    Plate player1(100, MAX_HEIGHT/2, Keyboard::Key::W, Keyboard::Key::S);
    Plate player2(MAX_WIDTH - 100, MAX_HEIGHT/2, Keyboard::Key::Up, Keyboard::Key::Down);

    Font font;

    if(!font.loadFromFile("arial.ttf"))
        std::cout << "font load error" << std::endl;

    Text score1("0", font, 100);
    score1.setColor(Color::White);
    score1.setPosition(200, 50);
    score1.setStyle(sf::Text::Bold);

    Text score2("0", font, 100);
    score2.setColor(Color::White);
    score2.setPosition(980, 50);
    score2.setStyle(sf::Text::Bold);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        window.clear(Color::Black);

        player1.update();
        player2.update();
        ball.update();
        Collider1(player1, ball);
        Collider2(player2, ball);
        window.draw(ball);
        window.draw(player1);
        window.draw(player2);
        window.draw(score1);
        window.draw(score2);
        window.display();
    }

    return 0;
}
