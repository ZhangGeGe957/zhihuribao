//
//  FreeStyleTableViewCell.h
//  知乎日报
//
//  Created by 张佳乔 on 2021/10/19.
//

#import <UIKit/UIKit.h>
#import "Masonry.h"

NS_ASSUME_NONNULL_BEGIN

@interface FreeStyleTableViewCell : UITableViewCell<UIScrollViewDelegate>

@property (nonatomic, strong) UIImageView *showImageView;
@property (nonatomic, strong) UILabel *mainLabel;
@property (nonatomic, strong) UILabel *subLabel;

@end

NS_ASSUME_NONNULL_END
