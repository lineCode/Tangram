// begin Add by TangramTeam
#include "chrome_proxy/blink/core/tangram.h"
#include "chrome_proxy/blink/core/tangram_event.h"
#include "chrome_proxy/blink/core/tangram_node.h"

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
	is_bundling_ = false;
}

Tangram::~Tangram() {}

void Tangram::Trace(blink::Visitor* visitor) {
  visitor->Trace(pending_callbacks_);
  EventTargetWithInlineData::Trace(visitor);
  ScriptWrappable::Trace(visitor);
  DOMWindowClient::Trace(visitor);
}

void Tangram::AddedEventListener(const AtomicString& event_type,
                                 RegisteredEventListener& registered_listener) {
  EventTargetWithInlineData::AddedEventListener(event_type,
                                                registered_listener);
}

DispatchEventResult Tangram::DispatchEventInternal(Event& event) {
	if (event.type() == event_type_names::kTangrammsg) {
		TangramEvent& tangram_event = (TangramEvent&)event;
		String type = tangram_event.messageType();
		if (type == "CB_GET_APPLICATION_DATA") {
			String data = tangram_event.param1();
			String callback_id = tangram_event.param2();
			auto it = pending_callbacks_.find(callback_id);
			if (it != pending_callbacks_.end()) {
				Member<V8GeneralCallback> callback = it->value;
				ScriptState* callback_relevant_script_state = callback->CallbackRelevantScriptState();
				// Add parameter data to the callback Context requires at least one scope.
				ScriptState::Scope callback_relevant_context_scope(callback_relevant_script_state);
				callback->InvokeAndReportException(nullptr, ScriptValue::From(callback_relevant_script_state, data));
			}
			return DispatchEventResult::kNotCanceled;
		}
		else if (type == "CB_GET_CURRENT_NODE") {
			String data = tangram_event.param1();
			TangramNode* node = TangramNode::Create(GetFrame(), data);
			String callback_id = tangram_event.param2();
			auto it = pending_callbacks_.find(callback_id);
			if (it != pending_callbacks_.end()) {
				Member<V8GeneralCallback> callback = it->value;
				ScriptState* callback_relevant_script_state = callback->CallbackRelevantScriptState();
				// Add parameter data to the callback Context requires at least one scope.
				ScriptState::Scope callback_relevant_context_scope(callback_relevant_script_state);
				callback->InvokeAndReportException(nullptr, ScriptValue::From(callback_relevant_script_state, node));
			}
			return DispatchEventResult::kNotCanceled;
		}
	}
	return EventTargetWithInlineData::DispatchEventInternal(event);
}

// Internal message interface.
void Tangram::ipcMessage__(const String& type, const String& param1, const String& param2) {
	sendIPCMessage(type, param1, param2);
}

void Tangram::addChannel(const String& channel) {
  sendIPCMessage(L"USER_LEVEL_ADD_CHANNEL", channel, L"");
}

void Tangram::removeChannel(const String& channel) {
  sendIPCMessage(L"USER_LEVEL_REMOVE_CHANNEL", channel, L"");
}

void Tangram::sendMessage(const String& channel, const String& data) {
  sendIPCMessage(L"USER_LEVEL_MESSAGE", channel, data);
}

void Tangram::putApplicationData(const String& key, const String& value) {
	// TODO
}

void Tangram::getApplicationData(const String& key, V8GeneralCallback* callback) {
	String callback_id = WTF::CreateCanonicalUUIDString();
	sendIPCMessage(L"GET_APPLICATION_DATA", key, callback_id);
	auto it = pending_callbacks_.find(callback_id);
	if (it == pending_callbacks_.end()) {
		pending_callbacks_.insert(callback_id, callback);
	}
}

unsigned int Tangram::createObject(const String& constructor, const String& constructString) {
	// TODO
	return 0;
}
//
//String Tangram::invoke(unsigned int objectHandle, const base::Optional<Vector<ScriptValue>>& args) {
//	// TODO
//	return String();
//}

void Tangram::createWorkspace(blink::Element* elt, const String& name) {
	// TODO
}

void Tangram::createView(blink::Element* elt, const String& name) {
	// TODO
}

void Tangram::loadDocument(const String& doc, const String& name, const String& viewName, const String& workspaceName) {
	// TODO
}

// Create a view based on the current viewport and load the document.
void Tangram::loadDocument(const String& name, const String& html) {
	sendIPCMessage(L"LOAD_DOCUMENT_TO_VIEWPORT", name, html);
}

void Tangram::getCurrentNode(V8GeneralCallback* callback) {
	String callback_id = WTF::CreateCanonicalUUIDString();
	sendIPCMessage(L"GET_CURRENT_NODE", L"", callback_id);
	auto it = pending_callbacks_.find(callback_id);
	if (it == pending_callbacks_.end()) {
		pending_callbacks_.insert(callback_id, callback);
	}
}

// Define a rule that uses an extra method to handle the specified tag.
void Tangram::createRule(const String& name, const String& html) {
  sendIPCMessage(L"CREATE_RULE", name, html);
}

// Renders an element based on the specified rules.
void Tangram::renderElement(const String& ruleName, const String& html) {
  sendIPCMessage(L"RENDER_ELEMENT", ruleName, html);
}

void Tangram::sendIPCMessage(const String& type, const String& param1, const String& param2) {
	WebLocalFrameImpl* web_local_frame_impl = WebLocalFrameImpl::FromFrame(GetFrame());
	// Null when opening a new tab.
	if (web_local_frame_impl != nullptr) {
		WebLocalFrameClient* web_local_frame_client = web_local_frame_impl->Client();
		if (web_local_frame_client) {
			if (is_bundling_) {
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

void Tangram::startBundlingMessage() {
	is_bundling_ = true;
}

void Tangram::stopBundlingMessage() {
	is_bundling_ = false;
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
