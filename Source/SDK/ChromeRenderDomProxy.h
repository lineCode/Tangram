#pragma once

#include <string>

namespace TangramCommon {

class CChromeWebFrameClient {
 public:
  CChromeWebFrameClient(){};

  virtual ~CChromeWebFrameClient(){};

  virtual void OnTangramExtend(std::wstring strXml,
                               std::wstring strKey,
                               std::wstring strFeatures){};

  virtual void ExternalSend(std::wstring strType,
                            std::wstring strKey,
                            std::wstring strData){};

  virtual void SendNodeMessage(__int64 nHandle,
                               std::wstring strXml,
                               std::wstring strData){};

  virtual void sendMessage(std::wstring strContent, void*, void*){};

  virtual void SendTangramMessage(std::wstring strChannel,
	  std::wstring strArg1,
	  std::wstring strArg2) {};

  virtual void OnTangramMessage(std::wstring strChannel,
	  std::wstring strArg1,
	  std::wstring strArg2) {};
};

}  // namespace TangramCommon
