// begin Add by TangramTeam
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_H_

#include <map>

#include "third_party/blink/renderer/bindings/core/v8/script_value.h"
#include "third_party/blink/renderer/bindings/core/v8/serialization/transferables.h"
#include "third_party/blink/renderer/core/execution_context/context_lifecycle_observer.h"
#include "third_party/blink/renderer/core/dom/events/event_target.h"
#include "third_party/blink/renderer/core/event_type_names.h"

#include "third_party/blink/renderer/platform/heap/handle.h"
#include "third_party/blink/renderer/platform/wtf/assertions.h"
#include "third_party/blink/renderer/platform/wtf/forward.h"
#include "third_party/blink/renderer/platform/wtf/uuid.h"

namespace blink {

using namespace std;
class Element;
class LocalFrame;
class ExceptionState;
class Document;
class ScriptState;
class SerializedScriptValue;
class V8GeneralCallback;

class CORE_EXPORT Tangram final : public EventTargetWithInlineData,
                                  // public ContextLifecycleObserver,
                                  public DOMWindowClient {
  DEFINE_WRAPPERTYPEINFO();
  USING_GARBAGE_COLLECTED_MIXIN(Tangram);

 public:
  static Tangram* Create(LocalFrame* frame) { return MakeGarbageCollected<Tangram>(frame); }
  static bool CanTransferArrayBuffersAndImageBitmaps() { return true; }

  void Trace(blink::Visitor*) override;

  // Called when an event listener has been successfully added.
  void AddedEventListener(const AtomicString& event_type,
                          RegisteredEventListener&) override;

  DEFINE_ATTRIBUTE_EVENT_LISTENER(MessageReceived, kTangrammsg)

  // Intercept the specified message.
  DispatchEventResult DispatchEventInternal(Event& event) override;

  // Internal method

  void ipcMessage__(const String& type, const String& param1, const String& param2);

  // Message method

  void addChannel(const String& channel);
  void removeChannel(const String& channel);
  void sendMessage(const String& channel, const String& data);

  // Core API

  void putApplicationData(const String& key, const String& value);
  void getApplicationData(const String& key, V8GeneralCallback* callback);
  unsigned int createObject(const String& constructor, const String& constructString);
  String invoke(unsigned int objectHandle, const base::Optional<Vector<ScriptValue>>& args);

  // Core View API
  void createWorkspace(blink::Element* elt, const String& name);
  void createView(blink::Element* elt, const String& name);
  void loadDocument(const String& doc, const String& name, const String& viewName, const String& workspaceName);

  // View API
  void loadDocument(const String& name, const String& html);
  void getCurrentNode(V8GeneralCallback* callback);

  // DOM method

  void createRule(const String& name, const String& html);
  void renderElement(const String& ruleName, const String& html);

  // Non-js method
  
  void sendIPCMessage(const String& type, const String& param1, const String& param2);
  void startBundlingMessage();
  void stopBundlingMessage();

  // EventTarget overrides:
  const AtomicString& InterfaceName() const override;
  ExecutionContext* GetExecutionContext() const override;

  explicit Tangram(LocalFrame*);
  ~Tangram() override;

private:
	bool is_bundling_;
	Vector<String> pending_messages_;
	HeapHashMap<String, Member<V8GeneralCallback>> pending_callbacks_;

};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_FRAME_TANGRAM_H_
        // end Add by TangramTeam
