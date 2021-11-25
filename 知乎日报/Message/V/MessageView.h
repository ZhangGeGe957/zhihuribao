//
//  MessageView.h
//  知乎日报
//
//  Created by 张佳乔 on 2021/11/2.
//

#import <UIKit/UIKit.h>
#import "Masonry.h"
#import "MessageTableViewCell.h"
#import "SDWebImage.h"

NS_ASSUME_NONNULL_BEGIN

@interface MessageView : UIView<UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) UIView *topView;
@property (nonatomic, strong) UIButton *backButton;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *lineLabel;
@property (nonatomic, strong) UITableView *messageTableView;
@property (nonatomic, strong) MessageTableViewCell *messageCell;
@property (nonatomic, strong) UIButton *openButton;

@property (nonatomic, strong) NSMutableArray *longDataArray;
@property (nonatomic, strong) NSMutableArray *shortDataArray;
@property (nonatomic, strong) NSMutableArray *tempArray;
@property (nonatomic, assign) NSInteger longNumber;
@property (nonatomic, assign) NSInteger shortNumber;
@property (nonatomic, copy) NSString *allMessageNumber;
@property (nonatomic, strong) NSMutableArray *longHeightArray;
@property (nonatomic, strong) NSMutableArray *shortHeightArray;
@property (nonatomic, strong) NSMutableArray *longReplyHeightArray;
@property (nonatomic, strong) NSMutableArray *shorReplytHeightArray;
@property (nonatomic, strong) NSMutableArray *longOpenFlagArray;
@property (nonatomic, strong) NSMutableArray *shortOpenFlagArray;

//时间戳转时间
- (NSString *)getTimeFromTimestamp:(NSString *)timeString;

@end

NS_ASSUME_NONNULL_END
