#ifndef _FCITX5_SP_H_
#define _FCITX5_SP_H_

#include <fcitx-utils/inputbuffer.h>
#include <fcitx/addonfactory.h>
#include <fcitx/addonmanager.h>
#include <fcitx/inputcontext.h>
#include <fcitx/inputcontextproperty.h>
#include <fcitx/inputmethodengine.h>
#include <fcitx/instance.h>

class IloSitelenState : public fcitx::InputContextProperty {
public:
  void keyEvent(fcitx::InputContext *ic, fcitx::KeyEvent &keyEvent);

  void reset(fcitx::InputContext *ic);

private:
  void updateUi(fcitx::InputContext *ic);

  fcitx::InputBuffer buffer_{{
      fcitx::InputBufferOption::AsciiOnly,
  }};
};

class IloSitelenEngine : public fcitx::InputMethodEngineV3 {
public:
  IloSitelenEngine();

  void keyEvent(const fcitx::InputMethodEntry &entry,
                fcitx::KeyEvent &keyEvent) override;

  void reset(const fcitx::InputMethodEntry &entry,
             fcitx::InputContextEvent &keyEvent) override;

private:
  fcitx::FactoryFor<IloSitelenState> factory_;

  friend class IloSitelenEngineFactory;
};

class IloSitelenEngineFactory : public fcitx::AddonFactory {
  fcitx::AddonInstance *create(fcitx::AddonManager *manager) override;
};

#endif
