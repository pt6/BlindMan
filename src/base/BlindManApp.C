#include "BlindManApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<BlindManApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

BlindManApp::BlindManApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  BlindManApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  BlindManApp::associateSyntax(_syntax, _action_factory);
}

BlindManApp::~BlindManApp()
{
}

// External entry point for dynamic application loading
extern "C" void BlindManApp__registerApps() { BlindManApp::registerApps(); }
void
BlindManApp::registerApps()
{
  registerApp(BlindManApp);
}

// External entry point for dynamic object registration
extern "C" void BlindManApp__registerObjects(Factory & factory) { BlindManApp::registerObjects(factory); }
void
BlindManApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void BlindManApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { BlindManApp::associateSyntax(syntax, action_factory); }
void
BlindManApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
