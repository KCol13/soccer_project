#ifndef __PLAYER_TWO__H
#define __PLAYER_TWO__H 

#include "enviro.h"
#include "styles.h"

using namespace enviro;
// PlayerTwoController class
class PlayerTwoController : public Process, public AgentInterface {

  public:
  PlayerTwoController() : Process(), AgentInterface(), v(0), omega(0) {}
  // PlayerTwo initialization method. Player two is controlled with 
  // a, w, s, d keys where a left, d is right, w is up, and s is down
  // If PlayerTwo scores, the label is updated and if either player 
  // scores, PlayerTwo is teleported to the starting position.
  // Also if the reset button is pressed, PlayerTwo is teleported to
  // the starting position.
  void init() {
    watch("keydown", [&](Event &e) {
        auto k = e.value()["key"].get<std::string>();
        if ( k == "w" ) {
              v = v_m;              
        } else if ( k == "s" ) {
              v = -v_m;  
        } else if ( k == "a" ) {
              omega = -omega_m;
        } else if ( k == "d" ) {
              omega = omega_m;
        } 
    });        
    watch("keyup", [&](Event &e) {
        auto k = e.value()["key"].get<std::string>();
        if ( k == "w" || k == "s" ) {
              v = 0;               
        } else if ( k == "a" ) {
              omega = 0;
        } else if ( k == "d" ) {
              omega = 0;
        } 
    });
    watch("one_score", [&](Event &e) {
	    teleport(-100, 0, 0);
    });
    watch("two_score", [&](Event &e) {
	    teleport(-100, 0, 0);
	    score++;
	    label(std::to_string(score), 0, 0);
    });
    watch("button_click", [&](Event& e) {
      if ( e.value()["value"] == "reset" ) {
         teleport(-100, 0, 0);
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
// PlayerTwo class adds process for PlayerTwoController
class PlayerTwo : public Agent {
  public:
  PlayerTwo(json spec, World& world) : Agent(spec, world) {
    add_process(c);
  }
  private:
  PlayerTwoController c;
};

DECLARE_INTERFACE(PlayerTwo)

#endif
