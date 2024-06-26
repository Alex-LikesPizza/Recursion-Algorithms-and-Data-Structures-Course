#pragma once
#define is_down(button_key) input->buttons[button_key].is_down
#define pressed(button_key) (input->buttons[button_key].is_down && input->buttons[button_key].changed)
#define released(button_key) (!input->buttons[button_key].is_down && input->buttons[button_key].changed)

#include <string>
#include <vector>

#include "platform_common.cpp"
#include "utility.cpp"


const float arena_half_sizeX = 85, arena_half_sizeY = 45;
class Entity{
public: 
    float x;
    float y;
    float velX {0};
    float velY {0};
    float sizeX;
    float sizeY;
    std::string name;
    void set(float x, float y){
        this->x = x;
        this->y = y;
    };
    void addX(float x){this->x += x;}
    void addY(float y){this->y += y;}
    void add(float x, float y){addX(x); addY(y);};

    Entity(std::string name, float x, float y, float sizeX, float sizeY) : name(name), x(x), y(y), sizeX(sizeX), sizeY(sizeY){};

    Entity(std::string name) : Entity(name, 0, 0, 0, 0){};
};

class Player : public Entity{
    using Entity::Entity;
public:
    void addX(float x) = delete;
    void add(float x, float y) = delete;
    
    void draw() {
        draw_rect(x, y, sizeX, sizeY, 0xFFAA00);
    }
    void updatePoz(int acc, float dt) {
        acc -= velY * 14.f;
        y = y + velY*dt + acc*dt*dt * 0.5f;
        velY = velY + acc*dt; 

        if(y + sizeY > arena_half_sizeY){
            y = arena_half_sizeY - sizeY;
            velY = 0;
        }
        if (y - sizeY < -arena_half_sizeY) {
            y = -arena_half_sizeY + sizeY;
            velY = 0;
        }
    }
};
class Ball : public Entity {
    using Entity::Entity;
public:
    void updatePoz(float dt, std::vector<Entity>& collisions){
        x += velX * dt;
        y += velY * dt;
        for (Entity& collision : collisions) {
            bool collisionX = collision.x - collision.sizeX < x + sizeX &&
                              collision.x + collision.sizeX > x - sizeX;
            bool collisionY = collision.y - collision.sizeY < y + sizeY &&
                              collision.y + collision.sizeY > y - sizeY;
            if (collisionX && collisionY) {
                if (x < collision.x)
                    x = collision.x - collision.sizeX - sizeX;
                else 
                    x = collision.x + collision.sizeX + sizeX;
                bool is_poz = velX > 0;
                velX = (is_poz == true? -1 : 1) * (abs(velX) + 2.f);
                velY = 0.25*velY + collision.velY * 0.5f;
            }
        }
        if(y + sizeY > arena_half_sizeY){
            y = arena_half_sizeY - sizeY;
            velY *= -1;
        }
        else if (y - sizeY < -arena_half_sizeY) {
            y = -arena_half_sizeY + sizeY;
            velY *= -1;
        }
        if (x + sizeX > arena_half_sizeX) {
            reset(2);
        }
        else if (x - sizeX < -arena_half_sizeX) {
            reset(1);
        }
    }
    void reset(int losing_player) {
        y = 0;
        x = 0;
        
        velY = 50.f * ((std::rand() % 2 == 0) ? 1 : -1);

        if (losing_player == 1)
            velX = 50.f;
        else velX = -50.f;

    }
    void draw(){
        draw_rect(x, y, sizeX, sizeY, 0xAAAAFF);
    }
};

Player player1("Player 1", -80, 0, 2, 10);
Player player2("Player 2", 80, 0, 2, 10);
Ball ball("Ball", 0, 0, 1.5, 1.5);

internal void simulate_game(Input* input, float delta_time){
    const float dt = delta_time;

    clear_screen(0x333333);
    draw_rect(0, 0, arena_half_sizeX, arena_half_sizeY, 0x555555);
    
    float acc1 = 0;
    if(is_down(BUTTON_W)) acc1 = 2000;
    if(is_down(BUTTON_S)) acc1 = -2000;
    player1.updatePoz(acc1, dt);

    float acc2 = 0;
    if (is_down(BUTTON_UP)) acc2 = 2000;
    if (is_down(BUTTON_DOWN)) acc2 = -2000;
    player2.updatePoz(acc2, dt);

    if(ball.velX == 0){
        ball.velX = 50.f;
        ball.velY = 50.f * ((std::rand() % 2 == 0) ? 1 : -1);
    }
    std::vector<Entity> collisions;
    collisions.push_back(player1);
    collisions.push_back(player2);

    ball.updatePoz(dt, collisions);
    ball.draw();
    
    
    player1.draw();
    player2.draw();
    
}