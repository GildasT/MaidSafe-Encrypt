// Generated by the protocol buffer compiler.  DO NOT EDIT!

#include "maidsafe_service.pb.h"
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format_inl.h>

namespace maidsafe {

namespace {

const ::google::protobuf::ServiceDescriptor* MaidsafeService_descriptor_ = NULL;
const ::google::protobuf::ServiceDescriptor* VaultRegistration_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_maidsafe_5fservice_2eproto() {
  protobuf_AddDesc_maidsafe_5fservice_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "maidsafe_service.proto");
  GOOGLE_CHECK(file != NULL);
  MaidsafeService_descriptor_ = file->service(0);
  VaultRegistration_descriptor_ = file->service(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_maidsafe_5fservice_2eproto);
}

void protobuf_RegisterTypes() {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_maidsafe_5fservice_2eproto() {
}

void protobuf_AddDesc_maidsafe_5fservice_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::maidsafe::protobuf_AddDesc_maidsafe_5fservice_5fmessages_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026maidsafe_service.proto\022\010maidsafe\032\037maid"
    "safe_service_messages.proto2\246\r\n\017Maidsafe"
    "Service\022I\n\016StoreChunkPrep\022\032.maidsafe.Sto"
    "rePrepRequest\032\033.maidsafe.StorePrepRespon"
    "se\022G\n\nStoreChunk\022\033.maidsafe.StoreChunkRe"
    "quest\032\034.maidsafe.StoreChunkResponse\022J\n\013S"
    "torePacket\022\034.maidsafe.StorePacketRequest"
    "\032\035.maidsafe.StorePacketResponse\022S\n\016AddTo"
    "WatchList\022\037.maidsafe.AddToWatchListReque"
    "st\032 .maidsafe.AddToWatchListResponse\022b\n\023"
    "RemoveFromWatchList\022$.maidsafe.RemoveFro"
    "mWatchListRequest\032%.maidsafe.RemoveFromW"
    "atchListResponse\022_\n\022AddToReferenceList\022#"
    ".maidsafe.AddToReferenceListRequest\032$.ma"
    "idsafe.AddToReferenceListResponse\022n\n\027Rem"
    "oveFromReferenceList\022(.maidsafe.RemoveFr"
    "omReferenceListRequest\032).maidsafe.Remove"
    "FromReferenceListResponse\022M\n\014AmendAccoun"
    "t\022\035.maidsafe.AmendAccountRequest\032\036.maids"
    "afe.AmendAccountResponse\022Y\n\020GetAccountSt"
    "atus\022!.maidsafe.GetAccountStatusRequest\032"
    "\".maidsafe.GetAccountStatusResponse\022G\n\nC"
    "heckChunk\022\033.maidsafe.CheckChunkRequest\032\034"
    ".maidsafe.CheckChunkResponse\022A\n\010GetChunk"
    "\022\031.maidsafe.GetChunkRequest\032\032.maidsafe.G"
    "etChunkResponse\022D\n\tGetPacket\022\032.maidsafe."
    "GetPacketRequest\032\033.maidsafe.GetPacketRes"
    "ponse\022J\n\013UpdateChunk\022\034.maidsafe.UpdateCh"
    "unkRequest\032\035.maidsafe.UpdateChunkRespons"
    "e\022J\n\013DeleteChunk\022\034.maidsafe.DeleteChunkR"
    "equest\032\035.maidsafe.DeleteChunkResponse\022P\n"
    "\rValidityCheck\022\036.maidsafe.ValidityCheckR"
    "equest\032\037.maidsafe.ValidityCheckResponse\022"
    "D\n\tSwapChunk\022\032.maidsafe.SwapChunkRequest"
    "\032\033.maidsafe.SwapChunkResponse\022J\n\013VaultSt"
    "atus\022\034.maidsafe.VaultStatusRequest\032\035.mai"
    "dsafe.VaultStatusResponse\022A\n\010CreateBP\022\031."
    "maidsafe.CreateBPRequest\032\032.maidsafe.Crea"
    "teBPResponse\022M\n\014ModifyBPInfo\022\035.maidsafe."
    "ModifyBPInfoRequest\032\036.maidsafe.ModifyBPI"
    "nfoResponse\022P\n\rGetBPMessages\022\036.maidsafe."
    "GetBPMessagesRequest\032\037.maidsafe.GetBPMes"
    "sagesResponse\022M\n\014AddBPMessage\022\035.maidsafe"
    ".AddBPMessageRequest\032\036.maidsafe.AddBPMes"
    "sageResponse2\233\001\n\021VaultRegistration\022A\n\010Ow"
    "nVault\022\031.maidsafe.OwnVaultRequest\032\032.maid"
    "safe.OwnVaultResponse\022C\n\014IsVaultOwned\022\030."
    "maidsafe.IsOwnedRequest\032\031.maidsafe.IsOwn"
    "edResponse", 1930);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "maidsafe_service.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_maidsafe_5fservice_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_maidsafe_5fservice_2eproto {
  StaticDescriptorInitializer_maidsafe_5fservice_2eproto() {
    protobuf_AddDesc_maidsafe_5fservice_2eproto();
  }
} static_descriptor_initializer_maidsafe_5fservice_2eproto_;


// ===================================================================

MaidsafeService::~MaidsafeService() {}

const ::google::protobuf::ServiceDescriptor* MaidsafeService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MaidsafeService_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* MaidsafeService::GetDescriptor() {
  protobuf_AssignDescriptorsOnce();
  return MaidsafeService_descriptor_;
}

void MaidsafeService::StoreChunkPrep(::google::protobuf::RpcController* controller,
                         const ::maidsafe::StorePrepRequest*,
                         ::maidsafe::StorePrepResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method StoreChunkPrep() not implemented.");
  done->Run();
}

void MaidsafeService::StoreChunk(::google::protobuf::RpcController* controller,
                         const ::maidsafe::StoreChunkRequest*,
                         ::maidsafe::StoreChunkResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method StoreChunk() not implemented.");
  done->Run();
}

void MaidsafeService::StorePacket(::google::protobuf::RpcController* controller,
                         const ::maidsafe::StorePacketRequest*,
                         ::maidsafe::StorePacketResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method StorePacket() not implemented.");
  done->Run();
}

void MaidsafeService::AddToWatchList(::google::protobuf::RpcController* controller,
                         const ::maidsafe::AddToWatchListRequest*,
                         ::maidsafe::AddToWatchListResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method AddToWatchList() not implemented.");
  done->Run();
}

void MaidsafeService::RemoveFromWatchList(::google::protobuf::RpcController* controller,
                         const ::maidsafe::RemoveFromWatchListRequest*,
                         ::maidsafe::RemoveFromWatchListResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method RemoveFromWatchList() not implemented.");
  done->Run();
}

void MaidsafeService::AddToReferenceList(::google::protobuf::RpcController* controller,
                         const ::maidsafe::AddToReferenceListRequest*,
                         ::maidsafe::AddToReferenceListResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method AddToReferenceList() not implemented.");
  done->Run();
}

void MaidsafeService::RemoveFromReferenceList(::google::protobuf::RpcController* controller,
                         const ::maidsafe::RemoveFromReferenceListRequest*,
                         ::maidsafe::RemoveFromReferenceListResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method RemoveFromReferenceList() not implemented.");
  done->Run();
}

void MaidsafeService::AmendAccount(::google::protobuf::RpcController* controller,
                         const ::maidsafe::AmendAccountRequest*,
                         ::maidsafe::AmendAccountResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method AmendAccount() not implemented.");
  done->Run();
}

void MaidsafeService::GetAccountStatus(::google::protobuf::RpcController* controller,
                         const ::maidsafe::GetAccountStatusRequest*,
                         ::maidsafe::GetAccountStatusResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method GetAccountStatus() not implemented.");
  done->Run();
}

void MaidsafeService::CheckChunk(::google::protobuf::RpcController* controller,
                         const ::maidsafe::CheckChunkRequest*,
                         ::maidsafe::CheckChunkResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method CheckChunk() not implemented.");
  done->Run();
}

void MaidsafeService::GetChunk(::google::protobuf::RpcController* controller,
                         const ::maidsafe::GetChunkRequest*,
                         ::maidsafe::GetChunkResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method GetChunk() not implemented.");
  done->Run();
}

void MaidsafeService::GetPacket(::google::protobuf::RpcController* controller,
                         const ::maidsafe::GetPacketRequest*,
                         ::maidsafe::GetPacketResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method GetPacket() not implemented.");
  done->Run();
}

void MaidsafeService::UpdateChunk(::google::protobuf::RpcController* controller,
                         const ::maidsafe::UpdateChunkRequest*,
                         ::maidsafe::UpdateChunkResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method UpdateChunk() not implemented.");
  done->Run();
}

void MaidsafeService::DeleteChunk(::google::protobuf::RpcController* controller,
                         const ::maidsafe::DeleteChunkRequest*,
                         ::maidsafe::DeleteChunkResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method DeleteChunk() not implemented.");
  done->Run();
}

void MaidsafeService::ValidityCheck(::google::protobuf::RpcController* controller,
                         const ::maidsafe::ValidityCheckRequest*,
                         ::maidsafe::ValidityCheckResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method ValidityCheck() not implemented.");
  done->Run();
}

void MaidsafeService::SwapChunk(::google::protobuf::RpcController* controller,
                         const ::maidsafe::SwapChunkRequest*,
                         ::maidsafe::SwapChunkResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method SwapChunk() not implemented.");
  done->Run();
}

void MaidsafeService::VaultStatus(::google::protobuf::RpcController* controller,
                         const ::maidsafe::VaultStatusRequest*,
                         ::maidsafe::VaultStatusResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method VaultStatus() not implemented.");
  done->Run();
}

void MaidsafeService::CreateBP(::google::protobuf::RpcController* controller,
                         const ::maidsafe::CreateBPRequest*,
                         ::maidsafe::CreateBPResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method CreateBP() not implemented.");
  done->Run();
}

void MaidsafeService::ModifyBPInfo(::google::protobuf::RpcController* controller,
                         const ::maidsafe::ModifyBPInfoRequest*,
                         ::maidsafe::ModifyBPInfoResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method ModifyBPInfo() not implemented.");
  done->Run();
}

void MaidsafeService::GetBPMessages(::google::protobuf::RpcController* controller,
                         const ::maidsafe::GetBPMessagesRequest*,
                         ::maidsafe::GetBPMessagesResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method GetBPMessages() not implemented.");
  done->Run();
}

void MaidsafeService::AddBPMessage(::google::protobuf::RpcController* controller,
                         const ::maidsafe::AddBPMessageRequest*,
                         ::maidsafe::AddBPMessageResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method AddBPMessage() not implemented.");
  done->Run();
}

void MaidsafeService::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             ::google::protobuf::RpcController* controller,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), MaidsafeService_descriptor_);
  switch(method->index()) {
    case 0:
      StoreChunkPrep(controller,
             ::google::protobuf::down_cast<const ::maidsafe::StorePrepRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::StorePrepResponse*>(response),
             done);
      break;
    case 1:
      StoreChunk(controller,
             ::google::protobuf::down_cast<const ::maidsafe::StoreChunkRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::StoreChunkResponse*>(response),
             done);
      break;
    case 2:
      StorePacket(controller,
             ::google::protobuf::down_cast<const ::maidsafe::StorePacketRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::StorePacketResponse*>(response),
             done);
      break;
    case 3:
      AddToWatchList(controller,
             ::google::protobuf::down_cast<const ::maidsafe::AddToWatchListRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::AddToWatchListResponse*>(response),
             done);
      break;
    case 4:
      RemoveFromWatchList(controller,
             ::google::protobuf::down_cast<const ::maidsafe::RemoveFromWatchListRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::RemoveFromWatchListResponse*>(response),
             done);
      break;
    case 5:
      AddToReferenceList(controller,
             ::google::protobuf::down_cast<const ::maidsafe::AddToReferenceListRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::AddToReferenceListResponse*>(response),
             done);
      break;
    case 6:
      RemoveFromReferenceList(controller,
             ::google::protobuf::down_cast<const ::maidsafe::RemoveFromReferenceListRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::RemoveFromReferenceListResponse*>(response),
             done);
      break;
    case 7:
      AmendAccount(controller,
             ::google::protobuf::down_cast<const ::maidsafe::AmendAccountRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::AmendAccountResponse*>(response),
             done);
      break;
    case 8:
      GetAccountStatus(controller,
             ::google::protobuf::down_cast<const ::maidsafe::GetAccountStatusRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::GetAccountStatusResponse*>(response),
             done);
      break;
    case 9:
      CheckChunk(controller,
             ::google::protobuf::down_cast<const ::maidsafe::CheckChunkRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::CheckChunkResponse*>(response),
             done);
      break;
    case 10:
      GetChunk(controller,
             ::google::protobuf::down_cast<const ::maidsafe::GetChunkRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::GetChunkResponse*>(response),
             done);
      break;
    case 11:
      GetPacket(controller,
             ::google::protobuf::down_cast<const ::maidsafe::GetPacketRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::GetPacketResponse*>(response),
             done);
      break;
    case 12:
      UpdateChunk(controller,
             ::google::protobuf::down_cast<const ::maidsafe::UpdateChunkRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::UpdateChunkResponse*>(response),
             done);
      break;
    case 13:
      DeleteChunk(controller,
             ::google::protobuf::down_cast<const ::maidsafe::DeleteChunkRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::DeleteChunkResponse*>(response),
             done);
      break;
    case 14:
      ValidityCheck(controller,
             ::google::protobuf::down_cast<const ::maidsafe::ValidityCheckRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::ValidityCheckResponse*>(response),
             done);
      break;
    case 15:
      SwapChunk(controller,
             ::google::protobuf::down_cast<const ::maidsafe::SwapChunkRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::SwapChunkResponse*>(response),
             done);
      break;
    case 16:
      VaultStatus(controller,
             ::google::protobuf::down_cast<const ::maidsafe::VaultStatusRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::VaultStatusResponse*>(response),
             done);
      break;
    case 17:
      CreateBP(controller,
             ::google::protobuf::down_cast<const ::maidsafe::CreateBPRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::CreateBPResponse*>(response),
             done);
      break;
    case 18:
      ModifyBPInfo(controller,
             ::google::protobuf::down_cast<const ::maidsafe::ModifyBPInfoRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::ModifyBPInfoResponse*>(response),
             done);
      break;
    case 19:
      GetBPMessages(controller,
             ::google::protobuf::down_cast<const ::maidsafe::GetBPMessagesRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::GetBPMessagesResponse*>(response),
             done);
      break;
    case 20:
      AddBPMessage(controller,
             ::google::protobuf::down_cast<const ::maidsafe::AddBPMessageRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::AddBPMessageResponse*>(response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& MaidsafeService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::maidsafe::StorePrepRequest::default_instance();
    case 1:
      return ::maidsafe::StoreChunkRequest::default_instance();
    case 2:
      return ::maidsafe::StorePacketRequest::default_instance();
    case 3:
      return ::maidsafe::AddToWatchListRequest::default_instance();
    case 4:
      return ::maidsafe::RemoveFromWatchListRequest::default_instance();
    case 5:
      return ::maidsafe::AddToReferenceListRequest::default_instance();
    case 6:
      return ::maidsafe::RemoveFromReferenceListRequest::default_instance();
    case 7:
      return ::maidsafe::AmendAccountRequest::default_instance();
    case 8:
      return ::maidsafe::GetAccountStatusRequest::default_instance();
    case 9:
      return ::maidsafe::CheckChunkRequest::default_instance();
    case 10:
      return ::maidsafe::GetChunkRequest::default_instance();
    case 11:
      return ::maidsafe::GetPacketRequest::default_instance();
    case 12:
      return ::maidsafe::UpdateChunkRequest::default_instance();
    case 13:
      return ::maidsafe::DeleteChunkRequest::default_instance();
    case 14:
      return ::maidsafe::ValidityCheckRequest::default_instance();
    case 15:
      return ::maidsafe::SwapChunkRequest::default_instance();
    case 16:
      return ::maidsafe::VaultStatusRequest::default_instance();
    case 17:
      return ::maidsafe::CreateBPRequest::default_instance();
    case 18:
      return ::maidsafe::ModifyBPInfoRequest::default_instance();
    case 19:
      return ::maidsafe::GetBPMessagesRequest::default_instance();
    case 20:
      return ::maidsafe::AddBPMessageRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

const ::google::protobuf::Message& MaidsafeService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::maidsafe::StorePrepResponse::default_instance();
    case 1:
      return ::maidsafe::StoreChunkResponse::default_instance();
    case 2:
      return ::maidsafe::StorePacketResponse::default_instance();
    case 3:
      return ::maidsafe::AddToWatchListResponse::default_instance();
    case 4:
      return ::maidsafe::RemoveFromWatchListResponse::default_instance();
    case 5:
      return ::maidsafe::AddToReferenceListResponse::default_instance();
    case 6:
      return ::maidsafe::RemoveFromReferenceListResponse::default_instance();
    case 7:
      return ::maidsafe::AmendAccountResponse::default_instance();
    case 8:
      return ::maidsafe::GetAccountStatusResponse::default_instance();
    case 9:
      return ::maidsafe::CheckChunkResponse::default_instance();
    case 10:
      return ::maidsafe::GetChunkResponse::default_instance();
    case 11:
      return ::maidsafe::GetPacketResponse::default_instance();
    case 12:
      return ::maidsafe::UpdateChunkResponse::default_instance();
    case 13:
      return ::maidsafe::DeleteChunkResponse::default_instance();
    case 14:
      return ::maidsafe::ValidityCheckResponse::default_instance();
    case 15:
      return ::maidsafe::SwapChunkResponse::default_instance();
    case 16:
      return ::maidsafe::VaultStatusResponse::default_instance();
    case 17:
      return ::maidsafe::CreateBPResponse::default_instance();
    case 18:
      return ::maidsafe::ModifyBPInfoResponse::default_instance();
    case 19:
      return ::maidsafe::GetBPMessagesResponse::default_instance();
    case 20:
      return ::maidsafe::AddBPMessageResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

MaidsafeService_Stub::MaidsafeService_Stub(::google::protobuf::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
MaidsafeService_Stub::MaidsafeService_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}
MaidsafeService_Stub::~MaidsafeService_Stub() {
  if (owns_channel_) delete channel_;
}

void MaidsafeService_Stub::StoreChunkPrep(::google::protobuf::RpcController* controller,
                              const ::maidsafe::StorePrepRequest* request,
                              ::maidsafe::StorePrepResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}
void MaidsafeService_Stub::StoreChunk(::google::protobuf::RpcController* controller,
                              const ::maidsafe::StoreChunkRequest* request,
                              ::maidsafe::StoreChunkResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(1),
                       controller, request, response, done);
}
void MaidsafeService_Stub::StorePacket(::google::protobuf::RpcController* controller,
                              const ::maidsafe::StorePacketRequest* request,
                              ::maidsafe::StorePacketResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(2),
                       controller, request, response, done);
}
void MaidsafeService_Stub::AddToWatchList(::google::protobuf::RpcController* controller,
                              const ::maidsafe::AddToWatchListRequest* request,
                              ::maidsafe::AddToWatchListResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(3),
                       controller, request, response, done);
}
void MaidsafeService_Stub::RemoveFromWatchList(::google::protobuf::RpcController* controller,
                              const ::maidsafe::RemoveFromWatchListRequest* request,
                              ::maidsafe::RemoveFromWatchListResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(4),
                       controller, request, response, done);
}
void MaidsafeService_Stub::AddToReferenceList(::google::protobuf::RpcController* controller,
                              const ::maidsafe::AddToReferenceListRequest* request,
                              ::maidsafe::AddToReferenceListResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(5),
                       controller, request, response, done);
}
void MaidsafeService_Stub::RemoveFromReferenceList(::google::protobuf::RpcController* controller,
                              const ::maidsafe::RemoveFromReferenceListRequest* request,
                              ::maidsafe::RemoveFromReferenceListResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(6),
                       controller, request, response, done);
}
void MaidsafeService_Stub::AmendAccount(::google::protobuf::RpcController* controller,
                              const ::maidsafe::AmendAccountRequest* request,
                              ::maidsafe::AmendAccountResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(7),
                       controller, request, response, done);
}
void MaidsafeService_Stub::GetAccountStatus(::google::protobuf::RpcController* controller,
                              const ::maidsafe::GetAccountStatusRequest* request,
                              ::maidsafe::GetAccountStatusResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(8),
                       controller, request, response, done);
}
void MaidsafeService_Stub::CheckChunk(::google::protobuf::RpcController* controller,
                              const ::maidsafe::CheckChunkRequest* request,
                              ::maidsafe::CheckChunkResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(9),
                       controller, request, response, done);
}
void MaidsafeService_Stub::GetChunk(::google::protobuf::RpcController* controller,
                              const ::maidsafe::GetChunkRequest* request,
                              ::maidsafe::GetChunkResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(10),
                       controller, request, response, done);
}
void MaidsafeService_Stub::GetPacket(::google::protobuf::RpcController* controller,
                              const ::maidsafe::GetPacketRequest* request,
                              ::maidsafe::GetPacketResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(11),
                       controller, request, response, done);
}
void MaidsafeService_Stub::UpdateChunk(::google::protobuf::RpcController* controller,
                              const ::maidsafe::UpdateChunkRequest* request,
                              ::maidsafe::UpdateChunkResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(12),
                       controller, request, response, done);
}
void MaidsafeService_Stub::DeleteChunk(::google::protobuf::RpcController* controller,
                              const ::maidsafe::DeleteChunkRequest* request,
                              ::maidsafe::DeleteChunkResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(13),
                       controller, request, response, done);
}
void MaidsafeService_Stub::ValidityCheck(::google::protobuf::RpcController* controller,
                              const ::maidsafe::ValidityCheckRequest* request,
                              ::maidsafe::ValidityCheckResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(14),
                       controller, request, response, done);
}
void MaidsafeService_Stub::SwapChunk(::google::protobuf::RpcController* controller,
                              const ::maidsafe::SwapChunkRequest* request,
                              ::maidsafe::SwapChunkResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(15),
                       controller, request, response, done);
}
void MaidsafeService_Stub::VaultStatus(::google::protobuf::RpcController* controller,
                              const ::maidsafe::VaultStatusRequest* request,
                              ::maidsafe::VaultStatusResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(16),
                       controller, request, response, done);
}
void MaidsafeService_Stub::CreateBP(::google::protobuf::RpcController* controller,
                              const ::maidsafe::CreateBPRequest* request,
                              ::maidsafe::CreateBPResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(17),
                       controller, request, response, done);
}
void MaidsafeService_Stub::ModifyBPInfo(::google::protobuf::RpcController* controller,
                              const ::maidsafe::ModifyBPInfoRequest* request,
                              ::maidsafe::ModifyBPInfoResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(18),
                       controller, request, response, done);
}
void MaidsafeService_Stub::GetBPMessages(::google::protobuf::RpcController* controller,
                              const ::maidsafe::GetBPMessagesRequest* request,
                              ::maidsafe::GetBPMessagesResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(19),
                       controller, request, response, done);
}
void MaidsafeService_Stub::AddBPMessage(::google::protobuf::RpcController* controller,
                              const ::maidsafe::AddBPMessageRequest* request,
                              ::maidsafe::AddBPMessageResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(20),
                       controller, request, response, done);
}
// ===================================================================

VaultRegistration::~VaultRegistration() {}

const ::google::protobuf::ServiceDescriptor* VaultRegistration::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return VaultRegistration_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* VaultRegistration::GetDescriptor() {
  protobuf_AssignDescriptorsOnce();
  return VaultRegistration_descriptor_;
}

void VaultRegistration::OwnVault(::google::protobuf::RpcController* controller,
                         const ::maidsafe::OwnVaultRequest*,
                         ::maidsafe::OwnVaultResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method OwnVault() not implemented.");
  done->Run();
}

void VaultRegistration::IsVaultOwned(::google::protobuf::RpcController* controller,
                         const ::maidsafe::IsOwnedRequest*,
                         ::maidsafe::IsOwnedResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method IsVaultOwned() not implemented.");
  done->Run();
}

void VaultRegistration::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             ::google::protobuf::RpcController* controller,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), VaultRegistration_descriptor_);
  switch(method->index()) {
    case 0:
      OwnVault(controller,
             ::google::protobuf::down_cast<const ::maidsafe::OwnVaultRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::OwnVaultResponse*>(response),
             done);
      break;
    case 1:
      IsVaultOwned(controller,
             ::google::protobuf::down_cast<const ::maidsafe::IsOwnedRequest*>(request),
             ::google::protobuf::down_cast< ::maidsafe::IsOwnedResponse*>(response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& VaultRegistration::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::maidsafe::OwnVaultRequest::default_instance();
    case 1:
      return ::maidsafe::IsOwnedRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

const ::google::protobuf::Message& VaultRegistration::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::maidsafe::OwnVaultResponse::default_instance();
    case 1:
      return ::maidsafe::IsOwnedResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

VaultRegistration_Stub::VaultRegistration_Stub(::google::protobuf::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
VaultRegistration_Stub::VaultRegistration_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}
VaultRegistration_Stub::~VaultRegistration_Stub() {
  if (owns_channel_) delete channel_;
}

void VaultRegistration_Stub::OwnVault(::google::protobuf::RpcController* controller,
                              const ::maidsafe::OwnVaultRequest* request,
                              ::maidsafe::OwnVaultResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}
void VaultRegistration_Stub::IsVaultOwned(::google::protobuf::RpcController* controller,
                              const ::maidsafe::IsOwnedRequest* request,
                              ::maidsafe::IsOwnedResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(1),
                       controller, request, response, done);
}

}  // namespace maidsafe
