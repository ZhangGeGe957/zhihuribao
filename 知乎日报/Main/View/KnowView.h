//
//  KnowView.h
//  知乎日报
//
//  Created by 张佳乔 on 2021/10/17.
//

#import <UIKit/UIKit.h>
#import "Masonry.h"
#import "FreeStyleTableViewCell.h"
#import "NetworkJSONModel.h"
#import "SDWebImage.h"

NS_ASSUME_NONNULL_BEGIN

@interface KnowView : UIView<UITableViewDelegate, UITableViewDataSource, UIScrollViewDelegate>

@property (nonatomic, strong) UITableView *tableView;
@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) UITableViewCell *rollCell;
@property (nonatomic, strong) UITableViewCell *flashCell;
@property (nonatomic, strong) FreeStyleTableViewCell *showCell;
@property (nonatomic, strong) UIButton *rollButton;
@property (nonatomic, strong) UIPageControl *pageControl;
@property (nonatomic, strong) NSTimer *timer;

@property (nonatomic, assign) NSInteger currentIndex; //当前的中心位置图片
@property (nonatomic, assign) NSInteger allIndex;  //总图片数
@property (nonatomic, assign) NSInteger UnKnowflag;
@property (nonatomic, assign) NSInteger againFlag;
@property (nonatomic, assign) float allOffset;

@property (nonatomic, strong) NSMutableArray *storiesTitle;
@property (nonatomic, strong) NSMutableArray *storiesUrl;
@property (nonatomic, strong) NSMutableArray *storiesHint;
@property (nonatomic, strong) NSMutableArray *storiesImages;
@property (nonatomic, strong) NSMutableArray *storiesId;

@property (nonatomic, strong) NSMutableArray *top_storiesTitle;
@property (nonatomic, strong) NSMutableArray *top_storiesUrl;
@property (nonatomic, strong) NSMutableArray *top_storiesHint;
@property (nonatomic, strong) NSMutableArray *top_storiesImage;
@property (nonatomic, strong) NSMutableArray *top_storiesId;

@property (nonatomic, strong) NSMutableArray *temporaryArray;  //临时存储一组字典型数据
@property (nonatomic, strong) NSMutableArray *allNetworkData;  //存储所有的字典型数据
@property (nonatomic, strong) NSMutableArray *allTopNetworkData;  //存储所有top的字典型数据
@property (nonatomic, strong) NSMutableArray *allTransURL;   //存储所有的URL
@property (nonatomic, strong) NSMutableArray *allTransID;   //存储所有的ID
@property (nonatomic, strong) NSMutableArray *allRollButton;  //存储所有的滚动视图上的button
@property (nonatomic, assign) NSInteger rollLocation;  //记录滚动视图上的button的滚动位置

//假导航栏
@property (nonatomic, strong) UIButton *flaseButton;
@property (nonatomic, strong) UILabel *flaseLabel;
@property (nonatomic, strong) UILabel *monthLabel;
@property (nonatomic, strong) UILabel *dayLabel;
@property (nonatomic, strong) UILabel *lineLabel;

//加载小菊花
@property (nonatomic, strong) UIActivityIndicatorView *flashView;
@property (nonatomic, assign) NSInteger networkFlag;

- (void)creatFalseView;

@end

NS_ASSUME_NONNULL_END
