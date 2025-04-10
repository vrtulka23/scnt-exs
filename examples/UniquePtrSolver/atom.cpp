#import "main.h"

constexpr std::string_view KEYWORD_TRUE  = "true";
constexpr std::string_view KEYWORD_FALSE = "false";

LogicalAtom& LogicalAtom::operator=(const LogicalAtom& a) {
  if (this != &a) {
    value = std::make_unique<bool>(*a.value);
  }
  return *this;
}

UniquePtrType LogicalAtom::from_string(std::string s) {
  if (s==KEYWORD_TRUE)
    return std::make_unique<bool>(true);
  else if (s==KEYWORD_FALSE)
    return std::make_unique<bool>(false);
  else
    throw std::runtime_error("Invalid atom value: "+s);
}

std::string LogicalAtom::to_string() {
  return std::string((*value) ? KEYWORD_TRUE : KEYWORD_FALSE);
}

void LogicalAtom::logical_and(LogicalAtom* other) {
  value = std::make_unique<bool>(*value && *(other->value));
}
