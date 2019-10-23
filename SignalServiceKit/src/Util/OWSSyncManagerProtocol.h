//
//  Copyright (c) 2019 Open Whisper Systems. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@class AnyPromise;
@class SDSAnyWriteTransaction;
@class SSKProtoSyncMessageConfiguration;
@class SignalAccount;

@protocol OWSSyncManagerProtocol <NSObject>

- (void)sendConfigurationSyncMessage;

- (void)sendAllSyncRequestMessages;

- (AnyPromise *)syncLocalContact __attribute__((warn_unused_result));

- (AnyPromise *)syncAllContacts __attribute__((warn_unused_result));

- (AnyPromise *)syncContactsForSignalAccounts:(NSArray<SignalAccount *> *)signalAccounts __attribute__((warn_unused_result));

- (void)syncGroupsWithTransaction:(SDSAnyWriteTransaction *)transaction;

- (void)processIncomingConfigurationSyncMessage:(SSKProtoSyncMessageConfiguration *)syncMessage transaction:(SDSAnyWriteTransaction *)transaction;

@end

NS_ASSUME_NONNULL_END
