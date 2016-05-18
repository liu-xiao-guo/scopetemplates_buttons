#ifndef SCOPE_ACTION_H_
#define SCOPE_ACTION_H_

#include <scope/scope.h>

#include <unity/scopes/ActionMetadata.h>
#include <unity/scopes/ActivationQueryBase.h>
#include <unity/scopes/ActivationResponse.h>
#include <unity/scopes/Result.h>

namespace us = unity::scopes;

class Action : public unity::scopes::ActivationQueryBase
{
public:
    Action(unity::scopes::Result const& result,
           unity::scopes::ActionMetadata const& metadata,
           std::string const& widget_id,
           std::string const& action_id,
           scope::Scope & scope);
    ~Action() = default;

    Action(us::Result const& result,
           us::ActionMetadata const& metadata,
           scope::Scope & scope);

     virtual unity::scopes::ActivationResponse activate() override;

private:
   us::Result result_;
   scope::Scope &scope_;
   std::string   action_id_;
};

#endif // SCOPE_ACTION_H_

