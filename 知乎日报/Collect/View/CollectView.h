//
//  CollectView.h
//  知乎日报
//
//  Created by 张佳乔 on 2021/10/30.
//

#import <UIKit/UIKit.h>
#import "FreeStyleTableViewCell.h"
#import "SDWebImage.h"

NS_ASSUME_NONNULL_BEGIN

@interface CollectView : UIView<UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) FreeStyleTableViewCell *showCell;
@property (nonatomic, strong) UITableView *showTableView;
@property (nonatomic, strong) UIButton *backButton;
@property (nonatomic, assign) NSInteger judgeThings;
@property (nonatomic, strong) UILabel *tipsLabel;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UIView *topView;

@property (nonatomic, strong) NSMutableArray *allTransDataArray;

@end

NS_ASSUME_NONNULL_END
