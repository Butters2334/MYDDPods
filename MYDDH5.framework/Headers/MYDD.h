//
//  BPSchemeControl.h
//  BopaiH5
//
//  Created by ac on 2019/12/5.
//  Copyright © 2019 ancc. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol Mydd_Delegate <NSObject>
/**MYDD业务委托-前往充值页面,之后请调用[MYDD restart]重新打开*/
-(void)mydd_jumpToMyWallet:(NSString *)token;
/**MYDD业务委托-前往登录页面,登录完成后请调用[MYDD restart]重新打开*/
-(void)mydd_jumpToLogin;
/**MYDD业务委托-获取当前登录状态*/
-(BOOL)mydd_getLoginStatus;
/**MYDD业务委托-获取用户标示符*/
-(NSString *)mydd_getUserMark;
/**调试阶段:外部登录状态重置*/
-(void)mydd_logout;
@end

@interface MYDD : NSObject
/**
 *  启动应用时调用
 *  需要在AppDelegate.m - application: didFinishLaunchingWithOptions:中实现
 *
 *  @param launchOptions 启动MYDD时判断是否在safari打开MYDD scheme
 */
+(void)setLaunchOptions:(NSDictionary *)launchOptions;
/**
 *  设置SDK响应函数
 *
 *  @param delegate MYDD中相关业务需要外部支持(如登录和充值)
 */
+(void)setMydd_Delegate:(id<Mydd_Delegate>)delegate;
/**
 *  启动MYDD
 *  MYDD启动使用传入rootVC弹出模态视图
 */
+(void)startGame:(UIViewController *)rootViewController;
/**
 *  唤醒MYDD
 *  MYDD打开登录/充值后MYDD暂时处于挂起状态,可以通过调用[MYDD restart]唤醒MYDD
 *
 *  使用nav的页面推荐在pop之前调用
 *  使用模态弹出的页面推荐在dismissViewControllerAnimated:completion:的回调函数中调用
 */
+(void)restart;


/**
 *  通过scheme启动应用调用
 *  return url是否符合MYDD业务逻辑
 *  需要在AppDelegate.m - application:openURL:options:中实现
 *  #desc从safari或其他应用唤醒当前应用
 **/
+ (BOOL)handleOpenURL:(NSURL *)url;
/**
 *  唤醒应用时判断MYDD是否需要弹出口令弹框
 *  需要在AppDelegate.m - applicationWillEnterForeground:中实现
 *  #desc 从沙盒桌面或其他应用返回到应用中
 **/
+(void)applicationWillEnterForeground:(UIApplication *)application;
/**
 *  应用进入后台时将MYDD静音
 *  需要在AppDelegate.m - applicationDidEnterBackground:中实现
 *  #desc客户端进入沙盒桌面
 */
+(void)applicationDidEnterBackground:(UIApplication *)application;


/**MYDD默认启动页面可以修改(debug阶段)*/
+(void)setWebViewUrl:(NSString *)webviewUrl;
/**webview默认打开页面*/
+(NSString *)webviewUrl;
@end
