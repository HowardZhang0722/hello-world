/* global int eb_nw = 0;
#define PBULLET_XD
#define PBULLET_YD
#define EBULLET_XD
#define EBULLET_YD
MAX_PBULLET
MAX_EBULLET
MAX_ROCK
valid
pb_nw
eb_nw
rock_nw

*/
void create_player_bullet(){
	pb_nw += 1;
	if (pb_nw == MAX_PBULLET)
		pb_nw = 0;
	while(player_bullet[pb_nw].valid == 1){
		pb_nw += 1;
		if (pb_nw == MAX_PBULLET)
			pb_nw = 0;
	}

	player_bullet[pb_nw].Xpos = player.Xpos;//init
	player_bullet[pb_nw].Ypos = player.Ypos;
	player_bullet[pb_nw].Xd = PBULLET_XD;
	player_bullet[pb_nw].Yd = PBULLET_YD;
	player_bullet[pb_nw].valid = 1;
	player_bullet[pb_nw].rmv = 0;
	player_bullet[pb_nw].size = BULLET_SIZE;


	
}


void move_player_bullet(){
	for (int i = 0; i < MAX_PBULLET; ++i)
	{
		int next_x,next_y;
		next_x = player_bullet[i].Xpos + player_bullet[i].Xd;
		next_y = player_bullet[i].Ypos + player_bullet[i].Yd;
		// player bullet run into edges?
		if (next_x >= WIDTH || next_x < 0 || next_y >= HEIGHT || next_y < 0)
		{
			player_bullet[i].rmv = 1;
			return
		}

		// player bullet run into rocks?
		for (int j = 0; j < MAX_ROCK; ++j)
		{
			if (if_crash(next_x, next_y,rock[j].Xpos + rock[j].Xd, rock[j].Ypos+ rock[j].Yd, player_bullet[i].size + rock[j].size))
			{
				player_bullet[i].rmv = 1;
				return;
			}
		}

		// player bullet run into enemy planes?
		for (int j = 0; j < MAX_ENEMY; ++j)
		{
			if (if_crash(next_x, next_y,enemy[j].Xpos + enemy[j].Xd, enemy[j].Ypos+ enemy[j].Yd, player_bullet[i].size + enemy[j].size))
			{
				player_bullet[i].rmv = 1;
				return;
			}
		}
	}
}

void player_bullet_edge_detect(player_bullet_t *a ){
	int next_x,next_y;
	next_x = a->Xpos + a->Xd;
	next_y = a->Ypos + a->Yd;
	// player bullet run into edges?
	if (next_x >= WIDTH || next_x < 0 || next_y >= HEIGHT || next_y < 0)
	{
		a->valid = 0;
		return
	}
}

void enemy_bullet_edge_detect(enemy_bullet_t *a ){
	int next_x,next_y;
	next_x = a->Xpos + a->Xd;
	next_y = a->Ypos + a->Yd;
	// enemy bullet run into edges?
	if (next_x >= WIDTH || next_x < 0 || next_y >= HEIGHT || next_y < 0)
	{
		a->valid = 0;
		return
	}
}


int if_crash(int a_x,int a_y,int b_x,int b_y,int distance){
	int x = a_x - b_x, y = a_y - b_y;
	if(x*x+y*y > distance*distance)
		return 0;
	else
		return 1;
}



void create_enemy_bullet(uint16_t curr_enemy){//enemy shot 3 bullets once
	eb_nw += 1;
	if (eb_nw == MAX_PBULLET)
		eb_nw = 0;
	while(enemy_bullet[eb_nw].valid == 1){
		eb_nw += 1;
		if (eb_nw == MAX_PBULLET)
			eb_nw = 0;
	}
	enemy_bullet[eb_nw].Xpos = enemy[curr_enemy].Xpos;
	enemy_bullet[eb_nw].Ypos = enemy[curr_enemy].Ypos;
	enemy_bullet[eb_nw].Xd = EBULLET_XD;
	enemy_bullet[eb_nw].Yd = EBULLET_YD;
	enemy_bullet[eb_nw].valid = 1;
	enemy_bullet[eb_nw].rmv = 0;
	enemy_bullet[eb_nw].size = BULLET_SIZE;

	eb_nw += 1;
	if (eb_nw == MAX_PBULLET)
		eb_nw = 0;
	while(enemy_bullet[eb_nw].valid == 1){
		eb_nw += 1;
		if (eb_nw == MAX_PBULLET)
			eb_nw = 0;
	}
	enemy_bullet[eb_nw].Xpos = enemy[curr_enemy].Xpos;
	enemy_bullet[eb_nw].Ypos = enemy[curr_enemy].Ypos;
	enemy_bullet[eb_nw].Xd = EBULLET_XD;
	enemy_bullet[eb_nw].Yd = EBULLET_YD;
	enemy_bullet[eb_nw].valid = 1;
	enemy_bullet[eb_nw].rmv = 0;
	enemy_bullet[eb_nw].size = BULLET_SIZE;

	eb_nw += 1;
	if (eb_nw == MAX_PBULLET)
		eb_nw = 0;
	while(enemy_bullet[eb_nw].valid == 1){
		eb_nw += 1;
		if (eb_nw == MAX_PBULLET)
			eb_nw = 0;
	}
	enemy_bullet[eb_nw].Xpos = enemy[curr_enemy].Xpos;
	enemy_bullet[eb_nw].Ypos = enemy[curr_enemy].Ypos;
	enemy_bullet[eb_nw].Xd = EBULLET_XD;
	enemy_bullet[eb_nw].Yd = EBULLET_YD;
	enemy_bullet[eb_nw].valid = 1;
	enemy_bullet[eb_nw].rmv = 0;
	enemy_bullet[eb_nw].size = BULLET_SIZE;
}


void move_enemy_bullet(){
	for (int i = 0; i < MAX_EBULLET; ++i)
	{
		int next_x,next_y;
		next_x = enemy_bullet[i].Xpos + enemy_bullet[i].Xd;
		next_y = enemy_bullet[i].Ypos + enemy_bullet[i].Yd;

		// enemy bullet run into edges?
		if (next_x >= WIDTH || next_x < 0 || next_y >= HEIGHT || next_y < 0)
		{
			enemy_bullet[i].rmv = 1;
			return
		}
		// enemy bullet run into rocks?
		for (int j = 0; j < MAX_ROCK; ++j)
		{
			if (if_crash(next_x, next_y,rock[j].Xpos+ rock[j].Xd, rock[j].Ypos+ rock[j].Yd, enemy_bullet[i].size + rock[j].size))
			{
				enemy_bullet[i].rmv = 1;
				return;
			}
		}

		// enemy bullet run into player planes?
		for (int j = 0; j < MAX_PLAYER; ++j)
		{
			if (if_crash(next_x, next_y,player[j].Xpos+ player[j].Xd, player[j].Ypos+ player[j].Yd, enemy_bullet[i].size + player[j].size))
			{
				enemy_bullet[i].rmv = 1;
				return;
			}
		}

		
	}
}

void create_rock(){
	rock_nw += 1;
	if (rock_nw == MAX_ROCK)
		rock_nw = 0;
	while(rock[rock_nw].valid == 1){
		rock_nw += 1;
		if (rock_nw == MAX_ROCK)
			rock_nw = 0;
	}
	rock[rock_nw].Xpos = ROCK_X;
	rock[rock_nw].Ypos = ROCK_Y;
	rock[rock_nw].Xd = ROCK_XD;
	rock[rock_nw].Yd = ROCK_YD;
	rock[rock_nw].valid = 1;
	rock[rock_nw].rmv = 0;
	rock[rock_nw].size = ROCK_SIZE;
}

void move_rock(){
	for (int i = 0; i < MAX_ROCK; ++i)
	{
		int next_x,next_y;
		next_x = rock[i].Xpos + rock[i].Xd;
		next_y = rock[i].Ypos + rock[i].Yd;
		// rock run into edges?
		if (next_x >= WIDTH || next_x < 0 || next_y >= HEIGHT || next_y < 0)
		{
			rock[i].rmv = 1;
			return
		}
	}
}

void rock_edge_detect(rock_t *a ){
	int next_x,next_y;
	next_x = a->Xpos + a->Xd;
	next_y = a->Ypos + a->Yd;
	// player bullet run into edges?
	if (next_x >= WIDTH || next_x < 0 || next_y >= HEIGHT || next_y < 0)
	{
		a->valid = 0;
		return
	}
}