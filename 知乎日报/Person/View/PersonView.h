//
//  PersonView.h
//  知乎日报
//
//  Created by 张佳乔 on 2021/10/19.
//

#import <UIKit/UIKit.h>
#import "Masonry.h"
#import "PersonTableViewCell.h"

NS_ASSUME_NONNULL_BEGIN

@interface PersonView : UIView<UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) UIButton *headButton;
@property (nonatomic, strong) UIButton *backButton;
@property (nonatomic, strong) UILabel *nameLabel;
@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) PersonTableViewCell *cell;

@end

NS_ASSUME_NONNULL_END
