


typedef enum  {FALSE,TRUE} boolean;
//#define TestVAR1 0;
//#define TestVAR2 0;
int** step_Next(int**,int);
void init_Board(int**,int);
//int random_number(int, int);
int random_number(void);
boolean Alive(int**, int,int);
void Start_Game(int ,int);
void free_board(int **, int);