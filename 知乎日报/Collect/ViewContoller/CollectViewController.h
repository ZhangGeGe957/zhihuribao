//
//  CollectViewController.h
//  知乎日报
//
//  Created by 张佳乔 on 2021/10/30.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "FMDB.h"

NS_ASSUME_NONNULL_BEGIN

@interface CollectViewController : UIViewController<WKUIDelegate, UIScrollViewDelegate>

@property (nonatomic, strong) NSMutableArray *temporaryArray;   //临时存储数据
@property (nonatomic, strong) NSMutableArray *allTransDataArray;
@property (nonatomic, copy) NSString *fileName;  //数据库路径

@property (nonatomic, strong) UIScrollView *viewScrollView;
@property (nonatomic, strong) WKWebView *URLWebView;
@property (nonatomic, strong) UIView *bottomView;
@property (nonatomic, strong) UIButton *backButton;
@property (nonatomic, strong) UILabel *lineLabel;
@property (nonatomic, strong) UIButton *goodButton;
@property (nonatomic, strong) UIButton *messageButton;
@property (nonatomic, strong) UIButton *collectionButton;
@property (nonatomic, strong) UIButton *shareButton;

@property (nonatomic, strong) NSTimer *stopTimer;
@property (nonatomic, strong) UIAlertController *alertView;

@property (nonatomic, strong) NSDictionary *longDictionary;
@property (nonatomic, strong) NSDictionary *shortDictionary;
@property (nonatomic, assign) int a;

@end

NS_ASSUME_NONNULL_END
