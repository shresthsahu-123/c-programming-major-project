#ifndef CRICKET_SCOREBOARD_H
#define CRICKET_SCOREBOARD_H

// If you compile in C++, keep C linkage
#ifdef __cplusplus
extern "C" {
#endif

#define MAX_PLAYERS 15
#define MAX_BOWLERS 10
#define MAX_OVERS   50
#define MAX_WICKETS 10

typedef struct {
    char name[40];
    int runs;
    int balls;
    int fours;
    int sixes;
    int out;          // 0 not out, 1 out
    char how_out[40]; // e.g., "b Bowler", "c Fielder b Bowler", "run out"
} Batter;

typedef struct {
    char name[40];
    int balls_bowled;          // legal balls only
    int runs_conceded;         // includes batsmen runs + wides + no-balls + byes/leg-byes
    int wickets;
    int maidens;
    int over_balls_in_current; // track current over balls for maiden calc
    int runs_in_current_over;
} Bowler;

typedef struct {
    int wides;
    int noballs;
    int byes;
    int legbyes;
    int penalty;
} Extras;

typedef struct {
    int score_at_fall[MAX_WICKETS];
    int wicket_no; // how many fallen
} FallOfWickets;

typedef struct {
    char batting_team[40];
    char bowling_team[40];
    int players_per_side; // usually 11
    int max_overs;        // e.g., 20/50; 0 for unlimited
    Batter batters[MAX_PLAYERS];
    Bowler bowlers[MAX_BOWLERS];
    int num_bowlers;
    int striker;          // index of current striker
    int non_striker;      // index of current non-striker
    int next_batter_idx;  // next unused batter index
    int current_bowler;   // index in bowlers[]
    int total_runs;
    int wickets;
    int legal_balls;      // total legal balls bowled
    Extras extras;
    FallOfWickets fow;
    int partnership_runs; // current stand runs
    int last_wicket_stand;// previous partnership runs
} Innings;



void swap(int *a, int *b);
void print_overs_balls(int legal_balls);
int  innings_complete(Innings *inn);
void start_innings(Innings *inn);
void end_of_over_rotate(Innings *inn);
void record_boundary(Batter *bt, int runs);
void show_score(Innings *inn);
void wicket_falls(Innings *inn, const char *how_out);
void ball_menu(void);
void process_legal_runs(Innings *inn, int runs);
void process_wide(Innings *inn, int wide_runs);
void process_noball_with_bat_runs(Innings *inn, int bat_runs);
void process_byes(Innings *inn, int runs, int is_legbye);
void process_penalty(Innings *inn, int runs);
void main_loop(Innings *inn);

#ifdef __cplusplus
}
#endif

#endif // CRICKET_SCOREBOARD_H