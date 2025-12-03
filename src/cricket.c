#include <stdio.h>
#include <string.h>

int main() {
    // Simple score trackers
    int team1_runs = 0, team1_wickets = 0, balls = 0;
    int team2_runs = 0, team2_wickets = 0;
    
    char striker[20] = "Rohit", non_striker[20] = "Gill";
    char bowler[20] = "Starc";
    
    printf("🏏 LIVE CRICKET SCOREBOARD 🏏\n");
    printf("==========================\n\n");
    
    // === INNINGS 1: Team1 Bats ===
    printf("📝 INNINGS 1 - Team1 Batting\n");
    printf("Enter 0-6 for runs, 7 for wicket\n\n");
    
    while(team1_wickets < 3 && balls < 24) {  // 4 overs demo
        // Show current score
        printf("Team1: %d/%d (%.1f ov)\n", team1_runs, team1_wickets, balls/6.0);
        printf("Striker: %s  |  Non-striker: %s\n", striker, non_striker);
        printf("Bowler: %s\n\n", bowler);
        
        // Get next ball result
        int runs;
        printf("Next ball? ");
        scanf("%d", &runs);
        
        if(runs == 7) {
            // Wicket!
            team1_wickets++;
            printf("👋 WICKET! New batsman? ");
            scanf("%s", striker);
        } else {
            // Runs scored
            team1_runs += runs;
            printf("%s scores %d!\n", striker, runs);
            
            // Rotate strike for odd runs
            if(runs % 2 == 1) {
                printf("Strike rotates!\n");
                char temp[20];
                strcpy(temp, striker);
                strcpy(striker, non_striker);
                strcpy(non_striker, temp);
            }
        }
        
        balls++;
        printf("\n");
    }
    
    // === INNINGS 2: Team2 Chases ===
    printf("🏁 INNINGS 1 END: Team1 %d/%d\n", team1_runs, team1_wickets);
    printf("🎯 Team2 needs %d to win\n\n", team1_runs + 1);
    
    balls = 0;  // Reset balls
    strcpy(striker, "Kohli"); strcpy(non_striker, "Jadeja");
    
    printf("📝 INNINGS 2 - Team2 Chasing\n");
    while(team2_wickets < 3 && team2_runs < team1_runs + 1 && balls < 24) {
        printf("Team2: %d/%d (%.1f ov)  Need: %d\n", 
               team2_runs, team2_wickets, balls/6.0, team1_runs + 1 - team2_runs);
        printf("Striker: %s  |  Non-striker: %s\n\n", striker, non_striker);
        
        int runs;
        printf("Next ball? ");
        scanf("%d", &runs);
        
        if(runs == 7) {
            team2_wickets++;
            printf("New batsman? ");
            scanf("%s", striker);
        } else {
            team2_runs += runs;
            if(runs % 2 == 1) {
                char temp[20];
                strcpy(temp, striker);
                strcpy(striker, non_striker);
                strcpy(non_striker, temp);
            }
        }
        balls++;
    }
    
    // Final Result
    printf("\n🏆 MATCH OVER! 🏆\n");
    printf("Team1: %d/%d\n", team1_runs, team1_wickets);
    printf("Team2: %d/%d\n", team2_runs, team2_wickets);
    
    if(team1_runs > team2_runs) {
        printf("🎉 Team1 WINS by %d runs!\n", team1_runs - team2_runs);
    } else {
        printf("🎉 Team2 WINS by %d wickets!\n", 3 - team2_wickets);
    }
    
    return 0;
}
