#include "ilo-sitelen.h"

#include <fcitx/event.h>
#include <fcitx/inputpanel.h>
#include <fcitx/instance.h>
#include <unordered_map>
#include <unordered_set>

// todo: pi underline

// todo: replace with a map
// todo: allow customization
std::vector<std::pair<std::string, std::string>> words{
    {"kijetesantakalu", "\U000F1980"},
    {"kokosila", "\U000F1984"},
    {"misikeke", "\U000F1987"},
    {"kepeken", "\U000F1919"},
    {"monsuta", "\U000F197D"},
    {"sitelen", "\U000F1960"},
    {"jasima", "\U000F197F"},
    {"kalama", "\U000F1915"},
    {"kipisi", "\U000F197B"},
    {"kulupu", "\U000F191F"},
    {"lanpan", "\U000F1985"},
    {"namako", "\U000F1978"},
    {"pakala", "\U000F1948"},
    {"palisa", "\U000F194A"},
    {"pimeja", "\U000F194F"},
    {"sijelo", "\U000F195B"},
    {"sinpin", "\U000F195F"},
    {"soweli", "\U000F1962"},
    {"akesi", "\U000F1901"},
    {"alasa", "\U000F1903"},
    {"epiku", "\U000F1983"},
    {"kiwen", "\U000F191B"},
    {"linja", "\U000F1929"},
    {"lukin", "\U000F192E"},
    {"monsi", "\U000F1938"},
    {"nanpa", "\U000F193D"},
    {"nasin", "\U000F193F"},
    {"pilin", "\U000F194E"},
    {"tenpo", "\U000F196B"},
    {"tonsi", "\U000F197E"},
    {"utala", "\U000F1971"},
    {"anpa", "\U000F1905"},
    {"ante", "\U000F1906"},
    {"awen", "\U000F1908"},
    {"esun", "\U000F190B"},
    {"insa", "\U000F190F"},
    {"jaki", "\U000F1910"},
    {"jelo", "\U000F1912"},
    {"kala", "\U000F1914"},
    {"kama", "\U000F1916"},
    {"kasi", "\U000F1917"},
    {"kili", "\U000F191A"},
    {"kule", "\U000F191E"},
    {"kute", "\U000F1920"},
    {"lape", "\U000F1922"},
    {"laso", "\U000F1923"},
    {"lawa", "\U000F1924"},
    {"leko", "\U000F197C"},
    {"lete", "\U000F1926"},
    {"lili", "\U000F1928"},
    {"lipu", "\U000F192A"},
    {"loje", "\U000F192B"},
    {"luka", "\U000F192D"},
    {"lupa", "\U000F192F"},
    {"mama", "\U000F1931"},
    {"mani", "\U000F1932"},
    {"meli", "\U000F1933"},
    {"meso", "\U000F1982"},
    {"mije", "\U000F1935"},
    {"moku", "\U000F1936"},
    {"moli", "\U000F1937"},
    {"musi", "\U000F193B"},
    {"mute", "\U000F193C"},
    {"nasa", "\U000F193E"},
    {"nena", "\U000F1940"},
    {"nimi", "\U000F1942"},
    {"noka", "\U000F1943"},
    {"olin", "\U000F1945"},
    {"open", "\U000F1947"},
    {"pali", "\U000F1949"},
    {"pana", "\U000F194C"},
    {"pini", "\U000F1950"},
    {"pipi", "\U000F1951"},
    {"poka", "\U000F1952"},
    {"poki", "\U000F1953"},
    {"pona", "\U000F1954"},
    {"sama", "\U000F1956"},
    {"seli", "\U000F1957"},
    {"selo", "\U000F1958"},
    {"seme", "\U000F1959"},
    {"sewi", "\U000F195A"},
    {"sike", "\U000F195C"},
    {"sina", "\U000F195E"},
    {"soko", "\U000F1981"},
    {"sona", "\U000F1961"},
    {"suli", "\U000F1963"},
    {"suno", "\U000F1964"},
    {"supa", "\U000F1965"},
    {"suwi", "\U000F1966"},
    {"taso", "\U000F1968"},
    {"tawa", "\U000F1969"},
    {"telo", "\U000F196A"},
    {"toki", "\U000F196C"},
    {"tomo", "\U000F196D"},
    {"unpa", "\U000F196F"},
    {"walo", "\U000F1972"},
    {"waso", "\U000F1974"},
    {"wawa", "\U000F1975"},
    {"weka", "\U000F1976"},
    {"wile", "\U000F1977"},
    {"ala", "\U000F1902"},
    {"ale", "\U000F1904"},
    {"anu", "\U000F1907"},
    {"ijo", "\U000F190C"},
    {"ike", "\U000F190D"},
    {"ilo", "\U000F190E"},
    {"jan", "\U000F1911"},
    {"ken", "\U000F1918"},
    {"kin", "\U000F1979"},
    {"kon", "\U000F191D"},
    {"len", "\U000F1925"},
    {"lon", "\U000F192C"},
    {"mun", "\U000F193A"},
    {"oko", "\U000F197A"},
    {"ona", "\U000F1946"},
    {"pan", "\U000F194B"},
    {"sin", "\U000F195D"},
    {"tan", "\U000F1967"},
    {"uta", "\U000F1970"},
    {"wan", "\U000F1973"},
    {"en", "\U000F190A"},
    {"jo", "\U000F1913"},
    {"ko", "\U000F191C"},
    {"ku", "\U000F1988"},
    {"la", "\U000F1921"},
    {"li", "\U000F1927"},
    {"ma", "\U000F1930"},
    {"mi", "\U000F1934"},
    {"mu", "\U000F1939"},
    {"ni", "\U000F1941"},
    {"pi", "\U000F194D"},
    {"pu", "\U000F1955"},
    {"tu", "\U000F196E"},
    {"e", "\U000F1909"},
    {"n", "\U000F1986"},
    {"o", "\U000F1944"},
    {"a", "\U000F1900"},
};

// todo: customizable
std::unordered_map<char, std::string> punctuation = {
    {' ', " "},          {':', "\U0000FF1A"}, {'.', "."},   {'!', "!"},
    {'"', "\""},         {'$', "$"},          {'%', "%"},   {'^', "^"},
    {'&', "&"},          {'*', "*"},          {'(', "("},   {')', ")"},
    {'-', "-"},          {'=', "="},          {'_', "_"},   {'+', "+"},
    {'[', "\U000F1990"}, {']', "\U000F1991"}, {'{', "{"},   {'}', "}"},
    {';', ";"},          {':', ":"},          {'\'', "\'"}, {'#', "#"},
    {'@', "@"},          {'~', "~"},          {')', ")"},   {',', ","},
    {'<', "<"},          {'>', ">"},          {'/', "/"},   {'?', "?"},
    {'\\', "\\"},        {'|', "|"},
};

std::pair<std::string, size_t> toki_pona_to_sitelen_pona(const std::string &x,
                                                         size_t cursor) {
  std::string out;
  bool just_found_word = false;
  size_t out_cursor = cursor;
  for (size_t i = 0; i < x.length();) {
    bool found_word = false, found_end = false;
    // todo: filter by word length
    FCITX_INFO() << " i=" << i << " oc=" << out_cursor;
    for (auto it : words) {
      if (x.size() - i > it.first.size()) {
        if (0 == x.compare(i, it.first.size(), it.first) &&
            punctuation.count(x[i + it.first.size()])) {
          // if the cursor is before the start of this word, we replace and the
          // cursor stays where it is if the cursor is within this word, we do
          // not replace and the cursor stays where it is if the cursor is after
          // this word, we replace and the cursor is moved by how much we
          // replaced

          FCITX_INFO() << " i=" << i << " c=" << cursor;
          if (i + it.first.size() - 1 < cursor) {
            out_cursor -= it.first.size() - it.second.length();
          } else if (i <= cursor) {
            break;
          }

          // remove gaps between words
          // SAFETY: just_found_word should never be true when i = 0
          if (just_found_word && x[i - 1] == ' ') {
            out.pop_back();
            // if the cursor is after this word, account for loss of space
            if (i < cursor)
              out_cursor--;
          }

          i += it.first.size();
          out.append(it.second);
          found_word = true;
          break;
        }
      } else if (x.size() - i == it.first.size()) {
        if (0 == x.compare(i, it.first.size(), it.first)) {
          // same logic as above
          if (i + it.first.size() - 1 < cursor) {
            out_cursor -= it.first.size() - it.second.length();
          } else if (i <= cursor) {
            // cursor is within word, don't replace word
            break;
          }

          // remove gaps between words
          // SAFETY: just_found_word should never be true when i = 0
          if (just_found_word && x[i - 1] == ' ') {
            out.pop_back();
            // if the cursor is after this word, account for loss of space
            if (i < cursor)
              out_cursor--;
          }

          found_end = true;
          out.append(it.second);
          break;
        }
      }
    }
    if (found_end)
      break;

    just_found_word = found_word;

    // skip to past end of word
    while (!punctuation.count(x[i]) && i < x.length())
      out.push_back(x[i++]);

    // feed all punctuation
    std::unordered_map<char, std::string>::iterator it;
    while ((it = punctuation.find(x[i])) != punctuation.end() &&
           i < x.length()) {
      out.append(it->second);
      if (i < cursor) {
        // if the punctuation is now multiple bytes long, move the cursor
        // accordingly
        out_cursor += it->second.length() - 1;
      }
      i++;
    }
  }
  FCITX_INFO() << "converted \"" << x << "\" -> \"" << out << "\" i=" << cursor
               << " -> " << out_cursor;
  return {out, out_cursor};
}

void IloSitelenState::keyEvent(fcitx::InputContext *ic,
                               fcitx::KeyEvent &keyEvent) {
  // int in_letters = letters.count(keyEvent.key().sym());
  int in_letters = keyEvent.key().isSimple();

  FCITX_INFO() << keyEvent.key() << " isRelease=" << keyEvent.isRelease();

  if (buffer_.empty()) {
    if (in_letters) {
      buffer_.type(keyEvent.key().sym());
      updateUi(ic);
      return keyEvent.filterAndAccept();
    }
  } else {
    if (keyEvent.key().check(FcitxKey_BackSpace))
      buffer_.backspace();

    if (keyEvent.key().check(FcitxKey_Escape))
      buffer_.clear();

    if (keyEvent.key().check(FcitxKey_Return)) {
      ic->commitString(
          toki_pona_to_sitelen_pona(buffer_.userInput(), buffer_.size()).first);
      buffer_.clear();
    }

    if (keyEvent.key().check(FcitxKey_Left)) {
      size_t cursor = buffer_.cursor();
      if (cursor != 0)
        buffer_.setCursor(cursor - 1);
    }
    if (keyEvent.key().check(FcitxKey_Right)) {
      size_t cursor = buffer_.cursor();
      if (cursor != buffer_.size())
        buffer_.setCursor(cursor + 1);
    }

    FCITX_INFO() << buffer_.cursor() << " " << keyEvent.key().sym();

    if (in_letters)
      buffer_.type(keyEvent.key().sym());

    updateUi(ic);
    return keyEvent.filterAndAccept();
  }
}

void IloSitelenState::reset(fcitx::InputContext *ic) {
  buffer_.clear();
  updateUi(ic);
}

void IloSitelenState::updateUi(fcitx::InputContext *ic) {
  auto &ip = ic->inputPanel();
  ip.reset();

  auto predit_text =
      toki_pona_to_sitelen_pona(buffer_.userInput(), buffer_.cursor());
  if (ic->capabilityFlags().test(fcitx::CapabilityFlag::Preedit)) {
    fcitx::Text preedit(predit_text.first, fcitx::TextFormatFlag::Underline);
    preedit.setCursor(predit_text.second);
    ip.setClientPreedit(preedit);
  } else {
    fcitx::Text preedit(predit_text.first);
    ip.setPreedit(preedit);
  }

  ic->updateUserInterface(fcitx::UserInterfaceComponent::InputPanel);
  ic->updatePreedit();
}

IloSitelenEngine::IloSitelenEngine()
    : factory_([](fcitx::InputContext &ic) {
        FCITX_UNUSED(ic);
        return new IloSitelenState;
      }) {}

void IloSitelenEngine::keyEvent(const fcitx::InputMethodEntry &entry,
                                fcitx::KeyEvent &keyEvent) {
  FCITX_UNUSED(entry);
  if (keyEvent.isRelease() || keyEvent.key().states())
    return;
  auto *ic = keyEvent.inputContext();
  auto *state = ic->propertyFor(&this->factory_);
  state->keyEvent(ic, keyEvent);
}

void IloSitelenEngine::reset(const fcitx::InputMethodEntry &entry,
                             fcitx::InputContextEvent &keyEvent) {
  FCITX_UNUSED(entry);
  auto *state = keyEvent.inputContext()->propertyFor(&this->factory_);
  state->reset(keyEvent.inputContext());
}

FCITX_ADDON_FACTORY(IloSitelenEngineFactory);

fcitx::AddonInstance *
IloSitelenEngineFactory::create(fcitx::AddonManager *manager) {
  auto engine = new IloSitelenEngine();
  manager->instance()->inputContextManager().registerProperty(
      "ijo-pona", &engine->factory_);
  return engine;
}
