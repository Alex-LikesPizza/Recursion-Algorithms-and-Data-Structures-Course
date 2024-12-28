#pragma once
#define is_down(button_key) input->buttons[button_key].is_down
#define pressed(button_key) (input->buttons[button_key].is_down && input->buttons[button_key].changed)
#define released(button_key) (!input->buttons[button_key].is_down && input->buttons[button_key].changed)

#include <string>
#include <vector>

#include "platform_common.cpp"
#include "utility.cpp"
#include "renderer.cpp"


const float arena_half_sizeX = 85, arena_half_sizeY = 45;
int score1 = 0;
int score2 = 0;
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
    int score{ 0 };

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
    void updatePoz(float dt, std::vector<Player>& collisions){
        x += velX * dt;
        y += velY * dt;
        for (Player& collision : collisions) {
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
                velX = (is_poz == true? -1 : 1) * (abs(velX) + 3.f);
                //velY = 0.30*velY + collision.velY * 0.3f + (collision.x - x) * velY * 0.3f;
                velY = 0.35*velY + collision.velY * 0.5f + (collision.x - x);
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
            score1++;
        }
        else if (x - sizeX < -arena_half_sizeX) {
            reset(1);
            score2++;
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
enum Gamemode {
    GM_MENU,
    GM_GAMEPLAY
};
enum Game_Style {
    GS_EASY,
    GS_MEDIUM,
    GS_HARD,
    GS_2P
};

Gamemode current_gamemode{GM_MENU};
Game_Style current_game_style;

void reset() {
    player1.x = -80;
    player1.y = 0;
    player2.x = 80;
    player2.y = 0;
    ball.velX = 0;
    ball.velY = 0;
    ball.x = 0;
    ball.y = 0;
    current_gamemode = GM_MENU;
    score1 = 0;
    score2 = 0;
}
internal void simulate_game(Input* input, float delta_time){

    if (current_gamemode == GM_MENU) {
        clear_screen(0x333333);
        draw_rect(0, 0, arena_half_sizeX, arena_half_sizeY, 0x555555);
        player1.draw();
        player2.draw();
        if(current_game_style == GS_EASY)
            draw_rect(-15, 5, 6, 6, 0x757575);
        else if(current_game_style == GS_MEDIUM)
            draw_rect(0, 5, 6, 6, 0x757575);
        else if(current_game_style == GS_HARD)
            draw_rect(15, 5, 6, 6, 0x757575);
        else if(current_game_style == GS_2P)
            draw_rect(0, -10, 7, 7, 0x757575);
        draw_rect(-15, 5, 5, 5, 0x00CC22);
        draw_rect(-15, 5, 0.8, 4, 0xAFABAA);

        draw_rect(0, 5, 5, 5, 0xDDDD00);
        draw_rect(-1.5, 5, 0.8, 4, 0xAFABAA);
        draw_rect(1.5, 5, 0.8, 4, 0xAFABAA);

        draw_rect(15, 5, 5, 5, 0xCC2222);
        draw_rect(12, 5, 0.8, 4, 0xAFABAA);
        draw_rect(15, 5, 0.8, 4, 0xAFABAA);
        draw_rect(18, 5, 0.8, 4, 0xAFABAA);

        draw_rect(0, -10, 6, 6, 0xFFAA00);
        draw_rect(-2.8, -6.7, 2, 0.7, 0xAFABAA);// 2
        draw_rect(-0.7, -8.4, 0.7, 2.4, 0xAFABAA);
        draw_rect(-2.8, -10.1, 2, 0.7, 0xAFABAA);
        draw_rect(-4.1, -12, 0.7, 1.9, 0xAFABAA);
        draw_rect(-2.4, -13.2, 2.4, 0.7, 0xAFABAA);

        draw_rect(1.5, -10, 0.7, 4, 0xAFABAA); // P
        draw_rect(2.8, -6.7, 2, 0.7, 0xAFABAA);
        draw_rect(4.1, -8, 0.7, 2, 0xAFABAA);
        draw_rect(2.8, -9.5, 2, 0.7, 0xAFABAA);

        if (pressed(BUTTON_D) || pressed(BUTTON_RIGHT)) {
            current_game_style = Game_Style((current_game_style + 1) % 4);
        }
        if (pressed(BUTTON_A) || pressed(BUTTON_LEFT)) {
            current_game_style = Game_Style((current_game_style - 1) < 0? 3 : (current_game_style - 1));
        }
        if (pressed(BUTTON_W) || pressed(BUTTON_UP)) {
            current_gamemode = GM_GAMEPLAY;
        }
    }

    if(current_gamemode == GM_GAMEPLAY){
        clear_screen(0x333333);
        draw_rect(0, 0, arena_half_sizeX, arena_half_sizeY, 0x555555);

        const float dt = delta_time;
    
        float acc1 = 0;
        if(is_down(BUTTON_W)) acc1 = 2000;
        if(is_down(BUTTON_S)) acc1 = -2000;
        player1.updatePoz(acc1, dt);

        float acc2 = 0;
        if (current_game_style == GS_2P) {
            if (is_down(BUTTON_UP)) acc2 = 2000;
            if (is_down(BUTTON_DOWN)) acc2 = -2000;
        }
        else if (current_game_style == GS_EASY) {
            if (ball.x > 0 && ball.velX > 0) {
                if (ball.y > player2.y + 2.f) acc2 = 700;
                if (ball.y < player2.y - 2.f) acc2 = -700;
            }
        }
        else if (current_game_style == GS_MEDIUM) {
            if (ball.x > 0 && ball.velX > 0) {
                if (ball.y > player2.y + 2.f) acc2 = 950;
                if (ball.y < player2.y - 2.f) acc2 = -950;
            }
        }
        else if (current_game_style == GS_HARD) {
            if (ball.x > 0 && ball.velX > 0) {
                if (ball.y > player2.y + 2.f) acc2 = 1150;
                if (ball.y < player2.y - 2.f) acc2 = -1150;
            }
        }
        player2.updatePoz(acc2, dt);

        if(ball.velX == 0){
            ball.velX = 60.f;
            ball.velY = 60.f * ((std::rand() % 2 == 0) ? 1 : -1);
        }
        std::vector<Player> collisions;
        collisions.push_back(player1);
        collisions.push_back(player2);

        ball.updatePoz(dt, collisions);
        u32 color1 = 0x00FF00;
        if (score1 >= 7) color1 = 0xFFFF00;
        if (score1 >= 12) color1 = 0xFF0000;
        u32 color2 = 0x00FF00;
        if (score2 >= 7) color2 = 0xFFFF00;
        if (score2 >= 12) color2 = 0xFF0000;
        for (int i = 0; i < score1; i++) {
            draw_rect(-arena_half_sizeX + 5 + i * 5, arena_half_sizeY + 2, 1.5, 1.5, color1);
        }
        for (int i = 0; i < score2; i++) {
            draw_rect(arena_half_sizeX - 5 - i * 5, arena_half_sizeY + 2, 1.5, 1.5, color2);
        }
        if (score1 >= 16) reset();
        if (score2 >= 16) reset();
    
        ball.draw();
        player1.draw();
        player2.draw();
    }
}