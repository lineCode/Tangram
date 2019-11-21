// begin Add by TangramTeam
#include "tangram_event.h"

namespace blink {

TangramEvent* TangramEvent::Create(const AtomicString& event_type,
                                   const String& message_type,
                                   const String& param1,
                                   const String& param2) {
  return MakeGarbageCollected<TangramEvent>(event_type, message_type, param1, param2);
}

String TangramEvent::messageType() {
  return message_type_;
}

void TangramEvent::setMessageType(const String& message_type) {
  message_type_ = message_type;
}

String TangramEvent::param1() {
  return param1_;
}

void TangramEvent::setParam1(const String& param1) {
  param1_ = param1;
}

String TangramEvent::param2() {
  return param2_;
}

void TangramEvent::setParam2(const String& param2) {
  param2_ = param2;
}

TangramEvent::TangramEvent() : Event("", Bubbles::kNo, Cancelable::kNo) {

}

TangramEvent::TangramEvent(const AtomicString& event_type, 
                           const String& message_type,
                           const String& param1,
                           const String& param2) 
  : Event(event_type, Bubbles::kNo, Cancelable::kNo) {
  message_type_ = message_type;
  param1_ = param1;
  param2_ = param2;
}

TangramEvent::~TangramEvent() = default;

}  // namespace blink
// end Add by TangramTeam
