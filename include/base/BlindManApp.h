#ifndef BLINDMANAPP_H
#define BLINDMANAPP_H

#include "MooseApp.h"

class BlindManApp;

template<>
InputParameters validParams<BlindManApp>();

class BlindManApp : public MooseApp
{
public:
  BlindManApp(InputParameters parameters);
  virtual ~BlindManApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* BLINDMANAPP_H */
