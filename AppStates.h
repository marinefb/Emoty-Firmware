// This file declares and implements the State* classes, which are the child of State class
// and contains the logic of each state of our application.
//
// Pierre Rossel   2024-05-07  Initial version

#include "StateMachine.h"

class StateIdle : public State
{
  void enter();

  // Loop is declared here, but implemented below, after the declaration of other states
  State *loop();

  void exit();
};

class StateHappy : public State
{
  void enter();

  // Loop is declared here, but implemented below, after the declaration of other states
  State *loop();

  void exit();
};

class StateSad : public State
{
  void enter();

  // Loop is declared here, but implemented below, after the declaration of other states
  State *loop();

  void exit();
};

class StateSurprised : public State
{
  void enter();

  // Loop is declared here, but implemented below, after the declaration of other states
  State *loop();

  void exit();
};

class StateDisgusted : public State
{
  void enter();

  // Loop is declared here, but implemented below, after the declaration of other states
  State *loop();

  void exit();
};

class StateScared : public State
{
  void enter();

  // Loop is declared here, but implemented below, after the declaration of other states
  State *loop();

  void exit();
};

class StateAngry : public State
{
  void enter();

  // Loop is declared here, but implemented below, after the declaration of other states
  State *loop();

  void exit();
};
