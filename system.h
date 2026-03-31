// defines new type GameState
typedef enum
{
    STATE_MAIN_MENU,
    STATE_MAIN_GAME,
    STATE_SAVES,
    STATE_SETTINGS,
    STATE_PAUSE_MENU,
    STATE_BATTLING,
    STATE_BATTLE_SIM,
} GameState;

typedef enum {
    NORMAL,
    FIRE,
    WATER,
    GRASS,
    DARK,
    ELECTRIC,
    ICE,
    FIGHTING,
    POISON,
    GROUND,
    FLYING,
    PSYCHIC,
    BUG,
    ROCK,
    GHOST,
    DRAGON,
    STEEL,
    FAIRY,
    NUM_TYPES,
} ElementType;

typedef struct
{
    char name[20];
    int max_hp;
    int current_hp;
    int attack_power;
    int level;
    int xp;
    ElementType type;
} Asciimon;


extern float type_chart[NUM_TYPES][NUM_TYPES];


