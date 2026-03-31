//game-loop
void init_map();
void player_location();
//void road_location();
void build_city();
void draw_map();

extern int player_r;
extern int player_c;

//creates and controls the map size
#define MAP_RVERT 30
#define MAP_CHORI 60

//extern char world_map;
extern char world_map[MAP_RVERT][MAP_CHORI];