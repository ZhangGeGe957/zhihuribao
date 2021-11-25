//
//  NetworkModel.h
//  知乎日报
//
//  Created by 张佳乔 on 2021/10/18.
//

#import <Foundation/Foundation.h>
#import "NetworkJSONModel.h"

typedef void (^NetworkBlock)(NetworkJSONModel * _Nullable networkModel);
typedef void (^ErrorBlock)(NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

@interface NetworkModel : NSObject

+ (instancetype)shareNetworkModel;
- (void)NetworkModelData:(NetworkBlock)networkDataBlock andError:(ErrorBlock)errorBlock;

@end

NS_ASSUME_NONNULL_END
