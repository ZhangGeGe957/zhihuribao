//
//  MessageViewController.h
//  知乎日报
//
//  Created by 张佳乔 on 2021/11/2.
//

#import <UIKit/UIKit.h>
#import "MessageView.h"
#import "MessageTableViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface MessageViewController : UIViewController<UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) MessageView *messageView;

@property (nonatomic, strong) NSDictionary *longDictionary;
@property (nonatomic, strong) NSDictionary *shortDictionary;
@property (nonatomic, strong) NSMutableArray *longHeightArray;
@property (nonatomic, strong) NSMutableArray *shortHeightArray;
@property (nonatomic, strong) NSMutableArray *longReplyHeightArray;
@property (nonatomic, strong) NSMutableArray *shorReplytHeightArray;
@property (nonatomic, strong) NSMutableDictionary *longHeightDictionary;
@property (nonatomic, strong) NSMutableDictionary *shortHeightDictionary;

@end

NS_ASSUME_NONNULL_END
