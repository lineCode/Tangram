// begin Add by TangramTeam
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_NODE_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_NODE_H_

#include <map>

#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/bindings/core/v8/serialization/transferables.h"
#include "third_party/blink/renderer/core/execution_context/context_lifecycle_observer.h"
#include "third_party/blink/renderer/core/dom/events/event_target.h"
#include "third_party/blink/renderer/core/event_type_names.h"

#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/assertions.h"
#include "third_party/blink/renderer/platform/wtf/forward.h"

namespace blink {

using namespace std;

class ExceptionState;
class Document;
class ScriptState;
class SerializedScriptValue;
class V8GeneralCallback;

class CORE_EXPORT TangramNode final : public EventTargetWithInlineData,
									  public DOMWindowClient {
  DEFINE_WRAPPERTYPEINFO();
  USING_GARBAGE_COLLECTED_MIXIN(TangramNode);

 public:
  static TangramNode* Create(LocalFrame* frame) { return MakeGarbageCollected<TangramNode>(frame); }
  static TangramNode* Create(LocalFrame* frame, const String& strHandle);

  void Trace(blink::Visitor*) override;

  // Called when an event listener has been successfully added.
  void AddedEventListener(const AtomicString& event_type,
                          RegisteredEventListener&) override;

  // Message method

  void addChannel(const String& channel);
  void removeChannel(const String& channel);
  void sendMessage(const String& channel, const String& data);

  DEFINE_ATTRIBUTE_EVENT_LISTENER(MessageReceived, kTangrammsg)

  // Non-js method

  void sendIPCMessage(const String& type, const String& param1, const String& param2);

  // EventTarget overrides:
  const AtomicString& InterfaceName() const override;
  ExecutionContext* GetExecutionContext() const override;

  TangramNode(LocalFrame*);
  TangramNode(LocalFrame*, const String& strHandle);

  ~TangramNode() override;

private:
	String m_strHandle;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_NODE_H_
// end Add by TangramTeam
