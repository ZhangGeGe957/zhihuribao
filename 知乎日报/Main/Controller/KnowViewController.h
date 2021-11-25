//
//  KnowViewController.h
//  知乎日报
//
//  Created by 张佳乔 on 2021/10/17.
//

#import <UIKit/UIKit.h>
#import "KnowView.h"
#import "Masonry.h"
#import "NetworkJSONModel.h"
#import "OldNetworkJSONModel.h"
#import <WebKit/WebKit.h>
#import "FMDB.h"

NS_ASSUME_NONNULL_BEGIN

@interface KnowViewController : UIViewController<UIScrollViewDelegate, UIWebViewDelegate, WKUIDelegate>

@property (nonatomic, copy) NSString *monthString;
@property (nonatomic, copy) NetworkJSONModel *getJSONModel;
@property (nonatomic, copy) NSDictionary *dictionaryModel;
@property (nonatomic, copy) OldNetworkJSONModel *getOldJSONModel;
@property (nonatomic, copy) NSDateFormatter *getFormatter;
@property (nonatomic, copy) NSDate *getDate;
@property (nonatomic, copy) NSString *getString;
@property (nonatomic, strong) NSMutableDictionary *getDictionary;

@property (nonatomic, strong) UIScrollView *viewScrollView;
@property (nonatomic, strong) NSMutableArray *allTransURL;   //接收传过来的所有的URL
@property (nonatomic, strong) NSMutableArray *allTransID;   //存储所有的ID
@property (nonatomic, assign) NSInteger atLocation;   //当前URL位置
@property (nonatomic, strong) WKWebView *URLWebView;
@property (nonatomic, strong) UIView *bottomView;
@property (nonatomic, strong) UIButton *backButton;
@property (nonatomic, strong) UILabel *lineLabel;
@property (nonatomic, strong) NSMutableArray *goodArray;   //点赞状态数组
@property (nonatomic, strong) UIButton *goodButton;
@property (nonatomic, strong) UIButton *messageButton;
@property (nonatomic, strong) NSMutableArray *collectionArray;  //收藏状态数组
@property (nonatomic, strong) UIButton *collectionButton;
@property (nonatomic, strong) UIButton *shareButton;

@property (nonatomic, strong) NSMutableArray *allNetworkData;  //存储所有的字典型数据
@property (nonatomic, strong) NSMutableArray *temporaryArray;   //临时存储数据
@property (nonatomic, strong) NSMutableArray *allTransDataArray;  //收藏传输的数据

@property (nonatomic, strong) NSDictionary *longDictionary;
@property (nonatomic, strong) NSDictionary *shortDictionary;

@property (nonatomic, assign) int a;

//转化月份
- (NSString *)changMonth:(NSString*)string;

- (void)createDataBase;   //创建数据库
- (void)insertData;  //插入数据
- (void)updateData;  //更新数据
- (void)deleteData;  //删除数据
- (void)queryData; //查询数据

@end

NS_ASSUME_NONNULL_END
