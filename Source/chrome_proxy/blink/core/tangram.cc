// begin Add by TangramTeam
#include "tangram.h"
#include "tangram_event.h"
#include "tangram_node.h"

#include "third_party/blink/public/web/web_local_frame_client.h"
#include "third_party/blink/renderer/core/frame/local_dom_window.h"
#include "third_party/blink/renderer/core/frame/local_frame.h"
#include "third_party/blink/renderer/core/frame/web_local_frame_impl.h"
#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/html/html_element.h"
#include "third_party/blink/renderer/core/html/html_head_element.h"

#include "third_party/blink/renderer/bindings/core/v8/v8_general_callback.h"

namespace blink {

Tangram::Tangram(LocalFrame* frame) : DOMWindowClient(frame) {
	is_pending_ = false;
}

Tangram::~Tangram() {}

void Tangram::Trace(blink::Visitor* visitor) {
  EventTargetWithInlineData::Trace(visitor);
  ScriptWrappable::Trace(visitor);
  DOMWindowClient::Trace(visitor);
}

void Tangram::AddedEventListener(const AtomicString& event_type,
                                 RegisteredEventListener& registered_listener) {
  EventTargetWithInlineData::AddedEventListener(event_type,
                                                registered_listener);
}

// Internal message interface.
void Tangram::ipcMessage__(const String& type, const String& param1, const String& param2) {
	ipcMessage(type, param1, param2);
}

// User level message
void Tangram::addChannel(const String& channel) {
  ipcMessage(L"USER_LEVEL_ADD_CHANNEL", channel, L"");
}

void Tangram::removeChannel(const String& channel) {
  ipcMessage(L"USER_LEVEL_REMOVE_CHANNEL", channel, L"");
}

void Tangram::sendMessage(const String& channel, const String& data) {
  ipcMessage(L"USER_LEVEL_MESSAGE", channel, data);
}

// Define a element
void Tangram::defineElement(const String& tagName, const String& html) {
  ipcMessage(L"DEFINE_ELEMENT", tagName, html);
}

// Render an element.
void Tangram::renderElement(const String& tagName, const String& html) {
  ipcMessage(L"RENDER_ELEMENT", tagName, html);
}

void Tangram::ipcMessage(const String& type, const String& param1, const String& param2) {
	WebLocalFrameImpl* web_local_frame_impl = WebLocalFrameImpl::FromFrame(GetFrame());
	// Null when opening a new tab.
	if (web_local_frame_impl != nullptr) {
		WebLocalFrameClient* web_local_frame_client = web_local_frame_impl->Client();
		if (web_local_frame_client) {
			if (is_pending_) {
				String message = type + "%%%" + param1 + "%%%" + param2;
				pending_messages_.push_back(message);
			}
			else {
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
}

void Tangram::waitMessage() {
	is_pending_ = true;
}

void Tangram::releaseMessage() {
	is_pending_ = false;
	WebLocalFrameImpl* web_local_frame_impl = WebLocalFrameImpl::FromFrame(GetFrame());
	// Null when opening a new tab.
	if (web_local_frame_impl != nullptr) {
		WebLocalFrameClient* web_local_frame_client = web_local_frame_impl->Client();
		if (web_local_frame_client) {
			if (pending_messages_.size() > 0) {
				String stringBuffer = "";
				for (wtf_size_t i = 0; i < pending_messages_.size(); i++) {
					if (i > 0) {
						stringBuffer = stringBuffer + "$$$";
					}
					stringBuffer = stringBuffer + pending_messages_[i];
				}
				WebString bundle = stringBuffer;
				std::wstring type = L"BUNDLE_MESSAGE";
				std::wstring param1 = bundle.Utf16();
				std::wstring param2 = L"";
				web_local_frame_client->SendTangramMessage(type, param1, param2);
				pending_messages_.clear();
			}
		}
	}
}

const AtomicString& Tangram::InterfaceName() const {
  return event_target_names::kTangram;
}

ExecutionContext* Tangram::GetExecutionContext() const {
  return DomWindow()->document();
}

}  // namespace blink
   // end Add by TangramTeam
