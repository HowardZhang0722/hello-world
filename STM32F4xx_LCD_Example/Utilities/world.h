#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

#include <stdio.h>
#include <math.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct 
{
	int hp;
	uint16_t Xpos;
	uint16_t Ypos;
	int Xd;
	int Yd;
	//void (*move)(uint16_t* x,uint16_t* y, uint16_t dx, uint16_t dy);// size
    
}player_t;

typedef struct 
{
	int hp;
	uint16_t Xpos;
	uint16_t Ypos;
	int Xd;
	int Yd;
	// size
	//void (*move)(uint16_t* x,uint16_t* y, uint16_t dx, uint16_t dy);
	//void (*create)(int* hp, uint16_t* x, uint16_t* y);
}enemy_t;

typedef struct
{
	int hp;
    uint16_t Xpos;
	uint16_t Ypos;
	int Xd;
	int Yd;
	// size
	//void (*move)(uint16_t* x,uint16_t* y, uint16_t dy);
}rock_t;

typedef struct
{
    uint16_t Xpos;
	uint16_t Ypos;
	int Xd;
	int Yd;
	// size
	// type
	// void (*move)(uint16_t* x,uint16_t* y, uint16_t dx, uint16_t dy);
}player_bullet_t;

typedef struct 
{
	uint16_t Xpos;
	uint16_t Ypos;
	int Xd;
	int Yd;
}enemy_bullet_t;

void init_world();
void create_enemy();
void move_enemy();
void create_player();
void move_player();
void create_rock();
void move_rock();
void create_player_bullet();
void move_player_bullet();
void create_enemy_bullet();
void move_enemy_bullet();