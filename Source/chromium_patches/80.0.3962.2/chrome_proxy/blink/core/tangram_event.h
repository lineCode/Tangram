// begin Add by TangramTeam
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_TANGRAM_EVENT_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_TANGRAM_EVENT_H_

#include "third_party/blink/renderer/core/dom/events/Event.h"

namespace blink {

class ScriptState;

class CORE_EXPORT TangramEvent : public Event {
  DEFINE_WRAPPERTYPEINFO();

public:
  static TangramEvent* Create() { return MakeGarbageCollected<TangramEvent>(); }

  static TangramEvent* Create(const AtomicString& event_type,
                              const String& message_type,
                              const String& param1,
                              const String& param2);

  String messageType();
  void setMessageType(const String&);
  String param1();
  void setParam1(const String&);
  String param2();
  void setParam2(const String&);

  ~TangramEvent() override;

  TangramEvent();

  TangramEvent(const AtomicString& event_type, 
               const String& message_type, 
               const String& param1,
               const String& param2);

private:
  String message_type_;
  String param1_;
  String param2_;

};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_EVENTS_PROGRESS_EVENT_H_
// end Add by TangramTeam
