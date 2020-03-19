#ifndef __PLAYER_ONE__H
#define __PLAYER_ONE__H 

#include "enviro.h"
#include "styles.h"

using namespace enviro;

// PlayerOne Controller class. Uses arrow keys for control
class PlayerOneController : public Process, public AgentInterface {

  public:
  PlayerOneController() : Process(), AgentInterface(), v(0), omega(0) {}
  // Initialize PlayerOneController. Arrow keys control movement
  // Also watches for when PlayerOne scores and updates the label with the score
  // and teleports to starting position. Also teleports to the starting position
  // when "Reset" button is pressed
  void init() {
    watch("keydown", [&](Event &e) {
        auto k = e.value()["key"].get<std::string>();
        if ( k == "ArrowUp" ) {
              v = v_m;              
        } else if ( k == "ArrowDown" ) {
              v = -v_m;  
        } else if ( k == "ArrowLeft" ) {
              omega = -omega_m;
        } else if ( k == "ArrowRight" ) {
              omega = omega_m;
        } 
    });        
    watch("keyup", [&](Event &e) {
        auto k = e.value()["key"].get<std::string>();
        if ( k == "ArrowUp" || k == "ArrowDown" ) {
              v = 0;               
        } else if ( k == "ArrowLeft" ) {
              omega = 0;
        } else if ( k == "ArrowRight" ) {
              omega = 0;
        } 
    });
    watch("two_score", [&](Event &e) {
        teleport(100, 0, 3.14);
    });
	  watch("one_score", [&](Event &e) {
		  teleport(100, 0, 3.14);
		  score++;
		  label(std::to_string(score), 0, 0);
    });
    watch("button_click", [&](Event& e) {
      if ( e.value()["value"] == "reset" ) {
         teleport(100, 0, 3.14);
      }
    });  
  }
  void start() { }
  // Update method tracks velocity
  void update() {
    track_velocity(v,omega,10,400);
  }
  void stop() {}

  double v, omega;
  double const v_m = 30, omega_m = 1;
  int score = 0;
};
// Player class, adds process for PlayerOneController
class Player : public Agent {
  public:
  Player(json spec, World& world) : Agent(spec, world) {
    add_process(c);
  }
  private:
  PlayerOneController c;
};

DECLARE_INTERFACE(Player)

#endif
