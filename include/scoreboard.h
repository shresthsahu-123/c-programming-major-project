/* scoreboard.h */
#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <stdbool.h>

/* Simple scoreboard structure */
typedef struct {
    int runs;    /* total runs */
    int wickets; /* total wickets */
    int overs;   /* completed overs */
    int balls;   /* balls in current over (0-5) */
    int extras;  /* total extras */
} Scoreboard;

/* Initialize scoreboard to zeros */
void sb_init(Scoreboard *sb);

/* Add runs scored on a legal delivery (0,1,2,3,4,6) */
void sb_add_runs(Scoreboard *sb, int runs);

/* Register a wicket (counts as a legal delivery) */
void sb_add_wicket(Scoreboard *sb);

/* Add extras (wide/no-ball/byes) — does NOT count as a legal delivery */
void sb_add_extra(Scoreboard *sb, int extra_runs);

/* Print the current scoreboard (to stdout) */
void sb_display(const Scoreboard *sb);

#endif /* SCOREBOARD_H */