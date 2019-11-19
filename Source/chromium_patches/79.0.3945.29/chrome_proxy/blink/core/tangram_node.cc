// begin Add by TangramTeam
#include "chrome_proxy/blink/core/tangram_node.h"
#include "chrome_proxy/blink/core/tangram_event.h"

#include "third_party/blink/public/web/web_local_frame_client.h"
#include "third_party/blink/renderer/core/frame/local_dom_window.h"
#include "third_party/blink/renderer/core/frame/local_frame.h"
#include "third_party/blink/renderer/core/frame/web_local_frame_impl.h"
#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/html/html_element.h"
#include "third_party/blink/renderer/core/html/html_head_element.h"

#include "third_party/blink/renderer/bindings/core/v8/v8_general_callback.h"

namespace blink {

TangramNode::TangramNode(LocalFrame* frame) : DOMWindowClient(frame) {}

TangramNode::~TangramNode() {}

TangramNode* TangramNode::Create(LocalFrame* frame, const String& strHandle) {
	return MakeGarbageCollected<TangramNode>(frame, strHandle);
}

TangramNode::TangramNode(LocalFrame* frame, const String& strHandle) : DOMWindowClient(frame)
{
	m_strHandle = strHandle;
}

void TangramNode::Trace(blink::Visitor* visitor) {
  EventTargetWithInlineData::Trace(visitor);
  ScriptWrappable::Trace(visitor);
  DOMWindowClient::Trace(visitor);
}

void TangramNode::AddedEventListener(const AtomicString& event_type,
                                 RegisteredEventListener& registered_listener) {
  EventTargetWithInlineData::AddedEventListener(event_type,
                                                registered_listener);
}

void TangramNode::addChannel(const String& channel) {
  sendIPCMessage(L"USER_LEVEL_ADD_CHANNEL", channel, L"");
}

void TangramNode::removeChannel(const String& channel) {
  sendIPCMessage(L"USER_LEVEL_REMOVE_CHANNEL", channel, L"");
}

void TangramNode::sendMessage(const String& channel, const String& data) {
  sendIPCMessage(L"USER_LEVEL_MESSAGE", channel, data);
}

void TangramNode::sendIPCMessage(const String& type, const String& param1, const String& param2) {
	WebLocalFrameImpl* web_local_frame_impl = WebLocalFrameImpl::FromFrame(GetFrame());
	// Null when opening a new tab.
	if (web_local_frame_impl != nullptr) {
		WebLocalFrameClient* web_local_frame_client = web_local_frame_impl->Client();
		if (web_local_frame_client) {
			WebString webstr = type;
			std::wstring u16_type = webstr.Utf16();
			webstr = param1;
			std::wstring u16_param1 = webstr.Utf16();
			webstr = param2;
			std::wstring u16_param2 = webstr.Utf16();
			web_local_frame_client->SendTangramMessage(u16_type, u16_param1, u16_param2);
		}
	}
}

const AtomicString& TangramNode::InterfaceName() const {
  return event_target_names::kTangram;
}

ExecutionContext* TangramNode::GetExecutionContext() const {
  return DomWindow()->document();
}

}  // namespace blink
// end Add by TangramTeam
