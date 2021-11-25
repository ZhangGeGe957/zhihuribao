//
//  MessageViewController.m
//  知乎日报
//
//  Created by 张佳乔 on 2021/11/2.
//

#import "MessageViewController.h"

#define myWidth [UIScreen mainScreen].bounds.size.width
#define myHeight [UIScreen mainScreen].bounds.size.height

@interface MessageViewController ()

@end

@implementation MessageViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    
    [self createUI];
    
}
//使用动画的方式隐藏导航栏
- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];

    [self.navigationController setNavigationBarHidden:YES animated:animated];
}
- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];

    [self.navigationController setNavigationBarHidden:NO animated:animated];
}

- (void)createUI {
    
    self.longHeightArray = [[NSMutableArray alloc] init];
    self.shortHeightArray = [[NSMutableArray alloc] init];
    self.longReplyHeightArray = [[NSMutableArray alloc] init];
    self.shorReplytHeightArray = [[NSMutableArray alloc] init];
    
    for (int i = 0; i < [self.longDictionary[@"comments"] count]; i++) {
        UILabel *label = [[UILabel alloc] init];
        label.text = self.longDictionary[@"comments"][i][@"content"];
        label.font = [UIFont systemFontOfSize:18];
        label.numberOfLines = 0;
        CGSize size = [label sizeThatFits:CGSizeMake(myWidth / 1.3, CGFLOAT_MAX)];
        UILabel *labelReply = [[UILabel alloc] init];
        CGSize sizeReply = CGSizeZero;
        if ([self.longDictionary[@"comments"][i] objectForKey:@"reply_to"]) {
            NSString *replyAll = [[NSString alloc] initWithFormat:@"//%@：%@", self.longDictionary[@"comments"][i][@"reply_to"][@"author"], self.longDictionary[@"comments"][i][@"reply_to"][@"content"]];
            labelReply.text = replyAll;
            labelReply.font = [UIFont systemFontOfSize:15];
            labelReply.numberOfLines = 0;
            sizeReply = [labelReply sizeThatFits:CGSizeMake(myWidth / 1.3, CGFLOAT_MAX)];
        }
        NSString *replyHeight = [[NSString alloc] initWithFormat:@"%lf", sizeReply.height];
        [self.longReplyHeightArray addObject:replyHeight];
        NSString *height = [[NSString alloc] initWithFormat:@"%lf", size.height];
        [self.longHeightArray addObject:height];
    }
    
    for (int i = 0; i < [self.shortDictionary[@"comments"] count]; i++) {
        UILabel *label = [[UILabel alloc] init];
        label.text = self.shortDictionary[@"comments"][i][@"content"];
        label.font = [UIFont systemFontOfSize:18];
        label.numberOfLines = 0;
        CGSize size = [label sizeThatFits:CGSizeMake(myWidth / 1.3, CGFLOAT_MAX)];
        UILabel *labelReply = [[UILabel alloc] init];
        CGSize sizeReply = CGSizeZero;
        if ([self.shortDictionary[@"comments"][i] objectForKey:@"reply_to"]) {
            NSString *replyAll = [[NSString alloc] initWithFormat:@"//%@：%@", self.shortDictionary[@"comments"][i][@"reply_to"][@"author"], self.shortDictionary[@"comments"][i][@"reply_to"][@"content"]];
            labelReply.text = replyAll;
            labelReply.font = [UIFont systemFontOfSize:15];
            labelReply.numberOfLines = 0;
            sizeReply = [labelReply sizeThatFits:CGSizeMake(myWidth / 1.3, CGFLOAT_MAX)];
        }
        NSString *replyHeight = [[NSString alloc] initWithFormat:@"%lf", sizeReply.height];
        [self.shorReplytHeightArray addObject:replyHeight];
        NSString *height = [[NSString alloc] initWithFormat:@"%lf", size.height];
        [self.shortHeightArray addObject:height];
    }
    
    self.messageView = [[MessageView alloc] initWithFrame:CGRectMake(0, 0, myWidth, myHeight)];
    
    self.longHeightDictionary = [[NSMutableDictionary alloc] init];
    [self.longHeightDictionary setObject:self.longHeightArray forKey:@"Height"];
    [self.longHeightDictionary setObject:self.longReplyHeightArray forKey:@"Reply"];
    self.shortHeightDictionary = [[NSMutableDictionary alloc] init];
    [self.shortHeightDictionary setObject:self.shortHeightArray forKey:@"Height"];
    [self.shortHeightDictionary setObject:self.shorReplytHeightArray forKey:@"Reply"];
    
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"TransLongHeightDictionary" object:nil userInfo:self.longHeightDictionary];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"TransShortHeightDictionary" object:nil userInfo:self.shortHeightDictionary];
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"TransLongDictionary" object:nil userInfo:self.longDictionary];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"TransShortDictionary" object:nil userInfo:self.shortDictionary];
    
    [self.messageView.backButton addTarget:self action:@selector(pressBack:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.messageView];
}


- (void)pressBack:(UIButton*)button {
    [self.navigationController popViewControllerAnimated:YES];
}

- (CGFloat)calculatedHeight:(UILabel *)label {
    //有源码在 有需求自行微调即可
    NSInteger n = 6;//最多显示的行数
    CGSize labelSize = {0, 0};
    
    labelSize = [self calculatedTextHeightFromTextString:label.text width:label.frame.size.width fontSize:label.font.pointSize];
    
    return label.font.lineHeight;
    //NSLog(@"%f",label.font.pointSize);//获取 label的字体大小
    //NSLog(@"%f",label.font.lineHeight);//获取label的在不同字体下的时候所需要的行高
    //NSLog(@"%f",labelSize.height);//label计算行高
    CGFloat rate = label.font.lineHeight; //每一行需要的高度

    CGRect frame= label.frame;
    if (labelSize.height > rate * n) {
        frame.size.height = rate * n;
    } else {
        frame.size.height = labelSize.height;
    }
    label.frame = frame;
}

//计算 label需要的宽度和高度方法
- (CGSize)calculatedTextHeightFromTextString:(NSString *)text width:(CGFloat)textWidth fontSize:(CGFloat)size{
    //计算 label需要的宽度和高度
    NSDictionary *dict = @{NSFontAttributeName:[UIFont systemFontOfSize:size]};
    CGRect rect = [text boundingRectWithSize:CGSizeMake(textWidth, MAXFLOAT) options:NSStringDrawingTruncatesLastVisibleLine|NSStringDrawingUsesFontLeading|NSStringDrawingUsesLineFragmentOrigin attributes:dict context:nil];
    
     CGSize nowTextSize = [text sizeWithAttributes:@{NSFontAttributeName: [UIFont systemFontOfSize:size]}];
    
    return CGSizeMake(nowTextSize.width, rect.size.height);
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
